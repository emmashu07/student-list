#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void addStudent();
int convertInt(char id[6]);
bool checkDigit(char id[6]);

struct Student{
	char firstName[15];
	char lastName[15];
	int studentId;
	float gpa;
};

int main() {
	addStudent();
	return 0;
}

void addStudent() {
	char id[10];
	Student student;
	cout << "Please enter in the first name of the new student: ";
        cin >> student.firstName;
	cout << "\nPlease enter in the last name of the new student: ";
	cin >> student.lastName;
	cout << "\nPlease enter in the student ID of the new student: ";
	cin >> id;
	while(strlen(id) != 6 || !checkDigit(id)) {
		cout << "\nPlease enter a valid, 6-digit student ID (e.g. 823759, 135703): ";
		cin >> id;
	}
	student.studentId = convertInt(id);		
	cout << "\nPlease enter in the GPA of the new student: ";
	cin >> student.gpa;
	while(student.gpa < 0.01 || student.gpa > 5.00) {
		cout << "\nPlease enter a valid GPA between 0 and 5 with 2 decimal points (e.g. 3.21, 0.34, 4.00): ";
	}
	cout << "The student's name is " << student.firstName << " " << student.lastName << "." << endl;
	cout << "The student's ID is " << student.studentId << "." << endl;
	cout << "The student's GPA is " << student.gpa << "." << endl;
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
