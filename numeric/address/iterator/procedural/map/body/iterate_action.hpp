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


template<typename pointer, size_type intervalEnum, size_type iteratorEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::mutate, iteratorEnum>> & adj)
{
	++p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::allocate, Association::segment>> & adj)
{
	++p;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::allocate, Association::hook>> & adj)
{
	p = +p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::allocate, Association::link>> & adj)
{
	+p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	-+p = p;
	++p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::deallocate, Association::segment>> & adj)
{
	++p;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::deallocate, Association::hook>> & adj)
{
	delete p++;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::forward, intervalEnum, Association::deallocate, Association::link>> & adj)
{
	delete -++p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum, size_type iteratorEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::mutate, iteratorEnum>> & adj)
{
	--p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::allocate, Association::segment>> & adj)
{
	--p;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::allocate, Association::hook>> & adj)
{
	pointer tmp = p;
	p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	+p = tmp;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::allocate, Association::link>> & adj)
{
	-p = new typename structural<nik::semiotic>::template trim<pointer>::pointer;
	+-p = p;
	--p;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::deallocate, Association::segment>> & adj)
{
	--p;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::deallocate, Association::hook>> & adj)
{
	delete p--;
}


template<typename pointer, size_type intervalEnum>
static void iterate_action(pointer & p,
	const _adjective<LIST<Association::backward, intervalEnum, Association::deallocate, Association::link>> & adj)
{
	delete +--p;
}


