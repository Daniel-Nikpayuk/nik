Context
=======

# Context Space

The library design as a whole primarily extends the existing grammar of the existing C++ language---as it is implementation oriented.
We could do that for each modular and/or extensible builtin grammar point (and we do), but we'd still be left with a semantic mess
of how to organize it all after that. We categorize the grammar points as a *technology space*.

Our technology space is a computability space. A computability space's context is a memory space. Looking at the grammar space of C++,
the memory space is oriented around the memory hardware as well as the primitive builtin types. Extending this, its type system
is further built on top of templates. Thus, any classes that maximally privilege the representation of hardware memory, primitive types,
as well as templates should be centered in the context space. Breaking down the context space though, the most abstract or low level
interactions with types and hardware is the context of the context space. The base form of hardware memory is the register, so any
code which idealizes that belongs in the context. The semiotics have more to do with refined constructs to represent more refined
forms of memory such as the RAM. Thus, generic high entropy highly compressible constructs (templated iterator and pointer methods)
belong here. In the context's media space belong less compressible safer forms of meaningful generic algorithms.

