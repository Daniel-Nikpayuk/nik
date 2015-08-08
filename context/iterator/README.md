iterator
========

<section id="bidirectional_iterator">
<nav>
 <ul>
  <li>
   <a href="#decrement_assign">
	template&lt;typename OutputIterator, typename InputIterator&gt;
	static OutputIterator decrement_assign(OutputIterator, InputIterator, const InputIterator)
   </a>
 </ul>
</nav>
 <div id="decrement_assign">
	template&lt;typename OutputIterator, typename InputIterator&gt;
	decrement_assign(OutputIterator out, InputIterator in, const InputIterator end)

	*out*, *in*-->*end* are preallocated structures with *in* > *end*; both *out* and *in* are decremented.

	Assigns values iterated from *in*--*end* to *out* until *in* reaches *end*.

	Primarily useful when shifting values rightward.
 </div>
</section>

