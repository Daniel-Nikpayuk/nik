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

namespace nik		{
namespace numeric	{
namespace address	{
namespace iterator	{
namespace structural	{

	template<typename SizeType>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef grammaric::control_flow::functional::media<size_type> gcf_media;

		typedef grammaric::variadic::functional::semiotic<size_type> gvf_semiotic;
		typedef grammaric::variadic::structural::semiotic<size_type> gvs_semiotic;

		typedef grammaric::variadic::functional::media<size_type> gvf_media;

/***********************************************************************************************************************/

		typedef nik::modifier<size_type> Mod;
		typedef typename Mod::iterator ModIterator;
		typedef typename Mod::optimizer ModOptimizer;

		template<size_type... params>
		using list = typename gvs_semiotic::template list<params...>;

		template<bool conditional, typename if_true, typename if_false>
		using if_then_else = typename gcf_media::template if_then_else<conditional, if_true, if_false>::rtn;

		template<size_type pos, typename L>
		using cases = typename gvf_semiotic::template cases<pos, L>::rtn;

		template<typename L, size_type pos>
		using at = typename gvf_semiotic::template at<L, pos>;

		template<typename modifier, size_type... params>
		using sortFill = typename gvf_media::template sortFill<modifier, params...>::rtn;

/***********************************************************************************************************************/

		#include"segment/semiotic.hpp"
		#include"node/semiotic.hpp"
		#include"hook/semiotic.hpp"
		#include"link/semiotic.hpp"
		#include"type/semiotic.hpp"
	};

}}}}}

