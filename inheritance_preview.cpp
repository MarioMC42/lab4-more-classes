/*
 * Course: COEN 2220 - Programming 2
 * Name: Mario A. Marrero Colón
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Preview of inheritance and runtime polymorphism
 * Due date: Sept/15/2026
 */

#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
        string name;  // Every Person object has its own name.

    public:
        Person(string n) { name = n; }  // Initialize the shared base-class state.

        string getName() const { return name; }  // Derived classes can read this through the public interface.

        virtual void introduce() const {
            // virtual allows a derived class to provide its own behavior.
            cout << "Person: " << name << endl;
        }
};

class Student : public Person
{
    private:
        string major;  // Data that exists only for Student objects.

    public:
        Student(string n, string m) : Person(n) {
            // Person(n) initializes the name before Student's constructor body runs.
            major = m;  // Student adds data beyond the base Person class.
        }

        void introduce() const override {
            // override asks the compiler to verify that this replaces a virtual base method.
            // This version runs when a Person pointer refers to a Student.
            cout << "Student: " << getName() << ", Major: " << major << endl;
        }
};

int main() {
    Person visitor("Jordan Lee");
    Student student("Taylor Morgan", "Computer Engineering");

    // Both addresses fit in Person pointers because Student is a Person.
    Person *people[] = {&visitor, &student};

    for (int i = 0; i < 2; i++) {
        people[i]->introduce();  // virtual selects behavior from the actual object.
    }

    return 0;
}
