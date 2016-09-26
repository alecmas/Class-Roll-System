//*****************************************************************
//  Team_Polk_FaultSeeded.cpp
//  A small class-roll maintenance system
//
//  Programmers: Ryan Binder, Constance Luong, Elin Cheung, 
//		 Wesam Ali, Alexander Mas
//
//  This file contains the RollSystem class and all functions
//
//  BUGGED VERSION
//*****************************************************************

#include <cstdlib>
#include <iostream>
#include <iomanip>
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

	bool validateStudent(string name, string email, string usfId);
	bool validateGrade(int grade);

	void addStudent(string name, string usfId, string email);
	void removeStudent(string usfId);

	void searchByName(string name);
	void searchById(string usfId);
	void searchByEmail(string email);

	void editInfo(int index);
	void editGrades(int index);
	void editStudent(string usfId);

	void displaySystem();
	void displayStudent(int index);
	void displayMenu();
};

//******************************************************************
// validateStudent function will check to see if name, UID,
// and email are all valid inputs
//******************************************************************
bool RollSystem::validateStudent(string name, string email, string usfId) {
	// if name is not a valid length
	if (name.size() == 0 || name.size() > 40) {
		cout << endl;
		cout << "ERROR: invalid name. Names must contain between 1 and 40 characters" << endl;
		return false;
	}

	// if UID is not a valid length
	if (usfId.size() != 8) {
		cout << endl;
		cout << "ERROR: invalid UID. UID must be exactly 8 characters" << endl;
		return false;
	}

	// find if UID contains all numbers
	size_t numberFound = usfId.find_first_not_of("0123456789");

	// if all characters are numbers, numberFound will equal npos
	if (numberFound != string::npos) {
		cout << endl;
		cout << "ERROR: invalid UID. UID consists of numbers only" << endl;
		return false;
	}

	// find if email contains '@' character
	size_t atFound = email.find("@");

	// if @ not found, atFound will equal npos
	if (atFound == string::npos) {
		cout << endl;
		cout << "ERROR: invalid email. Email addresses must contain an @ symbol" << endl;
		return false;
	}

	// if email is not a valid length
	if (email.size() < 3 || email.size() > 40) {
		cout << endl;
		cout << "ERROR: invalid email. Email addresses must contain between 3 and 40 characters" << endl;
		return false;
	}

	return true;
}

//******************************************************************
// validateGrade function makes sure grade input is valid
// (between 0 and 4)
//******************************************************************
bool RollSystem::validateGrade(int grade) {
	// if newGrade is out of range, print error and fail the grade edit
	if (grade < 0 || grade > 4) {
		cout << endl;
		cout << "ERROR: Please enter a grade value between 0 and 4\n";
		
		cout << endl;
		cout << "Grade edit failed!" << endl;

		return false;
	}
	else {
		return true;
	}
}

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
		cout << endl;
		cout << "ERROR: a student with that UID is already in the system.\n";
		return;
	}
	else if (duplicateEmail == true) {
		cout << endl;
		cout << "ERROR: a student with that email is already in the system.\n";
		return;
	}

	// validate email and name
	else if (validateStudent(name, email, usfId) == false) {
		return;
	}

	// else there were no errors
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

		cout << endl;
		cout << "Student added!\n";
	}
}

//******************************************************************
// removeStudent function will find a student by UID
// and remove that student from the system
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
		cout << endl;
		cout << "ERROR: student you wish to remove is not in the system\n";
	}
	else {
		// erase the student at the saved index
		students.erase(students.begin() + indexToRemove);

		cout << endl;
		cout << "Removal successful!\n";
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
			displayStudent(i);
		}
	}

	if (foundName == false) {
		cout << endl;
		cout << "Student \"" << name << "\" not found in the system\n";
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
			displayStudent(i);
		}
	}

	if (foundId == false) {
		cout << endl;
		cout << "UID " << usfId << " not found in the system\n";
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
			displayStudent(i);
		}
	}

	if (foundEmail == false) {
		cout << endl;
		cout << "Email \"" << email << "\" not found in the system\n";
	}
}

//******************************************************************
// editInfo function will edit student's information
// (name, UID, email)
//******************************************************************
void RollSystem::editInfo(int index) {
	// variables for the new information
	string newName, newId, newEmail;

	cout << "New name: ";
	getline(cin, newName);
	cout << "New UID: ";
	getline(cin, newId);
	cout << "New email: ";
	getline(cin, newEmail);

	// validate new email
	if (validateStudent(newName, newEmail, newId) == false) {
		return;
	}
 
 	// transform user's name input to lowercase to eliminate case-sensitivity issues
 	transform(newName.begin(), newName.end(), newName.begin(), ::tolower);
 
 	// transform user's email input to all lowercase to eliminate case-sensitivity issues
 	transform(newEmail.begin(), newEmail.end(), newEmail.begin(), ::tolower);

	// update information of the student at the saved index
	students[index].name = newName;
	students[index].usfId = newId;
	students[index].email = newEmail;

 	cout << endl;
 	cout << "Info edit successful!" << endl;
}

