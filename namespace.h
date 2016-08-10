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


#define declare_bounds()										\
													\
	static constexpr size_type length = 1;								\
													\
	template<size_type index, typename Filler = void>						\
	struct bounds { };


#define subclass_bounds(subclass)									\
													\
	static constexpr size_type length = subclass::length + 1;					\
													\
	template<size_type index, typename Filler = void>						\
	struct bounds : public subclass::template bounds<index, Filler> { };


#define define_bounds(modifier, index, begin, end)							\
													\
	template<typename Filler>									\
	struct bounds<modifier::index, Filler>								\
	{												\
		static constexpr size_type initial = begin;						\
		static constexpr size_type terminal = end;						\
	};


#define initialize_enum(modifier, index)								\
													\
	index::template bounds<modifier::index>::terminal + 1


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template<typename SizeType>
	struct arg
	{
		typedef SizeType size_type;

		struct empty { };

		struct definite : public empty { };

		enum adjective
		{
			interval,
			iterator,
			memrator,
			pointer
		};

		enum adverb
		{
			verse,
			tracer
		};

		struct interval : public definite
		{
			declare_bounds()

			enum : size_type
			{
				closing,
				closed,
				opening,
				open
			};

			define_bounds(adjective, interval, 0, 3)
		};

		struct iterator : public interval
		{
			subclass_bounds(interval)

			enum : size_type
			{
				forward = initialize_enum(adjective, interval),
				backward
			};

			define_bounds(adjective, iterator, 4, 5)
		};

		struct memrator : public iterator
		{
			subclass_bounds(iterator)

			enum : size_type
			{
				mutate = initialize_enum(adjective, iterator),
				allocate,
				deallocate
			};

			define_bounds(adjective, memrator, 6, 8)
		};

		struct pointer : public memrator
		{
			subclass_bounds(memrator)

			enum : size_type
			{
				segment = initialize_enum(adjective, memrator),
				hook,
				link
			};

			define_bounds(adjective, pointer, 9, 11)
		};

		struct verse : public definite
		{
			declare_bounds()

			enum : size_type
			{
				apply_return,
				omit_return
			};

			define_bounds(adverb, verse, 0, 1)
		};

		struct tracer : public verse
		{
			subclass_bounds(verse)

			enum : size_type
			{
				omit_count = initialize_enum(adverb, verse),
				apply_count
			};

			define_bounds(adverb, tracer, 2, 3)
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


