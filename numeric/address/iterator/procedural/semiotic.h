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

		struct Modifier
		{
			enum : size_type
			{
				functor,
				tracer,
				effector,
				optimizer,
				filler
			};
		};

		struct Attribute
		{
			static constexpr size_type dimension = Modifier::filler;

			template<size_type, typename Filler = void> struct bounds;

			enum : size_type
			{
				omit_assign,
				apply_assign,

				omit_count,
				apply_count,

				omit_effect,
				apply_effect,

				prototype,
				specialize
			};

			template<typename Filler>
			struct bounds<Modifier::functor, Filler>
			{
				static constexpr size_type initial = omit_assign;
				static constexpr size_type terminal = apply_assign;
			};

			template<typename Filler>
			struct bounds<Modifier::tracer, Filler>
			{
				static constexpr size_type initial = omit_count;
				static constexpr size_type terminal = apply_count;
			};

			template<typename Filler>
			struct bounds<Modifier::effector, Filler>
			{
				static constexpr size_type initial = omit_effect;
				static constexpr size_type terminal = apply_effect;
			};

			template<typename Filler>
			struct bounds<Modifier::optimizer, Filler>
			{
				static constexpr size_type initial = prototype;
				static constexpr size_type terminal = specialize;
			};
		};

/***********************************************************************************************************************/

		template<size_type orientation_enum, size_type interface_enum>
		using variadic = grammaric::module<nik::variadic, orientation_enum, interface_enum, size_type>;

		template<size_type interface_enum>
		using structural = module<nik::iterator, nik::structural, interface_enum, size_type>;

		using StrModifier = typename structural<nik::semiotic>::Modifier;
		using StrAttribute = typename structural<nik::semiotic>::Attribute;

		#define LIST		typename variadic<nik::structural, nik::semiotic>::template list
		#define AT			 variadic<nik::functional, nik::semiotic>::template at
		#define CASES		typename variadic<nik::functional, nik::media>::template cases
		#define SORTFILL	typename variadic<nik::functional, nik::media>::template sortFill

//		#include"map/semiotic.hh"

		#include"adverb/semiotic.hpp"

		#undef LIST
		#undef AT
		#undef CASES
		#undef SORTFILL
	};

}}

