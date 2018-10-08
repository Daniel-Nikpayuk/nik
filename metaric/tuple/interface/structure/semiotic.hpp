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

struct structure
{
	using module				= metaric;

	template<typename... Exps>
	struct tuple
	{
		using module			= metaric;

		using type			= tuple;

		using rtn			= tuple;
	};

/*
	template<typename Type, Type Value>
	struct tuple<parameter<Type, Value>>
	{
		using rtn = constant<Type, Value>;
	};

	template<typename Type, Type Value1, Type Value2, Type... Values>
	struct tuple<parameter<Type, Value1, Value2, Values...>>
	{
		using rtn = typename cons
		<
			constant<Type, Value1>,
			act<tuple<parameter<Type, Value2, Values...>>>

		>::rtn;
	};
*/

/*
	I've added this "array" in that it might be useful,
	but as of yet, I have not had need to use it.

	template<size_type N, size_type... params>
	struct array
	{
		static constexpr size_type size = N;
		static constexpr size_type names[size] { params... };
	};
*/
};

