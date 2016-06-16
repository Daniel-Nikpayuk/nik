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

#include"grammaric/functional/policy.h"
#include"grammaric/procedural/policy.h"

#include"numeric/word/uint/functional/policy.h"
#include"numeric/word/uint/procedural/policy.h"

#include"numeric/word/sint/functional/policy.h"
#include"numeric/word/sint/procedural/policy.h"

namespace nik
{
	template<typename SizeType>
	struct policy
	{
		typedef SizeType size_type;

		typedef grammaric::functional::semiotic<size_type> gfs;
		typedef grammaric::functional::media<size_type> gfm;

		typedef grammaric::procedural::semiotic<size_type> gps;
		typedef grammaric::procedural::media<size_type> gpm;

		typedef numeric::word::uint::functional::semiotic<size_type> nwufs;
		typedef numeric::word::uint::functional::media<size_type> nwufm;

		typedef numeric::word::uint::procedural::semiotic<size_type> nwups;
		typedef numeric::word::uint::procedural::media<size_type> nwupm;

		typedef numeric::word::sint::functional::semiotic<size_type> nwsfs;
		typedef numeric::word::sint::functional::media<size_type> nwsfm;

		typedef numeric::word::sint::procedural::semiotic<size_type> nwsps;
		typedef numeric::word::sint::procedural::media<size_type> nwspm;
	};
}

