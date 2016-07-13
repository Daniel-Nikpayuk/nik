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

template<unsigned... Args>
struct Parameters { };

typedef Parameters<> Null;

/************************************************************************************************************************/

template<unsigned count, typename P>
struct Size { };

template<unsigned count, unsigned current, unsigned... Args>
struct Size<count, Parameters<current, Args...> >
{
	static constexpr unsigned result = Size<count+1, Parameters<Args...> >::result;
};

template<unsigned count>
struct Size<count, Parameters<> >
{
	static constexpr unsigned result = count;
};

/************************************************************************************************************************/

template<unsigned N, typename P>
struct Array { };


template<unsigned N, unsigned... Args>
struct Array<N, Parameters<Args...> >
{
	static constexpr unsigned size = N;
	static constexpr unsigned names[size] { Args... };
};

/************************************************************************************************************************/

template<unsigned current, typename P>
struct Cons { };

template<unsigned current, unsigned... Args>
struct Cons<current, Parameters<Args...> >
{
	typedef Parameters<current, Args...> Return;
};

/************************************************************************************************************************/

template<unsigned current, typename P>
struct Append { };

template<unsigned current, unsigned... Args>
struct Append<current, Parameters<Args...> >
{
	typedef Parameters<Args..., current> Return;
};

/************************************************************************************************************************/

template<typename P1, unsigned current, typename P2>
struct Catenate { };

template<unsigned... Args1, unsigned current, unsigned... Args2>
struct Catenate<Parameters<Args1...>, current, Parameters<Args2...> >
{
	typedef Parameters<Args1..., current, Args2...> Return;
};

/************************************************************************************************************************/

template<unsigned test, typename filtered, typename unfiltered>
struct FilterLessThanOrEqual { };

template<unsigned test, typename filtered, unsigned current, unsigned... Args>
struct FilterLessThanOrEqual<test, filtered, Parameters<current, Args...> >
{
	typedef typename if_then_else
		<
			(current <= test),
			typename Append<current, filtered>::Return,
			filtered
		>::return_type Filtered;

	typedef typename FilterLessThanOrEqual<test, Filtered, Parameters<Args...> >::Return Return;
};

template<unsigned test, typename filtered>
struct FilterLessThanOrEqual<test, filtered, Parameters<> >
{
	typedef filtered Return;
};

/************************************************************************************************************************/

template<unsigned test, typename filtered, typename unfiltered>
struct FilterGreaterThanOrEqual { };

template<unsigned test, typename filtered, unsigned current, unsigned... Args>
struct FilterGreaterThanOrEqual<test, filtered, Parameters<current, Args...> >
{
	typedef typename if_then_else
		<
			(current >= test),
			typename Append<current, filtered>::Return,
			filtered
		>::return_type Filtered;

	typedef typename FilterGreaterThanOrEqual<test, Filtered, Parameters<Args...> >::Return Return;
};

template<unsigned test, typename filtered>
struct FilterGreaterThanOrEqual<test, filtered, Parameters<> >
{
	typedef filtered Return;
};

/************************************************************************************************************************/

template<typename P>
struct QuickSort { };

template<unsigned current, unsigned... Args>
struct QuickSort<Parameters<current, Args...> >
{
	typedef Parameters<Args...> CDR;

	typedef typename FilterLessThanOrEqual<current, Null, CDR>::Return LTOE;
	typedef typename QuickSort<LTOE>::Return LeftSorted;

	typedef typename FilterGreaterThanOrEqual<current, Null, CDR>::Return GTOE;
	typedef typename QuickSort<GTOE>::Return RightSorted;

	typedef typename Catenate<LeftSorted, current, RightSorted>::Return Return;
};

template<>
struct QuickSort<Parameters<> >
{
	typedef Parameters<> Return;
};

