/************************************************************************************************************************
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
************************************************************************************************************************/


template
<
	typename traits,
	size_type inMemory = traits::in_memory,
	size_type inPointer = traits::in_pointer

> struct objectArgs { };


/***********************************************************************************************************************/


template<typename traits, size_type inPointer>
struct objectArgs<traits, ArgPointer::mutate, inPointer>
{
	typedef typename traits::in_type in_type;

	in_type inr;
	in_type endr;

	objectArgs(in_type i, in_type e) : inr(i), endr(e) { }

	objectArgs(const objectArgs & args) : inr(args.inr), endr(args.endr) { }
};


/***********************************************************************************************************************/


template<typename traits>
struct objectArgs<traits, ArgPointer::deallocate, ArgPointer::segment>
{
	typedef typename traits::in_type in_type;

	in_type originr;
	in_type inr;
	in_type endr;

	objectArgs(in_type o, in_type i, in_type e) : originr(o), inr(i), endr(e) { }

	objectArgs(const objectArgs & args) : inr(args.inr), endr(args.endr) { }
};


