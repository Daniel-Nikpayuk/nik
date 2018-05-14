
using size_type = unsigned;

	//

namespace nik
{
	template<size_type N, typename Type, Access access = Access::readwrite>
	struct nested_copower : public nested_copower<N-1, Type, access>
	{
		using type		= nested_copower;
		using type_ptr		= type*;
		using type_ref		= type&;

		using const_type	= nested_copower<N, Type, Access::readonly>;

		using sub_copower	= nested_copower<N-1, Type, access>;
		using sub_copower_ptr	= sub_copower*;
		using sub_copower_ref	= sub_copower&;

		sub_copower focus;

			// type:

		nested_copower() { }

		nested_copower(const sub_copower_ref f) : focus(f) { }

		~nested_copower() { }

		bool operator == (const type_ref c) const
		{
			return focus == c.focus;
		}

		bool operator != (const type_ref c) const
		{
			return focus != c.focus;
		}

			// Exists to convert readwrite to readonly.
			// Is redundant when already readonly.

		operator const_type () const
		{
			return (const_type) this;
		}

			// value:

		sub_copower_ref operator * () const
		{
			return focus;
		}

			// navigator:

		type_ref operator ++ ()
		{
			++focus;

			return *this;
		}

		type operator ++ (int)
		{
			return focus++;
		}

		type_ref operator += (size_type n)
		{
			focus += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return focus + n;
		}

		type_ref operator -- ()
		{
			--focus;

			return *this;
		}

		type operator -- (int)
		{
			return focus--;
		}

		type_ref operator -= (size_type n)
		{
			focus -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return focus - n;
		}

		size_type operator - (const type_ref c) const
		{
			return focus - c.focus;
		}
	};

		// N = 0:

	template<typename Type, Access access>
	struct nested_copower<0, Type, access>
	{
		using type		= nested_copower;
		using type_ptr		= type*;
		using type_ref		= type&;

		using const_type	= nested_copower<0, Type, Access::readonly>;

		using value_type	= typename read_type<Type, access>::rtn;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		value_type focus;

			// type:

		nested_copower() { }

		nested_copower(const value_type_ref f) : focus(f) { }

		~nested_copower() { }

		bool operator == (const type_ref c) const
		{
			return focus == c.focus;
		}

		bool operator != (const type_ref c) const
		{
			return focus != c.focus;
		}

			// Exists to convert readwrite to readonly.
			// Is redundant when already readonly.

		operator const_type () const
		{
			return (const_type) this;
		}

			// value:

		value_type_ref operator * () const
		{
			return focus;
		}

			// navigator:

		type_ref operator ++ ()
		{
			++focus;

			return *this;
		}

		type operator ++ (int)
		{
			return focus++;
		}

		type_ref operator += (size_type n)
		{
			focus += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return focus + n;
		}

		type_ref operator -- ()
		{
			--focus;

			return *this;
		}

		type operator -- (int)
		{
			return focus--;
		}

		type_ref operator -= (size_type n)
		{
			focus -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return focus - n;
		}

		size_type operator - (const type_ref c) const
		{
			return focus - c.focus;
		}
	};

	/*
		Copowers are meant as an alternative to pointers. When instantiated with a pointer as parameter,
		they should be partially specialized to interface directly with their dereferenced value types.
	*/

	template<typename Type, Access access>
	struct nested_copower<0, Type*, access>
	{
		using type		= nested_copower;
		using type_ptr		= type*;
		using type_ref		= type&;

		using const_type	= nested_copower<0, Type*, Access::readonly>;

		using value_type	= typename read_type<Type, access>::rtn;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		value_type_ptr focus;

			// type:

		nested_copower() { }

		nested_copower(value_type_ptr f) : focus(f) { }

		~nested_copower() { }

		bool operator == (const type_ref c) const
		{
			return focus == c.focus;
		}

		bool operator != (const type_ref c) const
		{
			return focus != c.focus;
		}

			// Exists to convert readwrite to readonly.
			// Is redundant when already readonly.

		operator const_type () const
		{
			return (const_type) this;
		}

			// value:

		value_type_ref operator * () const
		{
			return *focus;
		}

			// navigator:

		type_ref operator ++ ()
		{
			++focus;

			return *this;
		}

		type operator ++ (int)
		{
			return focus++;
		}

		type_ref operator += (size_type n)
		{
			focus += n;

			return *this;
		}

		type operator + (size_type n) const
		{
			return focus + n;
		}

		type_ref operator -- ()
		{
			--focus;

			return *this;
		}

		type operator -- (int)
		{
			return focus--;
		}

		type_ref operator -= (size_type n)
		{
			focus -= n;

			return *this;
		}

		type operator - (size_type n) const
		{
			return focus - n;
		}

		size_type operator - (const type_ref c) const
		{
			return focus - c.focus;
		}
	};

		//

	template<size_type N, typename Type, Access access = Access::readwrite>
	struct mobile_copower
	{
		using type		= mobile_copower;
		using type_ptr		= type*;
		using type_ref		= type&;

		using const_type	= mobile_copower<N, Type, Access::readonly>;

		using value_type	= typename read_type<Type, access>::rtn;
		using value_type_ptr	= value_type*;
		using value_type_ref	= value_type&;

		using nested_type	= nested_copower<N, Type, access>;
		using nested_type_ptr	= nested_type*;
		using nested_type_ref	= nested_type&;

		nested_type_ptr path[N+1];
		nested_type_ptr *location;

			// type:

		mobile_copower() : location(path) { }

		~mobile_copower()
		{
			// deallocate location componentwise.
		}

		bool operator == (const type_ref c) const
		{
			return *location == *c.location;
		}

		bool operator != (const type_ref c) const
		{
			return *location != *c.location;
		}

			// Exists to convert readwrite to readonly.
			// Is redundant when already readonly.

		operator const_type () const
		{
			return (const_type) this;
		}

			// value:

		value_type_ref operator * () const
		{
			return *path[N-1];
		}

			// meta:

		void operator + ()
		{
			++location;
		}
		
		void operator - ()
		{
			--location;
		}

			// navigator:

		type_ref operator ++ ()
		{
			(*location)->operator++();

			return *this;
		}

		type operator ++ (int int_value)
		{
			return (*location)->operator++(int_value);
		}

		type_ref operator += (size_type n)
		{
			(*location)->operator+=(n);

			return *this;
		}

		type operator + (size_type n) const
		{
			return (*location)->operator+(n);
		}

		type_ref operator -- ()
		{
			(*location)->operator--();

			return *this;
		}

		type operator -- (int int_value)
		{
			return (*location)->operator--(int_value);
		}

		type_ref operator -= (size_type n)
		{
			(*location)->operator-=(n);

			return *this;
		}

		type operator - (size_type n) const
		{
			return (*location)->operator-(n);
		}

		size_type operator - (const type_ref c) const
		{
			return *location - *c.location;
		}
	};
}

