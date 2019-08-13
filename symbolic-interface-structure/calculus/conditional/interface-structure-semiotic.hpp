/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	using kind		= module;

	using rtn		= structure;

/*
	memoized_conditional:
*/

	template<bool True, typename Filler = void>
	struct memoized_conditional
	{
		using rtn = memoized_conditional;

		template
		<
			typename Ante, typename Conse

		> using reflex = Ante;

		template
		<
			template<typename> class signature,

			typename Ante, typename Conse

		> using left_transit = signature<Ante>;

		template
		<
			template<typename> class signature,

			typename Ante, typename... Conses

		> using right_transit = Ante;

/*
		template
		<
			template<typename> class ante_signature,

			typename Ante,

			template<typename> class conse_signature,

			typename Conse

		> using transit = ante_signature<Ante>;

		template
		<
			template<typename> class ante_signature,

			template<typename> class conse_signature,

			typename Exp

		> using cotransit = ante_signature<Exp>;
*/
	};

	template<typename Filler>
	struct memoized_conditional<false, Filler>
	{
		using rtn = memoized_conditional;

		template
		<
			typename Ante, typename Conse

		> using reflex = Conse;

		template
		<
			template<typename> class signature,

			typename Ante, typename Conse

		> using left_transit = Conse;

		template
		<
			template<typename> class signature,

			typename Ante, typename... Conses

		> using right_transit = signature<Conses...>;

/*
		template
		<
			template<typename> class ante_signature,

			typename Ante,

			template<typename> class conse_signature,

			typename Conse

		> using transit = conse_signature<Conse>;

		template
		<
			template<typename> class ante_signature,

			template<typename> class conse_signature,

			typename Exp

		> using cotransit = conse_signature<Exp>;
*/
	};
};

