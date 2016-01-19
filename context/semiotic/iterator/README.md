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

