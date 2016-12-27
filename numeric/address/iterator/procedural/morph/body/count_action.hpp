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


#define OMIT	LIST<functorEnum, Connotation::omit_count, optimizerEnum>
#define APPLY	LIST<functorEnum, Connotation::apply_count, optimizerEnum>


/***********************************************************************************************************************/


template
<
	size_type functorEnum,
	size_type optimizerEnum,
	typename F
>
static inline void count_action(Adverb<OMIT, F> & ad)
	{ }


/***********************************************************************************************************************/


template
<
	size_type functorEnum,
	size_type optimizerEnum,
	typename F
>
static inline void count_action(Adverb<APPLY, F> & ad)
{
	++ad.count;
}


/***********************************************************************************************************************/


#undef APPLY
#undef OMIT


