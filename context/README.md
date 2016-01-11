Context
=======

# Context Space

Decomposed as its own technology space:

## Pedagogical Narrative:

The main question to keep in mind when interpreting the context is: What "universal" approach do we take to navigating memory?

As our technology space has been narrowed to a *computability space*, the context is interpreted as *memory* in an abstract sense.
The other major theme is that the context as implementation is where we store our generic templated methods. As this is the case,
our *template space* context becomes metacode: template code as overhead to ease the use of template programming toward our intended
generic memory methods. Templates (within the C++ grammar) are the language we use to access memory in the most general and universal way.
Regardless of how we represent our primitives of templates, and of how we constrain our use of them, they are our language of abstract
memory.

The template semiotic space---as computability space---is a *process* space: It holds primitive generic methods
(largely having to do with manipulating processor register data) used to represent access to memory in instantiated ways.

Our template media space then as constraint, becomes the constraints we allow in navigating memory. The thing is, there's no universal
best way to interpret what memory is, and so there ends up being more than one paradigm of navigation. The navigational constraint
made famous by the C++ STL is that of *iterators*. This is developed here certainly, but there is an alternative within the nik library:
*seperators*. Seperators are fundamentally sifters and filters when interpreting memory from the lens of set theory.

Template loop unrolling requires unambiguous policy as there are alternatives to general implementations.

Be it componentwise or arithmetic or general recursive, the solution arises from refactoring/compressing code to have a minimal footprint.
I have decided to borrow from mathematical/combinatorial best practices by making use of the identity value (zero value) as default
for the specialized initial "seed" code regarding unrolling. This would refactor the loop iterative code to be defined solely within
the general definition leaving the specialized case to be minimalistic as possible. Any "natural" (intuitive) implementations
as part of the user-friendly interface versions (as part of the clean/unsafe paradigm split) would handle any specialized
overhead.

There are several reasons for choosing this particular policy, though the main reason is in privileging the paradigm of seperating
clean "normal forms" from local user-friendly versions. If these unrolled loops really are cleanly defined, there's no need for
variant specializations in the first place. Having variant specializations would further encourage such poor/bad coding practices.

The other consideration is when one is able to define composite carrys being passed along the unrolled loop.
If one has a choice between extending the modification within the body before the next iterative call,
or within the arguements passed within the next iterative call, for code readability at least it is better to do so within the body.

I have run some basic g++ compiler behavioural tests suggesting an important property: Incrementation under template unrolling
is not persistent. As such, in order to be able to specialize within the user-friendly versions, one has two options:
Use the return version of unrolling to update the iterator, or pass the iterator type as a reference when calling.

How a #Mathematician sees #ComputingScience:

With implementation, you should have a universal medium (a universal construct language), then you can build non-linear stories
around an efficient implementation (minimizing redundancy and overhead) and then simply navigate the story-specifications in more
complex ways. This is already done with the relationship between hard drive storage and filesystems. Hard drive is (close) to universal,
while the filesystem is lightweight stories. This is already done in math: The real line (or n-dimensional real number system) is universal,
while stories around it become nuanced and are in need of localized navigational semiotics and semantics.

