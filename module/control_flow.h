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

#ifndef MODULE_CONTROL_FLOW_H
#define MODULE_CONTROL_FLOW_H

#include"../grammaric/control_flow/functional/semiotic.h"
#include"../grammaric/control_flow/functional/media.h"

namespace nik
{
	template<typename SizeType>
	struct semiotic<SizeType, module::control_flow>
	{
		typedef SizeType size_type;

		using gcf = grammaric::control_flow::functional::semiotic<size_type>;
	};

	template<typename SizeType>
	struct media<SizeType, module::control_flow>
	{
		typedef SizeType size_type;

		using gcf = grammaric::control_flow::functional::media<size_type>;
	};
}

#endif
