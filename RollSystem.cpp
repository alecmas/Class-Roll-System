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
#include <algorithm>

using namespace std;

//******************************************************************
// RollSystem class 
//******************************************************************
class RollSystem {
public:
	struct student {
		// up to 40 characters
		string name;
		// 10 characters
		string usfId;
		// up to 40 characters
		string email;
		// value from 0 (F) to 4 (A)
		int presGrade, e1Grade, e2Grade, projGrade;
	};

	// vector to hold students
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
	// variable to check if id is already in system
	bool duplicateId = false;
	// variable to check if email is already in system
	bool duplicateEmail = false;

	// iterate through the vector to see if there are any duplicate ids or emails
	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			duplicateId = true;
		}
		if (students[i].email == email) {
			duplicateEmail = true;
		}
	}

	if (duplicateId == true) {
		cout << "ERROR: a student with that UID is already in the system.";
	}
	else if (duplicateEmail == true) {
		cout << "ERROR: a student with that email is already in the system.";
	}
	// if there were no duplicate ids or emails
	else {
		// create student
		student newStudent;

		// transform user's name input to all lowercase to eliminate case-sensitivity issues
		transform(name.begin(), name.end(), name.begin(), ::tolower);

		// transform user's email input to all lowercase to eliminate case-sensitivity issues
		transform(email.begin(), email.end(), email.begin(), ::tolower);

		newStudent.name = name;
		newStudent.usfId = usfId;
		newStudent.email = email;

		// set initial grades to 0
		newStudent.presGrade = 0;
		newStudent.e1Grade = 0;
		newStudent.e2Grade = 0;
		newStudent.projGrade = 0;

		// push new student onto the end of the students vector
		students.push_back(newStudent);
		cout << "Student added!";
	}
}

//******************************************************************
// displayStudents function will display all students currently 
// in the system, as well as their data
//******************************************************************
void RollSystem::displayStudents() {
	// variable to keep count of students in system
	int count = 0;

	cout << "---------------------------\n";
	cout << "STUDENTS" << endl;
	cout << "----------------------------\n";

	// iterate through students vector and print all students
	for (int i = 0; i < students.size(); i++) {
		count++;
		cout << "Name:  " << students[i].name << endl;
		cout << "UID:   " << students[i].usfId << endl;
		cout << "Email: " << students[i].email << endl;
		cout << endl;
	}

	if (count == 0) {
		cout << "System contains no students." << endl;
		cout << "----------------------------";
	}
	else {
		cout << "TOTAL STUDENTS: " << count << endl;
		cout << "----------------------------";
	}
}

//******************************************************************
// searchByName function will search system for student
// by their name
//******************************************************************
void RollSystem::searchByName(string name) {
	// variable to check if name is in system
	bool foundName = false;

	// transform user's name input to lowercase to eliminate case-sensitivity issues
	transform(name.begin(), name.end(), name.begin(), ::tolower);

	// iterate through students vector to find a matching name
	for (int i = 0; i < students.size(); i++) {
		// compare names, which are now both lowercase
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
			cout << "----------------------------";
		}
	}

	if (foundName == false) {
		cout << "Student \"" << name << "\" not found in the system.";
	}
}

//******************************************************************
// searchById function will search system for student 
// by their UID
//******************************************************************
void RollSystem::searchById(string usfId) {
	// variable to check if id is in system
	bool foundId = false;

	// iterate through students vector to find a matching id
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
			cout << "----------------------------";
		}
	}

	if (foundId == false) {
		cout << "UID " << usfId << " not found in the system.";
	}
}

//******************************************************************
// searchByEmail function will search system for student
// by their email
//******************************************************************
void RollSystem::searchByEmail(string email) {
	// variable to check if email is in system
	bool foundEmail = false;

	// transform user's email input to all lowercase to eliminate case-sensitivity issues
	transform(email.begin(), email.end(), email.begin(), ::tolower);

	// iterate through students vector to find a matching email
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
			cout << "----------------------------";
		}
	}

	if (foundEmail == false) {
		cout << "Email \"" << email << "\" not found in the system.";
	}
}

