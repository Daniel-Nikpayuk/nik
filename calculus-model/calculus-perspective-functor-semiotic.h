/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifdef safe_name

	#define PREFIX		calpef_

#else

	#define PREFIX

#endif

//

							  template<typename Type>
	using nik_safe(PREFIX, dereference)		= typename nik::calculus::functor::template dereference<Type>;

//

							  template<typename Exp, typename ListType>
	using nik_safe(PREFIX, cons)			= typename nik::calculus::functor::template cons<Exp, ListType>;

							  template<typename ListType>
	using nik_safe(PREFIX, car)			= typename nik::calculus::functor::template car<ListType>;

							  template<typename ListType>
	using nik_safe(PREFIX, cdr)			= typename nik::calculus::functor::template cdr<ListType>;

//

							  template<global_size_type N>
	using nik_safe(PREFIX, unsigned_type)		= typename nik::calculus::functor::template unsigned_type<N>;

							  template<global_size_type N>
	using nik_safe(PREFIX, signed_type)		= typename nik::calculus::functor::template signed_type<N>;


#define ONE 1

							  template<global_size_type N>
	using nik_safe(PREFIX, half_type)		= typename nik::calculus::functor::template unsigned_type<(N >> ONE)>;

#undef ONE

//

							  template<char op, typename Type, Type Value>
	using nik_safe(PREFIX, apply11)			= typename nik::calculus::functor::template apply11<op, Type, Value>;

							  template<char op, typename Type, Type Value1, Type Value2>
	using nik_safe(PREFIX, apply12)			= typename nik::calculus::functor::template apply12<op, Type, Value1, Value2>;

							  template<char op1, char op2, typename Type, Type Value>
	using nik_safe(PREFIX, apply21)			= typename nik::calculus::functor::template apply21<op1, op2, Type, Value>;

							  template<char op1, char op2, typename Type, Type Value1, Type Value2>
	using nik_safe(PREFIX, apply22)			= typename nik::calculus::functor::template apply22<op1, op2, Type, Value1, Value2>;

//

#undef PREFIX

