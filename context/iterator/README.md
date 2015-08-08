iterator
========

# Bidirectional Iterator

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

