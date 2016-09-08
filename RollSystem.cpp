//*****************************************************************
//  RollSystem.cpp
//  A small class-roll maintenance system
//
//  Programmers: Ryan Binder, Constance Luong, Elin Cheung, 
//		 Wesam Ali, Alexander Mas
//
//  This file contains the RollSystem class and all functions
//*****************************************************************

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//******************************************************************
// RollSystem class 
//******************************************************************
class RollSystem {
public:
	struct student {
		string name;
		string usfId;
		string email;
		int presGrade, e1Grade, e2Grade, projGrade;
	};

	vector<student> students;

	void addStudent(string name, string usfId, string email);
	void displayStudents();
	void searchByName(string name);
	void searchById(string usfId);
	void searchByEmail(string email);
	void removeStudent(string usfId);
	void editStudent(string usfId);
	void displayMenu();
};

//******************************************************************
// addStudent function will create a student
// and add that student to the system
//******************************************************************
void RollSystem::addStudent(string name, string usfId, string email) {
	bool duplicateId = false;
	bool duplicateEmail = false;

	student newStudent;
	newStudent.name = name;
	newStudent.usfId = usfId;
	newStudent.email = email;
	newStudent.presGrade = 0;
	newStudent.e1Grade = 0;
	newStudent.e2Grade = 0;
	newStudent.projGrade = 0;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == newStudent.usfId) {
			duplicateId = true;
		}
		if (students[i].email == newStudent.email) {
			duplicateEmail = true;
		}
	}

	if (duplicateId == true) {
		cout << "ERROR: a student with that UID is already in the system." << endl;
	}
	else if (duplicateEmail == true) {
		cout << "ERROR: a student with that email is already in the system." << endl;
	}
	else {
		students.push_back(newStudent);
		cout << "Student added!" << endl;
	}
}

//******************************************************************
// displayStudents function will display all students currently 
// in the system, as well as their data
//******************************************************************
void RollSystem::displayStudents() {
	int count = 0;

	cout << "---------------------------\n";
	cout << "STUDENTS" << endl;
	cout << "----------------------------\n";

	for (int i = 0; i < students.size(); i++) {
		count++;
		cout << "Name:  " << students[i].name << endl;
		cout << "UID:   " << students[i].usfId << endl;
		cout << "Email: " << students[i].email << endl;
		cout << endl;
	}

	if (count == 0) {
		cout << "System contains no students." << endl;
		cout << "----------------------------\n";
	}
	else {
		cout << "TOTAL STUDENTS: " << count << endl;
		cout << "----------------------------\n";
	}
}

//******************************************************************
// searchByName function will search system for student
// by their name
//******************************************************************
void RollSystem::searchByName(string name) {
	bool foundName = false;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].name == name) {
			foundName = true;

			cout << endl;
			cout << "-----------------\n";
			cout << "INFO" << endl;
			cout << "-----------------\n";
			cout << "Name: " << students[i].name << endl;
			cout << "UID: " << students[i].usfId << endl;
			cout << "Email: " << students[i].email << endl;
			cout << "-----------------\n";
			cout << "GRADES" << endl;
			cout << "-----------------\n";
			cout << "Presentation Grade: " << students[i].presGrade << endl;
			cout << "Essay 1 Grade: " << students[i].e1Grade << endl;
			cout << "Essay 2 Grade: " << students[i].e2Grade << endl;
			cout << "Project Grade: " << students[i].projGrade << endl;
		}
	}

	if (foundName == false) {
		cout << "Student \"" << name << "\" not found in the system." << endl;
	}
}

//******************************************************************
// searchById function will search system for student 
// by their UID
//******************************************************************
void RollSystem::searchById(string usfId) {
	bool foundId = false;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			foundId = true;

			cout << "-----------------\n";
			cout << "INFO" << endl;
			cout << "-----------------\n";
			cout << "Name: " << students[i].name << endl;
			cout << "UID: " << students[i].usfId << endl;
			cout << "Email: " << students[i].email << endl;
			cout << "-----------------\n";
			cout << "GRADES" << endl;
			cout << "-----------------\n";
			cout << "Presentation Grade: " << students[i].presGrade << endl;
			cout << "Essay 1 Grade: " << students[i].e1Grade << endl;
			cout << "Essay 2 Grade: " << students[i].e2Grade << endl;
			cout << "Project Grade: " << students[i].projGrade << endl;
		}
	}

	if (foundId == false) {
		cout << "UID " << usfId << " not found in the system." << endl;
	}
}

//******************************************************************
// searchByEmail function will search system for student
// by their email
//******************************************************************
void RollSystem::searchByEmail(string email) {
	bool foundEmail = false;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].email == email) {
			foundEmail = true;

			cout << "-----------------\n";
			cout << "INFO" << endl;
			cout << "-----------------\n";
			cout << "Name: " << students[i].name << endl;
			cout << "UID: " << students[i].usfId << endl;
			cout << "Email: " << students[i].email << endl;
			cout << "-----------------\n";
			cout << "GRADES" << endl;
			cout << "-----------------\n";
			cout << "Presentation Grade: " << students[i].presGrade << endl;
			cout << "Essay 1 Grade: " << students[i].e1Grade << endl;
			cout << "Essay 2 Grade: " << students[i].e2Grade << endl;
			cout << "Project Grade: " << students[i].projGrade << endl;
		}
	}

	if (foundEmail == false) {
		cout << "Email \"" << email << "\" not found in the system." << endl;
	}
}

