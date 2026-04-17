
/* menu.c - menu function library */ 
/* 
* Copyright (c) 2026 Trenser Technologies. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technologies license agreement. 
*/

/* includes */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "menu.h"

/* defines */ 

/* typedefs */ 

/* globals */ 

/* locals */ 

/* forward declarations */ 

bool (*menuFunctionptr[MENU_OPTIONS_COUNT])(void) = 
    {
    menuStudentOverview,
    menuAddStudent,
    menuListStudent,
    menuDeleteStudent,
    };

bool (*menuListFunctionsptr[LIST_OPTIONS_COUNT])(void) = 
    {
    menuListSearchByName,
    menuListSortByName,
    menuListSortByRoll,
    menuListSortByRank,
    menuListStudentInfo, // Added option to list all students without sorting
    };

bool (*menuDeleteFunctionsptr[DELETE_OPTIONS_COUNT])(void) = 
    {
    menuDeleteByName,
    menuDeleteByRoll,
    menuDeleteAll,
    };

bool menuGetInput(uint8_t* pucBuffer, uint32_t ulBufferSize)
    {
    uint8_t buffer[MAX_NAME_LENGTH] = {0};
    uint8_t ucCount = 0;
    uint8_t ucChar = 0;
     if (pucBuffer == NULL || ulBufferSize == 0)
        {
        printf("Invalid input buffer.\n");
        return false;
        }
     else
        {
        /* No additional action needed */
        }
     if (ulBufferSize > MAX_NAME_LENGTH)
        {        printf("Input buffer size exceeds maximum allowed length.\n");
        return false;
        }
    if (pucBuffer == NULL || ulBufferSize == 0)
        {
        printf("Invalid input buffer.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    while (ucCount < sizeof(buffer) - 1) 
        {
        ucChar = getchar();
        if(ucChar == EOF)
            {
            printf("End of input detected.\n");
            break; // Stop reading input on EOF
            }
         else
            {
            /* No additional action needed */
            }
        if (ucChar == '\n') 
            {
            continue; // Stop reading input on newline
            }
        if (ucChar == '#')
            {
               break; // Stop reading input on '#' character
            }
        buffer[ucCount++] = ucChar;
    }
    buffer[ucCount] = '\0';
    if (buffer[0] == '\0')
        {
        printf("No input received.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    strncpy((char*)pucBuffer, (char*)buffer, ulBufferSize);
    return true;
    }


/** menuMain - Displays the main menu and handles user input.
* return -  true if successful, false otherwise.
*/
bool menuMain(void)
    {
    uint8_t ucOption = DEF_CLEAR;
    uint8_t ucChoice = DEF_CLEAR; // Buffer to hold user input for validation
    printf("\n=== Main Menu ===\n");
    printf("1. Student Overview\n");
    printf("2. Add Student\n");
    printf("3. List Students\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%hhd", &ucOption);
    ucChoice = ucOption - 1; // Store the original user input for validation
    if(ucChoice == EXIT)
        {
        return false; // Exit the program
        }
     else if (ucOption >= 1 && ucOption <= MENU_OPTIONS_COUNT)
        {
        return menuFunctionptr[ucChoice]();
        }
    else
        {
        printf("Invalid choice. Please try again.\n");
        return false;
        }
    return true;
    }
/*
* menuStudentOverview - Displays an overview of all students.
* return -  true if successful, false otherwise.
*/
bool menuStudentOverview(void)
    {
    printf("Student Overview:\n");
        uint32_t ulCount = 0;
    if (!studentGetCount(&ulCount))
        {        printf("Failed to get student count.\n");
        return false;
        }
    printf("Total Students: %d\n", ulCount);
    uint8_t pucAvgMarks[MAX_SUBJECTS] = {0};
    if (!studentGetAvgMarksOfSubjects(pucAvgMarks))
        {        printf("Failed to get average marks of subjects.\n");
        return false;
        }
    printf("Average Marks for Each Subject:\n");
    for (uint8_t i = 0; i < MAX_SUBJECTS; i++)
        {
        printf("Subject %d: %d\n", i + 1, pucAvgMarks[i]);
        }   
    return true;
    }

/*
* menuFillMarks - Fills the marks for a student.
* return -  true if successful, false otherwise.
*/
bool menuFillMarks(uint8_t* pucMarks)
    {
    for (uint8_t i = 0; i < MAX_SUBJECTS; i++)
        {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%hhd", &pucMarks[i]);
        if (pucMarks[i] > 100)
            {
            printf("Invalid marks. Please enter a value between 0 and 100.\n");
            return false;
            }
        else
            {
            /* No additional action needed */
            }
        }
    return true;
    }
/*
* menuFillStudentInfo - Fills the information for a student.
* return -  true if successful, false otherwise.
*/
bool menuFillStudentInfo(student* pstInfo)
    {
    if (pstInfo == NULL)
        {
        printf("Memory allocation failed for student name.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    pstInfo->pucName = (uint8_t*)malloc(MAX_NAME_LENGTH * sizeof(uint8_t));
     if (pstInfo->pucName == NULL)
        {
        printf("Memory allocation failed for student name.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    printf("Enter Student Name followed by a #: ");
    if (!menuGetInput(pstInfo->pucName, MAX_NAME_LENGTH))
    {
        printf("Failed to get student name.\n");
        free(pstInfo->pucName);
        return false;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &pstInfo->ulRoll);
    if (pstInfo->ulRoll == 0)
        {
        printf("Invalid roll number.\n");
        return false;
        }
    else
       {
        /* No additional action needed */
       }
    printf("Enter Marks for 10 subjects:\n");
    if (!menuFillMarks(pstInfo->ucMarks))
    {
        printf("Failed to fill student marks.\n");
        return false;
    }
    pstInfo->pucAddress = (uint8_t*)malloc(MAX_ADDRESS_LENGTH * sizeof(uint8_t));
     if (pstInfo->pucAddress == NULL)
        {
        printf("Memory allocation failed for student address.\n");
        free(pstInfo->pucName);
        return false;
        }
    else
        {
        /* No additional action needed */
        }

    printf("Enter Student Address followed by a #: ");
    if (!menuGetInput(pstInfo->pucAddress, MAX_ADDRESS_LENGTH))
        {
        printf("Failed to get student address.\n");
        free(pstInfo->pucName);
        free(pstInfo->pucAddress);
        return false;
        }
    else
        {/* No additional action needed */
        }

    return true;
}
/*
* menuAddStudent - Adds a new student to the system.
* return -  true if successful, false otherwise.
*/
bool menuAddStudent(void)
    {
    static uint32_t s_ulStudentCount = 0;
    if (s_ulStudentCount >= MAX_STUDENTS_OCCUPANCY)
        {
        printf("Maximum student occupancy reached. Cannot add more students.\n");
        return false;
        }
    
    student *newStudent = (student*)malloc(sizeof(student));
    memset(newStudent, 0, sizeof(student)); // Initialize the allocated memory to zero
    if (newStudent == NULL)
        {
        printf("Failed to allocate memory for new student.\n");
        return false;
        }

    if (!menuFillStudentInfo(newStudent))
        {
        printf("Failed to add student. Please try again.\n");
        return false;
        }
    printf("Calculating total marks, average, grade, and rank...\n");
    if (!studentCalcSum(newStudent, &newStudent->ulSum))
        {
        printf("Failed to calculate sum of marks.\n");
        return false;
        }
    if (!studentCalcAverage(newStudent, &newStudent->fAvg))
        {
        printf("Failed to calculate average marks.\n");
        return false;
        }
    if (!studentCalcGrades(newStudent, &newStudent->ucGrade))
        {
        printf("Failed to calculate grade.\n");
        return false;
        }
    if (!studentAdd(newStudent))
        {
        printf("Failed to add student.\n");
        return false;
        }
    if (!studentUpdateRank())
        {
        printf("Failed to update student rank.\n");
        return false;
        }
    s_ulStudentCount++;
    printf("Student added successfully! Total students: %d\n", s_ulStudentCount);
    return true;
    }
/*
* menuListStudent - Lists all students.
* return -  true if successful, false otherwise.
*/
bool menuListStudent(void)
    {
    uint8_t ucOption = DEF_CLEAR;
    
    printf("\n=== List Student Menu ===\n");
    printf("1. Search by Name\n");
    printf("2. Sort by Name\n");
    printf("3. Sort by Roll Number\n");
    printf("4. Sort by Rank\n");
    printf("5. All Students\n");
    printf("Enter your choice: ");
    scanf("%hhd", &ucOption);
    if (ucOption >= 1 && ucOption <= LIST_OPTIONS_COUNT)
        {
        return menuListFunctionsptr[ucOption - 1]();
        }
    else
        {
        printf("Invalid choice. Please try again.\n");
        return false;
        }
    return true;
    }
/*
* menuDeleteStudent - Deletes a student from the system.
* return -  true if successful, false otherwise.
*/
bool menuDeleteStudent(void)
    {
    uint8_t ucOption = DEF_CLEAR;

    printf("\n=== Delete Student Menu ===\n");
    printf("1. Delete by Name\n");
    printf("2. Delete by Roll Number\n");
    printf("3. Delete All\n");
    printf("Enter your choice: ");
    scanf("%hhd", &ucOption);
    if (ucOption >= 1 && ucOption <= DELETE_OPTIONS_COUNT)
        {
        return menuDeleteFunctionsptr[ucOption - 1]();
        }
    else
        {
        printf("Invalid choice. Please try again.\n");
        return false;
        }
    return true;
    }
/*
* menuListSearchByName - Searches for a student by name.
* return -  true if successful, false otherwise.
*/
bool menuListSearchByName(void)
    {
    uint8_t *pucName = NULL;
    pucName = (uint8_t*)malloc(MAX_NAME_LENGTH * sizeof(uint8_t));
    if (pucName == NULL)
        {
        printf("Failed to allocate memory for student name.\n");
        return false;
        }
    printf("Search Student by Name:\n");
    scanf("%s", pucName);
    if (pucName[0] == '\0')
        {
        printf("Invalid name input.\n");
        free(pucName); 
        return false;
        }
    if(!studentListSearchByName(pucName))
        {
        printf("Failed to search student by name.\n");
        free(pucName); 
        return false;
        }
    free(pucName);
    return true;
    }
/*
* menuListSortByName - Sorts students by name.
* return -  true if successful, false otherwise.
*/
bool menuListSortByName(void)
    {
    printf("List Students Sorted by Name:\n");
    if(!studentListSortByName())
        {
        printf("Failed to list students sorted by name.\n");
        return false;
        }
    return true;
    }

/*
* menuListSortByRoll - Sorts students by roll number.
* return -  true if successful, false otherwise.
*/
bool menuListSortByRoll(void)
    {
    printf("List Students Sorted by Roll Number:\n");
    if(!studentListSortByRoll())
        {
        printf("Failed to list students sorted by roll number.\n");
        return false;
        }
    return true;
    }

/*
* menuListSortByRank - Sorts students by rank.
* return -  true if successful, false otherwise.
*/
bool menuListSortByRank(void)
    {
    printf("List Students Sorted by Rank:\n");
    if(!studentListSortByRank())
        {
        printf("Failed to list students sorted by rank.\n");
        return false;
        }
    return true;
    }

/*
* menuDeleteByName - Deletes a student by name.
* return -  true if successful, false otherwise.
*/
bool menuDeleteByName(void)
    {
    uint8_t *ucname = NULL;
    ucname = (uint8_t*)malloc(MAX_NAME_LENGTH * sizeof(uint8_t));
    if (ucname == NULL)
        {
        printf("Failed to allocate memory for student name.\n");
        return false;
        }
    printf("Delete Student by Name:\n");
    scanf("%s", ucname);
    if (ucname[0] == '\0')
        {
        printf("Invalid name input.\n");
        free(ucname);
        return false;
        }
    if (!studentDeleteByName(ucname))
        {        printf("Failed to delete student by name.\n");
        free(ucname);
        return false;
        }
    free(ucname);
    return true;
    }

/*
* menuDeleteByRoll - Deletes a student by roll number.
* return -  true if successful, false otherwise.
*/
bool menuDeleteByRoll(void)
    {
    uint32_t ulRoll = DEF_CLEAR;
    printf("Delete Student by Roll Number:\n");
    scanf("%d", &ulRoll);
    if (!studentDeleteByRoll(ulRoll))
        {
        printf("Failed to delete student by roll number.\n");
        return false;
        }
    return true;
    }

/*
* menuDeleteAll - Deletes all students from the system.
* return -  true if successful, false otherwise.
*/
bool menuDeleteAll(void)
    {
    printf("Delete All Students:\n");
    if (!studentDeleteAll())
        {
        printf("Failed to delete all students.\n");
        return false;
        }
    return true;
    }

bool menuListStudentInfo(void)
    {
    printf("List All Students:\n");
    if(!studentPrintInfo(NULL)) // Passing NULL to print all students
        {
        printf("Failed to list all students.\n");
        return false;
        }
    return true;
    }

