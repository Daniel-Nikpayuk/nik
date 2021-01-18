/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct inductor
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, inductor)

/*
	template<typename Type, typename Exp>
	using pattern_match_judgment_stem = typename dependent_memoization<Type>::template pattern_match_<Exp>;
*/

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
					bool, Kind, ListKind, Aspect, Type, ListType,
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

	// v map t combine v:

		// assemblic:

		template<typename Condition, typename Break, typename Next>
		struct cp_a_judgment_stem_v_map_t_combine_v
		{
			template
			<
				typename Image,
				typename Kind, template<Kind...> class ListKind,
				typename Type, template<Type...> class ListType,

				bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
				bool (*Before_Map)(Type), template<typename> class After_Map,
				bool (*Before_Left_Combine)(Kind), template<typename> class Before_Right_Combine,
				bool (*After_Combine)(Kind),

				template<Kind, typename> class Combine, template<Type> class Map,
				size_type depth, size_type count,
				Kind Instance, typename Moment, Type... Values
			>
			static constexpr Image result = if_then_else
			<
				Condition::template result
				<
					bool, Kind, ListKind, Type, ListType,
					Before_Depth, Before_Count, Before_Map, After_Map,
					Before_Left_Combine, Before_Right_Combine, After_Combine,
					Combine, Map, depth, count, Instance, Moment, Values...
				>,

				Break, Next

			>::template result
			<
				Image, Kind, ListKind, Type, ListType,
				Before_Depth, Before_Count, Before_Map, After_Map,
				Before_Left_Combine, Before_Right_Combine, After_Combine,
				Combine, Map, depth, count, Instance, Moment, Values...
			>;
		};

	// v map void combine void:

		// procedural:

		template<typename Condition, typename Break, typename Next>
		struct cp_af_judgment_stem_v_map_void_combine_void
		{
			template
			<
				typename Type, template<Type...> class ListType,

				bool (*Before_Depth)(size_type), bool (*Before_Count)(size_type),
				bool (*Before_Map)(Type),

				void (*Map)(Type),
				size_type depth, size_type count,
				Type... Values
			>
			static constexpr void (*result)() = if_then_else
			<
				Condition::template result
				<
					bool, Type, ListType,
					Before_Depth, Before_Count, Before_Map,
					Map, depth, count, Values...
				>,

				Break, Next

			>::template result
			<
				Type, ListType,
				Before_Depth, Before_Count, Before_Map,
				Map, depth, count, Values...
			>;
		};
};
