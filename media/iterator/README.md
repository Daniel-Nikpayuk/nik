media
=====

# Media Space

Decomposed as its own technology space:

+ context - *literic*.
+ semiotic - *graphic*, *interic*, *kinetic*, *numeric*, *phonetic*.
+ media - *generic*.

## Intuition

Borrowing from the *Unix Philosophy*:

> Write programs that do one thing and do it well.
> Write programs to work together. Write programs to handle text streams,
> because that is a universal interface. (A Quarter Century of Unix, Salus)

Textual strings are universal. This is to say, the hardware type which has highest entropy (information theory)
relative to the other hardware representations is the literic classes which deal with textual and computational
literary analyses. It follows then that this would be the *subtext* (sub-context space) within the decomposition
of the main media space.

Regarding subsemiotics: The graphic, interic, kinetic, numeric, and phonetic classes are all intended to represent
a specific hardware component, and as such fit best into the semiotic framework. The *numeric* classes are notably
privileged with much time spent in optimization as they primarily consist of extended number classes: *block* being
a templated *int* class of dynamic but fixed length.  The *dynamic_block* is like the "Big Int" class in the Python
or Java programming languages. As arithmetic is used repeatedly in many different classes throughout this library,
special attention has been paid to these "workhorse" (or in the Inuit case, "workdog") classes and should be for any
future extensions.

Finally, the submedia is represented with the generic but safe classes. Generics are generic data structures, which
are constraints applied to accessing the relationships between the subsemiotics and their subtext. In practice,
the relationship between signifier and signfied (context) plays out as *translation*. As strings are the universal
medium, we should be able to translate any of the other specific hardware representations to and from string data.
In this sense the other classes are centralized around the literics classes. In particular then, special care is also
given to some of these classes like *regular expressions* because they also form workhorse classes within this whole
library.

## Folders

The current folders within this directory are as follows:

+ generic
+ graphic
+ interic
+ kinetic
+ literic
+ numeric
+ phonetic

## Pedagogical Narrative:

Logically it makes sense to start with the *display* class within the *generic* folder; it is the STL equivalent of *cout*.
This is necessary as debugging is constantly required for every single class added to this library, and one of
the best ways to do so is to print values to the screen.

