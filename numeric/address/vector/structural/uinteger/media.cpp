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
	Given the unsafe nature of semiotic::vector policy here is composability instead of inheritance.

	Test against self-assignment!
*/

/*
	The design of uinteger requires deciding whether or not the base of representation should be part of the template
	parameter or a modifiable member within the class.

	If it were a modifiable member, then uinteger would require native support for base conversion, whereas if it were
	a template parameter, to change base would be to instantiate a new template class with the new base and convert. At the
	same time, conversion itself is built upon basic operators such as addition and multiplication of these uinteger
	objects. Such operations break the rule of simplicity (type dispatches increase complexity and decrease efficiency).

	Given these considerations I have decided to add the base as a template parameter.
*/

/*
	uinteger:
		Need to fix the BlockSize calculation to account for a BitLength which isn't divisible by the c_policy::unit::length.
		For example one could round up to the nearest multiple of the c_policy::unit::length.

		It actually might be worthwhile keeping BlockSize as a separate template parameter, as it is possible someone
		might want to subclass this and come up with their own BlockSize for their own reason.
*/

template<size_type BitLength, size_type BlockSize=BitLength/c_policy::unit::length>
class uinteger : protected semiotic::iterator::uinteger<size_type, size_type, BlockSize>
{
	protected:
		friend c_policy; 
		friend s_policy; 
		friend m_policy; 
	protected:
		typedef semiotic::iterator::uinteger<size_type, size_type, BlockSize> subuinteger;
		typedef typename subuinteger::value_type value_type;
		typedef typename subuinteger::reference reference;
		typedef typename subuinteger::const_reference const_reference;
		typedef typename subuinteger::pointer pointer;
		typedef typename subuinteger::const_pointer const_pointer;
		typedef typename subuinteger::iterator iterator;
		typedef typename subuinteger::const_iterator const_iterator;
	public:
		static const size_type dimension=BlockSize;
/*
	Note: A null-initialization does not set the initial value (to 0 or otherwise).
*/
		uinteger() : subuinteger() { }
		uinteger(size_type n) : subuinteger()
		{
			*subuinteger::array=n;
			s_policy::template fwd_comp_unroll<dimension-1>::
				repeat::no_return(subuinteger::array+1, (value_type) 0);
		}
		uinteger(const uinteger & b) : subuinteger(b) { }
		const uinteger operator = (const uinteger & b)
		{
			subuinteger::terminalize();
			subuinteger::copy(b);

			return *this;
		}
	public:
			// iterators:
		iterator begin()
			{ return subuinteger::array; }
		const_iterator begin() const
			{ return subuinteger::array; }
		const_iterator cbegin() const
			{ return subuinteger::array; }
		iterator end()
			{ return subuinteger::array+dimension; }
		const_iterator end() const
			{ return subuinteger::array+dimension; }
		const_iterator cend() const
			{ return subuinteger::array+dimension; }
	public:
		bool operator == (const uinteger & b) const
		{
			return s_policy::template fwd_arit_unroll<dimension>::
				equal::fast::with_break(subuinteger::array, b.array);
		}
		bool operator != (const uinteger & b) const
		{
			return s_policy::template fwd_arit_unroll<dimension>::
				not_equal::fast::with_break(subuinteger::array, b.array);
		}
		bool operator < (const uinteger & b) const
		{
			return s_policy::template bwd_arit_unroll<dimension>::
				less_than::fast_break(subuinteger::array+(dimension-1), b.array+(dimension-1));
		}
		bool operator <= (const uinteger & b) const
		{
			return s_policy::template bwd_arit_unroll<dimension>::
				less_than_or_equal::fast_break(subuinteger::array+(dimension-1), b.array+(dimension-1));
		}
		bool operator > (const uinteger & b) const
		{
			return s_policy::template bwd_arit_unroll<dimension>::
				greater_than::fast_break(subuinteger::array+(dimension-1), b.array+(dimension-1));
		}
		bool operator >= (const uinteger & b) const
		{
			return s_policy::template bwd_arit_unroll<dimension>::
				greater_than_or_equal::fast_break(subuinteger::array+(dimension-1), b.array+(dimension-1));
		}
	public:
/*
	m is the bit length, not the array length.
*/
		const uinteger & operator <<= (size_type m)
		{
			size_type arr_dim(m/c_policy::unit::length);
			if (arr_dim >= dimension)
			{
				s_policy::template fwd_comp_unroll<dimension>::repeat(subuinteger::array, (value_type) 0);

				return *this;
			}

			size_type bit_dim(m%c_policy::unit::length);
			typename subuinteger::iterator b=subuinteger::array+(dimension-1);
			if (arr_dim)
			{
				typename subuinteger::const_iterator e=subuinteger::array-1;
				m_policy::bwd_arit::left_shift::no_return(b, e, b-arr_dim, e, bit_dim);
			}
			else m_policy::template bwd_arit_unroll<dimension, dimension>::assign::left_shift::no_return(b, bit_dim);

			return *this;
		}
/*
	m is the bit length, not the array length.
*/
		const uinteger & operator >>= (size_type m) const
		{
			size_type arr_dim(m/c_policy::unit::length);
			if (arr_dim >= dimension)
			{
				s_policy::template fwd_comp_unroll<dimension>::repeat(subuinteger::array, (value_type) 0);

				return *this;
			}

			size_type bit_dim(m%c_policy::unit::length);
			if (arr_dim)
			{
				typename subuinteger::const_iterator e=subuinteger::array+(dimension-1);
				m_policy::fwd_arit::right_shift::
					no_return(subuinteger::array, e, subuinteger::array+arr_dim, e, bit_dim);
			}
			else m_policy::template fwd_arit_unroll<dimension, dimension>::
				assign::right_shift::no_return(subuinteger::array, bit_dim);

			return *this;
		}
/*
	m is the bit length, not the array length.
*/
		uinteger operator << (size_type m) const
		{
			uinteger out;
			size_type arr_dim(m/c_policy::unit::length);
			if (arr_dim >= dimension)
			{
				s_policy::template fwd_comp_unroll<dimension>::repeat(out, (value_type) 0);

				return out;
			}

			size_type bit_dim(m%c_policy::unit::length);
			typename subuinteger::iterator b=out+(dimension-1);
			if (arr_dim)
			{
				typename subuinteger::const_iterator e=out-1;
				m_policy::bwd_arit::left_shift::no_return(b, e, b-arr_dim, e, bit_dim);
			}
			else m_policy::template bwd_arit_unroll
				<dimension, dimension>::assign::left_shift::no_return(b, bit_dim);

			return out;
		}
/*
	m is the bit length, not the array length.
*/
		uinteger operator >> (size_type m) const
		{
			uinteger out;
			size_type arr_dim(m/c_policy::unit::length);
			if (arr_dim >= dimension)
			{
				s_policy::template fwd_comp_unroll<dimension>::repeat(out, (value_type) 0);

				return out;
			}

			size_type bit_dim(m%c_policy::unit::length);
			if (arr_dim)
			{
				typename subuinteger::const_iterator e=out+(dimension-1);
				m_policy::fwd_arit::right_shift::no_return(out, e, out+arr_dim, e, bit_dim);
			}
			else m_policy::template fwd_arit_unroll
				<dimension, dimension>::assign::right_shift::no_return(out, bit_dim);

			return out;
		}
	public:
		uinteger operator + (const uinteger & b) const
		{
			uinteger out;
			m_policy::template fwd_arit_unroll<dimension>::plus::no_return(out.array, subuinteger::array, b.array);

			return out;
		}

		uinteger operator - (const uinteger & b) const
		{
			uinteger out;
			m_policy::template fwd_arit_unroll<dimension>::minus::no_return(out.array, subuinteger::array, b.array);

			return out;
		}

		uinteger operator * (size_type b) const
		{
			uinteger out;
			m_policy::template fwd_arit_unroll<dimension>::scale::no_return(out.array, subuinteger::array, b);

			return out;
		}

		uinteger operator * (const uinteger & b) const
		{
			uinteger out, tmp;
			s_policy::template fwd_comp_unroll<dimension>::repeat::no_return(out.array, (value_type) 0);
			m_policy::template fwd_arit_unroll<dimension>::asterisk::
				no_return(out.array, tmp.array, subuinteger::array, b.array);

			return out;
		}
};

