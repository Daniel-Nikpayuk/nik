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

#ifndef NIK_MEDIA_TRAITS_H
#define NIK_MEDIA_TRAITS_H

//#include"../numeric/random_access/iterator/extensionwise/structural/traits/traits.h"
//#include"../numeric/random_access/iterator/expansionwise/structural/traits/traits.h"
//#include"../numeric/random_access/iterator/componentwise/structural/traits/traits.h"

namespace nik
{
 namespace media
 {
	template<typename SizeType>
	struct traits
	{
		typedef SizeType size_type;

//		typedef numeric::random_access::iterator::extensionwise::structural::traits<size_type> nrits;
//		typedef numeric::random_access::iterator::expansionwise::structural::traits<size_type> nrips;
//		typedef numeric::random_access::iterator::componentwise::structural::traits<size_type> nrics;
	};
 }
}

#endif
