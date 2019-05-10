/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	using kind					= module;

	using type					= structure;

	struct display_printer
	{
		template<typename Type>
		const display_printer & operator << (const Type & t) const
		{
			Type::kind::functor::display(t);

			return *this;
		}
	};

	struct verbatim_printer
	{
		template<typename Type>
		const verbatim_printer & operator << (const Type & t) const
		{
			Type::kind::functor::verbatim(t);

			return *this;
		}
	};

	static const display_printer display;
	static const verbatim_printer verbatim;
};