//******************************************************************
// editGrades function will edit student's grades
//******************************************************************
void RollSystem::editGrades(int index) {
	// variables for new grades
	string newPresGrade, newE1Grade, newE2Grade, newProjGrade;

	// prompt user for input
	cout << endl;
	cout << "Please enter all grades as numeric values according to the following scale:" << endl;
	cout << "4 = A, 3 = B, 2 = C, 1 = D, 0 = F" << endl;
	cout << endl;

	cout << "New Presentation grade: ";
	getline(cin, newPresGrade);
	// convert input to int to prevent errors
	int presGradeInt = atoi(newPresGrade.c_str());

	// if input is not valid, exit the function
	if (validateGrade(presGradeInt) == false) {
		return;
	}
	// else make the edit
	else {
		students[index].presGrade = presGradeInt;
	}

	cout << "New Essay 1 grade: ";
	getline(cin, newE1Grade);
	int e1GradeInt = atoi(newE1Grade.c_str());

	if (validateGrade(e1GradeInt) == false) {
		return;
	}
	else {
		students[index].e1Grade = e1GradeInt;
	}

	cout << "New Essay 2 grade: ";
	getline(cin, newE2Grade);
	int e2GradeInt = atoi(newE2Grade.c_str());

	if (validateGrade(e2GradeInt) == false) {
		return;
	}
	else {
		students[index].e2Grade = e2GradeInt;
	}

	cout << "New Project grade: ";
	getline(cin, newProjGrade);
	int projGradeInt = atoi(newProjGrade.c_str());
	
	if (validateGrade(projGradeInt) == false) {
		return;
	}
	else {
		students[index].projGrade = projGradeInt;
	}

	// if the function makes it this far, the edit was successful
	cout << endl;
	cout << "Grades edit successful!" << endl;
}

//******************************************************************
// editStudent function will find student by UID and then 
// prompt user to editInfo or editGrades
//******************************************************************
void RollSystem::editStudent(string usfId) {
	// variable to make sure student is in the system
	bool foundStudent = false;
	// variable to save the index of the student to be edited
	int indexToEdit = 0;
	// variable for menu system
	string command;

	// iterate through students vector to find the student to be edited
	for (int i = 0; i < students.size(); i++) {
		if (students[i].usfId == usfId) {
			foundStudent = true;
			indexToEdit = i;
		}
	}

	if (foundStudent == false) {
		cout << endl;
		cout << "ERROR: student you wish to edit was not found.\n";
	}
	else {
		cout << endl;
		cout << "1. Edit student info" << endl;
		cout << "2. Edit student grades" << endl;

		cout << endl;
		cout << "Command number: ";
		getline(cin, command);
		cout << endl;

		int commandInt = atoi(command.c_str());

		switch(commandInt) {
			case 1:
				editInfo(indexToEdit);
				break;

			case 2:
				editGrades(indexToEdit);
				break;

			default:
				cout << "ERROR: invalid command." << endl;
				break;
		}
	}
}

//******************************************************************
// displaySystem function will display all students currently 
// in the system, as well as their information
//******************************************************************
void RollSystem::displaySystem() {
	// variable to keep count of students in system
	int count = 0;

	cout << "--------------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(40) << left << "Name" << "| " << setw(10) << left << "UID" << "| " << setw(40) << "Email " << " |" << endl;
	cout << "--------------------------------------------------------------------------------------------------\n";

	// iterate through students vector and print all students
	for (int i = 0; i < students.size(); i++) {
		count++;
		cout << "| " << setw(40) << left << students[i].name << "| " << setw(10) << left << students[i].usfId << "| " << setw(40) << students[i].email << " |" << endl;
	}

	if (count == 0) {
		cout << "| System contains no students" << setw(69) << right << " |" << endl;
		cout << "--------------------------------------------------------------------------------------------------\n";
	}
	else {
		cout << "--------------------------------------------------------------------------------------------------\n";
		cout << "| TOTAL STUDENTS: " << setw(78) << count << " |" << endl;
		cout << "--------------------------------------------------------------------------------------------------\n";
		cout << endl;
		cout << "NOTE: if you would like to see a student's grades, please search for them individually" << endl;
	}
}

