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

#include"grammaric/control_flow/functional/media.h"

#include"grammaric/identifier/structural/media.h"
#include"grammaric/identifier/procedural/media.h"

#include"grammaric/variadic/structural/media.h"
#include"grammaric/variadic/functional/media.h"

#include"numeric/word/boolean/structural/media.h"

#include"numeric/word/uint/structural/media.h"
#include"numeric/word/uint/functional/media.h"
#include"numeric/word/uint/procedural/media.h"

#include"numeric/word/sint/structural/media.h"
#include"numeric/word/sint/functional/media.h"
#include"numeric/word/sint/procedural/media.h"

#include"numeric/address/iterator/structural/media.h"
#include"numeric/address/iterator/procedural/media.h"

//#include"numeric/address/list/structural/media.h"

namespace nik
{
	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef grammaric::control_flow::functional::media<size_type> gcf;

		typedef grammaric::identifier::structural::media<size_type> gis;
		typedef grammaric::identifier::procedural::media<size_type> gip;

		typedef grammaric::variadic::structural::media<size_type> gvs;
		typedef grammaric::variadic::functional::media<size_type> gvf;

		typedef numeric::word::boolean::structural::media<size_type> nwbs;

		typedef numeric::word::uint::structural::media<size_type> nwus;
		typedef numeric::word::uint::functional::media<size_type> nwuf;
		typedef numeric::word::uint::procedural::media<size_type> nwup;

		typedef numeric::word::sint::structural::media<size_type> nwss;
		typedef numeric::word::sint::functional::media<size_type> nwsf;
		typedef numeric::word::sint::procedural::media<size_type> nwsp;

		typedef numeric::address::iterator::structural::media<size_type> nais;
		typedef numeric::address::iterator::procedural::media<size_type> naip;

//		typedef numeric::address::list::structural::media<size_type> nals;
	};
}

