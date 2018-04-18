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
	Coproducts aren't mutable, they only describe the current focus of an otherwise predetermined set of alternatives.
	Each alternative is enumeratively indexed, thus an indexing system is the medium for universal navigation. We do not
	know the properties of the parameter type in advance so we cannot rely on its internal properties to generate our index:
	We must rely on external construction. As no assumption is made to the concurrency (in memory) of the coproduct alternatives
        our index system will not rely on an external array. In this case the only remaining possibility is that the index system
        is decompressed by means of a successor function, which for convenience can be generalized to an arithmetic.

	For these reasons it is assumed the parameter type has either builtin or overloaded support for basic arithmetic.

	Effectively, coproducts represent variables, but with a standardized product-like interfaces.
*/

template<typename Type>
struct coproduct
{
	using type		= coproduct;
	using type_ptr		= type*;
	using type_ref		= type&;

	using iterator		= coproduct_navigator<Type>;
	using const_iterator	= coproduct_navigator<Type, Access::readonly>;

	using focus_type	= Type;
	using focus_type_ptr	= focus_type*;
	using focus_type_ref	= focus_type&;

	focus_type focus;

		// type:

	coproduct(const focus_type_ref f) : focus(f) { }

	~coproduct() { }

		// iterator:

	iterator name() const
	{
		return focus;
	}
};

