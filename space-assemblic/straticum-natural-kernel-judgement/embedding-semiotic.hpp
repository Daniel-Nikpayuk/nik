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

struct embedding
{
	// display:

		// procedural:

		static constexpr void char_display(char v)					{ printf("%c", v);			}
		static constexpr void unsigned_char_display(unsigned char v)			{ printf("%u", v);			}
		static constexpr void signed_char_display(signed char v)			{ printf("%c", v);			}
		static constexpr void wchar_t_display(wchar_t v)				{ printf("%c", v);			}
		static constexpr void char16_t_display(char16_t v)				{ printf("%u", v);			}
		static constexpr void char32_t_display(char32_t v)				{ printf("%u", v);			}
		static constexpr void unsigned_short_display(unsigned short v)			{ printf("%u", v);			}
		static constexpr void signed_short_display(signed short v)			{ printf("%d", v);			}
		static constexpr void unsigned_int_display(unsigned int v)			{ printf("%u", v);			}
		static constexpr void signed_int_display(signed int v)				{ printf("%d", v);			}
		static constexpr void unsigned_long_display(unsigned long v)			{ printf("%lu", v);			}
		static constexpr void signed_long_display(signed long v)			{ printf("%ld", v);			}
		static constexpr void unsigned_long_long_display(unsigned long long v)		{ printf("%llu", v);			}
		static constexpr void signed_long_long_display(signed long long v)		{ printf("%lld", v);			}
		static constexpr void float_display(float v)					{ printf("%f", v);			}
		static constexpr void double_display(double v)					{ printf("%f", v);			}
		static constexpr void long_double_display(long double v)			{ printf("%Lf", v);			}
};

