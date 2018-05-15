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

template<typename sub_policy, typename ob_policy>
struct functor
{
	using method = generic<sub_policy, ob_policy>;

	struct as_verb
	{
		template<typename sub_type, typename ob_type>
		inline void main_action(sub_type sub, ob_type ob)
		{
			*sub = *ob;
		}

		template<typename sub_type, typename ob_type>
		inline void last_action(sub_type sub, ob_type ob)
		{
			*sub = *ob;
		}
	};

		// assign:

	template<typename sub_type, typename ob_type>
	static sub_type assign(sub_type sub, ob_type ob, ob_type end)
	{
		as_verb as;

		return method::map(as, sub, ob, end);
	}
};

