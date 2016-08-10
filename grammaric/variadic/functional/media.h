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

#ifndef NIK_GRAMMARIC_VARIADIC_FUNCTIONAL_MEDIA_H
#define NIK_GRAMMARIC_VARIADIC_FUNCTIONAL_MEDIA_H

namespace nik		{
namespace grammaric	{
namespace variadic	{
namespace functional	{

	template<typename SizeType>
	struct media
	{
		typedef SizeType size_type;

		typedef control_flow::functional::media<size_type> cf_media;

		typedef structural::semiotic<size_type> s_semiotic;

		typedef functional::semiotic<size_type> semiotic;

		#include"cases/media.hpp"

		#include"isNull/media.hpp"
		#include"length/media.hpp"
		#include"at/media.hpp"
		#include"erase/media.hpp"
		#include"catenate/media.hpp"
		#include"filter/media.hpp"
		#include"sort/media.hpp"
		#include"fill/media.hpp"
		#include"sortFill/media.hpp"
	};

}}}}

#endif
