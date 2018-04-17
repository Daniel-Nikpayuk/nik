/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Keep in mind the interpretation of open and closed ends of an interval have different structural interpretations
	than functional. Functional means: if open, don't act on that element, you can still navigate it; if closed,
	both act on it as well as navigate it. Structural means: if open, its content is not relevant, so if you're
	growing it, discard; if closed, its content is relevant, so if you're growing, keep.
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Shrink
{
	enum struct Manner : size_type
	{
		fixer,

		dimension
	};

	using Selection = tuple
	<
		adv_list<Connotation::after, Connotation::before, Connotation::between>			// fixer
	>;

	template<Connotation... params>
	using verb = Adverb<typename sortFill<Selection, Connotation, params...>::rtn>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define AFTER			adv_list<Connotation::after>
#define BEFORE			adv_list<Connotation::before>
#define BETWEEN			adv_list<Connotation::between>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							segment
************************************************************************************************************************/


template
<
	typename pointer
>
static void shrink(const Adverb<AFTER> & adv, pointer & out, size_type length, size_type n)
{
	pointer	tmp;
	size_type size = length - n;

	typename Map::template verb<> assign;
	auto allocate = typename Map::template subject<Association::allocate>::with(size);
	auto deallocate = typename Map::template object<>::with(out);

	map(assign, tmp, allocate, out, out + size, deallocate);

	out = tmp;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void shrink(const Adverb<BEFORE> & adv, pointer & out, size_type length, size_type n)
{
	pointer	tmp;

	typename Map::template verb<> assign;
	auto allocate = typename Map::template subject<Association::allocate>::with(length - n);
	auto deallocate = typename Map::template object<>::with(out);

	map(assign, tmp, allocate, out + n, out + length, deallocate);

	out = tmp;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static void shrink(const Adverb<BETWEEN> & adv, pointer & out, size_type length, size_type n, size_type offset = 0)
{
	pointer	tmp;

	typename Map::template verb<> assign;

	typename Map::template subject<> mutate;
	auto allocate = mutate.with(length - n);

	typename Map::template object<> immutate;
	auto deallocate = immutate.with(out);

	pointer outset = out + offset;

	map(assign,
		map(assign, tmp, allocate, out, outset, immutate),
		mutate, outset + n, out + length, deallocate);

	out = tmp;
}


/***********************************************************************************************************************/


#undef AFTER
#undef BEFORE
#undef BETWEEN


