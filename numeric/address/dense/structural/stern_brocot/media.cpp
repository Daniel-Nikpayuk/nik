/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

class stern_brocot
{
	private:
		size_type num;
		size_type denom;

		size_type length;

		size_type *inf_num;
		size_type *inf_denom;

		size_type *sup_num;
		size_type *sup_denom;
	private:
		friend verbatim_printer;

		static void print(const stern_brocot & i)
		{
			for (size_type k=i.length-1; k != -1; --k)
			{
				builtin.print(' ');
				builtin.print(i.inf_num[k]);
				builtin.print(" / ");
				builtin.print(i.inf_denom[k]);
				builtin.print(endl);
			}

			builtin.print(endl);
			builtin.print(i.num);
			builtin.print(" / ");
			builtin.print(i.denom);
			builtin.print(endl);

			for (size_type k=0; k != i.length; ++k)
			{
				builtin.print(' ');
				builtin.print(i.sup_num[k]);
				builtin.print(" / ");
				builtin.print(i.sup_denom[k]);
				builtin.print(endl);
			}
		}
	public:
		stern_brocot(size_type n, size_type d)
		{
			size_type m=pbp_policy::math::media::gcd::with_return(n,d);

			num=n/m;
			denom=d/m;

			length=0;

			inf_num=new size_type[length];
			inf_denom=new size_type[length];

			sup_num=new size_type[length];
			sup_denom=new size_type[length];
		}

		stern_brocot operator ^ (const stern_brocot & i) const
		{
				// same level ?
			return stern_brocot(num + i.num, denom + i.denom);
		}
};

