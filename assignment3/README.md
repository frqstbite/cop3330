# Assignment 3

## Overview

For this homework, you will write a class called `Date` in the files `date.h`
and `date.cpp` for creating and using objects that will store valid dates of
the year. This class should be portable, so it should work with any up-to-date
C++ compiler.

An object of type `Date` should represent a calendar date in terms of month,
day, and year, as on a 12-month A.D. calendar. The valid months are January
through December, a valid day must correspond to a valid day for the given
month, and the year must be a positive number no less than 1900.

**Note:** For convenient input (from keyboard or into functions), date values
will be specified with integers. Month values will be `1` for January, `2` for
February, and so on up to `12` for December. A valid day value will be an
integer between `1` and the number of days in the month (definitely no more
than `31`). Valid year values are positive integer numbers greater than or
equal to `1900`.

## Permitted Libraries

* `<cstring>`
* `<iostream>`
* `<string>`

## Class Specification

### Fields

#### `int month`

Should be an integer between `1` and `12`, inclusive.

#### `int day`

Should be an integer between `1` and the number of days in the specified month,
inclusive. Remember to account for leap years in the case of February.

#### `int year`

Should be an integer greater than or equal to `1900`.

A year is a leap year if it is divisible by `4`, except for century years
(years ending in 00). A century year is a leap year only if it is divisible by
`400`. (For instance, 2000 is a leap year, but 1900 is not).

### Constructors

#### `Date()`

Should create a `Date` object initialized to January 1, 2025.

#### `Date(int m, int d, int y)`

If any of the values would result in an invalid date, the constructor should
throw out the erroneous information and initialize the object to represent
1/1/2025 (January 1, 2025).

### Methods

Your `Date` class must provide the following services (i.e. member functions).
These functions will make up the interface of the class. Make sure you use
function prototypes as specified here. You may write other private functions
you feel necessary, but the public interface must include all the functionality
described below. For each function and each parameter, you need to think
carefully if `const` is needed for declaration and definition.


