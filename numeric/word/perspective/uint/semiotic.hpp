/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
*/

struct uint
{

		// addition:

	template<typename WordType, Performance performance = Performance::specification>
	struct addition
	{
	};

	template<typename WordType>
	struct addition<WordType, Performance::optimization>
	{
	};

		// subtraction:

	template<typename WordType, Performance performance = Performance::specification>
	struct subtraction
	{
	};

	template<typename WordType>
	struct subtraction<WordType, Performance::optimization>
	{
	};

		// multiplication:

	template<typename WordType, Performance performance = Performance::specification>
	struct multiplication
	{
	};

	template<typename WordType>
	struct multiplication<WordType, Performance::optimization>
	{
	};

		// division:

	template<size_type length, Performance performance = Performance::specification> /* typename WordType,*/
	struct division
	{
		using reg_type		= typename byte_type<length>::reg_type;
		using half_length	= typename byte_type<length>::half_type::length;
		using low_pass		= typename byte_type<length>::low_pass;

		#include"division/specification/three_halves/semiotic.hpp"
	};

	template<size_type length> /* typename WordType */
	struct division<length, Performance::optimization>
	{
		using reg_type		= typename byte_type<length>::reg_type;
		using half_length	= typename byte_type<length>::half_type::length;
		using low_pass		= typename byte_type<length>::low_pass;

		#include"division/optimization/three_halves/semiotic.hpp"
	};
};