//******************************************************************
// removeStudent function will find a student by UID
// and remove that student from the system
//
// !! May add functionality to remove by name and/or email !!
//******************************************************************
void RollSystem::removeStudent(string usfId) {
	// variable to make sure student is in the system
	bool foundStudent = false;
	// variable to hold index of the student to be removed
	int indexToRemove;

	// iterate through students vector to find the student to be removed
	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			foundStudent = true;
			indexToRemove = i;
		}
	}

	if (foundStudent == false) {
		cout << "ERROR: student you wish to remove is not in the system";
	}
	else {
		// erase the student at the saved index
		students.erase(students.begin() + indexToRemove);
		cout << "Removal successful!";
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
// !! May add functionality to search by name and/or email !!
//******************************************************************
void RollSystem::editStudent(string usfId) {
	// variable to make sure student is in the system
	bool foundStudent = false;
	// variable to save the index of the student to be edited
	int indexToEdit = 0;
	// variables for the new information
	string newName, newId, newEmail;

	// iterate through students vector to find the student to be edited
	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			foundStudent = true;
			indexToEdit = i;
		}
	}

	if (foundStudent == false) {
		cout << "ERROR: student you wish to edit was not found.";
	}
	else {
		cout << "New name: ";
		getline(cin, newName);
		cout << "New UID: ";
		getline(cin, newId);
		cout << "New email: ";
		getline(cin, newEmail);

		// update information of the student at the saved index
		students[indexToEdit].name = newName;
		students[indexToEdit].usfId = newId;
		students[indexToEdit].email = newEmail;

		cout << "Edit successful!";
	}

	// EDIT GRADES FUNCTIONALIY WILL GO HERE?
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
	cout << "4. Search for student by name" << endl;
	cout << "5. Search for student by UID" << endl;
	cout << "6. Search for student by email" << endl;
	cout << "7. Edit student" << endl;
	cout << "8. Exit system" << endl;
}

//******************************************************************
// MAIN FUNCTION
//******************************************************************
int main() {
	// create system
	RollSystem classRoll;
	// command input for main menu
	string menuCommand;
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

	classRoll.displayMenu();
	cout << endl;

	cout << "Command number: ";
	getline(cin, menuCommand);
	cout << endl;

	// variable for string converted to int
	// fool-proofs menu so user can't break program
	int menuCommandInt = atoi(menuCommand.c_str());

	// loop menu until user wants to exit
	while (menuCommandInt != 8) {
		// switch statement for menu command
		switch (menuCommandInt) {
			// display students
			case 1:
				cout << "Displaying system..." << endl;
				cout << endl;

				classRoll.displayStudents();

				// cin.ignore() makes user have to hit enter to continue
				cin.ignore();
				// display the menu after whatever the user does to remind them of commands
				classRoll.displayMenu();

				// always ask for new command after each case to see what the user wants to do next
				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// add student
			case 2:
				cout << "Adding student..." << endl;
				cout << endl;

				cout << "Name: ";
				getline(cin, newName);

				cout << "UID: ";
				getline(cin, newId);

				cout << "Email: ";
				getline(cin, newEmail);

				classRoll.addStudent(newName, newId, newEmail);

				cin.ignore();
				classRoll.displayMenu();
				
				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// remove student
			case 3:
				cout << "Removing student..." << endl;
				cout << endl;

				cout << "UID of student you'd like to remove: ";
				getline(cin, removeId);

				classRoll.removeStudent(removeId);

				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// search student by name
			case 4:
				cout << "Searching for student by name..." << endl;
				cout << endl;

				cout << "Name: ";
				getline(cin, searchName);

				classRoll.searchByName(searchName);

				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// search student by id
			case 5:
				cout << "Searching for student by UID..." << endl;
				cout << endl;

				cout << "UID: ";
				getline(cin, searchId);

				classRoll.searchById(searchId);

				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// search student by email
			case 6:
				cout << "Searching by email..." << endl;
				cout << endl;

				cout << "Email: ";
				getline(cin, searchEmail);

				classRoll.searchByEmail(searchEmail);

				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// edit student
			case 7:
				cout << "Editing student..." << endl;
				cout << endl;

				cout << "UID of student you'd like to edit: ";
				getline(cin, editId);

				classRoll.editStudent(editId);

				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// error message
			default:
				cout << "ERROR: invalid command.";
				cin.ignore();

				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;
		}
	}

	cout << "Exiting system...";
	cin.ignore();

	return 0;
}
