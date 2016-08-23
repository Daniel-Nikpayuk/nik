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

#ifndef MODULE_VARIADIC_H
#define MODULE_VARIADIC_H

#include"control_flow.h"

#include"../grammaric/variadic/structural/semiotic.h"
#include"../grammaric/variadic/functional/semiotic.h"

#include"../grammaric/variadic/structural/media.h"
#include"../grammaric/variadic/functional/media.h"

namespace nik
{
	template<typename SizeType>
	struct semiotic<SizeType, module::variadic> : public semiotic<SizeType, module::control_flow>
	{
		typedef SizeType size_type;

		using gvs = grammaric::variadic::structural::semiotic<size_type>;
		using gvf = grammaric::variadic::functional::semiotic<size_type>;
	};

	template<typename SizeType>
	struct media<SizeType, module::variadic> : public media<SizeType, module::control_flow>
	{
		typedef SizeType size_type;

		using gvs = grammaric::variadic::structural::media<size_type>;
		using gvf = grammaric::variadic::functional::media<size_type>;
	};
}

#endif
