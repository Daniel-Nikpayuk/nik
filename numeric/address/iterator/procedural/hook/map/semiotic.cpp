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

/*
	"Side effects" at the general coder level is bad policy,
	but at this intended low level where safety is minimal it is more memory efficient.

	Methods that have more than one template typename (eg. Iterator1, Iterator2) have so for higher
	entropy, but in practice you may need to optimize (eg. Iterator2=const Iterator1 &).
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).
	As far as debugging goes, keep in mind the location of an array (as pointer) is c_policy::unit and thus not
	allowed as a reference, so for example if you declare "int array[100]" you can't pass "array" directly
	if you're template parameter is specified as a variable. Instead you need to make a copy of array:
		"int *a=array", so then you can pass "a" instead.

	If there is no "with_return" variant of a given method, it means it has and "end"
	parameter which is already equivalent to such a returned value. Would be redundant.
*/


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_interval(num)										\
													\
													\
	static constexpr size_type length = num;							\
													\
	template<size_type k, typename intervalFiller = void>						\
	struct initial { };										\
													\
	template<size_type k, typename intervalFiller = void>						\
	struct terminal { };


#define define_interval(index, begin, end)								\
													\
													\
	template<typename intervalFiller>								\
	struct initial<index, intervalFiller> { static constexpr size_type value = begin; };		\
													\
	template<typename intervalFiller>								\
	struct terminal<index, intervalFiller> { static constexpr size_type value = end; };


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


template<size_type rank_type = rank::out>
class map
{
	private:
		template<size_type rank, size_type... params>
		struct configuration
		{
			static_assert(true, "This functor has not yet been declared.");
		};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


		#include"define/semiotic/out/loop.cpp"
		#include"../../macro/define/rank/out/loop.cpp"


		template<size_type... params>
		struct configuration<rank::out, params...>
		{
			struct intervals
			{
				declare_interval(4)

				define_interval(0, 0, 3)
				define_interval(1, 4, 5)
				define_interval(2, 6, 7)
				define_interval(3, 8, 9)
			};

			#include"../../macro/define/map/out/loop.h"
			#include"../../macro/define/rank/out/loop.h"

			using loop = out_loop<typename gvf_media::template sortFill<intervals, params...>::rtn>;

			#include"../../macro/undef/rank/out/loop.h"
			#include"../../macro/undef/map/out/loop.h"
		};


		#include"../../macro/undef/rank/out/loop.cpp"
		#include"undef/semiotic/out/loop.cpp"


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


		#include"define/semiotic/in/loop.cpp"
		#include"../../macro/define/rank/in/loop.cpp"


		template<size_type... params>
		struct configuration<rank::in, params...>
		{
			struct intervals
			{
				declare_interval(5)

				define_interval(0, 0, 3)
				define_interval(1, 4, 5)
				define_interval(2, 6, 7)
				define_interval(3, 8, 9)
				define_interval(4, 10, 11)
			};

			#include"../../macro/define/map/in/loop.h"
			#include"../../macro/define/rank/in/loop.h"

			using loop = in_loop<typename gvf_media::template sortFill<intervals, params...>::rtn>;

			#include"../../macro/undef/rank/out/loop.h"
			#include"../../macro/undef/map/out/loop.h"
		};


		#include"../../macro/undef/rank/out/loop.cpp"
		#include"undef/semiotic/in/loop.cpp"
	public:
		template<size_type... params>
		using attributes = configuration<rank_type, params...>;

		using loop = typename attributes<>::loop;
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#undef define_interval
#undef declare_interval


