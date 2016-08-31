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
	The ordering of the arguments are intended to privilege template parameter type deduction.
*/

template<typename sub_pointer, typename map_adverb, typename ob_pointer, typename sub_adjective, typename ob_adjective>
static sub_pointer map(sub_pointer out, map_adverb & ad, ob_pointer in, ob_pointer end, const sub_adjective & sub, const ob_adjective & ob)
{
	using optimizer_type = CASES
	<
		(map_adverb::optimizer_enum - map_adverb::optimizer_offset),
		prototype<sub_adjective, ob_adjective>,
		specialize<sub_adjective, ob_adjective>

	>::rtn;

	return optimizer_type::map(out, ad, in, end, sub, ob);
}

/*
	allocate, segment:
*/

template<size_type directionEnum, size_type intervalEnum>
using allocate_segment = typename structural<nik::semiotic>::template
	adjective<directionEnum, intervalEnum, Association::allocate, Association::segment>;

template<typename sub_pointer, typename map_adverb, typename ob_pointer,
	size_type directionEnum, size_type intervalEnum, typename ob_adjective>
static sub_pointer map(sub_pointer & out, map_adverb & ad,
	ob_pointer in, ob_pointer end, allocate_segment<directionEnum, intervalEnum> sub, ob_adjective ob)
{
	using value_type = typename structural<nik::semiotic>::template trim<sub_pointer>::pointer::value_type;

	out = new value_type[sub.length];
	size_type offset = (directionEnum == Association::forward) ? sub.offset : sub.length - 1 - sub.offset;

	using optimizer_type = CASES
	<
		(map_adverb::optimizer_enum - map_adverb::optimizer_offset),
		prototype<allocate_segment<directionEnum, intervalEnum>, ob_adjective>,
		specialize<allocate_segment<directionEnum, intervalEnum>, ob_adjective>

	>::rtn;

	return optimizer_type::map(out + offset, ad, in, end, sub, ob);
}

