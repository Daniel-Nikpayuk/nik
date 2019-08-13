/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<size_type reg_length, Performance performance = Performance::specification> /* typename WordType,*/
struct characteristic
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	using uint_map_characteristic		= map_characteristic
						<
							reg_length
						>;

	using generic				= typename Power::generic;

	//

	static reg_type degree(reg_type value)
	{
		uint_map_characteristic umc;

		generic::map(umc, value, zero::value);

		return umc.value;
	}
};

/***********************************************************************************************************************/

template<typename Type, size_type N = builtin<Type>::length::value>
struct characteristic_unroll
{
	using reg_type				= Type;

	using zero				= typename Constant::template zero<reg_type>;
	using one				= typename Constant::template one<reg_type>;

	using half_length			= constant<reg_type, (reg_type) (N >> one::value)>;

	using sub_type				= characteristic_unroll<reg_type, half_length::value>;

	using high_pass				= constant
						<
							reg_type,
							(reg_type) ~((one::value << half_length::value) - one::value)
						>;

	//

	inline static reg_type degree(reg_type value, reg_type position = zero::value)
	{
		if (high_pass::value & value)
		{
			value		>>= half_length::value;
			position	 += half_length::value;
		}

		return sub_type::degree(value, position);
	}
};

template<typename Type>
struct characteristic_unroll<Type, One::value>
{
	using reg_type = Type;

	inline static reg_type degree(reg_type value, reg_type position)
	{
		return position;
	}
};

/*
*/

template<size_type reg_length> /* typename WordType */
struct characteristic<reg_length, Performance::optimization>
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	static reg_type degree(reg_type value)
	{
		return characteristic_unroll<reg_type>::degree(value);
	}
};

