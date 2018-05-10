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
	Although the template parameter allows for arbitrary types, product is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	8 << 3, void*

	In the context of this library, products are the disjoint union of concurrent instances of the same type.
	This generic code is only intended for a fixed number of similar types, but the length parameter generates
        further possibilities. As such, the basic methods for the objects of this class are called as external
        static functions allowing for identity, proximity, and shape methods between various lengths.
*/

struct identity
{
	enum struct Operator : size_type
	{
		equals,
		not_equals,

		dimension
	};

	enum struct Interval : size_type
	{
		closed,
		closing,
		opening,
		open,

		dimension
	};

	enum struct Direction : size_type
	{
		forward,
		backward,

		dimension
	};
 
	template<Interval interval, Direction direction>
	struct normalize
	{
		using value_type = coproduct<Type*>::value_type;
		using value_type_ref = value_type&:

		static void evaluate(value_type_ref focus)
		{
		}
	};

	template
	<
		Operator op,

		Interval out_interval, Direction out_direction,
		Interval in_interval, Direction in_direction,

		typename Type
	>
	static coproduct<Type*> compare(bool & result, coproduct<Type*> co_out, coproduct<Type*> co_in, coproduct<Type*> co_end)
	{
			// unpack:

		coproduct<Type*>::value_type out	= co_out.focus;
		coproduct<Type*>::value_type in		= co_in.focus;
		coproduct<Type*>::value_type end	= co_end.focus;

			// compute:

		normalize<out_interval, out_direction>::evaluate(out);
		normalize<in_interval, in_direction>::evaluate(in);

		while (in != end)
		{
			if (*out != *in) result = (op != Operator::equals);

			iterate<out_direction>::evaluate(out);
			iterate<in_direction>::evaluate(in);
		}

		finalize<out_interval, out_direction>::evaluate(out);
		finalize<in_interval, in_direction>::evaluate(in);

		result = (op == Operator::equals);

		return out;
	}
};

