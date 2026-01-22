#include <iostream>
using namespace std;


// Global Boundary Constants

const double MIN_GPA = 0.0;
const double MAX_GPA = 4.0;

const int MIN_CREDITS = 0;
const int MAX_CREDITS = 180;


struct Student {
    int id;
    double gpa;
    int credits;
};

Student makeStudent(int id, double gpa, int credits) {
    // Clamp GPA
    if (gpa > MAX_GPA) {
        gpa = MAX_GPA;
    } else if (gpa < MIN_GPA) {
        gpa = MIN_GPA;
    }

    // Clamp credits
    if (credits > MAX_CREDITS) {
        credits = MAX_CREDITS;
    } else if (credits < MIN_CREDITS) {
        credits = MIN_CREDITS;
    }

    return Student { id, gpa, credits };
}

bool isValidStudent(Student& s) {
    // Validate GPA
    if (s.gpa < MIN_GPA || s.gpa > MAX_GPA)
        return false;
    
    // Validate credits
    if (s.credits < MIN_CREDITS || s.credits > MAX_CREDITS)
        return false;
    
    return true;
}

bool updateGPA(Student& s, double newGPA) {
    if (newGPA < MIN_GPA || newGPA > MAX_GPA)
        return false;
    s.gpa = newGPA;
    return true;
}

bool addCredits(Student& s, int creditsToAdd) {
    // Must add positive number of credits
    if (creditsToAdd < 1)
        return false;
    
    // Bound to limits
    if (s.credits + creditsToAdd < MIN_CREDITS || s.credits + creditsToAdd > MAX_CREDITS)
        return false;

    s.credits += creditsToAdd;
    return true;
}

bool addCredits(Student& s) {
    return addCredits(s, 3);
}

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

