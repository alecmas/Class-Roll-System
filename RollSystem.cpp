//*****************************************************************
//  RollSystem.cpp
//  A small class-roll maintenance system
//
//  Programmers: Ryan Binder, Constance Luong, Elin Cheung, 
//		 Wesam Ali, Alexander Mas
//
//  This file contains the student class and all functions
//*****************************************************************

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//******************************************************************
// RollSystem class 
//******************************************************************
class RollSystem {
public:
	static const int TABLE_SIZE = 4;

	struct student {
		string name;
		string usfId;
		string email;
		int presGrade, e1Grade, e2Grade, projGrade;
		student* next;
	};

	student* HashTable[TABLE_SIZE];

	RollSystem();
	int hash(string key);
	void addStudent(string name, string usfId, string email);
	int numberOfStudentsInIndex(int index);
	void displayStudents();
	void searchByName(string name);
};

//******************************************************************
// RollSystem constructor initializes table of students
// as default empty entries
//******************************************************************
RollSystem::RollSystem() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		HashTable[i] = new student;
		HashTable[i]->name = "name";
		HashTable[i]->usfId = "0";
		HashTable[i]->email = "email";
		HashTable[i]->presGrade = 0;
		HashTable[i]->e1Grade = 0;
		HashTable[i]->e2Grade = 0;
		HashTable[i]->projGrade = 0;
		HashTable[i]-> next = NULL;
	}
}

//******************************************************************
// hash function generates a hash index
// in which to store a student entry in the table
//******************************************************************
int RollSystem::hash(string key) {
	int hash = 0;
	int index;

	for (int i  = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % TABLE_SIZE;

	return index;
}

//******************************************************************
// addStudent function will create a student
// and add that student to the system
//******************************************************************
void RollSystem::addStudent(string name, string usfId, string email) {
	int index = hash(name);

	if (HashTable[index]->name == "name") {
		HashTable[index]->name = name;
		HashTable[index]->usfId = usfId;
		HashTable[index]->email = email;
		HashTable[index]->presGrade = 0;
		HashTable[index]->e1Grade = 0;
		HashTable[index]->e2Grade = 0;
		HashTable[index]->projGrade = 0;
	}
	else {
		student* ptr = HashTable[index];
		student* n = new student;
		n->name = name;
		n->usfId = usfId;
		n->email = email;
		n->presGrade = 0;
		n->e1Grade = 0;
		n->e2Grade = 0;
		n->projGrade = 0;
		n->next = NULL;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}

		ptr->next = n;
	}
}

//******************************************************************
// numberOfItemsInIndex function returns
// the number of items in an index
//******************************************************************
int RollSystem::numberOfStudentsInIndex(int index) {
	int count = 0;

	if (HashTable[index]->name == "empty") {
		return count;
	}
	else {
		count++;
		student* ptr = HashTable[index];

		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}

		return count;
	}
}

//******************************************************************
// displayStudents function will display all students currently 
// in the system, as well as their data
//******************************************************************
void RollSystem::displayStudents() {
	int number;
	int count = 0;

	for (int i = 0; i < TABLE_SIZE; i++) {
		number = numberOfStudentsInIndex(i);
		cout << "-----------------\n";
		cout << "Index = " << i << endl;
		cout << "Name:  " << HashTable[i]->name << endl;
		cout << "UID:   " << HashTable[i]->usfId << endl;
		cout << "Email: " << HashTable[i]->email << endl;
		cout << "# of students = " << number << endl;
		cout << "-----------------\n";

		count += number;
	}

	if (count == 0) {
		cout << "Table is empty!" << endl;
	}
}

//******************************************************************
// searchByName function will search system for student
// by their name
//
// !! Need to consider duplicates !!
//******************************************************************
void RollSystem::searchByName(string name) {
	int index = hash(name);
	bool foundName = false;
	string usfId, email;
	int presGrade, e1Grade, e2Grade, projGrade;


	student* ptr = HashTable[index];

	// if the first entry in bucket is a match
	if (HashTable[index]->name == name) {
		foundName = true;
		usfId = ptr->usfId;
		email = ptr->email;
		presGrade = ptr->presGrade;
		e1Grade = ptr->e1Grade;
		e2Grade = ptr->e2Grade;
		projGrade = ptr->projGrade;
	}

	// otherwise, search the bucket
	while (ptr->next != NULL) {
		if (ptr->name == name) {
			foundName = true;
			usfId = ptr->usfId;
			email = ptr->email;
			presGrade = ptr->presGrade;
			e1Grade = ptr->e1Grade;
			e2Grade = ptr->e2Grade;
			projGrade = ptr->projGrade;
		}

		ptr = ptr->next;
	}

	// if the name was found, print that student's info
	if (foundName == true) {
		cout << "-----------------\n";
		cout << "INFO" << endl;
		cout << "-----------------\n";
		cout << "Name: " << name << endl;
		cout << "UID: " << usfId << endl;
		cout << "Email: " << email << endl;
		cout << "-----------------\n";
		cout << "GRADES" << endl;
		cout << "-----------------\n";
		cout << "Presentation Grade: " << presGrade << endl;
		cout << "Essay 1 Grade: " << e1Grade << endl;
		cout << "Essay 2 Grade: " << e2Grade << endl;
		cout << "Project Grade: " << projGrade << endl;
		cout << endl;
	}
	// otherwise print error message
	else {
		cout << name << "'s info was not found in the Roll System" << endl;
		cout << endl;
	}
}

//******************************************************************
// searchById function will search system for student 
// by their UID
//
// !! This will be difficult because we need to search by value !!
// !! instead of key !!
//******************************************************************

//******************************************************************
// searchByEmail function will search system for student
// by their email
//
// !! Should be like searchById function !!
//******************************************************************

//******************************************************************
// editName function will edit student's name
//******************************************************************

//******************************************************************
// editId function will edit student's UID
//******************************************************************

//******************************************************************
// editEmail function will edit student's email
//******************************************************************

//******************************************************************
// editGrades function will edit student's grades
//
// !! Could make user input all grades every time, OR split this into
// individual functions (ie. editProjectGrade, ...) and prompt user
// for what grade they would like to edit !!
//******************************************************************

//******************************************************************
// editStudent function will find student by searchById
// and then prompt the user for what field they would like to edit:
// editName, editId, editEmail, editGrades
//******************************************************************

int main() {
	RollSystem classRoll;

	classRoll.addStudent("Alexander", "70351384", "alexanderm@mail.usf.edu");
	classRoll.addStudent("Geoffrey", "92801743", "gkohlhase@mail.usf.edu");
	classRoll.addStudent("David", "1766534", "davidcap@mail.usf.edu");
	classRoll.displayStudents();

	classRoll.searchByName("Alexander");
	classRoll.searchByName("Geoffrey");
	classRoll.searchByName("Bill");

	return 0;
}
