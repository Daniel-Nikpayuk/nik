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
struct mapTraits
{
	typedef T value_type;

	using subjectList = sortFill<ArgPointer, subjectParams...>;

	static constexpr size_type out_interval = at<subjectList, Arg::interval>::rtn;
	static constexpr size_type out_direction = at<subjectList, Arg::iterator>::rtn;
	static constexpr size_type out_memory = at<subjectList, Arg::memrator>::rtn;
	static constexpr size_type out_pointer = at<subjectList, Arg::pointer>::rtn;

	using objectList = sortFill<ArgPointer, objectParams...>;

	static constexpr size_type in_interval = at<objectList, Arg::interval>::rtn;
	static constexpr size_type in_direction = at<objectList, Arg::iterator>::rtn;
	static constexpr size_type in_memory = at<objectList, Arg::memrator>::rtn;
	static constexpr size_type in_pointer = at<objectList, Arg::pointer>::rtn;

	using verbList = sortFill<ArgTracer, verbParams...>;

	static constexpr size_type count_policy = at<verbList, Arg::tracer>::rtn;

	using pointerList = typename gvs_semiotic::template tuple
	<
		typename structural::semiotic<size_type>::template segment<value_type>,
		typename structural::semiotic<size_type>::template hook<value_type>,
		typename structural::semiotic<size_type>::template link<value_type>
	>;

	using out_type = typename cases<(out_pointer - pointer_offset), pointerList>::pointer;
	using in_type = typename cases<(in_pointer - pointer_offset), pointerList>::pointer;
};


/***********************************************************************************************************************/


#include"subjectArgs.hpp"
#include"objectArgs.hpp"
#include"verbArgs.hpp"

#include"declareVariables.hpp"


/***********************************************************************************************************************/


template
<
	typename traits,

	size_type outInterval = traits::out_interval,
	size_type inInterval = traits::in_interval,

	typename subject_args = subjectArgs<traits>,
	typename object_args = objectArgs<traits>,
	typename verb_args = verbArgs<traits>,

	typename declare_variables = declareVariables<traits>

> struct Map { };


/***********************************************************************************************************************/

/*
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
*/


template
<
	typename traits,
	typename subject_args,
	typename object_args,
	typename verb_args,
	typename declare_variables
>
struct Map
<
	traits,
	ArgPointer::closing,
	ArgPointer::closing,
	subject_args,
	object_args,
	verb_args,
	declare_variables
>
{
	typedef subject_args sargs;
	typedef object_args oargs;
	typedef verb_args vargs;

	sargs subject;
	oargs object;
	vargs verb;

	void compute()
	{
		while (object.inr != object.endr)
		{
			*subject.out = *object.inr;
			++subject.out;
			++object.inr;
		}
	}

	Map()
	{
		compute();
	}

	Map(const sargs & s, const oargs & o, const vargs & v = vargs())
		: subject(s), object(o), verb(v)
	{
		compute();
	}
};


/***********************************************************************************************************************/


template<typename T>
using map = Map< mapTraits<T> >;


