/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct embedding
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// v map v combine v:

		// symbolic:

		template<typename Condition, typename Break, typename Next>
		struct cp_s_judgment_stem_v_map_v_combine_v
		{
			template
			<
				typename Kind, template<Kind...> class ListKind,
				typename Aspect,
				typename Type, template<Type...> class ListType,

				bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
				bool (*Before_Map)(Type), bool (*After_Map)(Aspect),
				bool (*Before_Left_Combine)(Kind), bool (*Before_Right_Combine)(Aspect),
				bool (*After_Combine)(Kind),

				Kind (*Combine)(Kind, Aspect), Aspect (*Map)(Type),
				size_type depth, size_type count,
				Kind Instance, Aspect Moment, Type... Values
			>
			using result = typename if_then_else
			<
				Condition::template result
				<
					Kind, ListKind, Aspect, Type, ListType,
					Before_Depth, Before_Count, Before_Map, After_Map,
					Before_Left_Combine, Before_Right_Combine, After_Combine,
					Combine, Map, depth, count, Instance, Moment, Values...
				>,

				Break, Next

			>::template result
			<
				Kind, ListKind, Aspect, Type, ListType,
				Before_Depth, Before_Count, Before_Map, After_Map,
				Before_Left_Combine, Before_Right_Combine, After_Combine,
				Combine, Map, depth, count, Instance, Moment, Values...
			>;
		};
};
