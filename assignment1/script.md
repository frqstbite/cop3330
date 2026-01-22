# Assignment 1 Script

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
struct definition is structured correctly, because otherwise the `printStudent`
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

Next, we check for the `addCredit()` function's ability to validate its
arguments. The number passed must be positive, excluding zero, so both of these
calls should fail. The printed student should be unchanged.
```
false
false
999 4 25
```

The `addCredit()` function should also have an overload that automatically adds
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
credit and print the result.
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
implementation of this program. With that out of the way, we can begin coding.
