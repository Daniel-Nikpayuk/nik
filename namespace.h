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


#define declare_bounds()												\
															\
	static constexpr size_type length = 1;										\
															\
	template<size_type index, typename Filler = void>								\
	struct bounds { };


#define subclass_bounds(subclass)											\
															\
	static constexpr size_type length = subclass::length + 1;							\
															\
	template<size_type index, typename Filler = void>								\
	struct bounds : public subclass::template bounds<index, Filler> { };


#define define_bounds(modifier, index, begin, end)									\
															\
	template<typename Filler>											\
	struct bounds<modifier::index, Filler>										\
	{														\
		static constexpr size_type initial = begin;								\
		static constexpr size_type terminal = end;								\
	};


#define initialize_enum(modifier, index)										\
															\
	index::template bounds<modifier::index>::terminal + 1


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template<typename SizeType>
	struct modifier
	{
		typedef SizeType size_type;

		enum adjective : size_type
		{
			arity,
			direction,
			interval,
			image,
			iterator
		};

		struct arity
		{
			declare_bounds()

			enum : size_type
			{
				unary,
				binary
			};

			define_bounds(adjective, arity, 0, 1)
		};

		struct direction : public arity
		{
			subclass_bounds(arity)

			enum : size_type
			{
				forward = initialize_enum(adjective, arity),
				backward
			};

			define_bounds(adjective, direction, 2, 3)
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

			define_bounds(adjective, interval, 4, 7)
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

			define_bounds(adjective, image, 8, 10)
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

			define_bounds(adjective, iterator, 11, 13)
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
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef declare_bounds
#undef subclass_bounds
#undef define_bounds
#undef initialize_enum


