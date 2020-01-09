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

#define define_identity(int_length)											\
															\
template<typename Filler>												\
struct identity<word<bit<boolean>, (int_length)>, Filler>								\
{															\
	using type			= identity;									\
	using type_ref			= type&;									\
	using type_ptr			= type*;									\
															\
	using word_type			= word<bit<boolean>, (int_length)>;						\
	using word_type_ref		= word_type&;									\
	using word_type_ptr		= word_type*;									\
															\
		// if they're of the same word_type it is assumed they have the same word_length.			\
															\
	static bool equals(const word_type & u, const word_type & v)							\
	{														\
		return u.product == v.product;										\
	}														\
															\
	static bool not_equals(const word_type & u, const word_type & v)						\
	{														\
		return u.product != v.product;										\
	}														\
};															\


//define_identity(8 << 0)
//define_identity(8 << 1)
//define_identity(8 << 2)
//define_identity(8 << 3)


#undef define_identity


// For whatever reason the above macro function doesn't compile,
// so until it does each case must be handled separately:

#define INT_LENGTH 8

template<typename Filler>
struct identity<word<bit<boolean>, INT_LENGTH>, Filler>
{
	using type			= identity;
	using type_ref			= type&;
	using type_ptr			= type*;

	using word_type			= word<bit<boolean>, INT_LENGTH>;
	using word_type_ref		= word_type&;
	using word_type_ptr		= word_type*;

		// if they're of the same word_type it is assumed they have the same word_length.

	static bool equals(const word_type & u, const word_type & v)
	{
		return u.product == v.product;
	}

	static bool not_equals(const word_type & u, const word_type & v)
	{
		return u.product != v.product;
	}
};

#undef INT_LENGTH
#define INT_LENGTH 16

template<typename Filler>
struct identity<word<bit<boolean>, INT_LENGTH>, Filler>
{
	using type			= identity;
	using type_ref			= type&;
	using type_ptr			= type*;

	using word_type			= word<bit<boolean>, INT_LENGTH>;
	using word_type_ref		= word_type&;
	using word_type_ptr		= word_type*;

		// if they're of the same word_type it is assumed they have the same word_length.

	static bool equals(const word_type & u, const word_type & v)
	{
		return u.product == v.product;
	}

	static bool not_equals(const word_type & u, const word_type & v)
	{
		return u.product != v.product;
	}
};

#undef INT_LENGTH
#define INT_LENGTH 32

template<typename Filler>
struct identity<word<bit<boolean>, INT_LENGTH>, Filler>
{
	using type			= identity;
	using type_ref			= type&;
	using type_ptr			= type*;

	using word_type			= word<bit<boolean>, INT_LENGTH>;
	using word_type_ref		= word_type&;
	using word_type_ptr		= word_type*;

		// if they're of the same word_type it is assumed they have the same word_length.

	static bool equals(const word_type & u, const word_type & v)
	{
		return u.product == v.product;
	}

	static bool not_equals(const word_type & u, const word_type & v)
	{
		return u.product != v.product;
	}
};

#undef INT_LENGTH
#define INT_LENGTH 64

template<typename Filler>
struct identity<word<bit<boolean>, INT_LENGTH>, Filler>
{
	using type			= identity;
	using type_ref			= type&;
	using type_ptr			= type*;

	using word_type			= word<bit<boolean>, INT_LENGTH>;
	using word_type_ref		= word_type&;
	using word_type_ptr		= word_type*;

		// if they're of the same word_type it is assumed they have the same word_length.

	static bool equals(const word_type & u, const word_type & v)
	{
		return u.product == v.product;
	}

	static bool not_equals(const word_type & u, const word_type & v)
	{
		return u.product != v.product;
	}
};

#undef INT_LENGTH

