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

template<typename Word, typename Filler = filler>
struct identity
{
	using type		= identity;
	using type_ref		= type&;
	using type_ptr		= type*;

	using word_type		= Word;
	using word_type_ref	= word_type&;
	using word_type_ptr	= word_type*;

		// if they're of the same word_type it is assumed they have the same word_length.

	static bool equals(const word_type & u, const word_type & v)
	{
		typename word_type::const_iterator k = u.begin();
		typename word_type::const_iterator e = u.end();
		typename word_type::const_iterator l = v.begin();

		for (; k != e; ++k, ++l) if (*k != *l) return false;

		return true;
	}

	static bool not_equals(const word_type & u, const word_type & v)
	{
		typename word_type::const_iterator k = u.begin();
		typename word_type::const_iterator e = u.end();
		typename word_type::const_iterator l = v.begin();

		for (; k != e; ++k, ++l) if (*k != *l) return true;

		return false;
	}
};

