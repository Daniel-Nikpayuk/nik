Iterator
========

Componentwise?

Prototypical

*Overload* iterators are the grammatically simplest variety of effective iterators.

"Closed" are equivalent to the overload methods, and could have been implemented at the same level (similar to the way
"componentwise" and "extensionwise" are), but as the main behavioural difference is from "while" to "do while" looping,
it makes sense to parallel them to their "while" and "do while" grammatical constructs: These grammar points are also
at the same level, but in practice "do while" is used far less often. Given this consideration I have decided on the policy
to navigate the "closed" variety within the name/struct spaces of the default variety.

There's a clear classification for "pure" or truly generic iterators and fuzzier iterator concepts: For example generic *list*
methods are presented here, but you could argue that lists manipulation methods could be classified under lists not iterators,
or that there's no clear hierarchy of type between the two. Fundamentally though, lists as memory are navigated by iterators,
and so are a form of iterator memory. Thus it's not unreasonable to privilege iterators over lists or vectors.

*no_return / with_return* is distinguished from *no_break / with_break* on account that a return is given inside the loop itself,
which potentially breaks the loop. In such cases, the loop-comparison iterator (in != end) is returned instead of the default *out*.
The reason for this is when there is no such loop breaking, the *in* iterator will equal *end* upon completion, and there is no
need for a return.

Iterators are prefixed with:

+R: Read
+W: Write
+RW: Read/write
+E: End.

WIterators are assumed safe for modification.
In practice this means providing a deep copy if necessary when passing const references as input.

Ordering policy for function arguments:

These templated functions are meant not only to be generic extensions of the existing implementation grammar,
but for greatest use, they are also meant to be composable with each other. Thus we privilege composability.
Keep in mind though the semiotics here are regarding *iterators* and so in order for them to be composable
the return value must be the primary iterator of interest. I've already decided to maintain "no\_return"
as well as "with\_return" versions for each function, and as such given the nature of C++ template deduction,
it is best to present this primary iterator of interest as the first argument (for the sake of the no\_return version)
as this way its type can be declared as a reference when necessary (without having to declare other types).
Such a policy supports the privileging of composability as it reduces grammar declarations for the user.

There is a slight twist though. Within the arithmetic classes, there is notably a "carry" value which for composability
purposes should preceed the primary iterator.

Finally, any read only iterators or constants should come after, as their types will not likely need to be declared
explicitly.

Policy also needs to be set regarding iterator intervals [in, end) related to iterator types: bidirectional, random\_access.
For example with bidirectional, you might have a forward iterator in1--end1 as well as a backward iterator in2--end2.
What order do you present these as function arguments? If for example (in1, end1, end2, in2), then this implicitly privileges
forward iteration. This lowers entropy in general and as such it is better to privilege (initial, terminal) regardless of
iterator direction. By extension, if you have any inbetween iterator values, they should be ordered accordingly.

