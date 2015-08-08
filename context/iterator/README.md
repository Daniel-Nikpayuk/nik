iterator
========

<!--<a href="#decrement_assign">decrement_assign</a>-->

template&lt;typename OutputIterator, typename InputIterator&gt;<br>
static OutputIterator [decrement\_assign]("#decrement_assign")(OutputIterator, InputIterator, const InputIterator)

<div id="decrement_assign"/>

template&lt;typename OutputIterator, typename InputIterator&gt;<br>
decrement\_assign(OutputIterator out, InputIterator in, const InputIterator end)

*out*, *in*-->*end* are preallocated structures with *in* > *end*;
both *out* and *in* are decremented.

Assigns values iterated from *in*--*end* to *out* until *in* reaches *end*.

Primarily useful when shifting values rightward.

