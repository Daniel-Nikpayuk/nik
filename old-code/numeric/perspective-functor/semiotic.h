/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

namespace nik
{
	nik_begin_division(functor, assemblic, semiotic)

		// display:

		inline static void display(bool v)			{ printf("%s", v ? "true" : "false");	}
		inline static void display(char v)			{ printf("%c", v);			}
		inline static void display(unsigned char v)		{ printf("%u", v);			}
		inline static void display(signed char v)		{ printf("%c", v);			}
		inline static void display(wchar_t v)			{ printf("%c", v);			}
		inline static void display(char16_t v)			{ printf("%u", v);			}
		inline static void display(char32_t v)			{ printf("%u", v);			}
		inline static void display(unsigned short v)		{ printf("%u", v);			}
		inline static void display(signed short v)		{ printf("%d", v);			}
		inline static void display(unsigned int v)		{ printf("%u", v);			}
		inline static void display(signed int v)		{ printf("%d", v);			}
		inline static void display(unsigned long v)		{ printf("%lu", v);			}
		inline static void display(signed long v)		{ printf("%ld", v);			}
		inline static void display(unsigned long long v)	{ printf("%llu", v);			}
		inline static void display(signed long long v)		{ printf("%lld", v);			}
		inline static void display(float v)			{ printf("%f", v);			}
		inline static void display(double v)			{ printf("%f", v);			}
		inline static void display(long double v)		{ printf("%Lf", v);			}
		inline static void display(const char *v)		{ printf("%s", v);			}

	nik_end_division(functor, assemblic, semiotic)
}