//******************************************************************
// removeStudent function will find a student by UID
// and remove that student from the system
//
// !! May add functionality to remove by name and/or email !!
//******************************************************************
void RollSystem::removeStudent(string usfId) {
	bool foundStudent = false;
	int indexToRemove;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			foundStudent = true;
			indexToRemove = i;
		}
	}

	if (foundStudent == false) {
		cout << "ERROR: student you wish to remove is not in the system" << endl;
	}
	else {
		students.erase(students.begin() + indexToRemove);
		cout << "Removal successful!" << endl;
	}
}

//******************************************************************
// editGrades function will edit student's grades
//
// !! Could make user input all grades every time, OR split this into
// individual functions (ie. editProjectGrade, ...) and prompt user
// for what grade they would like to edit !!
//******************************************************************

//******************************************************************
// editStudent function will find student by UID and then 
// allow user to reenter student information or editGrades
//
// !! Still needs editGrades function implemented !!
//
// !! May add functionality to search by name and/or email !!
//******************************************************************
void RollSystem::editStudent(string usfId) {
	bool foundStudent = false;
	int indexToEdit = 0;
	string newName, newId, newEmail;

	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			foundStudent = true;
			indexToEdit = i;
		}
	}

	if (foundStudent == false) {
		cout << "ERROR: student you wish to edit was not found." << endl;
	}
	else {
		cout << "Name: ";
		cin >> newName;
		cout << "UID: ";
		cin >> newId;
		cout << "Email: ";
		cin >> newEmail;

		students[indexToEdit].name = newName;
		students[indexToEdit].usfId = newId;
		students[indexToEdit].email = newEmail;

		cout << "Edit successful!" << endl;
	}

	// editGrades
}

//******************************************************************
// displayStudents function will display the menu to remind
// the user what commands are valid
//******************************************************************
void RollSystem::displayMenu() {
	cout << endl;
	cout << "1. Display students in system" << endl;
	cout << "2. Add student" << endl;
	cout << "3. Remove student" << endl;
	cout << "4. Search for student" << endl;
	cout << "5. Edit student" << endl;
	cout << "6. Exit the system" << endl;
}

//******************************************************************
// MAIN FUNCTION
//******************************************************************
int main() {
	// create system
	RollSystem classRoll;
	// command input for main menu
	int menuCommand = 0;
	// command input for type of search
	int searchCommand = 0;
	// variables for adding student
	string newName, newId, newEmail;
	// id of student to remove
	string removeId;
	// variables for searching student
	string searchName, searchId, searchEmail;
	// id of student to edit
	string editId;

	cout << endl;
	cout << "Welcome to the Class Roll Maintenance System!" << endl;
	cout << endl;

	cout << "1. Display students in system" << endl;
	cout << "2. Add student" << endl;
	cout << "3. Remove student" << endl;
	cout << "4. Search for student" << endl;
	cout << "5. Edit student" << endl;
	cout << "6. Exit the system" << endl;

	// loop menu until user wants to exit
	while (menuCommand != 6) {
		cout << endl;
		cout << "Command number: ";
		cin >> menuCommand;

		// switch statement for menu command
		switch (menuCommand) {
			// display students
			case 1:
				cout << "Displaying system..." << endl;
				classRoll.displayStudents();
				classRoll.displayMenu();
				break;

			// add student
			case 2:
				cout << "Adding student..." << endl;
				cout << "Name: ";
				cin >> newName;
				cout << "UID: ";
				cin >> newId;
				cout << "Email: ";
				cin >> newEmail;

				classRoll.addStudent(newName, newId, newEmail);
				classRoll.displayMenu();
				break;

			// remove student
			case 3:
				cout << "Removing student..." << endl;
				cout << "UID: ";
				cin >> removeId;

				classRoll.removeStudent(removeId);
				classRoll.displayMenu();
				break;

			// search student
			case 4:
				cout << "What would you like to search by?" << endl;
				cout << "1. Name" << endl;
				cout << "2. UID" << endl;
				cout << "3. Email" << endl;
				cout << endl;
				cout << "Command number: ";
				cin >> searchCommand;

				// switch statement for search command
				switch (searchCommand) {
					case 1:
						cout << "Searching for student by name..." << endl;
						cout << "Name: ";
						cin >> searchName;

						classRoll.searchByName(searchName);
						break;

					case 2:
						cout << "Searching for student by UID..." << endl;
						cout << "UID: ";
						cin >> searchId;

						classRoll.searchById(searchId);
						break;

					case 3:
						cout << "Searching by email..." << endl;
						cout << "Email: " << endl;
						cin >> searchEmail;

						classRoll.searchByEmail(searchEmail);
						break;

					default:
						cout << "ERROR: invalid command." << endl;
						break;
				}
				// end switch for search command

				classRoll.displayMenu();
				break;

			// edit student
			case 5:
				cout << "Editing student..." << endl;
				cout << "UID: ";
				cin >> editId;

				classRoll.editStudent(editId);
				classRoll.displayMenu();
				break;

			// exit system
			case 6:
				cout << "Exiting system..." << endl;
				break;

			// error message
			default:
				cout << "ERROR: invalid command." << endl;
				break;
		}
	}

	return 0;
}
