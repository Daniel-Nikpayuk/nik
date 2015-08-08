iterator
========

<table>
 <tr>
  <td><br>static OutputIterator</td>
  <td>

template&lt;typename OutputIterator, typename InputIterator&gt;<br>
<a href="#decrement_assign">decrement_assign</a>
(OutputIterator *out*, InputIterator, const InputIterator)

  </td>
 </tr>
</table>


<div id="decrement_assign"/>

template&lt;typename OutputIterator, typename InputIterator&gt;<br>
decrement\_assign(OutputIterator out, InputIterator in, const InputIterator end)

*out*, *in*-->*end* are preallocated structures with *in* > *end*;
both *out* and *in* are decremented.

Assigns values iterated from *in*--*end* to *out* until *in* reaches *end*.

Primarily useful when shifting values rightward.

