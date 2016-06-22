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

struct search
{
	struct find
	{
		struct index
		{
			struct before
			{
				struct last
				{
					template<typename WPointer, typename EWPointer>
					static void no_return(WPointer out, EWPointer end)
					{
						while (+(+out) != end) ++out;
					}

					template<typename WPointer, typename EWPointer>
					static WPointer with_return(WPointer out, EWPointer end)
					{
						while (+(+out) != end) ++out;

						return out;
					}

					struct count
					{
						template<typename WPointer, typename EWPointer>
						static void no_return(size_type & count, WPointer out, EWPointer end)
						{
							while (+(+out) != end)
							{
								++out;
								++count;
							}
						}

						template<typename WPointer, typename EWPointer>
						static WPointer with_return(size_type & count, WPointer out, EWPointer end)
						{
							while (+(+out) != end)
							{
								++out;
								++count;
							}

							return out;
						}
					};
				};

				struct end
				{
					template<typename WPointer, typename EWPointer>
					static void no_return(WPointer out, EWPointer end)
					{
						while (+out != end) ++out;
					}

					template<typename WPointer, typename EWPointer>
					static WPointer with_return(WPointer out, EWPointer end)
					{
						while (+out != end) ++out;

						return out;
					}

					struct count
					{
						template<typename WPointer, typename EWPointer>
						static void no_return(size_type & count, WPointer out, EWPointer end)
						{
							while (+out != end)
							{
								++out;
								++count;
							}
						}

						template<typename WPointer, typename EWPointer>
						static WPointer with_return(size_type & count, WPointer out, EWPointer end)
						{
							while (+out != end)
							{
								++out;
								++count;
							}

							return out;
						}
					};
				};
			};
		};
	};
};

