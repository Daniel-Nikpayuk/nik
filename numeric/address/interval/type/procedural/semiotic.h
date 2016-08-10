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

#ifndef NIK_NUMERIC_ADDRESS_INTERVAL_TYPE_PROCEDURAL_SEMIOTIC_H
#define NIK_NUMERIC_ADDRESS_INTERVAL_TYPE_PROCEDURAL_SEMIOTIC_H

namespace nik		{
namespace numeric	{
namespace address	{
namespace interval	{
namespace type		{
namespace procedural	{

	template<typename SizeType, typename T> struct media;

	template<typename SizeType, typename T>
	struct semiotic
	{
		typedef SizeType size_type;
		typedef T value_type;

		typedef typename structural::semiotic<size_type, value_type>::hook hook;
		typedef typename structural::semiotic<size_type, value_type>::link link;
		typedef typename structural::semiotic<size_type, value_type>::segment segment;

		typedef grammaric::variadic::functional::semiotic<size_type> gvf_semiotic;
		typedef grammaric::variadic::structural::semiotic<size_type> gvs_semiotic;

		typedef grammaric::variadic::functional::media<size_type> gvf_media;

		typedef word::uint::functional::semiotic<size_type> wuf_semiotic;

/***********************************************************************************************************************/

		typedef nik::arg<size_type> Arg;
		typedef typename Arg::pointer ArgPointer;
		typedef typename Arg::tracer ArgTracer;

		static constexpr size_type pointer_offset = ArgPointer::template bounds<Arg::pointer>::initial;

		template<size_type index, typename... params>
		using cases = typename gvf_media::template cases<index, params...>::rtn;

		template<typename L, size_type pos>
		using at = typename gvf_semiotic::template at<L, pos>;

		template<typename modifier, size_type... params>
		using sortFill = typename gvf_media::template sortFill<modifier, params...>::rtn;

/***********************************************************************************************************************/

		template<typename subjectList>
		struct Subject
		{
			static constexpr size_type out_interval = at<subjectList, Arg::interval>::rtn;
			static constexpr size_type out_direction = at<subjectList, Arg::iterator>::rtn;
			static constexpr size_type out_memory = at<subjectList, Arg::memrator>::rtn;
			static constexpr size_type out_pointer = at<subjectList, Arg::pointer>::rtn;

			using out_type = cases<(out_pointer - pointer_offset), segment, hook, link>;

			template<typename objectList>
			struct Object
			{
				static constexpr size_type in_interval = at<objectList, Arg::interval>::rtn;
				static constexpr size_type in_direction = at<objectList, Arg::iterator>::rtn;
				static constexpr size_type in_memory = at<objectList, Arg::memrator>::rtn;
				static constexpr size_type in_pointer = at<objectList, Arg::pointer>::rtn;

				using in_type = cases<(in_pointer - pointer_offset), segment, hook, link>;

				template<typename verbList>
				struct Verb
				{
					static constexpr size_type return_policy = at<verbList, Arg::verse>::rtn;
					static constexpr size_type count_policy = at<verbList, Arg::tracer>::rtn;

					#include"map/semiotic.hh"
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

}}}}}}

#endif
