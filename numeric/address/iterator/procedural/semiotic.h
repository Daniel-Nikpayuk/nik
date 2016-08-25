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

namespace nik		{
namespace numeric	{

	template<typename SizeType>
	struct module<nik::iterator, nik::procedural, nik::semiotic, SizeType>
	{
		typedef SizeType size_type;

		template<size_type orientation_enum, size_type interface_enum>
		using variadic = grammaric::module<nik::variadic, orientation_enum, interface_enum, size_type>;

		template<size_type interface_enum>
		using structural = module<nik::iterator, nik::structural, interface_enum, size_type>;

		typedef nik::Iterator<size_type> Modifier;
		typedef typename Modifier::Adjective Adjective;
		typedef typename Modifier::Adverb Adverb;

		#define LIST		typename variadic<nik::structural, nik::semiotic>::template list
		#define AT			 variadic<nik::functional, nik::semiotic>::template at
		#define CASES		typename variadic<nik::functional, nik::media>::template cases
		#define SORTFILL	typename variadic<nik::functional, nik::media>::template sortFill

		#include"type/semiotic.hpp"

		#include"map/semiotic.hh"

		#undef LIST
		#undef AT
		#undef CASES
		#undef SORTFILL
	};

}}

