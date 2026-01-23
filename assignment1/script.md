# Assignment 1 Script

## Intro

Hey. My name is Ashi Meide, and I'm taking COP3330 during the Spring 2026
semester. This video is intended to be submitted alongside my code for
assignment 1.

## Expected Output

For the purposes of this assignment, our `main()` function will run our test
cases. To determine if the code is written correctly, we need to know what we
should expect the output of these test cases to be. Since it's not provided to
us, it wouldn't hurt to start by figuring that out first.

This is the full source code for the `main()` function. It is *hefty* at 34
lines, excluding whitespace. I'm going to break it down piece-by-piece and put
the expected output on the right.

First, we make an initial `Student` struct and print it out. Since we don't
write the printing logic, this is moreso about making sure that our `Student`
definition is structured correctly, because otherwise the `printStudent`
function would blow up in our face.
```
999 3.8 25
```

Then we start testing boundaries. My understanding is that the boundaries for
GPA and credits are supposed to be inclusive, which means that both of these
calls to `updateGPA()` should succeed and output `true`. Finally, of course,
the printed `Student` struct should reflect the most recent update to the GPA,
which we see here is `4`.
```
true
true
999 4 25
```

The next block of tests check what happens if the GPA boundary is exceeded. In
both cases here it should output `false` for underflowing and overflowing the
boundary, respectively, followed by the unchanged student.
```
false
false
999 4 25
```

Next, we check for the `addCredits()` function's ability to validate its
arguments. The number passed must be positive, excluding zero, so both of these
calls should fail. The printed student should be unchanged.
```
false
false
999 4 25
```

The `addCredits()` function should also have an overload that automatically adds
three credits. We're well below the upper limit of credits, so this call should
succeed and output `true` followed by the modified `Student`.
```
true
999 4 28
```

Next, we directly assign the `Student`'s credits to be 3 short of the maximum
and print out the result. With a maximum of 180, the `Student` should have 177
credits.
```
999 4 177
```

Then we make sure that our overload for `addCredits()` that allows us to
specify the credit amount behaves as we expect by attempting to add one
credit and printing the result.
```
true
999 4 178
```

Finally, in this last portion, we explicitly check that a `Student` struct
produced by the `makeStudent()` function passes the `isValidStudent()` smell-
test. This probably should've been checked earlier, but... better late than
never, I guess. Since `makeStudent()` clamps our GPA and credit values, the
resulting `Student`s should be completely valid.
```
100 4 10
true
101 3 0
true
```

This gives us the complete output we should expect from a functioning
implementation of this program.

## Implementations

Now that we've squared that away, we can begin coding.

### Student (2.1)

The first thing we need to implement is the `Student` struct. A `Student`
should have an integer ID (`int id`), a floating-point GPA (`double gpa`), and
an amount of credits represented by another integer (`int credits`). Simple
enough.

### makeStudent (2.2.1)

Now that we've defined the `Student` struct, we need to write a constructor for
it. In this program, that will take the form of a `makeStudent()` function. As
input, it should take the three pieces of data we associate with a `Student`.
A naive first step would be to return a new `Student` verbatim. This *is* the
last line that we need, but theres some boundary checks we need to implement
first. If the supplied GPA overflows or underflows our GPA boundaries, we need
to clamp it. The same goes for the credits and credit boundaries.

### isValidStudent (2.2.2)

Next, we need to write a simple validation function for our `Student` struct.
Since there's only two ways a `Student` can be invalid, we'll have two
bounary checks; one will check the GPA, and the other will check the credits.
If both checks pass, the `Student` is valid. Light work.

### updateGPA (2.2.3)

The next function we need to implement is a setter for a `Student`'s GPA.
A naive implementation would set the GPA and be done with it, but we also need
to make sure the new GPA is within our limits.

### addCredits (2.2.4 & 2.2.5)

Finally, we need a function to add to a `Student`'s credits, with two
stipulations. We need the number of credits we want to add, called
`creditsToAdd` here, to be positive. We also don't want to exceed the upper
bound for a `Student`'s credits. We will only add the credits if both
stipulation are satisfied.

Oh, and, uh, we need an overload too. It just adds 3 credits if an amount is
not specified. Could've been implemented with a default parameter value, but...
whatever. Maybe it does the same thing under the hood.

With that, we've implemented our `Student` struct and the required satellite
functions.

## Compare Output

Upon running our completed file, we receive the results we predicted earlier.
While I did, for the most part, get the correct output on my first attempt, I
excluded some minor bug fixing I had to do in favor of a detailed explanation
of why the final implementation looks and behaves the way it does.

## Outro

This video was composited through [Motion Canvas][motioncanvas],
an open source [TypeScript] library for creating animated videos using the
[Canvas API][canvasapi]. The full source code that generated this video,
alongside my complete solution for assignment 1, can be found in an unlicensed
GitHub repository available in this video's description. Thank you.

[motioncanvas]: https://motioncanvas.io
[typescript]: https://www.typescriptlang.org
[canvasapi]: https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API