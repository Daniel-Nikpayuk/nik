Iterator
========

Componentwise?

Prototypical

*Functional* iterators are functional in the sense that they have no side effects. They are methods on the iterators themselves.
Every other variety of iterator (not classified as functional) comes with side effects (*effective*) on the dereference values
of these iterators.

*Overload* iterators are the grammatically simplest variety of effective iterators.

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
