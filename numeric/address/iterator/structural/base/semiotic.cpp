/*************************************************************************************************************************
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
*************************************************************************************************************************/

// defaults to bit base:

template<typename T, size_type Index=0>
struct base
{
};

// segment base

template<typename T>
struct base<T, 1>
{
	typedef typename gsm_traits::template container<base, T> attributes;

	typedef typename attributes::value_type value_type;
	typedef typename attributes::reference reference;
	typedef typename attributes::const_reference const_reference;
	typedef typename attributes::pointer pointer;
	typedef typename attributes::const_pointer const_pointer;
	typedef typename attributes::size_type size_type;

	pointer initial;

	void initialize(pointer p)
	{
		initial=p;
	}

	void copy_initialize(const base & i)
	{
		initial=i.initial;
	}

	void terminalize() { delete initial; }

	base() { }
	base(const base & i) { }
	~base() { }

	const base & operator = (const base & i)
		{ return *this; }
};

