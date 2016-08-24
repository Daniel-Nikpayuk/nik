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

#include"../numeric/address/iterator/structural/semiotic.h"
#include"../numeric/address/iterator/procedural/semiotic.h"

#include"../numeric/address/iterator/structural/media.h"
#include"../numeric/address/iterator/procedural/media.h"

namespace nik
{
	template<typename SizeType>
	struct modifier
	{
		typedef SizeType size_type;

		enum adjective : size_type
		{
			direction,
			interval,
			image,
			iterator
		};

		struct direction
		{
			declare_bounds()

			enum : size_type
			{
				forward,
				backward
			};

			define_bounds(adjective, direction, 0, 1)
		};

		struct interval : public direction
		{
			subclass_bounds(direction)

			enum : size_type
			{
				closing = initialize_enum(adjective, direction),
				closed,
				opening,
				open
			};

			define_bounds(adjective, interval, 2, 5)
		};

		struct image : public interval
		{
			subclass_bounds(interval)

			enum : size_type
			{
				mutate = initialize_enum(adjective, interval),
				allocate,
				deallocate
			};

			define_bounds(adjective, image, 6, 8)
		};

		struct iterator : public image
		{
			subclass_bounds(image)

			enum : size_type
			{
				segment = initialize_enum(adjective, image),
				hook,
				link
			};

			define_bounds(adjective, iterator, 9, 11)
		};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


		enum adverb : size_type
		{
			functor,
			tracer,
			optimizer
		};

		struct functor
		{
			declare_bounds()

			enum : size_type
			{
				apply_functor,
				omit_functor
			};

			define_bounds(adverb, functor, 0, 1)
		};

		struct tracer : public functor
		{
			subclass_bounds(functor)

			enum : size_type
			{
				omit_count = initialize_enum(adverb, functor),
				apply_count
			};

			define_bounds(adverb, tracer, 2, 3)
		};

		struct optimizer : public tracer
		{
			subclass_bounds(tracer)

			enum : size_type
			{
				prototype = initialize_enum(adverb, tracer),
				specialize
			};

			define_bounds(adverb, optimizer, 4, 5)
		};
	};

	template<typename SizeType>
	struct semiotic<SizeType, module::iterator> : public semiotic<SizeType, module::variadic>
	{
		typedef SizeType size_type;

		using naits = numeric::address::iterator::structural::semiotic<size_type>;
		using naitp = numeric::address::iterator::procedural::semiotic<size_type>;
	};

	template<typename SizeType>
	struct media<SizeType, module::iterator> : public media<SizeType, module::variadic>
	{
		typedef SizeType size_type;

		using naits = numeric::address::iterator::structural::media<size_type>;
		using naitp = numeric::address::iterator::procedural::media<size_type>;
	};
}

#endif
