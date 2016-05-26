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

#ifndef NIK_H
#define NIK_H

#include"builtin/printer/printer.h"

namespace nik
{
	char endl='\n'; // portable ?

	struct printer :
		public builtin::printer
//		public numeric::random_access::printer
	{ } display;

	template<typename S, typename T>
	S & operator << (S & s, T v)
	{
		s.print(v);
		return s;
	}
}

#include"numeric/processor/iterator/structural/traits/traits.h"
#include"numeric/processor/iterator/functional/policy/policy.h"

//#include"numeric/random_access/traits/traits.h"
//#include"numeric/random_access/policy/policy.h"
//#include"numeric/random_access/iterator/traits/traits.h"
//#include"numeric/random_access/iterator/extensionwise/structural/traits/traits.h"
//#include"numeric/random_access/iterator/extensionwise/functional/policy/policy.h"

namespace nik
{
	template<typename SizeType>
	struct traits
	{
		typedef SizeType size_type;

		typedef numeric::processor::iterator::structural::traits<size_type> npis;

//		typedef numeric::random_access::traits<size_type> nr;
//		typedef numeric::random_access::iterator::traits<size_type> nri;
//		typedef numeric::random_access::iterator::extensionwise::structural::traits<size_type> nrits;
	};

	template<typename SizeType>
	struct policy
	{
		typedef SizeType size_type;

		typedef numeric::processor::iterator::functional::policy<size_type> npif;

//		typedef numeric::random_access::policy<size_type> nr;
//		typedef numeric::random_access::iterator::extensionwise::functional::policy<size_type> nritf;
	};

	template<typename SizeType=size_t>
	using sbit=typename traits<SizeType>::npis::identity::template
			semiotic<typename traits<SizeType>::npis::identity::semiotic_pointer>;

/*
	template<typename T, typename SizeType=size_t>
	using list=iterator::generic::list<T, SizeType>;

	template<typename T, typename SizeType=size_t>
	using chain=iterator::generic::chain<T, SizeType>;

	template<typename T, typename SizeType=size_t>
	using vector=iterator::generic::vector<T, SizeType>;

	template<size_t BitLength>
	using uint_block=numeric::uint<size_t>::block<BitLength>;
*/
}

#endif
