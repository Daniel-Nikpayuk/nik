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

#ifndef NIK_GENERIC_FUNCTIONAL_POLICY_H
#define NIK_GENERIC_FUNCTIONAL_POLICY_H

namespace nik		{
namespace generic	{
namespace functional	{

	template<typename SizeType> struct media;

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef functional::media<size_type> media;

		typedef grammaric::functional::media<size_type> gfm_policy;

		template<size_type... params>
		using slist = typename structural::semiotic<size_type>::template list<params...>;
		using null_slist = typename structural::semiotic<size_type>::null_list;

		template<size_type... params>
		using mlist = typename structural::media<size_type>::template list<params...>;
		using null_mlist = typename structural::media<size_type>::null_list;

		#include"cons/semiotic.cpp"
		#include"cdr/semiotic.cpp"
		#include"append/semiotic.cpp"
		#include"catenate/semiotic.cpp"
		#include"filter/semiotic.cpp"
		#include"sort/semiotic.cpp"
	};

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef functional::semiotic<size_type> semiotic;

		typedef grammaric::functional::media<size_type> gfm_policy;

		template<size_type... params>
		using slist = typename structural::semiotic<size_type>::template list<params...>;
		using null_slist = typename structural::semiotic<size_type>::null_list;

		template<size_type... params>
		using mlist = typename structural::media<size_type>::template list<params...>;
		using null_mlist = typename structural::media<size_type>::null_list;

		#include"cons/media.cpp"
		#include"cdr/media.cpp"
		#include"append/media.cpp"
		#include"catenate/media.cpp"
		#include"filter/media.cpp"
		#include"sort/media.cpp"
	};

}}}

#endif
