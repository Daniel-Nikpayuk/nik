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

void print(char v) const { printf("%c", v); }
void print(signed char v) const { printf("%c", v); }
void print(unsigned char v) const { printf("%u", v); }
void print(wchar_t v) const { printf("%c", v); }
void print(char16_t v) const { printf("%u", v); }
void print(char32_t v) const { printf("%u", v); }
void print(short v) const { printf("%d", v); }
void print(unsigned short v) const { printf("%u", v); }
void print(int v) const { printf("%d", v); }
void print(unsigned int v) const { printf("%u", v); }
void print(long v) const { printf("%ld", v); }
void print(unsigned long v) const { printf("%lu", v); }
void print(long long v) const { printf("%lld", v); }
void print(unsigned long long v) const { printf("%llu", v); }
void print(float v) const { printf("%f", v); }
void print(double v) const { printf("%f", v); }
void print(long double v) const { printf("%Lf", v); }

void print(bool v) const { printf("%s", v? "true" : "false"); }
void print(const char *v) const { printf("%s", v); }

