#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

void displayMenu();
void writeToFile();
void addStudent();
bool checkExistence(int id);
void readFromFile();
void displayData();
int searchStudentById(int id);
void displayAverageIn3Subjects();
void parseData(string s, int arrayIndex);

int arraySize;
int studentId[100];
string name[100];
string gender[100];
double mathGrade[100];
double scienceGrade[100];
double englishGrade[100];

int main() {
    //defined variables
    int choice; //initially 0
    readFromFile(); // initially we always call this function at start to read all the data from the file to the array
    while (true) { // check that choice is not greater then 8 and not smaller then 0
        displayMenu();
        cout << "\n please enter a choice" << endl;
        cin >> choice;
        switch (choice) {
            case 1 :
                addStudent();
                writeToFile();
                break;
            case 2 :
                int id;
                int index;
                cout << "please enter id" << endl;
                cin >> id;
                index = searchStudentById(id);
                if (index != -1) {
                    cout << studentId[index] << "    " << name[index] << "   " << gender[index] << "     "
                         << mathGrade[index] << "   " << scienceGrade[index] << "   " << englishGrade[index] << endl;
                }
                break;
            case 3 :
                displayAverageIn3Subjects();
                break;
            case 4 :
                break;
            case 5 :
                break;
            case 6 :
                break;
            case 7 :
                break;
            case 8 :
                cout << "thank you for using the system!" << endl;
                exit(0);

            default :
                cout << "Invalid entry" << endl;
        }
    }
}

void displayMenu() { // function to display the menu
    cout
            << "\n 1. Add a new student  \n 2. Search for a student by his id. \n 3. Display Average grades in the three subjects. \n 4. Display failed students (whose average grade is less than 50) \n 5. Display the top student. \n 6. Display students who failed in a specific subject. \n 7. Display students by gender. \n 8. Exit & save "
            << endl;
}

void addStudent() {

    int tempId;
    bool uniqueId = false;
    do {
        cout << "please enter the users id" << endl;
        cin >> tempId;
        uniqueId = checkExistence(tempId);
    } while (uniqueId == false);

    studentId[arraySize] = tempId;
    cout << "please enter the name" << endl;
    cin.ignore();
    getline(cin, name[arraySize]);
    cout << "please enter the gender" << endl;
    cin >> gender[arraySize];
    cout << "please enter the math Grade" << endl;
    cin >> mathGrade[arraySize];
    cout << "please enter the science Grade" << endl;
    cin >> scienceGrade[arraySize];
    cout << "please enter the english Grade" << endl;
    cin >> englishGrade[arraySize];
    cout << "Thanks!" << endl;
    arraySize++;
}


void writeToFile() {
    ofstream write; // create ofstream object used to write to file.
    write.open("students.txt"); // open txt file, if does not exist will be automatilly created
    if (write.is_open())  //check if the file is open
    {
        for (int i = 0; i < arraySize; ++i) {
            write << studentId[i] << " " << name[i] << " " << gender[i] << " " << mathGrade[i] << " "
                  << scienceGrade[i] << " " << englishGrade[i] << "\n";
        }
    }
    write.close();
}

void readFromFile() {
    string line;
    ifstream read("students.txt");
    int currentRowIndex = 0;
    if (read.is_open()) {
        while (getline(read, line)) {
            parseData(line, currentRowIndex);
            arraySize++;
            currentRowIndex++;
        }
    }
    read.close();
}

int searchStudentById(int id) {
    for (int index = 0; index < arraySize; ++index) {
        if (id == studentId[index]) {
            return index;
        }
    }
    return -1; // we return -1 if we did not find student
}

void displayAverageIn3Subjects() {
    double mathSum;
    double scienceSum;
    double englishSum;

    for (int i = 0; i < arraySize; ++i) {
        mathSum = mathSum + mathGrade[i];
        scienceSum = scienceSum + scienceGrade[i];
        englishSum = englishSum + englishGrade[i];
    }
    cout << "Math average:" << mathSum / arraySize << endl;
    cout << "science average:" << scienceSum / arraySize << endl;
    cout << "english average:" << englishSum / arraySize << endl;
}

void parseData(string s, int arrayIndex) {
    string temp[10]; // temp array to save parsed data into it
    int counter = 0;
    istringstream dataStream(s);
    while (dataStream) {
        string subString;
        dataStream >> subString;
        temp[counter] = subString;
        counter++;
    }
    // stoi function converts string to integer
    studentId[arrayIndex] = stoi(temp[0]);
    name[arrayIndex] = temp[1];
    gender[arrayIndex] = temp[2];
    mathGrade[arrayIndex] = stoi(temp[3]);
    scienceGrade[arrayIndex] = stoi(temp[4]);
    englishGrade[arrayIndex] = stoi(temp[5]);
}
void displayData() {
    for (int i = 0; i < arraySize; ++i) {
        cout << studentId[i] << " " << name[i] << " " << gender[i] << " " << mathGrade[i] << " " << scienceGrade[i]
             << " " << englishGrade[i] << endl;
    }
}
bool checkExistence(int id) {
    for (int i = 0; i < 100; ++i) {
        if (id == studentId[i]) {
            return false;
        }
    }
    return true;
}

