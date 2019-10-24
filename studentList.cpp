/*
 * Emma Shu, 10/23/19: Add, print, and delete student information inside of a list of students.
 * Information includes first name, last name, student ID, and GPA.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

struct Student{ // What is stored inside of a student.
	char firstName[15];
	char lastName[15];
	int studentId;
	float gpa;
};

void readInStudent(Student *student);
void printStudent(Student *student);
void addStudent(vector<Student*> *studentList);
void printStudentList(vector<Student*> *studentList);
void deleteStudent(vector<Student*> *studentList);
int convertInt(char id[6]);
bool checkDigit(char id[6]);
void releaseMemory(vector<Student*> *studentList);

int main() {
    vector<Student*> *studentList = new vector<Student*>(); // List of all the students.
	char input[20];
	bool running = true;
	cout << "Type HELP to display commands." << endl;
	while (running) { // When QUIT is typed, the loop will end and terminate the program.
		cin >> input;
		if(strcmp(input,"HELP") == 0) {
			cout << "Type ADD to input student information." << endl;
			cout << "Type PRINT to display student information." << endl;
			cout << "Type DELETE to delete student information." << endl;
			cout << "Type QUIT to exit the program." << endl;
		}
		else if(strcmp(input,"ADD") == 0) {
			addStudent(studentList);
		}
		else if(strcmp(input,"PRINT") == 0) {
			printStudentList(studentList);
		}
		else if(strcmp(input,"DELETE") == 0) {
			deleteStudent(studentList);
		}
		else if(strcmp(input,"QUIT") == 0) {
			running = false;
        }
		else {
			cout << "Please enter in a valid command. Type HELP for help." << endl;
		}	
	}
    releaseMemory(studentList); 
	return 0;
}

void readInStudent(Student *student) {
	char id[10];
	cout << "Please enter in the first name of the new student: ";
        cin >> student -> firstName;
	cout << "\nPlease enter in the last name of the new student: ";
	cin >> student -> lastName;
	cout << "\nPlease enter in the student ID of the new student: ";
	cin >> id;
	while(strlen(id) != 6 || !checkDigit(id)) { // Restrictions to enter an ID.
		cout << "\nPlease enter a valid, 6-digit student ID (e.g. 823759, 135703): ";
		cin >> id;
	}
	student -> studentId = convertInt(id); // Stored into the ID in the student.	
	cout << "\nPlease enter in the GPA of the new student: ";
	cin >> student -> gpa;
	while(student -> gpa < 0.01 || student -> gpa > 5.00) {
		cout << "\nPlease enter a valid GPA between 0 and 5 with 2 decimal points (e.g. 3.21, 0.34, 4.00): ";
        cin >> student -> gpa;
	}

}

void addStudent(vector<Student*> *studentList) {
    Student *student = new Student();
    readInStudent(student); // The student has all the necessary information in the pointer.
    studentList -> push_back(student); // Append filled in information student into the list of student.
    cout << "Added." << endl;
}

void printStudentList(vector<Student*> *studentList) {
    vector<Student*>::iterator it;
    for(it = studentList -> begin(); it < studentList -> end(); it++) {
        printStudent(*it); // Run through the list of students and print out all the student information.
    }
    cout << "Printed." << endl;
}

void printStudent(Student *student) {
    cout << fixed; 
    cout << setprecision(2); // Accurate float to the 2 decimal points.
    cout << student -> firstName << " " << student -> lastName << ", " << student -> studentId << ", " << student -> gpa << endl;
}

void deleteStudent(vector<Student*> *studentList) {
    char input[10];
    int id; 
    cout << "Please enter the student ID of the student you would like to delete: " << endl;
    cin >> input;
	while(strlen(input) != 6 || !checkDigit(input)) {
		cout << "\nPlease enter a valid, 6-digit student ID (e.g. 823759, 135703): ";
		cin >> input;
	}
    id = convertInt(input);
    vector<Student*>::iterator it;
    for(it = studentList -> begin(); it < studentList -> end(); it++) {
        if((*it)->studentId == id) { // If the same ID as typed in, then delete the student.
            delete (*it);
            studentList -> erase(it);
	    break;
        } 
    }
    cout << "Deleted." << endl;
}

int convertInt(char id[6]) {
	int intId; 
	for(int i = 0; i < 6; i++) {
		intId += (int)((pow(10.0, 6.0 - i - 1))*(id[i]-'0')); // Create the 6-digit student ID.	
	}
	return intId - 6;
}


bool checkDigit(char id[6]) {
	for(int i = 0; i < 6; i++) {
		if(!isdigit(id[i])) {
			return false; // Determine whether all the characters inside the string is a digit and can be converted.
		}
	}
	return true;
}

void releaseMemory(vector<Student*> *studentList) {
    for(auto it = studentList -> begin(); it < studentList -> end(); it++) {
        delete (*it);
    }
    delete studentList;
}
