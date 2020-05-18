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

struct inductor
{
	// builtin types:

	template<typename, typename = filler>
	struct memoized_builtin
	{
		static constexpr bool match() { return false; }
	};

	template<typename Filler>
	struct memoized_builtin<bool, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "bool"; }
	};

	template<typename Filler>
	struct memoized_builtin<char, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "char"; }
	};

	template<typename Filler>
	struct memoized_builtin<unsigned char, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "unsigned char"; }
	};

	template<typename Filler>
	struct memoized_builtin<signed char, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "signed char"; }
	};

	template<typename Filler>
	struct memoized_builtin<wchar_t, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "wchar_t"; }
	};

	template<typename Filler>
	struct memoized_builtin<char16_t, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "char16_t"; }
	};

	template<typename Filler>
	struct memoized_builtin<char32_t, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "char32_t"; }
	};

	template<typename Filler>
	struct memoized_builtin<unsigned short, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "unsigned short"; }
	};

	template<typename Filler>
	struct memoized_builtin<signed short, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "signed short"; }
	};

	template<typename Filler>
	struct memoized_builtin<unsigned int, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "unsigned int"; }
	};

	template<typename Filler>
	struct memoized_builtin<signed int, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "signed int"; }
	};

	template<typename Filler>
	struct memoized_builtin<unsigned long, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "unsigned long"; }
	};

	template<typename Filler>
	struct memoized_builtin<signed long, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "signed long"; }
	};

	template<typename Filler>
	struct memoized_builtin<unsigned long long, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "unsigned long long"; }
	};

	template<typename Filler>
	struct memoized_builtin<signed long long, Filler>
	{
		static constexpr bool match() { return true; }

		static constexpr const char* induct() { return "signed long long"; }
	};

/***********************************************************************************************************************/

	// void_ptr values:

/*
	void_ptr values aren't generally considered meaningful as template parameters,
	this inductor is only here to maintain the narrative design of this library.
*/

	template<auto>
	struct memoized_void_ptr
	{
		static constexpr bool match() { return false; }
	};

	template<void_ptr Value>
	struct memoized_void_ptr<Value>
	{
		static constexpr bool match() { return true; }

		static constexpr void_ptr induct() { return Value; }
	};

	// void_ptr values:
};

