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

#include<stdlib.h>

namespace nik
{
	enum ErrorType : size_t
	{
		out_of_bounds
	};

	template<typename T>
	struct error
	{
	/*
		static constexpr char* message =
		{
			"index is out of bounds!"
		};
	*/

		static void report(size_t index)
		{
	//		builtin << message[index];
			builtin << "Now exiting.";

			exit(EXIT_FAILURE);
		}
	};
}

