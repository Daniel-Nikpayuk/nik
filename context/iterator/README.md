iterator
========

Iterators are a universal currency in templated C++, and so there should be a strong iterator library. It's also worth
the time thinking harder as to what an iterator is. Namely, an iterator is a vehicle, which provides access to content
of interest. An iterator itself is overhead, but given it can't be avoided, there are algorithms to make interaction
with them directly easier to use. Mostly though, the vast majority of generic iterator algorithms will be as means to
interact with the data referenced by such iterators.

Iterators are actually a strange construct from a pure theoretical view. Each primitive generic method in this contextual
library is intended to modify the internal state of a given object, so with Iterators you could loop increment and return
the resulting iterator, for example. Or just as well, you could specify the identity function on iterators, but because
of the nature of internal state, there actually is no such thing as *the* identity function. There would be infinitely
many possible such functions for the reason that each could have its own *side effects*. Same goes with a generic loop
increment method---each having its own side effects. Generally these side effects in practice would be to modify what
the iterator points to, what it refers to, and even though the input iterator itself might be modified, it's more of
an means to an end. This behaviour tends to be strange because the best way to classify such intentions are still by
means of iterators.

Each generic iterator class is narrowed by an attribute, a modifier, so for example "forward iterator" generic algorithms
act on iterators which are known to have an accessible forward direction. In the case of "iterator value", this collection
of algorithms don't put their emphasis on accessing or modifying the iterators themselves, rather it privileges acts upon
the iterator values.

#### Forward Iterator

<table>
 <tr>
  <td><br>static SizeType</td>
  <td>
template&lt;typename SizeType, typename InputIterator, typename TerminalIterator&gt;<br>
<a href="#forward_size">size</a>(InputIterator <em>in</em>, TerminalIterator <em>end</em>)
  </td>
 </tr>
 <tr>
  <td><br>static Iterator</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#forward_left_increment">left_increment</a>(Iterator & <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static Iterator</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#forward_right_increment">right_increment</a>(Iterator & <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static void</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#forward_advance">advance</a>(Iterator & <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static Iterator</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#forward_forward">forward</a>(Iterator <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static void</td>
  <td>
template&lt;typename OutputIterator, typename InputIterator, typename TerminalIterator&gt;<br>
<a href="#forward_plus_assign1">plus_assign</a>(OutputIterator <em>out</em>, InputIterator <em>in</em>, TerminalIterator <em>end</em>)
  </td>
 </tr>
 <tr>
  <td><br>static OutputIterator</td>
  <td>
template&lt;typename OutputIterator, typename InputIterator, typename TerminalIterator&gt;<br>
<a href="#forward_plus_assign2">plus_assign</a>(OutputIterator <em>out</em>, InputIterator <em>in</em>, TerminalIterator <em>end</em>)
  </td>
 </tr>
 <tr>
  <td><br>static void</td>
  <td>
template&lt;typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator&gt;<br>
<a href="#forward_plus1">plus</a>(OutputIterator <em>out</em>, InputIterator1 <em>in1</em>, InputIterator2 <em>in2</em>, TerminalIterator <em>end</em>)
  </td>
 </tr>
 <tr>
  <td><br>static OutputIterator</td>
  <td>
template&lt;typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator&gt;<br>
<a href="#forward_plus_assign2">plus_assign</a>(OutputIterator <em>out</em>, InputIterator1 <em>in1</em>, InputIterator2 <em>in2</em>, TerminalIterator <em>end</em>)
  </td>
 </tr>
</table>

#### Bidirectional Iterator

<table>
 <tr>
  <td><br>static Iterator</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#plus">plus</a>(Iterator <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static Iterator</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#minus">minus</a>(Iterator <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static void</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#plus_assign">plus_assign</a>(Iterator & <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static void</td>
  <td>
template&lt;typename Iterator, typename SizeType&gt;<br>
<a href="#minus_assign">minus_assign</a>(Iterator & <em>out</em>, SizeType <em>n</em>)
  </td>
 </tr>
 <tr>
  <td><br>static OutputIterator</td>
  <td>
template&lt;typename OutputIterator, typename InputIterator&gt;<br>
<a href="#decrement_assign">decrement_assign</a>(OutputIterator <em>out</em>, InputIterator <em>in</em>, const InputIterator <em>end</em>)
  </td>
 </tr>
</table>

<div id="plus"/>

template&lt;typename Iterator, typename SizeType&gt;<br>
static Iterator **plus**(Iterator <em>out</em>, SizeType <em>n</em>)

<div id="minus"/>

template&lt;typename Iterator, typename SizeType&gt;<br>
static Iterator **minus**(Iterator <em>out</em>, SizeType <em>n</em>)

<div id="plus_assign"/>

template&lt;typename Iterator, typename SizeType&gt;<br>
static void **plus\_assign**(Iterator & <em>out</em>, SizeType <em>n</em>)

<div id="minus_assign"/>

template&lt;typename Iterator, typename SizeType&gt;<br>
static void **minus\_assign**(Iterator & <em>out</em>, SizeType <em>n</em>)

<div id="decrement_assign"/>

template&lt;typename OutputIterator, typename InputIterator&gt;<br>
static OutputIterator **decrement\_assign**(OutputIterator <em>out</em>, InputIterator <em>in</em>, const InputIterator <em>end</em>)

*out*, *in*-->*end* are preallocated structures with *in* > *end*;
both *out* and *in* are decremented.

Assigns values iterated from *in*--*end* to *out* until *in* reaches *end*.

Primarily useful when shifting values rightward.

