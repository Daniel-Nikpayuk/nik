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

template<typename indexer, typename dispatcher, typename out, typename in>
struct fill { };

//

template<typename indexer, typename dispatcher, typename out, size_type current, size_type... params>
struct fill<indexer, dispatcher, out, mlist<current, params...> >
{
	static constexpr size_type index = indexer<out>::rtn;
	static constexpr size_type dispatch = dispatcher<current>::rtn;

	using appended = typename append<mapped, out>::rtn;

	using rtn = typename fill<dispatch, appended, mlist<params...> >::rtn;
};

template<size_type index>
struct fill<index, null_mlist>
{
	using rtn = null_mlist;
};

