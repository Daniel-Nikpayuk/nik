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

struct sift
{
	/*
		Optimized as max > 0: We need not call the conforming version.
	*/

	template<size_type t>
	struct low_pass
	{
		enum : size_type
		{
			value = semiotic::unit::max >> (semiotic::unit::length - t)
		};
	};

	template<size_type s>
	struct high_pass
	{
		enum : size_type
		{
			value = semiotic::unit::max & ~low_pass<s>::value
		};
	};

	/*
		Optimized as max > 0: We need not call the conforming version.
	*/

	template<size_type s, size_type t>
	struct band_pass
	{
		enum : size_type
		{
			value = (semiotic::unit::max >> (semiotic::unit::length-t+s)) << s
		};
	};

	template<size_type x, size_type t>
	struct low
	{
		enum : size_type
		{
			value = (x & low_pass<t>::value)
		};
	};

	template<size_type x, size_type s>
	struct high
	{
		enum : size_type
		{
			value = semiotic::over::template right_shift<x, s>::value
		};
	};

	template<size_type x, size_type s, size_type t>
	struct band
	{
		enum : size_type
		{
			value = semiotic::over::template right_shift<x & (1 << t) - 1, s>::value
		};
	};

	template<size_type x>
	struct lower_half
	{
		enum : size_type
		{
			value = low<x, unit::half::length>::value
		};
	};

	template<size_type x>
	struct upper_half
	{
		enum : size_type
		{
			value = high<x, unit::half::length>::value
		};
	};

	template<size_type primary, size_type secondary>
	class signed_degree
	{
		static constexpr size_type half_secondary = semiotic::over::template right_shift<secondary, 1>::value;

		public: enum : size_type
		{
			value = signed_degree<primary + 1, half_secondary>::value
		};
	};

	template<size_type primary>
	class signed_degree<primary, 1> { public: enum : size_type { value=primary }; };

	template<size_type primary>
	class signed_degree<primary, 0> { public: enum : size_type { value=primary }; };

	template<size_type primary, size_type secondary, size_type n>
	class unsigned_degree
	{
		static constexpr size_type m = n >> 1;

		public: enum : size_type
		{
			value = gfm_policy::cont::template
			if_then_else
			<
				band<secondary, m, n>::value,
				unsigned_degree<primary + m, band<secondary, m, n>::value, m>,
				unsigned_degree<primary, band<secondary, 0, m>::value, m>
			>::return_type::value
		};
	};

	template<size_type primary, size_type secondary>
	class unsigned_degree<primary, secondary, 0> { public: enum : size_type { value=primary }; };
};

