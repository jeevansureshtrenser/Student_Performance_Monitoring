
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
    };

bool (*menuDeleteFunctionsptr[DELETE_OPTIONS_COUNT])(void) = 
    {
    menuDeleteByName,
    menuDeleteByRoll,
    menuDeleteAll,
    };


/** menuMain - Displays the main menu and handles user input.
* return -  true if successful, false otherwise.
*/
bool menuMain(void)
    {
    uint32_t ucOption = DEF_CLEAR;

    printf("\n=== Main Menu ===\n");
    printf("1. Student Overview\n");
    printf("2. Add Student\n");
    printf("3. List Students\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ucOption);
    if (ucOption >= 1 && ucOption <= MENU_OPTIONS_COUNT)
        {
        return menuFunctionptr[ucOption - 1]();
        }
    else
        {
        printf("Invalid choice. Please try again.\n");
        }
    return true;
    }

bool menuStudentOverview(void)
    {
    printf("Student Overview:\n");
    return true;
    }


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

bool menuFillStudentInfo(student* pstInfo)
    {
    printf("Enter Student Name: ");
    scanf("%s", pstInfo->pucName);
    if (pstInfo->pucName == NULL)
        {
        printf("Memory allocation failed for student name.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
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
    printf("Enter Student Address: ");
    scanf("%s", pstInfo->pucAddress);
    if (pstInfo->pucAddress == NULL)
    {
        return false;
    }
    else
    {
        /* No additional action needed */
    }

    return true;
}

bool menuAddStudent(void)
    {
    static uint32_t s_ulStudentCount = 0;
    if (s_ulStudentCount >= MAX_STUDENTS_OCCUPANCY)
        {
        printf("Maximum student occupancy reached. Cannot add more students.\n");
        return false;
        }
    
    student newStudent = {0};
    
    if (!menuFillStudentInfo(&newStudent))
        {
        printf("Failed to add student. Please try again.\n");
        return false;
        }
    printf("Calculating total marks, average, grade, and rank...\n");
    if (!studentCalcSum(&newStudent, &newStudent.ulSum))
        {
        printf("Failed to calculate sum of marks.\n");
        return false;
        }
    if (!studentCalcAverage(&newStudent, &newStudent.fAvg))
        {
        printf("Failed to calculate average marks.\n");
        return false;
        }
    if (!studentCalcGrades(&newStudent, &newStudent.ucGrade))
        {
        printf("Failed to calculate grade.\n");
        return false;
        }
    if (!studentAdd(&newStudent))
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

bool menuListStudent(void)
    {
    uint8_t ucOption = DEF_CLEAR;
    
    printf("\n=== List Student Menu ===\n");
    printf("1. Search by Name\n");
    printf("2. Sort by Name\n");
    printf("3. Sort by Roll Number\n");
    printf("4. Sort by Rank\n");
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

bool menuListSortByName(void)
    {
    printf("List Students Sorted by Name:\n");
    return true;
    }


bool menuListSortByRoll(void)
    {
    printf("List Students Sorted by Roll Number:\n");
   
    return true;
    }

bool menuListSortByRank(void)
    {
    printf("List Students Sorted by Rank:\n");
    return true;
    }

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


