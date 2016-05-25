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

#include<stddef.h>

#include"numeric/processor/printer/printer.h"

namespace nik
{
	typedef size_t size_type;

	char endl='\n'; // portable ?

	struct printer :
		public numeric::processor::printer<size_type>
//		public numeric::random_access::printer<size_type>
		{} display;
}

#include"numeric/processor/policy/policy.h"
#include"numeric/processor/iterator/traits/traits.h"
//#include"numeric/processor/argument/policy/policy.h"
//#include"numeric/processor/parameter/policy/policy.h"

//#include"numeric/random_access/traits/traits.h"
//#include"numeric/random_access/policy/policy.h"
//#include"numeric/random_access/iterator/traits/traits.h"
//#include"numeric/random_access/iterator/extensionwise/structural/traits/traits.h"
//#include"numeric/random_access/iterator/extensionwise/functional/policy/policy.h"

namespace nik
{
	struct traits
	{
		typedef numeric::processor::iterator::traits<size_type> npi;

//		typedef numeric::random_access::traits<size_type> nr;
//		typedef numeric::random_access::iterator::traits<size_type> nri;
//		typedef numeric::random_access::iterator::extensionwise::structural::traits<size_type> nrits;
	};

	struct policy
	{
		typedef numeric::processor::policy<size_type> np;
//		typedef numeric::processor::argument::policy<size_type> npa;
//		typedef numeric::processor::parameter::policy<size_type> npp;

//		typedef numeric::random_access::policy<size_type> nr;
//		typedef numeric::random_access::iterator::extensionwise::functional::policy<size_type> nritf;
	};

	template<typename SizeType=size_t>
	using sbit=typename numeric::processor::iterator::bit<SizeType>::semiotic::template identity<
			typename numeric::processor::iterator::bit<SizeType>::semiotic::identity_pointer>;

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
