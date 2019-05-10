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

#include"define-size_type.h"

#ifdef safe_name

	#define PREFIX		calprf_

#else

	#define PREFIX

#endif

//

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, reflex_list_cons)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_list_cons<Type, Value, List>;

							  template<typename Type, typename Value, typename List>
	using nik_safe(PREFIX, transit_list_cons)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_list_cons<Type, Value, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, reflex_list_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_list_car<Type, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, transit_list_car)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_list_car<Type, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, reflex_list_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_list_cdr<Type, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, transit_list_cdr)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_list_cdr<Type, List>;

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, reflex_list_push)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_list_push<Type, Value, List>;

							  template<typename Type, typename Value, typename List>
	using nik_safe(PREFIX, transit_list_push)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_list_push<Type, Value, List>;

//

							  template<typename Value, typename Chain>
	using nik_safe(PREFIX, reflex_chain_cons)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_chain_cons<Value, Chain>;

							  template<typename Value, typename Chain>
	using nik_safe(PREFIX, transit_chain_cons)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_chain_cons<Value, Chain>;

							  template<typename Chain>
	using nik_safe(PREFIX, reflex_chain_car)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_chain_car<Chain>;

							  template<typename Chain>
	using nik_safe(PREFIX, transit_chain_car)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_chain_car<Chain>;

							  template<typename Chain>
	using nik_safe(PREFIX, reflex_chain_cdr)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_chain_cdr<Chain>;

							  template<typename Chain>
	using nik_safe(PREFIX, transit_chain_cdr)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_chain_cdr<Chain>;

							  template<typename Value, typename Chain>
	using nik_safe(PREFIX, reflex_chain_push)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  reflex_chain_push<Value, Chain>;

							  template<typename Value, typename Chain>
	using nik_safe(PREFIX, transit_chain_push)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  transit_chain_push<Value, Chain>;

//

							  template<typename Exp>
	using nik_safe(PREFIX, mostly_reflex)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  mostly_reflex<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, mostly_transit)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::template
							  mostly_transit<Exp>;

//

#undef PREFIX

#include"undef-size_type.h"

