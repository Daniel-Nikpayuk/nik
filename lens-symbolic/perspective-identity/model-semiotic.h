/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct model
{
	// is_Equal:

	template<typename Type1, typename Type2, typename Continuation>
	using universal_equal = typename cs_universal_equal<Type1, Type2>::template match
	<
		Continuation
	>;

	// is_equal:

	template<auto Value1, auto Value2, typename Continuation>
	using builtin_equal = typename Continuation::template result
	<
		constexpr_equal(Value1, Value2)
	>;
};

