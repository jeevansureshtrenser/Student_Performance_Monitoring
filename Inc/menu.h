/* menu.h - menu support function library */ 
/* 
* Copyright (c) Trenser Technology Solutions. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technology Solutions license agreement. 
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

#define WAIT_SEC 1U
#define MAX_TRY_COUNT 5U


/* typedefs */

typedef enum
    {
    MENU_EXIT,
    MENU_STUDENT_OVERVIEW,
    MENU_ADD_STUDENT,
    MENU_LIST_STUDENTS,
    MENU_DELETE_STUDENT,
    } MENU_OPTIONS;

/* function declarations */



bool menuMain(void);			// Displays  "main menu"

// Main Menu
static bool menuStudentOverview(void); // Show how many students are added and average marks

static bool menuAddStudent(void);		// Ask name, roll number, Marks of 10 subjects, student Address(Dyanamic size), calc sum of marks, average, grades of each and Rank

static bool menuListStudent(void);		// Print the students names based on "List Student menu"

static bool menuDeleteStudent(void);	// Remove the students based on "Delete Student menu"

// List Student Menu
static bool menuListSearchByName(void);	// Ask name, and show result
static bool menuListSortByName(void);		// Show all student list sorted by Name(Alphabetically)
static bool menuListSortByRoll(void);		// Show all student list sorted by Roll number
static bool menuListSortByRank(void);		// Show all student list sorted by Rank
static bool menuListStudentInfo(void);		// Show all student list without sorting
// Delete Student Menu
static bool menuDeleteByName(void);		// Ask name, and delete student
static bool menuDeleteByRoll(void);		// Ask Roll, and delete student
static bool menuDeleteAll(void);			// Delete all students
// Failsafe mode
#endif // __INCmenuh