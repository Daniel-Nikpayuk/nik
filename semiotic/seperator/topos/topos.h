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

#ifndef SEMIOTIC_SEPERATOR_TOPOS_H
#define SEMIOTIC_SEPERATOR_TOPOS_H

/*
	Ideally define the pointer before the structure, and define the memory structure in terms of the pointer,
	but given the constraints of C++ grammar it seems it must be done this way.

	Derivations of const_iterator from this codepoint require the container to be constant (this implicitly includes
	its value references as well as its linkages, depending on the data structure). The iterator itself is not constant.
	Regarding methods such as "insert" and "erase" that take const_iterators in the STL standard, the reason being is that
	the iterator itself might be intended to not modify the container, but passing it---and even calling in the first
	place---to methods such as "insert" imply the container itself is intended to be modifiable. In which case, the
	interpretation which is privileged is that the iterator serves as nothing more than communicating a position within
	the container (mediator). This is why "insert" and "erase" accept const_iterator.
*/

namespace nik
{
	namespace semiotic
	{
		namespace seperator
		{
/*
	topos_traits:
*/
			template<typename T, typename ToposType, typename SizeType>
			struct topos_traits
			{
				typedef T value_type;
				typedef T& reference;
				typedef ToposType topos_type;
				typedef ToposType* address;
				typedef SizeType size_type;
			};
/*
	topos:
		Generic dynamic topos.

			template<typename T, unsigned M, unsigned N>
			struct topos
			{
				typedef topos_traits<T> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::const_reference const_reference;

				T *value;
				topos **edge;

				topos1( e0) : edge0(e0) { }
			};
				topos1(const value_type & v, address e0) :
					value(v), edge0(e0) { }
				topos1(const topos1 & n) :
					value(n.value), edge0(n.edge0) { }
				const_reference operator = (const topos1 & n)
				{
					value=n.value;
					edge0=n.edge0;
					return *this;
				}
				~topos1() { }
*/
/*
	topos0:
		I don't know if this will actually be of any use, but I've included it just in case it ever is.
*/
			template<typename T, typename SizeType=size_t>
			struct topos0
			{
				typedef topos_traits<T,topos0,SizeType> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::topos_type topos_type;
				typedef typename traits::address address;
				typedef typename traits::size_type size_type;

				value_type value;

				topos0() { }
				topos0(const value_type & v) :
					value(v) { }
				topos0(const topos0 & t) :
					value(t.value) { }
				const topos0 & operator = (const topos0 & t)
				{
					value=t.value;
					return *this;
				}
				~topos0() { }
			};
/*
	topos1:
*/
			template<typename T, typename SizeType=size_t>
			struct topos1
			{
				typedef topos_traits<T,topos1,SizeType> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::topos_type topos_type;
				typedef typename traits::address address;
				typedef topos_pointer<topos1> pointer;
				typedef topos_pointer<topos1 const> const_pointer;
				typedef typename traits::size_type size_type;

				value_type value;
				address edge0;

				topos1() { }
				topos1(const value_type & v) :
					value(v) { }
				topos1(address e0) :
					edge0(e0) { }
				topos1(const value_type & v, address e0) :
					value(v), edge0(e0) { }
				topos1(const topos1 & t) :
					value(t.value), edge0(t.edge0) { }
				const topos1 & operator = (const topos1 & t)
				{
					value=t.value;
					edge0=t.edge0;
					return *this;
				}
				~topos1() { }
			};
/*
	topos2:
*/
			template<typename T, typename SizeType=size_t>
			struct topos2
			{
				typedef topos_traits<T,topos2,SizeType> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::topos_type topos_type;
				typedef typename traits::address address;
				typedef topos_pointer<topos2> pointer;
				typedef topos_pointer<topos2 const> const_pointer;
				typedef typename traits::size_type size_type;

				value_type value;
				address edge0;
				address edge1;

