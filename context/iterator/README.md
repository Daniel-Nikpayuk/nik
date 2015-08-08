iterator
========

<section id="bidirectional_iterator">
<nav>
 <ul>
  <li>
   <a href="#decrement_assign">
	template&lt;typename OutputIterator, typename InputIterator&gt;<br>
	static OutputIterator decrement_assign(OutputIterator, InputIterator, const InputIterator)
   </a>
 </ul>
</nav>
 <div id="decrement_assign">
	template&lt;typename OutputIterator, typename InputIterator&gt;<br>
	decrement_assign(OutputIterator out, InputIterator in, const InputIterator end)

	<em>out</em>, <em>in</em>--><em>end</em> are preallocated structures with <em>in</em> &gt; <em>end</em>&;
	both <em>out</em> and <em>in</em> are decremented.

	Assigns values iterated from <em>in</em>--<em>end</em> to <em>out</em> until <em>in</em> reaches <em>end</em>.

	Primarily useful when shifting values rightward.
 </div>
</section>

