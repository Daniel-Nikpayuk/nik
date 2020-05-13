
#include<iostream>

#include"../nik/inclusive.h"

#include nik_lens_unpack(../nik, literic, perspective, functor, alias)

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

	template<bool policy, typename Filler = void>
	struct conditional
	{
		template<typename Ante, typename Conse>
		using result = Ante;
	};

	template<typename Filler>
	struct conditional<false, Filler>
	{
		template<typename Ante, typename Conse>
		using result = Conse;
	};

	template<bool policy, typename Ante, typename Conse>
	using if_then_else = typename conditional<policy>::template result<Ante, Conse>;

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

	template<typename F1, typename F2>
	static constexpr auto compose(F1 f1, F2 f2)
	{
		return [=](auto const & x){ return f1(f2(x)); };
	}

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

	template<typename, typename>
	struct memoized_pair
	{
                template<typename Continuation>
                static constexpr bool match = Continuation::template result<false>;
	};

	template<typename Type>
	struct memoized_pair<Type, Type>
	{
                template<typename Continuation>
                static constexpr bool match = Continuation::template result<true>;
	};

	struct ch_pair_match
	{
		template<bool Value>
		static constexpr bool result = Value;
	};

        template<typename Type1, typename Type2>
        static constexpr bool equal = memoized_pair<Type1, Type2>::template match
        <
                ch_pair_match
        >;

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

        template<typename FunctionType, FunctionType>
        struct memoized_function
        {
                template<typename Continuation>
                using match = typename Continuation::template result<false>;
	};

        template<typename OutType, typename InType, OutType(*Function)(InType)>
        struct memoized_function<OutType(*)(InType), Function>
        {
                template<typename Continuation>
                using match = typename Continuation::template result<true>;

                template<typename Continuation>
                using type_induct = typename Continuation::template result<OutType, InType, OutType(*)(InType), Function>;

                template<typename Continuation>
                static constexpr auto value_induct = Continuation::template result<OutType, InType, OutType(*)(InType), Function>;
        };

	// :

	struct ch_function_out_type
	{
		template<typename OutType, typename InType, typename FunctionType, FunctionType Function>
		using result = OutType;
	};

	struct ch_function_in_type
	{
		template<typename OutType, typename InType, typename FunctionType, FunctionType Function>
		using result = InType;
	};

	struct ch_function_type
	{
		template<typename OutType, typename InType, typename FunctionType, FunctionType Function>
		using result = FunctionType;
	};

	struct ch_function
	{
		template<typename OutType, typename InType, typename FunctionType, FunctionType Function>
		static constexpr auto result = Function;
	};

	// :

	template<auto f>
	using make_function = memoized_function<decltype(f), f>;

        template<typename Function>
        using function_out_type = typename Function::template type_induct
        <
                ch_function_out_type
        >;

        template<typename Function>
        using function_in_type = typename Function::template type_induct
        <
                ch_function_in_type
        >;

        template<typename Function>
        using function_type = typename Function::template type_induct
        <
                ch_function_type
        >;

        template<typename Function>
        static constexpr auto function = Function::template value_induct
        <
                ch_function
        >;

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

        template<typename FunctionType1, typename FunctionType2, FunctionType1, FunctionType2>
        struct memoized_composite
        {
                template<typename Continuation>
                using match = typename Continuation::template result<false>;
	};

        template<typename OutType, typename MidType, typename InType, OutType(*Function1)(MidType), MidType(*Function2)(InType)>
        struct memoized_composite<OutType(*)(MidType), MidType(*)(InType), Function1, Function2>
        {
                template<typename Continuation>
                using match = typename Continuation::template result<true>;

                template<typename Continuation>
                using type_induct = typename Continuation::template result
		<
			OutType, MidType, InType, OutType(*)(MidType), MidType(*)(InType), Function1, Function2
		>;

                template<typename Continuation>
                static constexpr auto value_induct = Continuation::template result
		<
			OutType, MidType, InType, OutType(*)(MidType), MidType(*)(InType), Function1, Function2
		>;
        };

	// :

	struct ch_composite_out_type
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		using result = OutType;
	};

	struct ch_composite_mid_type
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		using result = MidType;
	};

	struct ch_composite_in_type
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		using result = InType;
	};

	struct ch_precomposite_type
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		using result = FunctionType1;
	};

	struct ch_postcomposite_type
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		using result = FunctionType2;
	};

	struct ch_composite_type
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		using result = OutType(*)(InType);
	};

	struct ch_precomposite
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		static constexpr auto result = Function1;
	};

	struct ch_postcomposite
	{
		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		static constexpr auto result = Function2;
	};

	struct ch_composite
	{
		template
		<
			typename OutType, typename InType,
			typename FunctionType1, typename FunctionType2,
			FunctionType1 Function1, FunctionType2 Function2
		>
		struct lambda
		{
			static constexpr OutType result(InType x)
			{
				return Function1(Function2(x));
			}
		};

		template<typename OutType, typename MidType, typename InType,
			typename FunctionType1, typename FunctionType2, FunctionType1 Function1, FunctionType2 Function2>
		static constexpr auto result = lambda
		<
			OutType, InType, FunctionType1, FunctionType2, Function1, Function2

		>::result;
	};

	// :

	template<auto f1, auto f2>
	using make_composite = memoized_composite<decltype(f1), decltype(f2), f1, f2>;

        template<typename Function>
        using composite_out_type = typename Function::template type_induct
        <
                ch_composite_out_type
        >;

        template<typename Function>
        using composite_mid_type = typename Function::template type_induct
        <
                ch_composite_mid_type
        >;

        template<typename Function>
        using composite_in_type = typename Function::template type_induct
        <
                ch_composite_in_type
        >;

        template<typename Function>
        using precomposite_type = typename Function::template type_induct
        <
                ch_precomposite_type
        >;

        template<typename Function>
        using postcomposite_type = typename Function::template type_induct
        <
                ch_postcomposite_type
        >;

        template<typename Function>
        using composite_type = typename Function::template type_induct
        <
                ch_composite_type
        >;

	// :

        template<typename Function, typename Continuation = ch_precomposite>
        static constexpr auto precomposite = Function::template value_induct
        <
                Continuation
        >;

        template<typename Function, typename Continuation = ch_postcomposite>
        static constexpr auto postcomposite = Function::template value_induct
        <
                Continuation
        >;

        template<typename Function, typename Continuation = ch_composite>
        static constexpr auto composite = Function::template value_induct
        <
                Continuation
        >;

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

	template<bool policy, typename Filler = void>
	struct memoized_dihold
	{
		template<auto f1, auto f2, auto f3, auto f4>
		using result = make_composite<f1, f2>;
	};

	template<typename Filler>
	struct memoized_dihold<false, Filler>
	{
		template<auto f1, auto f2, auto f3, auto f4>
		using result = make_composite<f3, f4>;
	};

	template<bool policy, auto f1, auto f2, auto f3, auto f4>
	using dihold = typename memoized_dihold<policy>::template result
	<
		f1, f2, f3, f4
	>;

	template<auto arg, bool policy, auto break_f, auto next_f>
	using open_call_call = dihold
	<
		policy, break_f, arg, next_f, arg
	>;

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/

	template<bool, typename Filler = void>
	struct recurse
	{
		template
		<
			typename arg,
			template<auto, bool, auto, auto> class bind,
			bool policy, auto break_f, auto next_f,
			auto... Rest
		>
		using compose = typename recurse<bool(sizeof...(Rest))>::template compose
		<
			bind<composite<arg>, policy, break_f, next_f>,
			bind,
			Rest...
		>;
	};

	template<typename Filler>
	struct recurse<false, Filler>
	{
		template
		<
			typename arg,
			template<auto, bool, auto, auto> class bind,
			auto... Rest
		>
		using compose = arg;
	};

	template
	<
		template<auto, bool, auto, auto> class bind,
		bool policy1, auto break_f1, auto next_f1,
		bool policy2, auto break_f2, auto next_f2,
		auto... Rest
	>
	using let_alternation = typename recurse<bool(sizeof...(Rest))>::template compose
	<
		bind
		<
			policy1 ? break_f1 : next_f1,
			policy2, break_f2, next_f2
		>,

		bind,
		Rest...
	>;

	/***********************************************************************************************************************/

	struct open	{ };
	struct closing	{ };
	struct closed	{ };
	struct opening	{ };

	struct call	{ };
	struct pass	{ };

	/***********************************************************************************************************************/

	template
	<
		typename interval_type, typename composition_type1, typename composition_type2,
		bool policy1, auto break_f1, auto next_f1,
		bool policy2, auto break_f2, auto next_f2,
		auto... Rest
	>
	using alternation = if_then_else
	<
		equal<interval_type, open>,

		if_then_else
		<
			equal<composition_type1, call>,

			if_then_else
			<
				equal<composition_type2, call>,

				let_alternation
				<
					open_call_call,

					policy1, break_f1, next_f1,
					policy2, break_f2, next_f2,
					Rest...
				>,

				void // temporary hack.
			>,

			void // temporary hack.
		>,

		void // temporary hack.
	>;

	/***********************************************************************************************************************/
	/***********************************************************************************************************************/


	constexpr int times2	(int x)	{ return 2*x; }
	constexpr int plus5	(int x)	{ return x+5; }
	constexpr int square	(int x)	{ return x*x; }

	using func = alternation
	<
		open,	call,	call,

		false,	times2, plus5,
		true,	square, plus5,
		true,	times2, plus5,
		false,	times2, plus5
	>;

	int main(int argc, char *argv[])
	{
		int y;
		std::cin >> y;

		Functor::display(composite<func>(y));
		Functor::display("\n");

		return 0;
	}



