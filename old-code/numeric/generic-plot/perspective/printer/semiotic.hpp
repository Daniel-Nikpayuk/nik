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

template<typename sub_policy>
struct printer
{
	using method = generic<sub_policy>;

	struct pr_verb
	{
		template<typename sub_type>
		inline void main_action(sub_type sub)
		{
			builtin_printer::print(*sub);
			builtin_printer::print(' ');
		}

		template<typename sub_type>
		inline void last_action(sub_type sub)
		{
			builtin_printer::print(*sub);
			builtin_printer::print('\n');
		}
	};

		// print:

	template<typename sub_type>
	static void print(sub_type sub, sub_type end)
	{
		pr_verb pr;

		method::repeat(pr, sub, end);
	}
};

