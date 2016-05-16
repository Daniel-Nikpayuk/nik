semiotic
========

## Pedagogical Narrative:

These classes as part of the semiotic space are designed to represent and access the memory space through its
object oriented constructs. Furthermore, such classes should be defined in a way to be as self-similar as possible
for recursive composability or inheritance.

Regarding design policy, we extend the natural underlying grammer with the above direction in mind. Classes
as grammar constructs primarily have constructors, destructors, and copy constructors if nothing else.
These though are not self-similar regarding composability or inheritance as they cannot be called directly.
Furthermore, "protected" and "private" class declarations furthermore break such composability and inheritance.

	Given this, the policy here is to circumvent constructors, copy constructors and destructors,
	as well as to avoid protected and private declarations leaving everything public and unsafe (struct).

With this established, the next policy consideration is the composable nature of these alternate constructors
and desstructors as well as how they relate to the proper constructors and destructors as their use cannot
be avoided. An additional feature a generic defined class will have is member data (otherwise why define the class?).
Constructors normally initialize that data.

	Given this, the policy first is to differentiate our alternates from proper constructors by changing
	their names. Instead of "construct" or "instantiate" which is terminology meant for objects,
	we will use:

		initialize(), terminalize(), copy_initialize<>().

	As we are looking to circumvent the automatic nature of constructors and destructors, our proper
	constructors and destructors and copy constructors must be explicitly defined to do nothing.
	This is less safe as the burden is now placed on the api coder to call the initializers and
	terminalizers explicitly.

Finally, the classes within the semiotic space are generally expected to have one additional constraint:
They are expected to interact with memory dynamically. Once initialized, it is expected to have various
"grow" as well as "shrink" methods. It is tempting to include defaults here, but doing so would create
implicit assumptions about how best to "grow" and "shrink" such memory. As such it is left to the iterator
inventories.

-------------------

The semiotic space is also the best place to set up "traits" for these templated classes.

For efficiency, these classes do not test against self-assignment. Burden is placed on the low-level coder.

