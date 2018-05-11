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

/*
	Although the template parameter allows for arbitrary types, identity methods are meant specifically for pointers
	of the following register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long
*/

struct identity														{

template<Operator verb_operator>
struct verb														{

template<Interval sub_interval, Direction sub_direction>
struct subject														{

template<Interval ob_interval, Direction ob_direction>
struct object														{

template<typename Type>
static Type* compare(bool & result, Type *sub, Type *ob, Type *end)
{
	initialize<sub_interval, sub_direction>::apply<Type>(sub);
	initialize<ob_interval, ob_direction>::apply<Type>(ob);

	while (ob != end)
	{
		if (*sub != *ob) result = (verb_operator != Operator::equals);

		iterate<sub_direction>::apply<Type>(sub);
		iterate<ob_direction>::apply<Type>(ob);
	}

	terminalize<sub_interval, sub_direction>::apply<Type>(sub);
	terminalize<ob_interval, ob_direction>::apply<Type>(ob);

	result = (verb_operator == Operator::equals);

	return sub;
}

};};};};

