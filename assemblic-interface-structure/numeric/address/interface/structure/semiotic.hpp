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

template
<
	typename WordType,
	size_type length,
	typename Filler = filler

> struct address;

/*
	address type		:= (0 + 1)^np;
	address instance	:= m^i/m^j/s^k, m^i/m^j/s^l in (0 + 1)^np -> k = l;

	An address is a power of WordType.
*/

template
<
	typename WordType,
	size_type length,
	typename Filler

> struct address
{
	using type			= address;
	using type_ref			= type&;
	using type_ptr			= type*;

	using value_type		= power<WordType, length>;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	using iterator			= typename power<WordType, length>::iterator;
	using const_iterator		= typename power<WordType, length>::const_iterator;

	using navigator			= coaddress<type>;
	using const_navigator		= coaddress<type, Access::readonly>;

	//

	using policy		= object
				<
					Interval::closing,
					Direction::forward
				>;

	using method		= typename Power::template functor
				<
					policy,
					policy
				>;

	//

	value_type value;

	address() { }
	
	address(const type & w)
	{
		method::assign(value.begin(), w.begin(), w.end());
	}

	~address() { }

	navigator begin()
	{
		return value;
	}

	const_navigator begin() const
	{
		return value;
	}

	navigator end()
	{
		return value;
	}

	const_navigator end() const
	{
		return value;
	}
};


#define define_word(int_length, int_type)										\
															\
template														\
<															\
	typename Filler													\
															\
> struct word														\
<															\
	bit<bool>,													\
	(int_length),													\
	Filler														\
>															\
{															\
	using type			= word;										\
	using type_ref			= type&;									\
	using type_ptr			= type*;									\
					=       									\
	using value_type		= (int_type);									\
	using value_type_ref		= value_type&;									\
	using value_type_ptr		= value_type*;									\
					=       									\
	using iterator			= (int_type)*;									\
	using const_iterator		= (int_type) const*;								\
					=       									\
	using navigator			= coword<type>;									\
	using const_navigator		= coword<type, Access::readonly>;						\
															\
	value_type value;												\
															\
	word() { }													\
															\
	word(const type & w) : value(w.value) { }									\
															\
	~word() { }													\
															\
	navigator begin()												\
	{														\
		return navigator(1, value);										\
	}														\
															\
	const_navigator begin() const											\
	{														\
		return navigator(1, value);										\
	}														\
															\
	navigator end()													\
	{														\
		return navigator(1 << (int_length), value);								\
	}														\
															\
	const_navigator end() const											\
	{														\
		return navigator(1 << (int_length), value);								\
	}														\
};															\


/*
	Although the template parameter allows for arbitrary types, word is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long
*/

define_word(8 << 0, unsigned char)
define_word(8 << 1, unsigned short)
define_word(8 << 2, unsigned int)
define_word(8 << 3, unsigned long)


#undef define_word

