/*************************************************************************************************************************
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
*************************************************************************************************************************/

#include"numeric/word/boolean/structural/traits.h"
#include"numeric/word/uint/structural/traits.h"
#include"numeric/word/sint/structural/traits.h"

#include"numeric/address/iterator/structural/traits.h"

#include"numeric/address/list/structural/traits.h"

namespace nik
{
	template<typename SizeType>
	struct traits
	{
		typedef SizeType size_type;

		typedef numeric::word::boolean::structural::semiotic<size_type> nwbss;
		typedef numeric::word::boolean::structural::media<size_type> nwbsm;

		typedef numeric::word::uint::structural::semiotic<size_type> nwuss;
		typedef numeric::word::uint::structural::media<size_type> nwusm;

		typedef numeric::word::sint::structural::semiotic<size_type> nwsss;
		typedef numeric::word::sint::structural::media<size_type> nwssm;

		typedef numeric::address::iterator::structural::semiotic<size_type> naiss;

		typedef numeric::address::list::structural::semiotic<size_type> nalss;
	};
}