//******************************************************************
// displayStudent function will display a single student's
// information and grades
//******************************************************************
void RollSystem::displayStudent(int index) {
	cout << "--------------------------------------------------\n";
	cout << "| " << setw(45) << left << "STUDENT " << index + 1 << " |" << endl;
	cout << "--------------------------------------------------\n";
	cout << "| " << "Name:" << setw(41) << right << students[index].name << " |" << endl;
	cout << "| " << "UID:" << setw(42) << right << students[index].usfId << " |" << endl;
	cout << "| " << "Email:" << setw(40) << right << students[index].email << " |" << endl;
	cout << "| " << setw(48) << " |" << endl;
	cout << "| " << setw(45) << left << "Presentation Grade: " << students[index].presGrade << " |" << endl;
	cout << "| " << setw(45) << left << "Essay 1 Grade: " << students[index].e1Grade << " |" << endl;
	cout << "| " << setw(45) << left << "Essay 2 Grade: " << students[index].e2Grade << " |" << endl;
	cout << "| " << setw(45) << left << "Project Grade: " << students[index].projGrade << " |" << endl;
	cout << "--------------------------------------------------\n";
}

//******************************************************************
// displayMenu function will display the menu to remind
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

	/* TESTING //
	classRoll.addStudent("Alexander Mas", "00000000", "alexanderm@mail.usf.edu");
	classRoll.addStudent("Geoffrey Kohlhase", "11111111", "gk@mail.usf.edu");
	classRoll.addStudent("David Cap", "22222222", "dc@mail.usf.edu");
	classRoll.addStudent("Mason Wudtke", "33333333", "mw@mail.usf.edu");
	// END TESTING */
	
	cout << endl;
	cout << "Welcome to the Class Roll Maintenance System!" << endl;

	classRoll.displayMenu();
	cout << endl;

	cout << "Command number: ";
	getline(cin, menuCommand);

	// variable for string converted to int
	// fool-proofs menu so user can't break program
	int menuCommandInt = atoi(menuCommand.c_str());

	// loop menu until user wants to exit
	while (menuCommandInt != 8) {
		// switch statement for menu command
		switch (menuCommandInt) {
			// display students
			case 1:
				cout << endl;
				cout << "Displaying system..." << endl;
				cout << endl;

				classRoll.displaySystem();
				cout << endl;

				cout << "Press ENTER to continue...";
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
				cout << endl;
				cout << "Adding student..." << endl;
				cout << endl;

				cout << "Name: ";
				getline(cin, newName);

				cout << "UID: ";
				getline(cin, newId);

				cout << "Email: ";
				getline(cin, newEmail);

				classRoll.addStudent(newName, newId, newEmail);
				cout << endl;

				cout << "Press ENTER to continue...";
				cin.ignore();
				classRoll.displayMenu();
				
				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// remove student
			case 3:
				cout << endl;
				cout << "Removing student..." << endl;
				cout << endl;

				cout << "UID of student you'd like to remove: ";
				getline(cin, removeId);

				classRoll.removeStudent(removeId);
				cout << endl;

				cout << "Press ENTER to continue...";
				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// search student by name
			case 4:
				cout << endl;
				cout << "Searching for student by name..." << endl;
				cout << endl;

				cout << "Name: ";
				getline(cin, searchName);

				classRoll.searchByName(searchName);
				cout << endl;

				cout << "Press ENTER to continue...";
				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// search student by id
			case 5:
				cout << endl;
				cout << "Searching for student by UID..." << endl;
				cout << endl;

				cout << "UID: ";
				getline(cin, searchId);

				classRoll.searchById(searchId);
				cout << endl;

				cout << "Press ENTER to continue...";
				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// search student by email
			case 6:
				cout << endl;
				cout << "Searching by email..." << endl;
				cout << endl;

				cout << "Email: ";
				getline(cin, searchEmail);

				classRoll.searchByEmail(searchEmail);
				cout << endl;

				cout << "Press ENTER to continue...";
				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// edit student
			case 7:
				cout << endl;
				cout << "Editing student..." << endl;
				cout << endl;

				cout << "UID of student you'd like to edit: ";
				getline(cin, editId);

				classRoll.editStudent(editId);
				cout << endl;

				cout << "Press ENTER to continue...";
				cin.ignore();
				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;

			// error message
			default:
				cout << endl;
				cout << "ERROR: invalid command." << endl;

				cout << endl;
				cout << "Press ENTER to continue...";
				cin.ignore();

				classRoll.displayMenu();

				cout << endl;
				cout << "Command number: ";
				getline(cin, menuCommand);
				menuCommandInt = atoi(menuCommand.c_str());
				break;
		}
	}

	cout << endl;
	cout << "Exiting system...";
	cin.ignore();

	return 0;
}
