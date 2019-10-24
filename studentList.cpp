#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

struct Student{
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

int main() {
    vector<Student*> *studentList = new vector<Student*>();
	char input[20];
	bool running = true;
	cout << "Type HELP to display commands." << endl;
	while (running) {
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
	while(strlen(id) != 6 || !checkDigit(id)) {
		cout << "\nPlease enter a valid, 6-digit student ID (e.g. 823759, 135703): ";
		cin >> id;
	}
	student -> studentId = convertInt(id);		
	cout << "\nPlease enter in the GPA of the new student: ";
	cin >> student -> gpa;
	while(student -> gpa < 0.01 || student -> gpa > 5.00) {
		cout << "\nPlease enter a valid GPA between 0 and 5 with 2 decimal points (e.g. 3.21, 0.34, 4.00): ";
        cin >> student -> gpa;
	}

}

void addStudent(vector<Student*> *studentList) {
    Student *student = new Student();
    readInStudent(student);
    studentList -> push_back(student);
    cout << "Added." << endl;
}

void printStudentList(vector<Student*> *studentList) {
    vector<Student*>::iterator it;
    for(it = studentList -> begin(); it < studentList -> end(); it++) {
        printStudent(*it);
    }
    cout << "Printed." << endl;
}

void printStudent(Student *student) {
    cout << fixed;
    cout << setprecision(2);
    cout << student -> firstName << " " << student -> lastName << ", " << student -> studentId << ", " << student -> gpa << endl;
}

void deleteStudent(vector<Student*> *studentList) {
    char input[10];
    int id;
    int count = 0;
    cout << "Please enter the student ID of the student you would like to delete: " << endl;
    cin >> input;
	while(strlen(input) != 6 || !checkDigit(input)) {
		cout << "\nPlease enter a valid, 6-digit student ID (e.g. 823759, 135703): ";
		cin >> input;
	}
    id = convertInt(input);
    vector<Student*>::iterator it;
    for(it = studentList -> begin(); it < studentList -> end(); it++) {
        if((*it)->studentId == id) {
            studentList -> erase(studentList -> begin() + count);
        }
        count++;
    }
    cout << "Deleted." << endl;
}

int convertInt(char id[6]) {
	int intId; 
	for(int i = 0; i < 6; i++) {
		intId += (int)((pow(10.0, 6.0 - i - 1))*(id[i]-'0'));	
	}
	return intId - 6;
}


bool checkDigit(char id[6]) {
	for(int i = 0; i < 6; i++) {
		if(!isdigit(id[i])) {
			return false;
		}
	}
	return true;
}


