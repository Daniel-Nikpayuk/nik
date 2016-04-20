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

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
*/

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

#define count_no_return_0(dir, inv, op)

#define count_with_return_0(dir, inv, op)

#define count_no_return_left_0(dir, inv, op)

#define count_with_return_left_0(dir, inv, op)

#define count_no_return_right_0(dir, inv, op)

#define count_with_return_right_0(dir, inv, op)

#define count_no_return_new_0(dir, inv) \
template<typename Node, typename WNode, typename WPointer, typename EWPointer> \
static void no_return(size_type & count, WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		*out=new Node(); \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); \
	} \
}

#define count_with_return_new_0(dir, inv) \
template<typename Node, typename WNode, typename WPointer, typename EWPointer> \
static WPointer with_return(size_type & count, WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		*out=new Node(); \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); \
	} \
 \
	return out; \
}

#define count_no_return_delete_0(dir, inv) \
template<typename WNode, typename WPointer, typename EWPointer> \
static void no_return(size_type & count, WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		++count; dir##dir(out); \
		delete *inv(out); \
		delete inv(out); \
	} \
}

#define count_with_return_delete_0(dir, inv) \
template<typename WNode, typename WPointer, typename EWPointer> \
static WPointer with_return(size_type & count, WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		++count; dir##dir(out); \
		delete *inv(out); \
		delete inv(out); \
	} \
 \
	return out; \
}

#define count_no_return_new_brackets_0(dir, inv) \
template<typename Node, typename WNode, typename WPointer, typename EWPointer> \
static void no_return(size_type & count, WPointer out, EWPointer end, size_type in) \
{ \
	while (out != end) \
	{ \
		*out=new Node[in]; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); \
	} \
}

#define count_with_return_new_brackets_0(dir, inv) \
template<typename Node, typename WNode, typename WPointer, typename EWPointer> \
static WPointer with_return(size_type & count, WPointer out, EWPointer end, size_type in) \
{ \
	while (out != end) \
	{ \
		*out=new Node[in]; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); \
	} \
 \
	return out; \
}

#define count_no_return_delete_brackets_0(dir, inv) \
template<typename WNode, typename WPointer, typename EWPointer> \
static void no_return(size_type & count, WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		++count; dir##dir(out); \
		delete [] *inv(out); \
		delete inv(out); \
	} \
}

#define count_with_return_delete_brackets_0(dir, inv) \
template<typename WNode, typename WPointer, typename EWPointer> \
static WPointer with_return(size_type & count, WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		++count; dir##dir(out); \
		delete [] *inv(out); \
		delete inv(out); \
	} \
 \
	return out; \
}

/************************************************************************************************************************/

#define count_no_return_1(dir, inv, op) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		(*out)op(*in); \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in); \
	} \
}

#define count_with_return_1(dir, inv, op) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		(*out)op(*in); \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in); \
	} \
 \
	return out; \
}

#define count_no_return_right_1(dir, inv, op, r) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		(*out)op(*in)r; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in); \
	} \
}

#define count_with_return_right_1(dir, inv, op, r) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		*(out)op(*in)r; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in); \
	} \
 \
	return out; \
}

#define count_no_return_new_brackets_1(dir, inv) \
template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
static void no_return(size_type & count, WPointer out, RPointer in, ERPointer end) \
{ \
	while (in != end) \
	{ \
		*out=new Node[*in]; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in); \
	} \
}

#define count_with_return_new_brackets_1(dir, inv) \
template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
static WPointer with_return(size_type & count, WPointer out, RPointer in, ERPointer end) \
{ \
	while (in != end) \
	{ \
		*out=new Node[*in]; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in); \
	} \
 \
	return out; \
}

/************************************************************************************************************************/

#define count_no_return_2(dir, inv, op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op(*in2); \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in1); dir##dir(in2); \
	} \
}

#define count_with_return_2(dir, inv, op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op(*in2); \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in1); dir##dir(in2); \
	} \
 \
	return out; \
}

#define count_no_return_brackets_2(dir, inv, op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op[*in2]; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in1); dir##dir(in2); \
	} \
}

#define count_with_return_brackets_2(dir, inv, op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op[*in2]; \
		dir(out)=new WNode; \
		inv(dir(out))=out; \
		++count; dir##dir(out); dir##dir(in1); dir##dir(in2); \
	} \
 \
	return out; \
}

