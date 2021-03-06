/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	cond_to_if_:

	Assumes the "cond" tag has been removed.
*/

	template<typename Expressions>
	struct cond_to_if_
	{
		using Clauses = typename Expressions::rtn;

		template<typename Exp1, typename Exp2>
		struct recurse
		{
			using first = typename Exp1::rtn;
			using rest = typename Exp2::rtn;

			using rtn = typename if_then_else
			<
				is_tagged<first, else_>,

				if_then_else
				<
					is_null<rest>,
					begin_sequence_to_expression<first>,
					error_else_clause_not_last
				>,

				if__make
				<
					car<first, one>, // cond_predicate

					begin_sequence_to_expression
					<
						cdr<first, one> // cond_actions
					>,

					cond_to_if_<rest>
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Clauses>,
			boolean<false>,

			recurse
			<
				car<Clauses>,
				cdr<Clauses>
			>

		>::rtn;
	};

