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


template<typename L, typename... params> class Type { };


/***********************************************************************************************************************/


template<typename L, size_type directionEnum, size_type intervalEnum, typename OL>
class Type
<
	L,
	LIST<directionEnum, intervalEnum, Adjective::allocate, Adjective::segment>,
	OL
>
{
	public:
		using parameter_list = L;

		static constexpr size_type functor_enum = AT<L, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<L, Modifier::tracer>::rtn;
	public:
		size_type value;

		Type() { }
		Type(size_type l, size_type o) { value = l + o; }
		Type(const Type & t) : value(t.value) { }
};


/************************************************************************************************************************/


template<typename L, size_type directionEnum, size_type intervalEnum, typename OL, typename Functor>
class Type
<
	L,
	LIST<directionEnum, intervalEnum, Adjective::mutate, Adjective::segment>,
	OL,
	Functor
>
{
	public:
		using parameter_list = L;

		static constexpr size_type functor_enum = AT<L, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<L, Modifier::tracer>::rtn;
	public:
		typedef Functor functor_type;
		functor_type functor;

		Type(const functor_type & f) : functor(f) { }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define APPLY_OMIT_ADVERB_LIST		LIST<Adverb::apply_functor, Adverb::omit_count, optimizerEnum>

template<size_type optimizerEnum>
class Type
<
	APPLY_OMIT_ADVERB_LIST
>
{
	public:
		using parameter_list = APPLY_OMIT_ADVERB_LIST;

		static constexpr size_type functor_enum = AT<APPLY_OMIT_ADVERB_LIST, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<APPLY_OMIT_ADVERB_LIST, Modifier::tracer>::rtn;
		static constexpr size_type optimizer_enum = AT<APPLY_OMIT_ADVERB_LIST, Modifier::optimizer>::rtn;

		static constexpr size_type optimizer_offset = Adverb::template bounds<Modifier::optimizer>::initial;

		template<typename sub_adjective, typename ob_adjective, typename Functor>
		using adverb = Type
		<
			parameter_list,
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list,
			Functor
		>;
	public:
		template<typename sub_adjective, typename ob_adjective, typename Functor>
		static adverb<sub_adjective, ob_adjective, Functor> verb(const Functor & f)
		{
			return adverb<sub_adjective, ob_adjective, Functor>(f);
		}
};


/***********************************************************************************************************************/


#define OMIT_OMIT_ADVERB_LIST		LIST<Adverb::omit_functor, Adverb::omit_count, optimizerEnum>

template<size_type optimizerEnum>
class Type
<
	OMIT_OMIT_ADVERB_LIST
>
{
	public:
		using parameter_list = OMIT_OMIT_ADVERB_LIST;

		static constexpr size_type functor_enum = AT<OMIT_OMIT_ADVERB_LIST, Modifier::functor>::rtn;
		static constexpr size_type tracer_enum = AT<OMIT_OMIT_ADVERB_LIST, Modifier::tracer>::rtn;
		static constexpr size_type optimizer_enum = AT<OMIT_OMIT_ADVERB_LIST, Modifier::optimizer>::rtn;

		static constexpr size_type optimizer_offset = Adverb::template bounds<Modifier::optimizer>::initial;

		template<typename sub_adjective, typename ob_adjective>
		using adverb = Type
		<
			parameter_list,
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list
		>;
	public:
		template<typename sub_adjective, typename ob_adjective>
		static adverb<sub_adjective, ob_adjective> verb(size_type l, size_type o)
		{
			return adverb<sub_adjective, ob_adjective>(l, o);
		}
};


/***********************************************************************************************************************/


template<size_type... params>
using type = Type<SORTFILL<Adverb, params...>::rtn>;


