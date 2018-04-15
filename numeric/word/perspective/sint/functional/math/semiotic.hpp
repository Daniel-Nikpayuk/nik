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

struct math
{
	template<size_type a, size_type b>
	class gcd
	{
		public: enum : size_type { value = gcd<b, a%b>::value };
	};

	template<size_type a>
	class gcd<a, 0> { public: enum : size_type { value = a }; };

	template<size_type rtn, size_type b, size_type n>
	class exp
	{
		static constexpr size_type sq = media::template square<b>::value;

		public: enum : size_type
		{
			value = gcf_media::template
			if_then_else
			<
				(1 & n),
				exp<rtn*b, b, n-1>,
				exp<rtn, sq, (n>>1)>
			>::return_type::value
		};
	};

	template<size_type rtn, size_type b>
	class exp<rtn, b, 0> { public: enum : size_type { value = rtn }; };
};

