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
	static const int TABLE_SIZE = 10;

	struct student {
		string name;
		int usfId;
		string email;
		int presGrade, e1Grade, e2Grade, projGrade;
		student* next;
	};

	student* HashTable[TABLE_SIZE];

	RollSystem();
	int hash(string key);
	void addStudent(string name, int usfId, string email);
	int numberOfStudentsInIndex(int index);
	void displayStudents();
};

//******************************************************************
// RollSystem constructor initializes table of students
// as default empty entries
//******************************************************************
RollSystem::RollSystem() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		HashTable[i] = new student;
		HashTable[i]->name = "name";
		HashTable[i]->usfId = 0;
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
void RollSystem::addStudent(string name, int usfId, string email) {
	int index = hash(name);

	if (HashTable[index]->name == "name") {
		HashTable[index]->name = name;
		HashTable[index]->usfId = usfId;
		HashTable[index]->email = email;
	}
	else {
		student* ptr = HashTable[index];
		student* n = new student;
		n->name = name;
		n->usfId = usfId;
		n->email = email;
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

//******************************************************************
// searchById function will search system for student 
// by their UID
//******************************************************************

//******************************************************************
// searchByEmail function will search system for student
// by their email
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

	classRoll.addStudent("Alec", 70351384, "alexanderm@mail.usf.edu");

	classRoll.displayStudents();

	return 0;
}
