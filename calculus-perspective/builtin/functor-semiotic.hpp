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
	using kind		= branch;

	using type		= functor;

/*
	dereference:
*/

	template<typename Type>
	struct dereference
	{
		using rtn = Type;
	};

	template<typename Type>
	struct dereference<Type*>
	{
		using rtn = Type;
	};

/*
	if_then_else:
*/

	template<bool True, typename Ante, typename Conse>
	struct if_then_else
	{
		using rtn = Ante;
	};

	template<typename Ante, typename Conse>
	struct if_then_else<false, Ante, Conse>
	{
		using rtn = Conse;
	};

/*
	untyped_cons:
*/

	template<typename, typename> struct untyped_cons;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_cons<Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

/*
	typed_cons:
*/

	template<typename Type, Type, typename> struct typed_cons;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_cons<Type, Value, ListType<Values...>>
	{
		using rtn = ListType<Value, Values...>;
	};

/*
	untyped_car:
*/

	template<typename> struct untyped_car;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_car<ListType<Value, Values...>>
	{
		using rtn = Value;
	};

/*
	typed_car:
*/

	template<typename Type, typename> struct typed_car;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_car<Type, ListType<Value, Values...>>
	{
		static constexpr Type value = Value;
	};

/*
	untyped_cdr:
*/

	template<typename> struct untyped_cdr;

	template<typename Value, typename... Values, template<typename...> class ListType>
	struct untyped_cdr<ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};

/*
	typed_cdr:
*/

	template<typename Type, typename> struct typed_cdr;

	template<typename Type, Type Value, Type... Values, template<Type...> class ListType>
	struct typed_cdr<Type, ListType<Value, Values...>>
	{
		using rtn = ListType<Values...>;
	};

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
};

