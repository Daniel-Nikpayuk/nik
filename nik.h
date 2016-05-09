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

#ifndef NIK_H
#define NIK_H

#define stringify(string) \
#string

// base:
#define nikbase(construct, header) \
stringify(../nik/context/context/construct/header/header.h)

#define nikbase_debug(construct, header) \
stringify(../nik/context/context/construct/header/debug/debug.h)

// system:
#define niksys(navigator, structure, construct, header) \
stringify(../nik/context/semiotic/navigator/structure/construct/header/header.h)

#define niksys_debug(navigator, structure, construct, header) \
stringify(../nik/context/semiotic/navigator/structure/construct/header/debug/debug.h)

// generic:
#define nikgen(navigator, structure, construct, header) \
stringify(../nik/context/media/navigator/structure/construct/header/header.h)

#define nikgen_debug(navigator, structure, construct, header) \
stringify(../nik/context/media/navigator/structure/construct/header/debug/debug.h)

// semiotic:
#define niksign(navigator, header) \
stringify(../nik/semiotic/navigator/header/header.h)

#define niksign_debug(navigator, header) \
stringify(../nik/semiotic/navigator/header/debug/debug.h)

// media:
#define nikapi(navigator, category, header) \
stringify(../nik/media/navigator/category/header/header.h)

#define nikapi_debug(navigator, category, header) \
stringify(../nik/media/navigator/category/header/debug/debug.h)

#endif
