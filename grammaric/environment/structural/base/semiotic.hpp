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

template<typename, typename Type, Type...> struct binding;

template<typename Variable, typename Type>
struct binding<Variable, Type>
{
	using variable = Variable;
	using type = Type;
};

template<typename Variable, typename Type, Type v>
struct binding<Variable, Type, v>
{
	using variable = Variable;
	using type = Type;

	static constexpr Type value = v;
};

using null_binding = binding<void, void>;

//

template<typename... Variables>
using storage = tuple<Variables...>;

using null_storage = null_tuple;

//

template<typename... Bindings>
using frame = tuple<Bindings...>;

using null_frame = null_tuple;

//

template<typename... Frames>
using environment = tuple<Frames...>;

using null_environment = null_tuple;

