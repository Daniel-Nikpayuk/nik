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

#ifndef MODULE_ITERATOR_H
#define MODULE_ITERATOR_H

#include"variadic.h"

namespace nik
{
	template<typename SizeType = global_size_type>
	struct Iterator
	{
		typedef SizeType size_type;

		enum AdjectiveType : size_type
		{
			direction,
			interval,
			image,
			iterator,
			adjective // filler
		};

		struct Adjective
		{
			static constexpr size_type length = AdjectiveType::adjective;

			template<size_type adjective_type, typename Filler = void> struct bounds;

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
			struct bounds<AdjectiveType::direction, Filler>
			{
				static constexpr size_type initial = forward;
				static constexpr size_type terminal = backward;
			};

			template<typename Filler>
			struct bounds<AdjectiveType::interval, Filler>
			{
				static constexpr size_type initial = closing;
				static constexpr size_type terminal = open;
			};

			template<typename Filler>
			struct bounds<AdjectiveType::image, Filler>
			{
				static constexpr size_type initial = mutate;
				static constexpr size_type terminal = deallocate;
			};

			template<typename Filler>
			struct bounds<AdjectiveType::iterator, Filler>
			{
				static constexpr size_type initial = segment;
				static constexpr size_type terminal = link;
			};
		};

/***********************************************************************************************************************/

		enum AdverbType : size_type
		{
			functor,
			tracer,
			optimizer,
			adverb // filler
		};

		struct Adverb
		{
			static constexpr size_type length = AdverbType::adverb;

			template<size_type adverb_type, typename Filler = void> struct bounds;

			enum : size_type
			{
				apply_functor,
				omit_functor,

				omit_count,
				apply_count,

				prototype,
				specialize
			};

			template<typename Filler>
			struct bounds<AdverbType::functor, Filler>
			{
				static constexpr size_type initial = apply_functor;
				static constexpr size_type terminal = omit_functor;
			};

			template<typename Filler>
			struct bounds<AdverbType::tracer, Filler>
			{
				static constexpr size_type initial = omit_count;
				static constexpr size_type terminal = apply_count;
			};

			template<typename Filler>
			struct bounds<AdverbType::optimizer, Filler>
			{
				static constexpr size_type initial = prototype;
				static constexpr size_type terminal = specialize;
			};
		};
	};
}

#include"../numeric/address/iterator/structural/semiotic.h"
#include"../numeric/address/iterator/procedural/semiotic.h"

#include"../numeric/address/iterator/structural/media.h"
#include"../numeric/address/iterator/procedural/media.h"

#endif
