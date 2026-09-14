/*
 * Course: COEN 2220 - Programming 2
 * Name: Mario A. Marrero Colón
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Guided example - static members, copies, and operators
 * Due date: Sept/15/2026
 */

#include <iostream>
using namespace std;

class StudyTime
{
    private:
        int minutes;               // Each object stores its own duration.
        static int objectCount;    // One counter is shared by the entire class.

    public:
        StudyTime(int m = 0)
        {
            minutes = m;
            objectCount++;         // Every new object increases the shared count.
        }

        int getMinutes() const { return minutes; }

        static int getObjectCount() {
            return objectCount;    // A static function reads class-level data.
        }

        // --- STEP 2: copy constructor (uncomment the /* ... */ block later) ---
        
        StudyTime(const StudyTime &other) {
            minutes = other.minutes;  // Copy the source object's duration.
            objectCount++;            // The copy is a new object too.
        }
        

        // --- STEP 3: operator+ (uncomment the /* ... */ block later) ---
        
        StudyTime operator+(const StudyTime &other) const {
            // Return a new duration without changing either operand.
            return StudyTime(minutes + other.minutes);
        }
        
};

int StudyTime::objectCount = 0;    // Define the single shared variable.

int main() {
    StudyTime reading(45);
    //StudyTime writing(30); second StudyTime object. output Reading: 45 minutes Objects created: 2

    cout << "Reading: " << reading.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

       StudyTime readingCopy = reading;  // Create a new object from reading.
    cout << "Copy: " << readingCopy.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

        StudyTime practice(30);
    StudyTime total = reading + practice;  // Calls reading.operator+(practice).

    cout << "Total: " << total.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    //Part D
    //Initialized object from reading (calls copy constructor)
    StudyTime reading2 = reading;
    //New object with duration by default
    StudyTime dfault;
    //Assigning default to reading2 (assignment), doesn't increment objectCount because it's not a new object.
    dfault = reading;

    //Printing final value of StudyTime::getObjectCount() and changes after added objects
    cout << "New reading object: " <<  reading2.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    cout << "Default object: " << dfault.getMinutes() << " minutes" << endl;
    cout << "Final objects created: " << StudyTime::getObjectCount() << endl;
    return 0;
}