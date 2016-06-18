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

struct left_shift
{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = p_policy::unit::length-m.
	template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator>
	static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator end, size_type m, size_type n)
	{
		while (in2 != end)
		{
			*out=(*in1<<m)+(*in2>>n);
			--out; --in1; --in2;
		}
	}

	template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator>
	static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator end, size_type m, size_type n)
	{
		while (in2 != end)
		{
			*out=(*in1<<m)+(*in2>>n);
			--out; --in1; --in2;
		}

		return out;
	}
*/
};

struct assign
{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = p_policy::unit::length-m.
	struct left_shift
	{
		template<typename WIterator, typename RIterator, typename ERIterator>
		static void no_return(WIterator out, RIterator in, ERIterator end, size_type m, size_type n)
		{
			while (in != end)
			{
				(*out<<=m)+=(*in>>n);
				--out; --in;
			}
		}

		template<typename WIterator, typename RIterator, typename ERIterator>
		static WIterator with_return(WIterator out, RIterator in, ERIterator end, size_type m, size_type n)
		{
			while (in != end)
			{
				(*out<<=m)+=(*in>>n);
				--out; --in;
			}

			return out;
		}
	};
*/
};

template<size_type N, size_type M=0, size_type L=0>
struct unroll
{
	struct left_shift
	{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = p_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1<<m); }.
	Do not add (*in2>>n) as in this specialization, in2 may be past the boundary.
		template<typename WIterator, typename RIterator1, typename RIterator2>
		static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
		{
			*out=(*in1<<m)+(*in2>>n);
			unroll<N-1>::left_shift::no_return(--out, --in1, --in2, m, n);
		}

		template<typename WIterator, typename RIterator1, typename RIterator2>
		static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
		{
			*out=(*in1<<m)+(*in2>>n);
			return unroll<N-1>::left_shift::with_return(--out, --in1, --in2, m, n);
		}
*/
	};

	struct assign
	{
		struct left_shift
		{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = p_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out<<=m); }.
	Do not add (*in>>n) as in this specialization, in2 may be past the boundary.
			template<typename RWIterator, typename RIterator>
			static void no_return(RWIterator out, RIterator in, size_type m, size_type n)
			{
				(*out<<=m)+=(*in>>n);
				unroll<N-1>::assign::left_shift::no_return(--out, --in, m, n);
			}

			template<typename RWIterator, typename RIterator>
			static RWIterator with_return(RWIterator out, RIterator in, size_type m, size_type n)
			{
				(*out<<=m)+=(*in>>n);
				return unroll<N-1>::assign::left_shift::with_return(--out, --in, m, n);
			}
*/
		};
	};
};

template<size_type M, size_type L>
struct unroll<0, M, L>
{
	struct left_shift
	{
/*
	Does not perform adding (*in2>>n) as in2 may be past the boundary.
		template<typename WIterator, typename RIterator1, typename RIterator2>
		static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, size_type m, size_type n)
			{ }

		template<typename WIterator, typename RIterator1, typename RIterator2>
		static WIterator with_return(WIterator out,
			RIterator1 in1, RIterator2 in2, size_type m, size_type n)
				{ return out; }
*/
	};

	struct assign
	{
		struct left_shift
		{
/*
		Does not perform adding (*in>>n) as in2 may be past the boundary.
			template<typename RWIterator, typename RIterator>
			static void no_return(RWIterator out, RIterator in, size_type m, size_type n)
				{ }

			template<typename RWIterator, typename RIterator>
			static RWIterator with_return(RWIterator out, RIterator in, size_type m, size_type n)
				{ return out; }
*/
		};
	};
};
