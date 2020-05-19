/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik.
**
** nik is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** nik is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik. If not, see
** <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

struct inductor
{
	template<typename>
	struct memoized_judgement
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, false>;
	};

	template<typename Type, template<typename Kind, Kind> class Judgement, Type Value>
	struct memoized_judgement<Judgement<Type, Value>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<bool, true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			Type, Judgement, Value
		>;
	};

	//

	struct ch_judgement
	{
		template<typename Type, template<typename Kind, Kind> class Judgement, Type Value>
		using result = Judgement<Type, Value>;
	};

	struct ch_judgement_type
	{
		template<typename Type, template<typename Kind, Kind> class Judgement, Type Value>
		using result = Type;
	};

	struct ch_judgement_value
	{
		template<typename Type, template<typename Kind, Kind> class Judgement, Type Value>
		static constexpr Type result = Value;
	};
};

