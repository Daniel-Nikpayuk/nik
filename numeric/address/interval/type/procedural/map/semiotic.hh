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


template<typename T>
struct map
{
	typedef T value_type;

	typedef typename structural::semiotic<size_type>::template segment<value_type> segment;
	typedef typename structural::semiotic<size_type>::template hook<value_type> hook;
	typedef typename structural::semiotic<size_type>::template link<value_type> link;

	using pointerList = typename gvs_semiotic::template tuple<segment, hook, link>; 

	template<typename subjectList>
	struct Subject
	{
		static constexpr size_type out_interval = at<subjectList, Arg::interval>::rtn;
		static constexpr size_type out_direction = at<subjectList, Arg::iterator>::rtn;
		static constexpr size_type out_memory = at<subjectList, Arg::memrator>::rtn;
		static constexpr size_type out_pointer = at<subjectList, Arg::pointer>::rtn;

		using out_type = cases<(out_pointer - pointer_offset), pointerList>;

		template<typename objectList>
		struct Object
		{
			static constexpr size_type in_interval = at<objectList, Arg::interval>::rtn;
			static constexpr size_type in_direction = at<objectList, Arg::iterator>::rtn;
			static constexpr size_type in_memory = at<objectList, Arg::memrator>::rtn;
			static constexpr size_type in_pointer = at<objectList, Arg::pointer>::rtn;

			using in_type = cases<(in_pointer - pointer_offset), pointerList>;

			template<typename verbList>
			struct Verb
			{
				static constexpr size_type return_policy = at<verbList, Arg::verse>::rtn;
				static constexpr size_type count_policy = at<verbList, Arg::tracer>::rtn;

				#include"macro/define/semiotic/loop/loop.hpp"
				#include"macro/define/semiotic/loop/loop.hh"
				#include"macro/define/semiotic/loop/loop.h"

				template<typename subjectParams, typename objectParams, typename verbParams, typename Filler = void>
				struct Loop { };

				declareLoop(segment)
				declareLoop(hook)

				using loop = Loop<subjectList, objectList, verbList>;

//				#include"macro/undef/semiotic/loop/loop.h"
//				#include"macro/undef/semiotic/loop/loop.hh"
//				#include"macro/undef/semiotic/loop/loop.hpp"
			};

			template<size_type... params>
			using verb = Verb< sortFill<ArgTracer, params...> >;
		};

		template<size_type... params>
		using object = Object< sortFill<ArgPointer, params...> >;
	};

	template<size_type... params>
	using subject = Subject< sortFill<ArgPointer, params...> >;
};


