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

#ifndef NIK_CONTEXT_CONTEXT_POLICY_H
#define NIK_CONTEXT_CONTEXT_POLICY_H

#include"../node/node.h"
#include"../unit/unit.h"
#include"../argument/binary/binary.h"
#include"../argument/math/math.h"
#include"../argument/meta/meta.h"
#include"../parameter/binary/binary.h"
#include"../parameter/math/math.h"
#include"../parameter/meta/meta.h"
#include"../parameter/numeric_limits/numeric_limits.h"

/*
	The justification for this policy class is threefold:

	1) Is a modularization strategy toward mitigating the depth complexity of nested namespaces.
	2) It allows one to include the "policy.h" header which by default includes all existing generic headers,
		easing the headerload within the media classes.
*/

namespace nik
{
 namespace context
 {
  namespace context
  {
/*
*/
	template<typename SizeType>
	struct policy
	{
		typedef SizeType size_type;
/*
	unit:
*/
		using unit=context::unit<size_type>;
/*
	node:
*/
		template<typename value_type>
		using hook=context::hook<value_type, size_type>;

		template<typename value_type>
		using const_hook=context::const_hook<value_type, size_type>;

		template<typename value_type>
		using link=context::link<value_type, size_type>;

		template<typename value_type>
		using const_link=context::const_link<value_type, size_type>;
/*
	argument:
*/
/*
		binary:
*/
			using arg_bin=argument::binary<size_type>;
/*
		math:
*/
			using arg_mat=argument::math<size_type>;
/*
		meta:
*/
			using arg_met=argument::meta;
/*

	parameter:
*/
/*
		binary:
*/
			using par_bin=parameter::binary<size_type>;
/*
		math:
*/
			using par_mat=parameter::math<size_type>;
/*
		meta:
*/
			using par_met=parameter::meta;
/*
		numeric_limits:
*/
			using par_num=parameter::numeric_limits<size_type>;
	};
  }
 }
}

#endif
