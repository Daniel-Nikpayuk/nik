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

#ifndef MODULE__H
#define MODULE__H

#include"../numeric/word/boolean/structural/semiotic.h"

#include"../numeric/word/uint/structural/semiotic.h"
#include"../numeric/word/uint/functional/semiotic.h"
#include"../numeric/word/uint/procedural/semiotic.h"

#include"../numeric/word/sint/structural/semiotic.h"
#include"../numeric/word/sint/functional/semiotic.h"
#include"../numeric/word/sint/procedural/semiotic.h"

#include"../numeric/address/iterator/structural/semiotic.h"
#include"../numeric/address/iterator/procedural/semiotic.h"

//#include"../numeric/address/list/structural/semiotic.h"

namespace nik
{
	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		using nwbs = numeric::word::boolean::structural::semiotic<size_type>;

		using nwus = numeric::word::uint::structural::semiotic<size_type>;
		using nwuf = numeric::word::uint::functional::semiotic<size_type>;
		using nwup = numeric::word::uint::procedural::semiotic<size_type>;

		using nwss = numeric::word::sint::structural::semiotic<size_type>;
		using nwsf = numeric::word::sint::functional::semiotic<size_type>;
		using nwsp = numeric::word::sint::procedural::semiotic<size_type>;

		using naits = numeric::address::iterator::structural::semiotic<size_type>;

		using naitp = numeric::address::iterator::procedural::semiotic<size_type>;

//		using nals = numeric::address::list::structural::semiotic<size_type>;
	};
}

#endif
