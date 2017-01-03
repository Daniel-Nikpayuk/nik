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

namespace nik		{
namespace numeric	{
namespace word		{
namespace uint		{
namespace procedural	{

	template<typename SizeType>
	struct media
	{
		static_assert(!functional::limits<SizeType>::min, "uint function argument signed!");

		typedef SizeType size_type;

		typedef grammaric::control_flow::functional::media<size_type> gcf_media;
		typedef functional::semiotic<size_type> f_semiotic;

		typedef functional::semiotic<size_type> semiotic;

		#include"overload/media.hpp"
		#include"discrete/media.hpp"
//		#include"math/media.hpp"
		#include"sift/media.hpp"
	};

}}}}}

