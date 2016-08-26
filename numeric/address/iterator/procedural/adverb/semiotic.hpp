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


template<typename S, typename O, typename L, typename F> struct Functor { };


/***********************************************************************************************************************/


/*
template<typename L, size_type directionEnum, size_type intervalEnum, typename OL>
class Functor
<
	LIST<directionEnum, intervalEnum, Attribute::allocate, Attribute::segment>,
	OL
	L,
>
{
	public:
		using parameter_list = L;

		static constexpr size_type functor_enum = AT<L, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<L, Modifier::tracer>::rtn;
	public:
		size_type value;

		Functor() { }
		Functor(size_type l, size_type o) { value = l + o; }
		Functor(const Functor & t) : value(t.value) { }
};
*/


/************************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum, typename OL, typename L, typename F>
class Functor
<
	LIST<directionEnum, intervalEnum, StrAttribute::mutate, StrAttribute::segment>,
	OL,
	L,
	F
>
{
		typedef F functor_type;
	public:
		using parameter_list = L;

		static constexpr size_type functor_enum = AT<L, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<L, Modifier::tracer>::rtn;
	public:
		functor_type functor;

		Functor(const functor_type & f) : functor(f) { }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
#define APPLY_OMIT_ATTRIBUTES		LIST<Attribute::omit_assign, Attribute::omit_count, Attribute::omit_effect, optimizerEnum>

template<typename sub_adjective, typename ob_adjective, size_type optimizerEnum>
class Functor
<
	sub_adjective,
	ob_adjective,
	APPLY_OMIT_ATTRIBUTES
>
{
	public:
		using parameter_list = APPLY_OMIT_ATTRIBUTES;

		static constexpr size_type functor_enum = AT<APPLY_OMIT_ATTRIBUTES, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<APPLY_OMIT_ATTRIBUTES, Modifier::tracer>::rtn;
		static constexpr size_type effector_enum = AT<APPLY_OMIT_ATTRIBUTES, Modifier::effector>::rtn;
		static constexpr size_type optimizer_enum = AT<APPLY_OMIT_ATTRIBUTES, Modifier::optimizer>::rtn;

		static constexpr size_type optimizer_offset = Attribute::template bounds<Modifier::optimizer>::initial;

		template<typename F>
		using type = Functor
		<
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list,
			parameter_list,
			F
		>;
	public:
		template<typename F>
		static type<F> set(const F & f)
		{
			return type<F>(f);
		}
};
*/


/***********************************************************************************************************************/


#define OMIT_OMIT_ATTRIBUTES		LIST<Attribute::apply_assign, Attribute::omit_count, Attribute::omit_effect, optimizerEnum>

/*
template<size_type optimizerEnum>
class Functor
<
	OMIT_OMIT_ATTRIBUTES
>
{
	public:
		using parameter_list = OMIT_OMIT_ATTRIBUTES;

		static constexpr size_type functor_enum = AT<OMIT_OMIT_ATTRIBUTES, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<OMIT_OMIT_ATTRIBUTES, Modifier::tracer>::rtn;
		static constexpr size_type optimizer_enum = AT<OMIT_OMIT_ATTRIBUTES, Modifier::optimizer>::rtn;

		static constexpr size_type optimizer_offset = Attribute::template bounds<Modifier::optimizer>::initial;

		template<typename sub_adjective, typename ob_adjective>
		using type = Functor
		<
			parameter_list,
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list
		>;
	public:
		template<typename sub_adjective, typename ob_adjective>
		static type<sub_adjective, ob_adjective> functor(size_type l, size_type o)
		{
			return type<sub_adjective, ob_adjective>(l, o);
		}
};
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... adjectives> struct adverb { };


/***********************************************************************************************************************/


/*
template<typename sub_adjective>
class adverb<sub_adjective>
{
	public:
		template<size_type... params>
		using functor = Functor<sub_adjective, SORTFILL<Attribute, params...>::rtn>;
};
*/


template<typename sub_adjective, typename ob_adjective>
class adverb<sub_adjective, ob_adjective>
{
	public:
/*
		template<typename F, size_type... params>
		using type = Functor
		<
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list,
			SORTFILL<Attribute, params...>::rtn,
			F
		>;
*/

		template<typename F>
		using type = Functor
		<
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list,
			SORTFILL<Attribute>::rtn,
			F
		>;

		template<typename F>
		static type<F> functor(const F & f)
		{
			return type<F>(f);
		}

/*
		template<size_type p0, typename F>
		static type<F, p0> functor(const F & f)
		{
			return type<F, p0>(f);
		}

		template<size_type p0, size_type p1, typename F>
		static type<F, p0, p1> functor(const F & f)
		{
			return type<F, p0, p1>(f);
		}

		template<size_type p0, size_type p1, size_type p2, typename F>
		static type<F, p0, p1, p2> functor(const F & f)
		{
			return type<F, p0, p1, p2>(f);
		}

		template<size_type p0, size_type p1, size_type p2, size_type p3, typename F>
		static type<F, p0, p1, p2, p3> functor(const F & f)
		{
			return type<F, p0, p1, p2, p3>(f);
		}
*/
};


