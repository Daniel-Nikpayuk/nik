iterator
========

<a href="#decrement_assign">
	template<typename OutputIterator, typename InputIterator><br>
	static OutputIterator decrement_assign(OutputIterator, InputIterator, const InputIterator)
</a>

<div id="decrement_assign"/>

template<typename OutputIterator, typename InputIterator><br>
decrement_assign(OutputIterator out, InputIterator in, const InputIterator end)

*out*, *in*-->*end* are preallocated structures with *in* > *end*;
both *out* and *in* are decremented.

Assigns values iterated from *in*--*end* to *out* until *in* reaches *end*.

Primarily useful when shifting values rightward.

