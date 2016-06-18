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

template<typename T>
struct identity
{
	typedef random_access::traits<SizeType> r_traits;
	typedef typename r_traits::cont::media::template identity<identity, T> attributes;

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

	void copy_initialize(const identity & i)
	{
		initial=i.initial;
	}

	void terminalize() { delete initial; }

	identity() { }
	identity(const identity & i) { }
	~identity() { }

	const identity & operator = (const identity & i)
		{ return *this; }
};

