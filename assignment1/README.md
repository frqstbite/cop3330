# Assignment 1

## Overview

In this assignment, you will practice core C++ basics, including defining and
using a `struct`, writing functions that manipulate a structure, performing
input validation with boundary conditions, and using function overloading.

You will complete the provided `driver.cpp`. The provided `main()` function
will test your implementation using different cases. You are given a
`driver.cpp` file that already contains global boundary constants for GPA and
credits, a fixed `printStudent` function, a fixed `main()` test driver, and
TODO comments indicating what you must implement.

**Do not modify the provided `printStudent` function or the provided `main()` function.**

## Boundary Constraints

The following constants are provided in the starter code:

```cpp
MIN GPA = 0.0, MAX GPA = 4.0
MIN CREDITS = 0, MAX CREDITS = 180
```

Your implementation must ensure that GPA and credits always remain within these
ranges.

## Implementations

### Define the `Student` Structure

Define a structure named `Student` with exactly three fields: an integer
student ID (`int id`), a double-precision GPA (`double gpa`), and an integer
number of credits (`int credits`).

### Implement Required Functions

You must implement the following functions exactly as specified in the starter
code. Function names and parameter lists must not be changed.

#### `Student makeStudent(int id, double gpa, int credits)`

This function constructs and returns a `Student`. The student ID must be set
directly from the input parameter. If the provided GPA is outside the valid
range, it must be clamped to the nearest boundary. Similarly, if the provided
number of credits is outside the valid range, it must be clamped to the nearest
boundary too.

#### `bool isValidStudent(Student& s)`

This function checks whether a student record is valid. It should return `true`
if both the GPA and the number of credits are within their respective valid
ranges, and `false` otherwise.

#### `bool updateGPA(Student& s, double newGPA)`

This function attempts to update the student’s GPA. If the new GPA is within
the valid range, the GPA should be updated, and the function should return
`true`. Otherwise, the GPA must remain unchanged, and the function should
return `false`.

#### `bool addCredits(Student& s, int creditsToAdd)`

This function attempts to add credits to the student record. The number of
credits to add must be non-negative (including 0). If adding the credits would
cause the total to exceed the maximum allowed number of credits, the function
must fail. In either failure case, the student record must remain unchanged,
and the function should return `false`. Otherwise, the credits should be added,
and the function should return `true`.

#### `bool addCredits(Student& s)`
This is an overloaded version of `addCredits`. It must add exactly 3 credits to
the current credits. Similar to `bool addCredits(Student& s, int creditsToAdd)`,
if adding credits would cause the total to exceed the maximum allowed number of
credits, the function must fail. In the failure case, the student record must
remain unchanged and the function should return `false`. Otherwise, the credits
should be added and the function should return `true`.