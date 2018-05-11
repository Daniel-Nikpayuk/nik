/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct identity
{
	using method = typename subject
	<
		Interval::opening,
		Direction::backward

	>::template object
	<
		Interval::opening,
		Direction::backward
	>;

	struct equals_verb
	{
		bool rtn;

		equals_verb() : rtn(false) { }

		template<typename type_ptr>
		bool closing_pattern(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub == *ob);

			return !rtn;
		}

		template<typename type_ptr>
		void closed_pattern(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub == *ob);
		}
	};

	template<typename type_ptr>
	static bool equals(type_ptr sub, type_ptr ob, type_ptr end)
	{
		equals_verb verb;

		method::compare(verb, sub, ob, end);

		return verb.rtn;
	}
};

