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

/*
	Make sure to consider composition of grammar as part of testing.
*/

namespace nik
{
 namespace debug
 {
	struct list
	{
		typedef media::list<int> list_type;

		static void constructors()
		{
			list_type l;

			list_type m(l);
		}

		static void assignment_operator()
		{
		}

		static void comparison()
		{
		}

		static void clear()
		{
/*
			list_type m;
			m.clear();
			nik::media::display << m << nik::endl;
*/
		}

		static void insert_after()
		{
			list_type l;

			l.insert_after(l.before_begin(), 3, 5);
			l.insert_after(l.before_begin(), 3);
			l.insert_after(l.before_begin(), 1);
			l.insert_after(l.begin(), 2);

			nik::media::display << l << nik::endl;
/*
			list_type m;
			m.insert_after(m.before_begin(), l.begin(), l.end());
			nik::media::display << m << nik::endl;
*/
		}

		static void erase_after()
		{
/*
			list_type m;
			m.erase_after(m.before_begin());
			nik::media::display << m << nik::endl;

			m.erase_after(m.begin());
			nik::media::display << m << nik::endl;

			m.erase_after(m.begin(), m.end());
			nik::media::display << m << nik::endl;

			m.erase_after(m.before_begin());
			nik::media::display << m << nik::endl;
*/
		}

		static void push_front()
		{
/*
			list_type m;
			m.push_front(7);
			nik::media::display << m << nik::endl;
*/
		}

		static void pop_front()
		{
/*
			list_type m;
			m.pop_front();
			nik::media::display << m << nik::endl;
*/
		}

		static void swap()
		{
/*
			list_type m;
			m.swap(l);
			nik::media::display << l << nik::endl;
			nik::media::display << m << nik::endl;
			nik::media::display << m << nik::endl;
*/
		}
	};
 }
}

