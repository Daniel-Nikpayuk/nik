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
	display:
*/

	inline static void display(char v)			{ printf("%c", v);			}
	inline static void display(signed char v)		{ printf("%c", v);			}
	inline static void display(unsigned char v)		{ printf("%u", v);			}
	inline static void display(wchar_t v)			{ printf("%c", v);			}
	inline static void display(char16_t v)			{ printf("%u", v);			}
	inline static void display(char32_t v)			{ printf("%u", v);			}
	inline static void display(short v)			{ printf("%d", v);			}
	inline static void display(unsigned short v)		{ printf("%u", v);			}
	inline static void display(int v)			{ printf("%d", v);			}
	inline static void display(unsigned int v)		{ printf("%u", v);			}
	inline static void display(long v)			{ printf("%ld", v);			}
	inline static void display(unsigned long v)		{ printf("%lu", v);			}
	inline static void display(long long v)			{ printf("%lld", v);			}
	inline static void display(unsigned long long v)	{ printf("%llu", v);			}
	inline static void display(float v)			{ printf("%f", v);			}
	inline static void display(double v)			{ printf("%f", v);			}
	inline static void display(long double v)		{ printf("%Lf", v);			}

	inline static void display(bool v)			{ printf("%s", v? "true" : "false");	}
	inline static void display(const char *v)		{ printf("%s", v);			}

/***********************************************************************************************************************/

/*
	display:

	Assumes list elements are coded within module::structure.
*/

	template<typename Exp, typename... Exps, template<typename...> class ListType>
	inline static void display(const ListType<Exp, Exps...> &, const char *sep = " ")
	{
		static constexpr bool expression_is_list	= is_list<Exp>::value;
		static constexpr bool remainder_is_null		= is_null<ListType<Exps...>>::value;

		static constexpr char l				= expression_is_list ? '[' : '(';
		static constexpr char r				= expression_is_list ? ']' : ')';

		printf("%c", l);
		Exp::kind::functor::display(Exp());
		printf("%c", r);

		if (!remainder_is_null) printf("%s", sep);

		display(ListType<Exps...>(), sep);
	}

	template<template<typename...> class ListType>
	inline static void display(const ListType<> &, const char *sep = " ")
	{
		// do nothing.
	}

/*
	Hack!

	The ListType Type is deducible by adding an apply<Type> argument.
*/

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	inline static void display(const apply<Type> & a, const ListType<Value, Values...> &, const char *sep = " ")
	{
		printf("%s", sep);
		display(Value);
		display(a, ListType<Values...>(), sep);
	}

	template<typename Type, template<Type...> class ListType>
	inline static void display(const apply<Type> &, const ListType<> &, const char *sep = " ")
	{
		// do nothing.
	}

