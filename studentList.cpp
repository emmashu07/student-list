#include <iostream>

using namespace std;

void addStudent();
int length(float number);

struct Student{
	char firstName[15];
	char lastName[15];
	int studentId;
	float gpa;
};

int main() {
	cout << length(3.12) << endl;
	cout << length(0.11);
	return 0;
}

void addStudent() {
	Student student;
	cout << "Please enter in the first name of the new student: ";
        cin >> student.firstName;
	cout << "\nPlease enter in the last name of the new student: ";
	cin >> student.lastName;
	cout << "\nPlease enter in the student ID of the new student: ";
	cin >> student.studentId;	
	while(student.studentId < 100000 || student.studentId > 999999 || !isdigit(student.studentId)) {
		cout << "\nPlease enter a valid, 6-digit student ID (e.g. 456789, 172592): ";
		cin >> student.studentId;
	}
	cout << "\nPlease enter in the GPA of the new student: ";
	cin >> student.gpa;
	while(student.gpa < 0.01 || student.gpa > 5.00 || length(student.gpa) != 3) {
		cout << "\nPlease enter a valid GPA between 0 and 5 with 2 decimal points (e.g. 3.21, 0.34, 4.00): ";
	}
}

int length(float number) {
	int len = 0;
	while (number != 0) {
		number /= 10;
		len++;
	}
	return len;
}
