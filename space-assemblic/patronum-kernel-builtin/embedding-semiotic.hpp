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

struct embedding
{
	template<typename Exp, typename Continuation = ch_judgement>
	using judgement = typename memoized_judgement<Exp>::template induct
	<
		Continuation
	>;

	template<typename Exp, typename Continuation = ch_judgement_type>
	using judgement_type = typename memoized_judgement<Exp>::template induct
	<
		Continuation
	>;

	template<typename Exp, typename Continuation = ch_judgement_value>
	static constexpr judgement_type<Exp> judgement_value = memoized_judgement<Exp>::template induct
	<
		Continuation
	>;
};

