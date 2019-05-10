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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, perspective, kernel, structure)

	#include nik_typedef(symbolic, kernel, core, functor)

/*
	memoized_conditional:
*/

	template<bool True, typename Filler = void>
	struct memoized_conditional
	{
		template
		<
			typename Ante, typename Conse

		> using project = Ante;

		template
		<
			template<typename> class signature,

			typename Ante, typename Conse

		> using left_inject = signature<Ante>;

		template
		<
			template<typename> class signature,

			typename Ante, typename... Conses

		> using right_inject = Ante;

		template
		<
			template<typename> class ante_signature,

			typename Ante,

			template<typename> class conse_signature,

			typename Conse

		> using inject = ante_signature<Ante>;

		template
		<
			template<typename> class ante_signature,

			template<typename> class conse_signature,

			typename Exp

		> using coinject = ante_signature<Exp>;
	};

	template<typename Filler>
	struct memoized_conditional<false, Filler>
	{
		template
		<
			typename Ante, typename Conse

		> using project = Conse;

		template
		<
			template<typename> class signature,

			typename Ante, typename Conse

		> using left_inject = Conse;

		template
		<
			template<typename> class signature,

			typename Ante, typename... Conses

		> using right_inject = signature<Conses...>;

		template
		<
			template<typename> class ante_signature,

			typename Ante,

			template<typename> class conse_signature,

			typename Conse

		> using inject = conse_signature<Conse>;

		template
		<
			template<typename> class ante_signature,

			template<typename> class conse_signature,

			typename Exp

		> using coinject = conse_signature<Exp>;
	};

//	#include nik_typedef(symbolic, calculus, product, functor)

/*
	echoed:

	better to use (Pred ? Ante : Conse) grammar directly.
*/

	template<typename Type>
	static constexpr Type echoed_if_then_else(bool Pred, Type Ante, Type Conse)
	{
		return (Pred ? Ante : Conse);
	}

/*
	pinged:
*/

	template<bool Pred, typename Ante, typename Conse>
	using pinged_if_then_else = typename memoized_conditional<Pred>::template project
	<
		Ante, Conse
	>;

/*
	called:
*/

	template<bool Pred, typename Ante, typename Conse>
	using called_if_then_else = call
	<
		pinged_if_then_else<Pred, Ante, Conse>
	>;

	template<bool Pred, typename Ante, typename Conse>
	using head_if_then_else = typename memoized_conditional<Pred>::template left_inject
	<
		call, Ante,
		Conse
	>;

	template<bool Pred, typename Ante, typename Conse>
	using tail_if_then_else = typename memoized_conditional<Pred>::template right_inject
	<
		Ante,
		call, Conse
	>;
};

