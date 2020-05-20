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

struct structure
{
	// judgements:

	template<typename Type, Type>			struct judgement;

	template<bool Value>				struct judgement<bool, Value>				{ };
	template<char Value>				struct judgement<char, Value>				{ };
	template<unsigned char Value>			struct judgement<unsigned char, Value>			{ };
	template<signed char Value>			struct judgement<signed char, Value>			{ };
	template<wchar_t Value>				struct judgement<wchar_t, Value>			{ };
	template<char16_t Value>			struct judgement<char16_t, Value>			{ };
	template<char32_t Value>			struct judgement<char32_t, Value>			{ };
	template<unsigned short Value>			struct judgement<unsigned short, Value>			{ };
	template<signed short Value>			struct judgement<signed short, Value>			{ };
	template<unsigned int Value>			struct judgement<unsigned int, Value>			{ };
	template<signed int Value>			struct judgement<signed int, Value>			{ };
	template<unsigned long Value>			struct judgement<unsigned long, Value>			{ };
	template<signed long Value>			struct judgement<signed long, Value>			{ };
	template<unsigned long long Value>		struct judgement<unsigned long long, Value>		{ };
	template<signed long long Value>		struct judgement<signed long long, Value>		{ };
};

