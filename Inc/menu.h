/* menu.h - menu support function library */ 
/* 
* Copyright (c) Trenser Technologies. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technologies license agreement. 
*/

#ifndef __INCmenuh
#define __INCmenuh
#include <stdint.h>
#include <stdbool.h>

/* defines */

#define FOREVER 1U
#define DEF_CLEAR 0U

#define MENU_OPTIONS_COUNT 4U
#define LIST_OPTIONS_COUNT 5U
#define DELETE_OPTIONS_COUNT 3U

#define WAIT_SEC 5

/* typedefs */

typedef enum
    {
    STUDENT_OVERVIEW,
    ADD_STUDENT,
    LIST_STUDENTS,
    DELETE_STUDENT,
    EXIT
    } MENU_OPTIONS;

/* function declarations */



bool menuMain(void);			// Displays  "main menu"

// Main Menu
bool menuStudentOverview(void); // Show how many students are added and average marks

bool menuAddStudent(void);		// Ask name, roll number, Marks of 10 subjects, student Address(Dyanamic size), calc sum of marks, average, grades of each and Rank

bool menuListStudent(void);		// Print the students names based on "List Student menu"

bool menuDeleteStudent(void);	// Remove the students based on "Delete Student menu"

// List Student Menu
bool menuListSearchByName(void);	// Ask name, and show result
bool menuListSortByName(void);		// Show all student list sorted by Name(Alphabetically)
bool menuListSortByRoll(void);		// Show all student list sorted by Roll number
bool menuListSortByRank(void);		// Show all student list sorted by Rank
bool menuListStudentInfo(void);		// Show all student list without sorting
// Delete Student Menu
bool menuDeleteByName(void);		// Ask name, and delete student
bool menuDeleteByRoll(void);		// Ask Roll, and delete student
bool menuDeleteAll(void);			// Delete all students
// Failsafe mode
bool FailSafeMode()
#endif // __INCmenuh