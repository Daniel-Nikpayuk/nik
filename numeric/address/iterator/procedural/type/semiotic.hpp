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
	LIST<directionEnum, intervalEnum, Adjective::mutate, Adjective::segment>,
	OL
>
{
	public:
		size_type value;

		Type() { }
		Type(size_type l, size_type o) { value = l + o; }
		Type(const Type & t) : value(t.value) { }
};


/***********************************************************************************************************************/


template<size_type optimizerEnum>
class Type
<
	LIST<Adverb::omit_functor, Adverb::omit_count, optimizerEnum>
>
{
	public:
		using parameter_list = LIST<Adverb::omit_functor, Adverb::omit_count, optimizerEnum>;

		template<typename sub_adjective, typename ob_adjective>
		using return_type = Type
		<
			parameter_list,
			typename sub_adjective::parameter_list,
			typename ob_adjective::parameter_list
		>;
	public:
		template<typename sub_adjective, typename ob_adjective>
		static return_type<sub_adjective, ob_adjective> verb(size_type l, size_type o)
		{
			return return_type<sub_adjective, ob_adjective>(l, o);
		}
};


/***********************************************************************************************************************/


template<size_type... params>
using type = Type<SORTFILL<Adverb, params...>::rtn>;


