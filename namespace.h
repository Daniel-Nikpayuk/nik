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

namespace nik
{
	enum Interval { closed=0, closing, open, opening };

	enum MapPolicy
	{
		out_as_closing,
		out_as_closed,
		out_as_opening,
		out_as_open,

		out_as_forward,
		out_as_backward,

		in_as_closing,
		in_as_closed,
		in_as_opening,
		in_as_open,

		in_as_forward,
		in_as_backward,

		omit_delete,
		apply_delete,

		omit_count,
		apply_count
	};

/*
	enum MapPolicy
	{
		omit_return,
		apply_return,

		omit_consume,
		apply_consume,

		omit_count,
		apply_count,

		out_as_closing,
		out_as_closed,
		out_as_opening,
		out_as_open,

		omit_reverse,
		apply_reverse,

		in_as_closing,
		in_as_closed,
		in_as_opening,
		in_as_open,

		omit_backward,
		apply_backward
	};
*/
}

