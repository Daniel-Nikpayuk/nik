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

/*
	This module is meant to be the interface to Type Theoretic Function Objects:

		(A --> B) x A

	As such functions can be considered "lazy", their constructors would be the classical "delay" function,
	while their selectors would then be "force". Given C++ grammar, I do not know of any practical way
	to provide the necessary constructors nor are there a single standardized internal structure to define
	or pattern match here. As such I only offer common signatures for their selectors. These are the patterns
	for which template meta-programming is in fact built upon.
*/

