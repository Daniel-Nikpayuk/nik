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
	struct module<nik::iterator, nik::structural, nik::semiotic, SizeType>
	{
		typedef SizeType size_type;

		struct Modifier
		{
			enum : size_type
			{
				direction,
				interval,
				image,
				iterator,
				filler
			};
		};

		struct Attribute
		{
			static constexpr size_type dimension = Modifier::filler;

			template<size_type modifier_type, typename Filler = void> struct bounds;

			enum : size_type
			{
				forward,
				backward,

				closing,
				closed,
				opening,
				open,

				mutate,
				allocate,
				deallocate,

				segment,
				hook,
				link
			};

			template<typename Filler>
			struct bounds<Modifier::direction, Filler>
			{
				static constexpr size_type initial = forward;
				static constexpr size_type terminal = backward;
			};

			template<typename Filler>
			struct bounds<Modifier::interval, Filler>
			{
				static constexpr size_type initial = closing;
				static constexpr size_type terminal = open;
			};

			template<typename Filler>
			struct bounds<Modifier::image, Filler>
			{
				static constexpr size_type initial = mutate;
				static constexpr size_type terminal = deallocate;
			};

			template<typename Filler>
			struct bounds<Modifier::iterator, Filler>
			{
				static constexpr size_type initial = segment;
				static constexpr size_type terminal = link;
			};
		};

/***********************************************************************************************************************/

		template<size_type orientation_enum, size_type interface_enum>
		using variadic = grammaric::module<nik::variadic, orientation_enum, interface_enum, size_type>;

		#define AT			 variadic<nik::functional, nik::semiotic>::template at
		#define CASES		typename variadic<nik::functional, nik::media>::template cases
		#define SORTFILL	typename variadic<nik::functional, nik::media>::template sortFill

		#include"segment/semiotic.hpp"
		#include"node/semiotic.hpp"
		#include"hook/semiotic.hpp"
		#include"link/semiotic.hpp"
		#include"adjective/semiotic.hpp"

		#undef AT
		#undef CASES
		#undef SORTFILl
	};

}}

