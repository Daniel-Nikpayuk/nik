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


template
<
	typename sub_adjective,
	typename ob_adjective,

	size_type sub_imageEnum = sub_adjective::image_enum,
	size_type sub_iteratorEnum = sub_adjective::iterator_enum,

	size_type ob_imageEnum = ob_adjective::image_enum,
	size_type ob_iteratorEnum = ob_adjective::iterator_enum
>
struct deinitialize_variables
{
	template<typename adverb>
	static void apply(sub_pointer & out, ob_pointer & in, adverb & side) { }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename sub_adjective, typename ob_adjective, size_type ob_imageEnum, size_type ob_iteratorEnum>
struct deinitialize_variables<sub_adjective, ob_adjective, Adjective::allocate, Adjective::segment, ob_imageEnum, ob_iteratorEnum>
{
	template<typename adverb>
	static void apply(sub_pointer & out, ob_pointer & in, adverb & side)
	{
		sub_pointer tmp = out;
		out = side.current;
		side.current = tmp;
	}
};


template<typename sub_adjective, typename ob_adjective, size_type sub_imageEnum, size_type sub_iteratorEnum>
struct deinitialize_variables<sub_adjective, ob_adjective, sub_imageEnum, sub_iteratorEnum, Adjective::deallocate, Adjective::segment>
{
	template<typename adverb>
	static void apply(sub_pointer & out, ob_pointer & in, adverb & side)
	{
		delete side.origin;
	}
};


template<typename sub_adjective, typename ob_adjective>
struct deinitialize_variables<sub_adjective, ob_adjective, Adjective::allocate, Adjective::segment, Adjective::deallocate, Adjective::segment>
{
	template<typename adverb>
	static void apply(sub_pointer & out, ob_pointer & in, adverb & side)
	{
		sub_pointer tmp = out;
		out = side.current;
		side.current = tmp;

		delete side.origin;
	}
};


