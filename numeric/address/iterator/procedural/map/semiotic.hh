/************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#include"prototype.hh"
#include"specialize.hh"

/************************************************************************************************************************/


/*
template<typename sub_adjective, typename ob_adjective, typename adverb>
static void map(sub_pointer & out, ob_pointer in, ob_pointer end, adverb & side)
{
	using optimizer_type = CASES
	<
		(adverb::optimizer_enum - adverb::optimizer_offset),
		prototype<sub_adjective, ob_adjective, adverb>,
		specialize<sub_adjective, ob_adjective, adverb>

	>::rtn;

	(void) optimizer_type::map(out, in, end, side);
}
*/

template<typename adverb, typename sub_pointer, typename sub_adjective, typename ob_pointer, typename ob_adjective>
static sub_pointer map(adverb & verb, sub_pointer out, sub_adjective sub, ob_pointer in, ob_pointer end, ob_adjective ob)
{
	using verb_type = type<Adverb::apply_functor, Adverb::omit_count, optimizerEnum>;
	using adverb = typename verb_type::template adverb<sub_adjective, ob_adjective, Functor>;

	adverb side = verb_type::template verb<sub_adjective, ob_adjective>(functor);

	using optimizer_type = CASES
	<
		(verb_type::optimizer_enum - verb_type::optimizer_offset),
		prototype<sub_adjective, ob_adjective, adverb>,
		specialize<sub_adjective, ob_adjective, adverb>

	>::rtn;

	return optimizer_type::map(out, side, in, end);
}