				topos2() { }
				topos2(const value_type & v) :
					value(v) { }
				topos2(address e0, address e1) :
					edge0(e0), edge1(e1) { }
				topos2(const value_type & v, address e0, address e1) :
					value(v), edge0(e0), edge1(e1) { }
				topos2(const topos2 & t) :
					value(t.value), edge0(t.edge0), edge1(t.edge1) { }
				const topos2 & operator = (const topos2 & t)
				{
					value=t.value;
					edge0=t.edge0;
					edge1=t.edge1;
					return *this;
				}
				~topos2() { }
			};
/*
	topos3:
*/
			template<typename T, typename SizeType=size_t>
			struct topos3
			{
				typedef topos_traits<T,topos3,SizeType> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::topos_type topos_type;
				typedef typename traits::address address;
				typedef typename traits::size_type size_type;

				value_type value;
				address edge0;
				address edge1;
				address edge2;

				topos3() { }
				topos3(const value_type & v) :
					value(v) { }
				topos3(address e0, address e1, address e2) :
					edge0(e0), edge1(e1), edge2(e2) { }
				topos3(const value_type & v, address e0, address e1, address e2) :
					value(v), edge0(e0), edge1(e1), edge2(e2) { }
				topos3(const topos3 & t) :
					value(t.value), edge0(t.edge0), edge1(t.edge1), edge2(t.edge2) { }
				const topos3 & operator = (const topos3 & t)
				{
					value=t.value;
					edge0=t.edge0;
					edge1=t.edge1;
					edge2=t.edge2;
					return *this;
				}
				~topos3() { }
			};
/*
	topos4:
*/
			template<typename T, typename SizeType=size_t>
			struct topos4
			{
				typedef topos_traits<T,topos4,SizeType> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::topos_type topos_type;
				typedef typename traits::address address;
				typedef typename traits::size_type size_type;

				value_type value;
				address edge0;
				address edge1;
				address edge2;
				address edge3;

				topos4() { }
				topos4(const value_type & v) :
					value(v) { }
				topos4(address e0, address e1, address e2, address e3) :
					edge0(e0), edge1(e1), edge2(e2), edge3(e3) { }
				topos4(const value_type & v, address e0, address e1, address e2, address e3) :
					value(v), edge0(e0), edge1(e1), edge2(e2), edge3(e3) { }
				topos4(const topos4 & t) :
					value(t.value), edge0(t.edge0), edge1(t.edge1), edge2(t.edge2), edge3(t.edge3) { }
				const topos4 & operator = (const topos4 & t)
				{
					value=t.value;
					edge0=t.edge0;
					edge1=t.edge1;
					edge2=t.edge2;
					edge3=t.edge3;
					return *this;
				}
				~topos4() { }
			};
/*
	topos5:
*/
			template<typename T, typename SizeType=size_t>
			struct topos5
			{
				typedef topos_traits<T,topos5,SizeType> traits;
				typedef typename traits::value_type value_type;
				typedef typename traits::reference reference;
				typedef typename traits::topos_type topos_type;
				typedef typename traits::address address;
				typedef typename traits::size_type size_type;

				value_type value;
				address edge0;
				address edge1;
				address edge2;
				address edge3;
				address edge4;

				topos5() { }
				topos5(const value_type & v) :
					value(v) { }
				topos5(address e0, address e1, address e2, address e3, address e4) :
					edge0(e0), edge1(e1), edge2(e2), edge3(e3), edge4(e4) { }
				topos5(const value_type & v, address e0, address e1, address e2, address e3, address e4) :
					value(v), edge0(e0), edge1(e1), edge2(e2), edge3(e3), edge4(e4) { }
				topos5(const topos5 & t) :
					value(t.value), edge0(t.edge0), edge1(t.edge1), edge2(t.edge2), edge3(t.edge3), edge4(t.edge4) { }
				const topos5 & operator = (const topos5 & t)
				{
					value=t.value;
					edge0=t.edge0;
					edge1=t.edge1;
					edge2=t.edge2;
					edge3=t.edge3;
					edge4=t.edge4;
					return *this;
				}
				~topos5() { }
			};
		}
	}
}

#endif
