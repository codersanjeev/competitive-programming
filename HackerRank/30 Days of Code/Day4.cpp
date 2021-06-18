using namespace std;
#include <iostream>

class Person {
   public:
    int age;
    Person(int initialAge);
    void amIOld();
    void yearPasses();
};

Person::Person(int initialAge) {
    // Add some more code to run some checks on initialAge
    if (initialAge > 0)
        age = initialAge;
    else {
        cout << "Age is not valid, setting age to 0." << endl;
        age = 0;
    }
}

void Person::amIOld() {
    // Do some computations in here and print out the correct statement to the console
    if (age < 13)
        cout << "You are young." << endl;
    else if (age >= 13 && age < 18)
        cout << "You are a teenager." << endl;
    else
        cout << "You are old." << endl;
}

void Person::yearPasses() {
    // Increment the age of the person in here
    age++;
}
int main() {