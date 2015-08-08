iterator
========

Iterators are a universal currency in templated C++, and so there should be a strong iterator library. It's also worth
the time thinking harder as to what an iterator is. Namely, an iterator is a vehicle, which provides access to content
of interest. An iterator itself is overhead, but given it can't be avoided, there are algorithms to make interaction
with them directly easier to use. Mostly though, the vast majority of generic iterator algorithms will be as means to
interact with the data referenced by such iterators.

Each generic iterator class is narrowed by an attribute, a modifier, so for example "forward iterator" generic algorithms
act on iterators which are known to have an accessible forward direction. In the case of "iterator value", this collection
of algorithms don't put their emphasis on accessing or modifying the iterators themselves, rather it privileges acts upon
the iterator values.

#### Forward Iterator

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

