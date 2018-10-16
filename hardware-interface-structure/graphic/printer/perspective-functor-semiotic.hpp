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

struct functor
{
	using kind					= module;

	using type					= functor;

	template<typename Type>
	const display_printer & operator << (const display_printer & p, const Type & t)
	{
		Type::kind::functor::display(t);

		return p;
	}

	template<typename Type>
	const verbatim_printer & operator << (const verbatim_printer & p, const Type & t)
	{
		Type::kind::functor::verbatim(t);

		return p;
	}
};
