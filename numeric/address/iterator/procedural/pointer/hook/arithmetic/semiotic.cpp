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

#include"define/semiotic/closed/loop.cpp"
#include"define/semiotic/closed/count.cpp"
#include"define/semiotic/closed/unroll.cpp"
#include"define/semiotic/closed/initial.cpp"

#include"define/semiotic/closing/loop.cpp"
#include"define/semiotic/closing/count.cpp"
#include"define/semiotic/closing/unroll.cpp"
#include"define/semiotic/closing/initial.cpp"

#include"define/semiotic/opening/loop.cpp"
#include"define/semiotic/opening/count.cpp"
#include"define/semiotic/opening/unroll.cpp"
#include"define/semiotic/opening/initial.cpp"

#include"define/semiotic/open/loop.cpp"
#include"define/semiotic/open/count.cpp"
#include"define/semiotic/open/unroll.cpp"
#include"define/semiotic/open/initial.cpp"

struct arithmetic
{
	#define SGN +
	#define INV -

	#include"../../macro/define/arithmetic/loop.cpp"

	template<size_type N, size_type M=0, size_type L=0>
	struct unroll
	{
		#include"../../macro/define/arithmetic/unroll.cpp"
	};

	template<size_type M, size_type L>
	struct unroll<0, M, L>
	{
		#include"../../macro/define/arithmetic/initial.cpp"
	};

	#undef INV
	#undef SGN
};

#include"../../macro/undef/arithmetic/open/initial.cpp"
#include"../../macro/undef/arithmetic/open/unroll.cpp"
#include"../../macro/undef/arithmetic/open/count.cpp"
#include"../../macro/undef/arithmetic/open/loop.cpp"

#include"../../macro/undef/arithmetic/opening/initial.cpp"
#include"../../macro/undef/arithmetic/opening/unroll.cpp"
#include"../../macro/undef/arithmetic/opening/count.cpp"
#include"../../macro/undef/arithmetic/opening/loop.cpp"

#include"../../macro/undef/arithmetic/closing/initial.cpp"
#include"../../macro/undef/arithmetic/closing/unroll.cpp"
#include"../../macro/undef/arithmetic/closing/count.cpp"
#include"../../macro/undef/arithmetic/closing/loop.cpp"

#include"../../macro/undef/arithmetic/closed/initial.cpp"
#include"../../macro/undef/arithmetic/closed/unroll.cpp"
#include"../../macro/undef/arithmetic/closed/count.cpp"
#include"../../macro/undef/arithmetic/closed/loop.cpp"

