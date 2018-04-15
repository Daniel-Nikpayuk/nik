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
	Given the special nature of bit_type, we can unencapsulate the binary_type and optimize.
*/

template<typename BitInterp, size_type length, bool greaterThan = (length > 8*sizeof(size_type))>
struct word_navigator
{
	typedef typename BitInterp::binary_type binary_type;

	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;

	typedef word_navigator* word_navigator_ptr;
	typedef word_navigator& word_navigator_ref;

	binary_type_ptr location;

	word_navigator(binary_type *b) : location(b) { }

	binary_type_ref operator * () const
	{
		return *location;
	}

	~word_navigator() { }

	word_navigator_ref operator ++ ()
	{
		return ++location;
	}

	word_navigator operator ++ (int)
	{
		return location++;
	}

	word_navigator_ref operator += (size_type n)
	{
		while (n)
		{
			++location;
			--n;
		}

		return *this;
	}

	word_navigator operator + (size_type n) const
	{
		word_navigator out(*this);
		while (n)
		{
			++out;
			--n;
		}

		return out;
	}

	word_navigator_ref operator -- ()
	{
		return --location;
	}

	word_navigator operator -- (int)
	{
		return location--;
	}

	word_navigator_ref operator -= (size_type n)
	{
		while (n)
		{
			--location;
			--n;
		}

		return *this;
	}

	word_navigator operator - (size_type n) const
	{
		word_navigator out(*this);
		while (n)
		{
			--out;
			--n;
		}

		return out;
	}
};

