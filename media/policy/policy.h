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

#ifndef NIK_MEDIA_POLICY_H
#define NIK_MEDIA_POLICY_H

#include"../numeric/processor/policy/policy.h"

#include"../numeric/processor/argument/policy/policy.h"
#include"../numeric/processor/parameter/policy/policy.h"

#include"../numeric/random_access/policy/policy.h"

//#include"../numeric/random_access/iterator/extensionwise/functional/policy/policy.h"
//#include"../numeric/random_access/iterator/expansionwise/functional/policy/policy.h"
//#include"../numeric/random_access/iterator/componentwise/functional/policy/policy.h"

//#include"../numeric/random_access/list/functional/policy/policy.h"
//#include"../numeric/random_access/chain/functional/policy/policy.h"
//#include"../numeric/random_access/vector/functional/policy/policy.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the depth complexity of nested namespaces.
	2) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
 namespace media
 {
	template<typename SizeType>
	struct policy
	{
		typedef SizeType size_type;

		typedef numeric::processor::policy<size_type> np;

		typedef numeric::processor::argument::policy<size_type> npa;
		typedef numeric::processor::parameter::policy<size_type> npp;

		typedef numeric::random_access::policy<size_type> nr;

//		typedef numeric::random_access::iterator::extensionwise::functional::policy<size_type> nritf;
//		typedef numeric::random_access::iterator::expansionwise::functional::policy<size_type> nripf;
//		typedef numeric::random_access::iterator::componentwise::functional::policy<size_type> nricf;

//		typedef numeric::random_access::list::functional::policy<size_type> nrlf;
//		typedef numeric::random_access::chain::functional::policy<size_type> nrcf;
//		typedef numeric::random_access::vector::functional::policy<size_type> nrvf;
	};
 }
}

#endif
