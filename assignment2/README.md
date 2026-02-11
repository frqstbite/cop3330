# Assignment 2

## Overview

You are to write a class called `Sphere`, using filenames `sphere.h` and
`sphere.cpp`. This class will allow for the creation and handling of `Sphere`
objects.

A sample main program (`driver.cpp`) that uses objects of type `Sphere` and
illustrates sample usage of the member functions is provided. You will also
find a sample output from the sample execution of the `driver.cpp` program.
Your class declaration and definition files must work with the main program
(`driver.cpp`), as-is (do not change the `driver.cpp` file to make your code
work!). You are encouraged to write your own driver routines to further test
the functionality of your class as well. Most questions about the required
behavior of the class and the expected output can be determined by carefully
examining the driver program and the sample execution.

## Permitted Libraries

* `<cstdlib>`
* `<ctime>`
* `<iomanip>`
* `<iostream>`

## Class Specification

### Fields

#### `double radius`

Should always be greater than 0.

#### `char color`

The valid values for `color` are `'B'` (blue), `'R'` (red), `'P'` (purple),
`'Y'` (yellow), `'G'` (green), `'L'` (black), and `'M'` (maroon).

### Constructors

#### `Sphere()`

Create a `Sphere` object of `radius` `1.0` and a random color (use a random
number generator for this).

#### `Sphere(double r, char c)`

If the radius provided is smaller or equal to `0.0`, set the `radius` to `1.0`.
If the color is not specified or is an invalid value, a random color should be
assigned as the color of the `Sphere` (use a random number generator for this).

When entering the color,
**BOTH uppercase and lowercase input should be accepted.**

### Methods

#### `getRadius`, `getColor`, `getDiameter`, `getSurfaceArea`, and `getVolume`

These getter methods return the radius, color, diameter, surface area, and
volume of the sphere, respectively.

#### `setRadius`

Should receive a `double` as parameter and update the `Sphere`’s `radius` to be
that value if the value is larger than `0.0`. No change should be made if the
`radius` provided as parameter is smaller than or equal to `0.0`.

#### `setColor`

This function should update the `Sphere`’s `color` accordingly if the `char`
provided is a valid color character. No change should be made if the `char`
provided is not a valid color.

#### `grow`, `shrink`

Will increase or decrease, respectively, the radius of the `Sphere` by the
given `double` value, unless this would cause the `radius` to be less than or
equal to `0.0`. If applying `grow` or `shrink` leads to a `radius` less than or
equal to `0.0`, no change should be made.

#### `randomizeColor`

Should randomly assign a new color for the `Sphere` object.

#### `printSummary`

Receives an optional integer precision as parameter and displays all
the information about a sphere — one item per line: its `radius`, `color`,
diameter, volume, and surface area. When displaying the data, always show
exactly the number of decimal places specified by the precision parameter. If
no precision is specified, or the precision is larger than `5` or smaller than
`1`, the output should be shown to two decimal places. The summary should print
the color of the sphere as the full word for that color (e.g., Red, Green) and
not only the `char` representation stored in the object. Your output should be
in the exact same format shown in the example below.

Given a blue `Sphere` with `radius` `1.0`, a call to `printSummary` with a
precision parameter of `2` would produce the following output:

```
Radius: 1.00
Color: Blue
Diameter: 2.00
Volume: 4.19
Surface Area: 12.57
```
