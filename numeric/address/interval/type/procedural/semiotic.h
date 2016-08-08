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

#ifndef NIK_NUMERIC_ADDRESS_INTERVAL_TYPE_PROCEDURAL_SEMIOTIC_H
#define NIK_NUMERIC_ADDRESS_INTERVAL_TYPE_PROCEDURAL_SEMIOTIC_H

namespace nik		{
namespace numeric	{
namespace address	{
namespace iterator	{
namespace procedural	{

	template<typename SizeType, typename T> struct media;

	template<typename SizeType, typename T>
	struct semiotic
	{
		typedef SizeType size_type;

		typedef typename structural::semiotic<size_type, T>::hook hook;
		typedef typename structural::semiotic<size_type, T>::link link;
		typedef typename structural::semiotic<size_type, T>::segment segment;

		typedef grammaric::variadic::functional::semiotic<size_type> gvf_semiotic;
		typedef grammaric::variadic::structural::semiotic<size_type> gvs_semiotic;

		typedef grammaric::variadic::functional::media<size_type> gvf_media;

		typedef word::uint::functional::semiotic<size_type> wuf_semiotic;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


		template<typename paramList>
		struct _memrator
		{
			#include"map/memrator/define/semiotic/basis/loop.hpp"
			#include"map/memrator/define/semiotic/basis/loop.hh"

			template<size_type... params>
			struct interval
			{
				#include"map/memrator/define/semiotic/interval/loop.hh"

				template<size_type... verb_params>
				struct tracer
				{
					using loop = _loop
					<
						paramList,
						typename gvf_media::template sortFill<Interval, params...>::rtn,
						typename gvf_media::template sortFill<Tracer, verb_params...>::rtn
					>;

					specialize_loop()
				};

//				#include"map/memrator/undef/semiotic/interval/loop.hh"
			};

//			#include"map/memrator/undef/semiotic/basis/loop.hh"
//			#include"map/memrator/undef/semiotic/basis/loop.hpp"
		};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


		template<size_type... params>
		using memrator = _memrator<typename gvf_media::template sortFill<Memrator, params...>::rtn>;
	};

}}}}}

#endif
