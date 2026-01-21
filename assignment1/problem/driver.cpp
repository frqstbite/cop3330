#include <iostream>
using namespace std;


// Global Boundary Constants

const double MIN_GPA = 0.0;
const double MAX_GPA = 4.0;

const int MIN_CREDITS = 0;
const int MAX_CREDITS = 180;


// TODO: Define a struct named Student with the following fields:
//       int id
//       double gpa
//       int credits

// TODO: Implement 
// Student makeStudent(int id, double gpa, int credits);

// TODO: Implement 
// bool isValidStudent(Student& s);

// TODO: Implement 
// bool updateGPA(Student& s, double newGPA);

// TODO: Implement 
// bool addCredits(Student& s, int creditsToAdd);

// TODO: Implement 
// bool addCredits(Student& s);

//print function do not change
void printStudent(const Student& s)
{
    cout << s.id << " " << s.gpa << " " << s.credits << endl;
}
int main()
{
    Student s = makeStudent(999, 3.8, 25);
    printStudent(s);

    bool ok;
    cout << boolalpha;

    ok = updateGPA(s, MIN_GPA);
    cout << ok << endl;
    ok = updateGPA(s, MAX_GPA);
    cout << ok << endl;
    printStudent(s);

    ok = updateGPA(s, -0.1);
    cout << ok << endl;
    ok = updateGPA(s, 4.0001);
    cout << ok << endl;
    printStudent(s);

    ok = addCredits(s, 0);
    cout << ok << endl;
    ok = addCredits(s, -5);
    cout << ok << endl;
    printStudent(s);

    ok = addCredits(s);
    cout << ok << endl;
    printStudent(s);

    s.credits = MAX_CREDITS - 3;
    printStudent(s);

    ok = addCredits(s, 1);
    cout << ok << endl;
    printStudent(s);

    Student s2 = makeStudent(100, 5.0, 10);
    Student s3 = makeStudent(101, 3.0, -1);

    printStudent(s2);
    ok = isValidStudent(s2);
    cout << ok << endl;

    printStudent(s3);
    ok = isValidStudent(s3);
    cout << ok << endl;

    return 0;
}

