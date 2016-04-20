Iterator
========

Componentwise?

Prototypical

*Pointer* iterators are pure in the sense that they have no side effects: They are an inventory of methods focused on accessing
and modifying pointers themselves, not having to do with the dereferenciable value they hold.

*Overload* iterators are the grammatically simplest variety of effective iterators.

There's a clear classification for "pure" or truly generic iterators and fuzzier iterator concepts: For example generic *list*
methods are presented here, but you could argue that lists manipulation methods could be classified under lists not iterators,
or that there's no clear hierarchy of type between the two. Fundamentally though, lists as memory are navigated by iterators,
and so are a form of iterator memory. Thus it's not unreasonable to privilege iterators over lists or vectors.
