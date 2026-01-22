# Assignment 1 Devlog

## 2.1 `Student`

```cpp
struct Student {
    int id;
    double gpa;
    int credits;
};
```

## 2.1.1 `Student makeStudent(int id, double gpa, int credits)`

```cpp
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
```

## 2.1.2 `bool isValidStudent(Student& s)`

```cpp
bool isValidStudent(Student& s) {
    // Validate GPA
    if (s.gpa < MIN_GPA || s.gpa > MAX_GPA)
        return false;
    
    // Validate credits
    if (s.credits < MIN_CREDITS || s.credits > MAX_CREDITS)
        return false;
    
    return true;
}
```

## 2.1.3 `bool updateGPA(Student& s, double newGPA)`

```cpp
bool updateGPA(Student& s, double newGPA) {
    if (newGPA < MIN_GPA || newGPA > MAX_GPA)
        return false;
    s.gpa = newGPA;
    return true;
}
```

## 2.1.4 `bool addCredits(Student& s, int creditsToAdd)`

```cpp
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
```

## 2.1.5 `bool addCredits(Student& s)`

```cpp
bool addCredits(Student& s) {
    return addCredits(s, 3);
}
```