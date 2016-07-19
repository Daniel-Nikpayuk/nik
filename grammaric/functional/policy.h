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

#ifndef NIK_GRAMMARIC_FUNCTIONAL_POLICY_H
#define NIK_GRAMMARIC_FUNCTIONAL_POLICY_H

namespace nik		{
namespace grammaric	{
namespace functional	{

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		#include"control_flow/semiotic.cpp"
		#include"length/semiotic.cpp"
		#include"car/semiotic.cpp"
	};

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef functional::semiotic<size_type> semiotic;

		#include"control_flow/media.cpp"
		#include"length/media.cpp"
		#include"car/media.cpp"
	};

}}}

#endif
