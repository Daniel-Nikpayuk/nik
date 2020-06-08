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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

		// The following bool value pattern matcher is here as its induction operator requires its own specialization.

	template<auto, typename = filler>
	struct pattern_match_bool_judgment
	{
		// match: id.

			// symbolic:

				template
				<
					typename Continuation, template<typename> class Memoizer
				>
			using s_match_induct = typename Continuation::template result
					<
						Memoizer, bool, false
					>;

			// assemblic:

				template
				<
					typename Continuation, typename Image
				>
			static constexpr Image a_match_induct = Continuation::template result
					<
						Image, bool, false
					>;
	};

	template<typename Filler>
	struct pattern_match_bool_judgment<true, Filler>
	{
		// match: id.

			// symbolic:

				template
				<
					typename Continuation, template<typename> class Memoizer
				>
			using s_match_induct = typename Continuation::template result
					<
						Memoizer, bool, true
					>;

			// assemblic:

				template
				<
					typename Continuation, typename Image
				>
			static constexpr Image a_match_induct = Continuation::template result
					<
						Image, bool, true
					>;

		// induct:

			// symbolic:

				template
				<
					typename Continuation, template<typename> class Memoizer,

					typename Antecedent, typename Consequent
				>
			using s_induct = typename Continuation::template result
					<
						Memoizer, Antecedent
					>;

			// assemblic:

				// not implemented as it's better to use the native C++ ( ? : ) grammar.
	};

	template<typename Filler>
	struct pattern_match_bool_judgment<false, Filler>
	{
		// match: id.

			// symbolic:

				template
				<
					typename Continuation, template<typename> class Memoizer
				>
			using s_match_induct = typename Continuation::template result
					<
						Memoizer, bool, true
					>;

			// assemblic:

				template
				<
					typename Continuation, typename Image
				>
			static constexpr Image a_match_induct = Continuation::template result
					<
						Image, bool, true
					>;

		// induct:

			// symbolic:

				template
				<
					typename Continuation, template<typename> class Memoizer,

					typename Antecedent, typename Consequent
				>
			using s_induct = typename Continuation::template result
					<
						Memoizer, Consequent
					>;

			// assemblic:

				// not implemented as it's better to use the native C++ ( ? : ) grammar.
	};
};
