#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void displayMenu();
void writeToFile();
void readFromFile();


int studentId[100];
string name[100];
string gender[100];
double mathGrade[100];
double scienceGrade[100];
double englishGrade[100];


int main() {
    //defined variables
    int choice; //initially 0

    while (choice > 8 || choice <= 0) { // check that choice is not greater then 8 and not smaller then 0
        displayMenu();
        cout << "\n please enter a choice" << endl;
        cin >> choice;

        if (choice == 8){
            cout<<"thank you for using the system!"<<endl;
            writeToFile();
        }
    }
}


void displayMenu() { // function to display the menu
    cout
            << "\n 1. Add a new student  \n 2. Search for a student by his id. \n 3. Display Average grades in the three subjects. \n 4. Display failed students (whose average grade is less than 50) \n 5. Display the top student. \n 6. Display students who failed in a specific subject. \n 7. Display students by gender. \n 8. Exit. "
            << endl;
}

void writeToFile() {
    ofstream outfile; // create ofstream object used to write to file.
    outfile.open("students.txt"); // open txt file, if does not exist will be automatilly created


    outfile.close();
}

void readFromFile() {

}

