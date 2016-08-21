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
	size_type directionEnum = traits::direction_enum,
	size_type imageEnum = traits::image_enum,
	size_type iteratorEnum = traits::iterator_enum

> struct declare_variables { };


/***********************************************************************************************************************/


template<typename traits, size_type directionEnum, size_type iteratorEnum>
struct declare_variables<traits, directionEnum, ModIterator::mutate, iteratorEnum>
{
	template<typename sAdjective, typename const_sAdjective>
	declare_variables(sAdjective & subject, const const_sAdjective & const_subject)
	{
		subject.initial = const_subject.initial;
	}
};


/***********************************************************************************************************************/


template<typename traits>
struct declare_variables<traits, ModIterator::forward, ModIterator::allocate, ModIterator::segment>
{
	template<typename sAdjective, typename const_sAdjective>
	declare_variables(sAdjective & subject, const const_sAdjective & const_subject)
	{
		subject.initial = new value_type[const_subject.initial];
		subject.terminal = subject.initial + const_subject.terminal;
	}
};


