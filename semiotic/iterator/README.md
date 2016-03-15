semiotic
========

## Pedagogical Narrative:

Semiotic classes are meant to be weak structures which are efficient and reusable. In this case, their design
is influenced also by C++ classes. Most importantly, C++ class constructors and destructors are not inherited
through class inheritance (by default), even though many component parts of such constructors and destructors
are generic and reusable. As such, the general design of classes in the semiotic space should have inheritable
methods for initializing and terminalizing (constructing and destructing) the classes.

Keep in mind as far as reuse goes, there is composition and there is inheritance. Design should maintain highest
entropy for both. In addition, careful consideration should be given to which methods to declare as virtual
regarding inheritance policies of polymorphism.

The semiotic space is also the best place to set up "traits" for these templated classes.

For efficiency, these classes do not test against self-assignment. Burden is placed on the low-level coder.

