#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "sphere.h"
using namespace std;

const double PI = 3.14159;   // Operating definition of PI from the assignment
const int COLUMN_WIDTH = 15; // For formatting output

/*
 * Constructors
 */

Sphere::Sphere() : Sphere(1.0) {}

Sphere::Sphere(double r, char c)
{
    // Clamp radius
    if (r <= 0.0)
        radius = 1.0;
    else
        radius = r;

    // Validate color character
    switch (c)
    {
    // Case insensitive
    case 'b':
        color = 'B';
        break;
    case 'r':
        color = 'R';
        break;
    case 'p':
        color = 'P';
        break;
    case 'y':
        color = 'Y';
        break;
    case 'g':
        color = 'G';
        break;
    case 'l':
        color = 'L';
        break;
    case 'm':
        color = 'M';
        break;

    case 'B':
    case 'R':
    case 'P':
    case 'Y':
    case 'G':
    case 'L':
    case 'M':
        color = c;
        break;

    default:
        randomizeColor(); // Invalid character, randomize
    }
}

/*
 * Getters
 */

double Sphere::getRadius() const
{
    return radius;
}

char Sphere::getColor() const
{
    return color;
}

double Sphere::getDiameter() const
{
    return 2.0 * radius;
}

double Sphere::getSurfaceArea() const
{
    return 4.0 * PI * radius * radius;
}

double Sphere::getVolume() const
{
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

/*
 * Setters
 */

void Sphere::setRadius(double r)
{
    if (r > 0.0)
    {
        radius = r;
    }
}

void Sphere::setColor(char c)
{
    switch (c)
    {
    case 'B':
    case 'R':
    case 'P':
    case 'Y':
    case 'G':
    case 'L':
    case 'M':
        color = c;
    }
}

void Sphere::grow(double r)
{
    if (radius + r > 0.0)
    {
        radius += r;
    }
}

void Sphere::shrink(double r)
{
    grow(-r);
}

void Sphere::randomizeColor()
{
    const char colors[] = {'B', 'R', 'P', 'Y', 'G', 'L', 'M'};
    color = colors[rand() % 7]; // Select randomly from list
}

/*
 * Loggers
 */

void Sphere::printSummary(int precision) const
{
    cout << fixed << setprecision(precision) // Set desired precision
         << right;                           // Align right for better formatting

    // Radius
    cout << setw(COLUMN_WIDTH) << "Radius:"
         << setw(COLUMN_WIDTH) << radius << endl;

    // Color
    cout << setw(COLUMN_WIDTH) << "Color:"
         << setw(COLUMN_WIDTH);
    switch (color)
    {
    case 'B':
        cout << "Blue";
        break;
    case 'R':
        cout << "Red";
        break;
    case 'P':
        cout << "Purple";
        break;
    case 'Y':
        cout << "Yellow";
        break;
    case 'G':
        cout << "Green";
        break;
    case 'L':
        cout << "Black";
        break;
    case 'M':
        cout << "Maroon";
        break;
    }
    cout << endl;

    // Diameter
    cout << setw(COLUMN_WIDTH) << "Diameter:"
         << setw(COLUMN_WIDTH) << getDiameter() << endl;

    // Volume
    cout << setw(COLUMN_WIDTH) << "Volume:"
         << setw(COLUMN_WIDTH) << getVolume() << endl;

    // Surface Area
    cout << setw(COLUMN_WIDTH) << "Surface Area:"
         << setw(COLUMN_WIDTH) << getSurfaceArea() << endl;
}