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


#define define_bounds(index, begin, end)								\
													\
	template<typename Filler>									\
	struct bounds<arg_type::index, Filler>								\
	{												\
		static constexpr size_type initial = begin;						\
		static constexpr size_type terminal = end;						\
	};


#define initialize_enum(index)										\
													\
	index::template bounds<arg_type::index>::terminal + 1


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


namespace nik
{
	template<typename SizeType>
	struct arg
	{
		typedef SizeType size_type;

		struct empty { };

		struct definitive { };

		enum arg_type
		{
			iterator,
			interval,
			pointer,
			list,
			tracer,
			verse
		};

		struct iterator
		{
			declare_bounds()

			enum : size_type
			{
				forward,
				backward
			};

			define_bounds(iterator, 0, 1)
		};

		struct interval : public iterator
		{
			subclass_bounds(iterator)

			enum : size_type
			{
				closing = initialize_enum(iterator),
				closed,
				opening,
				open
			};

			define_bounds(interval, 2, 5)
		};

		struct pointer : public interval
		{
			subclass_bounds(interval)

			enum : size_type
			{
				hook = initialize_enum(interval),
				link,
				segment
			};

			define_bounds(pointer, 6, 8)
		};

		struct list : public pointer
		{
			subclass_bounds(pointer)

			enum : size_type
			{
				allocate = initialize_enum(pointer),
				deallocate,
				mutate
			};

			define_bounds(list, 9, 11)
		};

		struct tracer : public list
		{
			subclass_bounds(list)

			enum : size_type
			{
				omit_count = initialize_enum(list),
				apply_count
			};

			define_bounds(tracer, 12, 13)
		};

		struct verse : public tracer
		{
			subclass_bounds(tracer)

			enum : size_type
			{
				apply_return = initialize_enum(tracer),
				omit_return
			};

			define_bounds(verse, 14, 15)
		};
	};
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#undef declare_bounds
#undef subclass_bounds
#undef define_bounds
#undef initialize_enum


