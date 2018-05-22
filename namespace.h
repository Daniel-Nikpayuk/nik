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

namespace nik
{
	enum struct Branch : global_size_type
	{
		grammaric,
		numeric,

		dimension // filler
	};

	enum struct Module : global_size_type
	{
		constant,
		builtin,
		pointer,
		power,
		range,

		bit,
		word,
		address,

		list,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};

	template
	<
		Branch branch_enum,
		Module module_enum,
		Permission permission_enum,

		typename SizeType = global_size_type
	>
	struct space { static_assert(true, "This module is not yet implemented!"); };

	//

				  template<Module module, Permission permission, typename SizeType = global_size_type>
	using grammaric		= space<Branch::grammaric, module, permission, SizeType>;

				  template<Module module, Permission permission, typename SizeType = global_size_type>
	using numeric		= space<Branch::numeric, module, permission, SizeType>;

/***********************************************************************************************************************/

	#define unpack_constant()											\
															\
		using Constant		= grammaric<Module::constant, Permission::semiotic, size_type>;			\
															\
		using Zero		= typename Constant::zero;							\
		using One		= typename Constant::one;							\
		using Two		= typename Constant::two;							\
		using Three		= typename Constant::three;							\
															\
		using Nibble		= typename Constant::nibble;							\
		using Byte		= typename Constant::byte;							\

	//

	#define unpack_builtin()											\
															\
		using Builtin		= grammaric<Module::builtin, Permission::semiotic, size_type>;			\
															\
					  template<size_type N>								\
		using byte_type		= typename Builtin::template byte_type<N>;					\

	//

	#define unpack_pointer()											\
															\
		using Pointer		= grammaric<Module::pointer, Permission::semiotic, size_type>;			\
															\
		using Access		= typename Pointer::Access;							\
															\
					  template<typename Type, Access access = Access::readwrite>			\
		using read_type		= typename Pointer::template read_type<Type, access>;				\

	//

	#define unpack_power()												\
															\
		using Power		= grammaric<Module::power, Permission::semiotic, size_type>;			\
															\
					  template<typename Type, Access access = Access::readwrite>			\
		using copower		= typename Power::template copower<Type, access>;				\
															\
					  template<typename Type, size_type length>					\
		using power		= typename Power::template power<Type, length>;					\
															\
		using Interval		= typename Power::Interval;							\
															\
		using Direction		= typename Power::Direction;							\
															\
					  template<Interval interval, Direction direction>				\
		using object		= typename Power::template object<interval, direction>;				\
															\
					  template<typename... Objects>							\
		using functor		= typename Power::template functor<Objects...>;					\

	//

	#define unpack_bit()												\
															\
		using Bit		= numeric<Module::bit, Permission::semiotic, size_type>;			\
															\
					  template<typename Type, Access access = Access::readwrite>			\
		using cobit		= typename Bit::template cobit<Type, access>;					\
															\
					  template<typename RegType>							\
		using bit		= typename Bit::template bit<RegType>;						\

	//

	#define unpack_word()												\
															\
		using Word		= numeric<Module::word, Permission::semiotic, size_type>;			\
															\
					  template<typename Type, Access access = Access::readwrite>			\
		using coword		= typename Word::template coword<Type, access>;					\
															\
					  template<typename BitType, size_type length>					\
		using word		= typename Word::template word<BitType, length>;				\

}

