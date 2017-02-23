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

template<typename Exp>
struct is_variable
{
	using rtn = typename Or
	<
		equal<Exp, a>,
		equal<Exp, b>,
		equal<Exp, c>,
		equal<Exp, d>,
		equal<Exp, e>,

		equal<Exp, f>,
		equal<Exp, g>,
		equal<Exp, h>,
		equal<Exp, i>,
		equal<Exp, j>,

		equal<Exp, k>,
		equal<Exp, l>,
		equal<Exp, m>,
		equal<Exp, n>,
		equal<Exp, o>,

		equal<Exp, p>,
		equal<Exp, q>,
		equal<Exp, r>,
		equal<Exp, s>,
		equal<Exp, t>,

		equal<Exp, u>,
		equal<Exp, v>,
		equal<Exp, w>,
		equal<Exp, x>,
		equal<Exp, y>,

		equal<Exp, z>

	>::rtn;
};

