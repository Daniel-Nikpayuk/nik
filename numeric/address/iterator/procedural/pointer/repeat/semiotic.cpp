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

	If there is no "with_return" variant of a given method, it means it has and "end"
	parameter which is already equivalent to such a returned value. Would be redundant.
*/

#include"../../macro/define/interval/interval.cpp"

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


class repeat
{
	private:

		template<typename listParams, size_type car = listParams::car>
		struct listArguments { };

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

			#include"define/semiotic/allocate/loop.cpp"
			#include"../../macro/define/repeat/allocate/loop.cpp"

	private:

		template<typename listParams>
		struct listArguments<listParams, arg::list::allocate>
		{
			struct constantArgs
			{
				#include"../../macro/define/repeat/allocate/loop.h"

				using loop = allocate_loop<typename listParams::cdr>;

				#include"../../macro/undef/repeat/allocate/loop.h"
			};
		};

			#include"../../macro/undef/repeat/allocate/loop.cpp"
			#include"undef/semiotic/allocate/loop.cpp"

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

			#include"define/semiotic/deallocate/loop.cpp"
			#include"../../macro/define/repeat/deallocate/loop.cpp"

	private:

		template<typename listParams>
		struct listArguments<listParams, arg::list::deallocate>
		{
			struct emptyArgs
			{
				#include"../../macro/define/repeat/deallocate/loop.h"

				using loop = deallocate_loop<typename listParams::cdr>;

				#include"../../macro/undef/repeat/deallocate/loop.h"
			};
		};

			#include"../../macro/undef/repeat/deallocate/loop.cpp"
			#include"undef/semiotic/deallocate/loop.cpp"

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

			#include"define/semiotic/mutate/loop.cpp"
			#include"../../macro/define/repeat/mutate/loop.cpp"

	private:

		template<typename listParams>
		struct listArguments<listParams, arg::list::mutate>
		{
			struct emptyArgs
			{
				#include"../../macro/define/repeat/mutate/loop.h"

				using loop = mutate_loop<typename listParams::cdr>;

				#include"../../macro/undef/repeat/mutate/loop.h"
			};
		};

			#include"../../macro/undef/repeat/mutate/loop.cpp"
			#include"undef/semiotic/mutate/loop.cpp"

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

	private:

		struct intervals
		{
			declare_interval(5)

			define_interval(0, 0, 2)
			define_interval(1, 3, 6)
			define_interval(2, 7, 8)
			define_interval(3, 9, 10)
			define_interval(4, 11, 12)
		};

	public:

		template<size_type... params>
		using listArgs = listArguments<typename gvf_media::template sortFill<intervals, params...>::rtn>;
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#include"../../macro/undef/interval/interval.cpp"

