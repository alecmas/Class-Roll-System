# Roll-System
A small class-roll maintenance system

Programmers: Ryan Binder, Constance Luong, Elin Cheung, Wesam Ali, Alec Mas

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
	
	09/13/2016 (Alec)  
	- Condensed validation for name, UID, and email inputs into a single function called validateStudent  
	- Finished validateStudent function  
	- Reorganized functions 
	- Renamed some variables to make them easier to understand  
	
	09/28/2016 (Alec)  
	- Noticed an inconsistency between validateStudent and addStudent; just rearranged the variables passed into validateStudent  

