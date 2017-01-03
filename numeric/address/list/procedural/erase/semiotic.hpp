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

/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
*/

template<typename WPointer>
static void erase(<deject>, WPointer out)
{
	++out;
	delete -out;
	-out=0;
}

/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/

template<typename WPointer, typename ERPointer>
static void erase(<deject>, WPointer out, ERPointer end)
{
	-last=0;
	while ((first=+first) != last) delete (-first);
	delete (-first);
}

/*
	Assumes 't' is the original back: detaches 't'; deletes 't'; returns the new back.

	Does not detach new back from original back resulting in a dangling pointer.
*/

template<typename WPointer>
static void erase(<reject>, WPointer out)
{
	t=-t;
	delete (+t);
	+t=0;
}

/*
	Pops everything from first to last while returning before first.

	Assumes last is the proper back.  No need for generic Iterator as you are erasing from a given structure.
*/

template<typename WPointer, typename ERPointer>
static void erase(<reject>, WPointer out, ERPointer end)
{
	RPointer rtn=-first;
	+rtn=0;
	while ((first=+first) != last) delete (-first);
	delete (-first);
	delete first;
}

/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
*/

template<typename WPointer, typename ERPointer>
static void erase(<reject, apply_count>, WPointer out, ERPointer end)
{
	RPointer rtn=-first;
	+rtn=0;
	for (--count; (first=+first) != last; --count) delete (-first);
	delete (-first);
	delete first;
}

template<typename WPointer>
static WPointer erase(<eject>, WPointer out)
{
	WPointer in=+(+out);
	delete +out;
	+out=in;

	return in;
}

template<typename WPointer, typename EWPointer>
static WPointer erase(<eject>, WPointer out, EWPointer end)
{
	clear::no_return(+out, end);
	+out=end;

	return end;
}

