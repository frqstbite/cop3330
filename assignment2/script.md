# Assignment 2 Script

## Intro

Hey. My name is Ashi Meide, and I'm taking COP3330 during the Spring 2026
semester. This video is intended to be submitted alongside my code for
assignment 2.

## Header

### Fields

### Constructors

### Methods

## Implementation

### Constructors

### Methods

## Build Process

Before we talk about the output, I want to talk about my build process.

My build pipeline expanded significantly since the last assignment. I now have
a main makefile in the root directory of the repository that orchestrates the
build process, while each assignment has its own makefile that handles the
specifics of building, testing, and submitting that assignment. The idea here
was to make it trivial to centrally manage the build process across all
assignments while still allowing each individual assignment's makefile to be
self-sufficient and focused on the specifics of its codebase.

The `common.mk` fragment file provides a consistent set of targets and
variables that allow you to build from either the assignment makefile OR the
repository makefile. In essence, it defines an interface for specifying _where_
build artifacts should be placed. The `assignment.mk` fragment file is an
extension of `common.mk` that includes common targets and variables for
building, testing, and submitting C++ code. The master makefile then defers to
the assignment makefiles to do the heavy lifting.

## Compare Output

For the last assignment I manually compared the output by eye. Now that I have
a `test` target, I can automate that process. To verify the correctness of my
implementation, I can simply `diff` the program output against the provided
output file. Because `diff` returns a non-zero exit code if the files differ,
the target will automatically fail if the output doesn't match the expected
output. However, I did have to modify the `driver.cpp` file to use a constant
seed for the random number generator so that the output is deterministic. I
then simply modified the sphere colors to match what they would be with the new
seed. With that, I can be confident that my implementation is correct as long
as the `test` target passes.

## Outro

This video was composited through [Motion Canvas][motioncanvas],
an open source [TypeScript] library for creating animated videos using the
[Canvas API][canvasapi]. The full source code that generated this video,
alongside my complete solution for assignment 1, can be found in an unlicensed
GitHub repository available in this video's description. Thank you.

[motioncanvas]: https://motioncanvas.io
[typescript]: https://www.typescriptlang.org
[canvasapi]: https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API
