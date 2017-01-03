/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

////////////////////////////// Set up but not yet analyzed or coded!!!!!

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
*/

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	As "out" is assign shifted when its "dir(out)" is allocated, there is no need to increment seperately.
*/

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_unroll_find_index_before_last(dir, inv, label, rtn, stmt) \
template<typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	while (dir(dir(out)) != end) dir##dir(out); \
 \
	stmt unroll<N-1>::find::index::before::last::closed::label##_return(out); \
}

#define closed_unroll_no_return_find_index_before_last(dir, inv)	_closed_unroll_find_index_before_last(dir, inv, no, void, )
#define closed_unroll_with_return_find_index_before_last(dir, inv)	_closed_unroll_find_index_before_last(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closed_unroll_find_index_before_end(dir, inv, label, rtn, stmt) \
template<typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	while (dir(out) != end) dir##dir(out); \
 \
	stmt unroll<N-1>::find::index::before::end::closed::label##_return(out); \
}

#define closed_unroll_no_return_find_index_before_end(dir, inv)	_closed_unroll_find_index_before_end(dir, inv, no, void, )
#define closed_unroll_with_return_find_index_before_end(dir, inv)	_closed_unroll_find_index_before_end(dir, inv, with, WPointer, return)

