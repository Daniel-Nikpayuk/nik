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

#include"grammaric/control_flow/functional/semiotic.h"

#include"grammaric/identifier/structural/semiotic.h"
#include"grammaric/identifier/procedural/semiotic.h"

#include"grammaric/variadic/structural/semiotic.h"
#include"grammaric/variadic/functional/semiotic.h"

#include"numeric/word/boolean/structural/semiotic.h"

#include"numeric/word/uint/structural/semiotic.h"
#include"numeric/word/uint/functional/semiotic.h"
#include"numeric/word/uint/procedural/semiotic.h"

#include"numeric/word/sint/structural/semiotic.h"
#include"numeric/word/sint/functional/semiotic.h"
#include"numeric/word/sint/procedural/semiotic.h"

#include"numeric/address/iterator/structural/semiotic.h"
#include"numeric/address/iterator/procedural/semiotic.h"

//#include"numeric/address/list/structural/semiotic.h"

namespace nik
{
	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef grammaric::control_flow::functional::semiotic<size_type> gcf;

		typedef grammaric::identifier::structural::semiotic<size_type> gis;
		typedef grammaric::identifier::procedural::semiotic<size_type> gip;

		typedef grammaric::variadic::structural::semiotic<size_type> gvs;
		typedef grammaric::variadic::functional::semiotic<size_type> gvf;

		typedef numeric::word::boolean::structural::semiotic<size_type> nwbs;

		typedef numeric::word::uint::structural::semiotic<size_type> nwus;
		typedef numeric::word::uint::functional::semiotic<size_type> nwuf;
		typedef numeric::word::uint::procedural::semiotic<size_type> nwup;

		typedef numeric::word::sint::structural::semiotic<size_type> nwss;
		typedef numeric::word::sint::functional::semiotic<size_type> nwsf;
		typedef numeric::word::sint::procedural::semiotic<size_type> nwsp;

		typedef numeric::address::iterator::structural::semiotic<size_type> nais;
		typedef numeric::address::iterator::procedural::semiotic<size_type> naip;

//		typedef numeric::address::list::structural::semiotic<size_type> nals;
	};
}

