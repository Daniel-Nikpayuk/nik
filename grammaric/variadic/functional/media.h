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

namespace nik
{
	template<typename SizeType>
	struct module<nik::variadic, nik::functional, nik::media, SizeType>
	{
		typedef SizeType size_type;

		template<size_type orientation_enum, size_type interface_enum>
		using control_flow = module<nik::control_flow, orientation_enum, interface_enum, SizeType>;

		template<size_type interface_enum>
		using structural = module<nik::variadic, nik::structural, interface_enum, SizeType>;

		using semiotic = module<nik::variadic, nik::functional, nik::semiotic, SizeType>;

		#define cf_media control_flow<nik::functional, nik::media>

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

		#undef cf_media
	};
}

