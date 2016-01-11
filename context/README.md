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

Template loop unrolling until further notice assumes the partially specialized iteration coincides with the final iteration of the loop.
Such policy may change under a better understanding of general design, but is otherwise needed as clean loops when optimized toward
their "normal" (intuitive) use (safe/user-friendly form) often require overhead before and/or after the main loop. The main issue
stems from the "carry" variable passing information from one iteration to the next. It's possible to use that carry value to
pass some initial iterative information which then shifts the loop such that the partially specialized case more often than not
passes as the identity. This would reduce code size for these functions, but would then require more detailed information in
constructing the initial carry. Another way to change this is to define the N=0 case instead of the N=1 case.

