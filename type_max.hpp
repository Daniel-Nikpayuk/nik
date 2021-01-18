
			template<auto, typename K> using is_signed_char		= T_equal_TxT<K, signed char>;
			template<auto, typename K> using is_unsigned_char	= T_equal_TxT<K, unsigned char>;

			template<auto, typename K> using is_signed_short	= T_equal_TxT<K, signed short>;
			template<auto, typename K> using is_unsigned_short	= T_equal_TxT<K, unsigned short>;

			template<auto, typename K> using is_signed_int		= T_equal_TxT<K, signed int>;
			template<auto, typename K> using is_unsigned_int	= T_equal_TxT<K, unsigned int>;

			template<auto, typename K> using is_signed_long		= T_equal_TxT<K, signed long>;
			template<auto, typename K> using is_unsigned_long	= T_equal_TxT<K, unsigned long>;

			template<auto, typename K> using is_signed_long_long	= T_equal_TxT<K, signed long long>;
			template<auto, typename K> using is_unsigned_long_long	= T_equal_TxT<K, unsigned long long>;

		//

			template<auto, typename> using signed_char_max		= T_value_V<SCHAR_MAX>;
			template<auto, typename> using unsigned_char_max	= T_value_V<UCHAR_MAX>;

			template<auto, typename> using signed_short_max		= T_value_V<SHRT_MAX>;
			template<auto, typename> using unsigned_short_max	= T_value_V<USHRT_MAX>;

			template<auto, typename> using signed_int_max		= T_value_V<INT_MAX>;
			template<auto, typename> using unsigned_int_max		= T_value_V<UINT_MAX>;

			template<auto, typename> using signed_long_max		= T_value_V<LONG_MAX>;
			template<auto, typename> using unsigned_long_max	= T_value_V<ULONG_MAX>;

			template<auto, typename> using signed_long_long_max	= T_value_V<LLONG_MAX>;
			template<auto, typename> using unsigned_long_long_max	= T_value_V<ULLONG_MAX>;

		//

			template<typename Type>
			static constexpr Type int_type_max = V_colist_T_Cs
			<
				Type,

				is_signed_char,			signed_char_max,
				is_unsigned_char,		unsigned_char_max,

				is_signed_short,		signed_short_max,
				is_unsigned_short,		unsigned_short_max,

				is_signed_int,			signed_int_max,
				is_unsigned_int,		unsigned_int_max,

				is_signed_long,			signed_long_max,
				is_unsigned_long,		unsigned_long_max,

				is_signed_long_long,		signed_long_long_max,
				is_unsigned_long_long,		unsigned_long_long_max	
			>;

