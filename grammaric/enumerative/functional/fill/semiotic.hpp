/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename Ordering, typename inL, typename outL = typename inL::null>
struct fill;

template<typename Ordering, Parameter... out_params>
struct fill<Ordering, null_list, list<out_params...>>
{
	using field = typename Ordering::car::type;
	static constexpr Parameter field_first = field::car::value;

	using new_outL = typename push<list<out_params...>, field_first>::type;

	//

	using type = typename fill<typename Ordering::cdr::type, null_list, new_outL>::type;
};

template<typename Ordering, Parameter in_first, Parameter... in_params, Parameter... out_params>
struct fill<Ordering, list<in_first, in_params...>, list<out_params...>>
{
	using field = typename Ordering::car::type;
	static constexpr Parameter field_first = field::car::value;

	using new_inL = typename if_then_else
	<
		contains<field, in_first>::value,
		list<in_params...>,
		list<in_first, in_params...>

	>::type;

	using new_outL = typename if_then_else
	<
		contains<field, in_first>::value,
		typename push<list<out_params...>, in_first>::type,
		typename push<list<out_params...>, field_first>::type

	>::type;

	//

	using type = typename fill<typename Ordering::cdr::type, new_inL, new_outL>::type;
};

template<Parameter... in_params, Parameter... out_params>
struct fill<null_tuple, list<in_params...>, list<out_params...>>
{
	using type = list<out_params...>;
};

/*
template<typename inL, typename Ordering, typename outL = typename inL::null, typename Null = typename Ordering::null>
struct fill
{
	using set = typename Ordering::car;

	//

	template<typename in, typename inNull = typename in::null>
	struct safe_new_out
	{
		using type = typename if_then_else
		<
			isMember<set, in::car>::type,
			typename outL::template append<in::car>,
			typename outL::template append<set::car>

		>::type;
	};

	template<typename inNull>
	struct safe_new_out<inNull, inNull>
	{
		using type = typename outL::template append<set::car>;
	};

	using new_outL = typename safe_new_out<inL>::type;

	//

	template<typename in, typename inNull = typename in::null>
	struct safe_new_in
	{
		using type = typename if_then_else
		<
			isMember<set, in::car>::type,
			typename in::cdr,
			in

		>::type;
	};

	template<typename inNull>
	struct safe_new_in<inNull, inNull>
	{
		using type = inNull;
	};

	using new_inL = typename safe_new_in<inL>::type;

	//

	using type = typename fill<new_inL, typename Ordering::cdr, new_outL>::type;
};

template<typename inL, typename Null, typename outL>
struct fill<inL, Null, outL, Null>
{
	using type = outL;
};
*/

