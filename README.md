# Roll-System
A small class-roll maintenance system

Programmers: Ryan Binder, Constance Luong, Elin Cheung, Wesam Ali, Alexander Mas

Data:  
	- Name (up to 40 characters)  
	- USF ID (10 characters)  
	- Email (up to 40 characters)  
	- Grade of the presentation (numerical value from 0 (F) to 4 (A))  
	- Grade of essay 1 (numerical value from 0 (F) to 4 (A))  
	- Grade of the essay 2 (numerical value from 0 (F) to 4 (A))  
	- Grade of the term project (numerical value from 0 (F) to 4 (A))

Capabilities:  
	- Read/write student data  
	- Add/delete students  
	- Retrieve student data based on search by name, ID, or email  
	- Update any or all data fields  

## Things to do  
	- Set max characters allowed in each input  
	- Make sure UID is a valid input (Is it all numbers? Is it the proper length?)  

## Log
	09/01/2016 (Alec)
	- Created RollSystem class  
	- Implemented addStudent and displayStudents functions  

	09/04/2016 (Alec)  
	- Implemented searchByName function  
	
	09/06/2016 (Alec)
	- Scrapped hash table implementation for a vector implementation (will be easier to search multiple ways)  
	- Implemented basic main menu system using while loop and switch statements  
	- Implemented removeStudent, searchById, searchByEmail, and displayMenu functions 
	- Started implementation of editStudent (still need to allow grade edits)  
	
	09/08/2016 (Ryan)
	- Implemented transform to lowercase functions to eliminate case-sensitivity issues  
	
	09/08/2016 (Alec)  
	- Cleaned up code and display  
	- Added cin.ignore() in certain spots so that it's easier for the user to see what happened
	- Commented code so it should be easier to read
	- Replaced all cin with getline to allow for spaces  
	- Implemented conversion from string to int for switch statement so that user can't break it  
	- Split the search command in the switch statement into individual options (search by name, search by id, etc..)  
	
	09/10/2016 (Alec)  
	- Renamed displayStudents to displaySystem to avoid confusion with a new function  
	- Implemented displayStudent function  
	- Made console display much prettier using iomanip functions such as setw  
	- Split editStudent function into two parts: editInfo and editGrades  
	- Created menu for editStudent function to select either editInfo or editGrades  
	- Implemented validateGrade function  
	- Finished editStudent and editGrades functions  
	
	09/12/2016 (Ryan)  
	- Used .find() to validate email by searching for "@" in user input (addStudent, editStudent)  
	- Moved display of "Info edit successful!" in case of invalid email input  
	- Converted name and email to lowercase in editStudent function  
	
	

