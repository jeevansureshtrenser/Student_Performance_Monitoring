
/* menu.c - menu function library */ 
/* 
* Copyright (c) 2026 Trenser Technology Solutions. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technology Solutions license agreement. 
*/

/* includes */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "student.h"
#include "menu.h"

/* defines */ 

/* typedefs */ 

/* globals */ 

/* locals */ 

/* forward declarations */ 
static bool menuFailSafeMode();
static bool menuRemoveNewline(uint8_t* pucBuffer);
static bool menuGetInput(uint8_t* pucBuffer, uint32_t ulBufferSize);
static bool menuFillMarks(uint8_t* pucMarks);
static bool menuFillStudentInfo(student* pstInfo);
static bool menuCalcAverageAndGrade(student* pstInfo);
static bool menuPrintMainMenu(void);
static bool menuPrintListMenu(void);
static bool menuPrintDeleteMenu(void);

/* Function pointers for main menu options */
static bool (*menuFunctionptr[MENU_OPTIONS_COUNT])(void) = 
    {
    menuStudentOverview,
    menuAddStudent,
    menuListStudent,
    menuDeleteStudent,
    };

static bool (*menuListFunctionsptr[LIST_OPTIONS_COUNT])(void) = 
    {
    menuListSearchByName,
    menuListSortByName,
    menuListSortByRoll,
    menuListSortByRank,
    menuListStudentInfo, // Added option to list all students without sorting
    };

static bool (*menuDeleteFunctionsptr[DELETE_OPTIONS_COUNT])(void) = 
    {
    menuDeleteByName,
    menuDeleteByRoll,
    menuDeleteAll,
    };

/** menuPrintMainMenu - Displays the main menu List.
* return -  true if successful, false otherwise.
*/
bool menuPrintMainMenu(void)
    {
    bool bReturn = false;
    printf("\n=== Student Performance Monitoring System ===\n");
    if(printf("1. Student Overview\n") > 0)
        {
        if(printf("2. Add Student\n") > 0)
            {
            if(printf("3. List Students\n") > 0)
                {
                if(printf("4. Delete Student\n") > 0)
                    {
                    if(printf("0. Exit\n") > 0)
                        {
                        if(printf("Enter your choice: ") > 0)
                            {
                                bReturn = true;
                            }
                        }
                    }
                }
            }
        }

    return bReturn;
    }

/** menuPrintListMenu - Displays the list student menu and handles user input.
* return -  true if successful, false otherwise.
*/
bool menuPrintListMenu(void)
    {
    bool bReturn = false;
    if(printf("\n=== List Student Menu ===\n") > 0)
    {
        if(printf("1. Search by Name\n") > 0)
        {
            if(printf("2. Sort by Name\n") > 0)
            {
                if(printf("3. Sort by Roll Number\n") > 0)
                {
                    if(printf("4. Sort by Rank\n") > 0)
                    {
                        if(printf("5. All Students\n") > 0)
                        {
                            if(printf("Enter your choice: ") > 0)
                            {
                                bReturn = true;
                            }
                        }
                    }
                }
            }
        }
    }

    return bReturn;
    }

/** menuPrintDeleteMenu - Displays the delete student menu and handles user input.
* return -  true if successful, false otherwise.
*/
static bool menuPrintDeleteMenu(void)
    {
    bool bReturn = false;
    if(printf("\n=== Delete Student Menu ===\n") > 0)
    {
        if(printf("1. Delete by Name\n") > 0)
        {
            if(printf("2. Delete by Roll Number\n") > 0)
            {
                if(printf("3. Delete All\n") > 0)
                {
                    if(printf("Enter your choice: ") > 0)
                    {
                        bReturn = true;
                    }
                }
            }
        }
    }

    return bReturn;
    }

/** menuGetInput - Gets input from the user.
* return -  true if successful, false otherwise.
*/
static bool menuGetInput(uint8_t* pucBuffer, uint32_t ulBufferSize)
    {
    bool bReturn = true;
    if (pucBuffer == NULL || ulBufferSize == 0)
        {
        printf("Invalid input buffer or buffer size.\n");
        return false;
        }
    else
        {
        if (fgets((char*)pucBuffer, ulBufferSize, stdin) != NULL)
            {
            if(pucBuffer[INDEX_ZERO] == NEWLINE_CHAR)
                {
                if (fgets((char*)pucBuffer, ulBufferSize, stdin) != NULL)
                    {
                        if(!menuRemoveNewline(pucBuffer))
                            {
                            printf("Failed to remove newline character.\n");
                            bReturn = false;
                            }
                    }
                    else
                    {
                        printf("Failed to read input.\n");
                        bReturn = false;
                    }
                }
            else
                {
                /* No additional action needed */
                }
            }
        else
            {
            printf("Failed to read input.\n");
            bReturn = false;
            }
        }

    return bReturn;
    }

/** menuMain - Gets input from the user.
* return -  true if successful, false otherwise.
*/
bool menuMain(void)
    {
    uint8_t ucOption = DEF_CLEAR;
    uint8_t iReadCount = DEF_CLEAR;
    bool bReturn = true;
    if(!menuPrintMainMenu())
        {
        printf("Failed to print main menu.\n");
        bReturn = false;
        }
    else
        {
        iReadCount = scanf("%hhu", &ucOption);
        if(iReadCount == 0)
            {
            printf("Invalid input\n");
            bReturn = false;
            }
        else
            {
            if(ucOption == MENU_EXIT)
                {
                bReturn = false; // Exit the program
                }
            else if (ucOption >= MENU_STUDENT_OVERVIEW && ucOption <= MENU_OPTIONS_COUNT)
                {
                if(!menuFunctionptr[ucOption - 1]())
                    {
                    printf("Failed to execute selected menu option.\n");
                    if(!menuFailSafeMode()) // Call failsafe mode if the selected menu function fails
                        {
                        printf("Failed to enter failsafe mode.\n");
                        bReturn = false;
                        }
                    }
                else
                    {
                        bReturn = true;
                    }
                }
            else
                {
                printf("Invalid choice. Please try again.\n");
                if(!menuFailSafeMode()) // Call failsafe mode if the selected menu function fails
                    {
                    printf("Failed to enter failsafe mode.\n");
                    bReturn = false;
                    }
                }
            }
        }


    return bReturn;
    }

/*
* menuStudentOverview - Displays an overview of all students.
* return -  true if successful, false otherwise.
*/
static bool menuStudentOverview(void)
    {
    uint8_t pucAvgMarks[MAX_SUBJECTS] = {0};
    uint32_t ulCount = 0;
    uint8_t ucCount = 0;
    bool bReturn = false;
    printf("Student Overview:\n");
    if (!studentGetCount(&ulCount))
        {
        printf("Failed to get student count.\n");
        bReturn = false;
        }
    else
        {
        printf("Total Students: %u\n", ulCount);
        if (!studentGetAvgMarksOfSubjects(pucAvgMarks))
            {        printf("Failed to get average marks of subjects.\n");
            bReturn = false;
            }
        else
            {
            printf("Average Marks for Each Subject:\n");
            for (ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
                {
                printf("Subject %d: %d\n", ucCount + 1, pucAvgMarks[ucCount]);
                }
            bReturn = true;
            }
        }

    return bReturn;
    }

/*
* menuFillMarks - Fills the marks for a student.
* return -  true if successful, false otherwise.
*/
static bool menuFillMarks(uint8_t* pucMarks)
    {
    bool bReturn = true;
    uint8_t ucCount = 0;
    if (pucMarks == NULL)
        {
        printf("Invalid input to menuFillMarks.\n");
        bReturn = false;
        }
    else
        {
        for ( ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
            {
            printf("Enter marks for subject %d: ", ucCount + 1);
            if(scanf("%hhu", &pucMarks[ucCount]) == 0)
                {
                    printf("Invalid mark Input\n");
                    bReturn = false;
                    break;
                }
            if (pucMarks[ucCount] > MAX_MARK_FOR_SUBJECT)
                {
                printf("Invalid marks. Please enter a value between 0 and %d.\n", MAX_MARK_FOR_SUBJECT);
                bReturn = false;
                break;
                }
            else
                {
                /* No additional action needed */
                }
            }
        }

    return bReturn;
    }

/*
* menuFillStudentInfo - Fills the information for a student.
* return -  true if successful, false otherwise.
*/
static bool menuFillStudentInfo(student* pstInfo)
    {
    bool bReturn = true;
    int32_t iReadCount = DEF_CLEAR;
    if (pstInfo == NULL)
        {
        printf("Memory allocation failed for student name.\n");
        bReturn = false;
        }
    else
        {
        printf("Enter Student Name: ");
        if (!menuGetInput(pstInfo->ucName, MAX_NAME_LENGTH))
            {
            printf("Failed to get student name.\n");
            bReturn = false;
            }
        else if (pstInfo->ucName[INDEX_ZERO] == NULL_CHAR)
            {
            printf("Invalid name input.\n");
            bReturn = false;
            }
        else
            {
            printf("Enter Roll Number: ");
            iReadCount = scanf("%d", &pstInfo->ulRoll);
            if (pstInfo->ulRoll == 0 || iReadCount == 0)
                {
                printf("Invalid roll number.\n");
                bReturn = false;
                }
            else
                {
                printf("Enter Marks for 10 subjects:\n");
                if (!menuFillMarks(pstInfo->ucMarks))
                    {
                    printf("Failed to fill student marks.\n");
                    bReturn = false;
                    }
                else
                    {
                    printf("Enter Student Address: ");
                    if (!menuGetInput(pstInfo->ucAddress, MAX_ADDRESS_LENGTH))
                        {
                        printf("Failed to get student address.\n");
                        bReturn = false;
                        }
                    else
                        {
                            /* No additional action needed */
                        }
                    }
                }
            }
        }

    return bReturn;
}

/*
* menuAddStudent - Adds a new student to the system.
* return -  true if successful, false otherwise.
*/
static bool menuAddStudent(void)
    {
    static uint32_t s_ulStudentCount = 0;
    student *newStudent = NULL;
    bool bReturn = false;
     if (s_ulStudentCount >= MAX_STUDENTS_OCCUPANCY)
        {
        printf("Maximum student occupancy reached. Cannot add more students.\n");
        bReturn = false;
        }
    else
        {
        newStudent = (student*)malloc(sizeof(student));
        if (newStudent == NULL)
            {
            printf("Failed to allocate memory for new student.\n");
            bReturn = false;
            }
        else
            {
            memset(newStudent, 0, sizeof(student)); // Initialize the allocated memory to zero

            if (!menuFillStudentInfo(newStudent))
                {
                printf("Failed to add student. Please try again.\n");
                free(newStudent);
                bReturn = false;
                }
            else
                {
                if(!menuCalcAverageAndGrade(newStudent))
                    {
                    printf("Failed to calculate average and grade.\n");
                    free(newStudent);
                    bReturn = false;
                    }
                else
                    {
                    if (!studentAdd(newStudent))
                        {
                        printf("Failed to add student to the system.\n");
                        free(newStudent);
                        bReturn = false;
                        }
                    else
                        {
                        if (!studentUpdateRank())
                            {
                            printf("Failed to update student ranks.\n");
                            free(newStudent);
                            bReturn = false;
                            }
                        else
                            {
                            s_ulStudentCount++; // Increment the student count
                            printf("Student added successfully!\n");
                            bReturn = true;
                            }
                        }
                    }
                }
            }
       
        }

    return bReturn;
    }

/*
* menuListStudent - Lists all students.
* return -  true if successful, false otherwise.
*/
static bool menuListStudent(void)
    {
    uint8_t ucOption = DEF_CLEAR;
    int32_t iReadCount = DEF_CLEAR;
    bool bReturn = true;
    if(!menuPrintListMenu())
        {
        bReturn = false;
        }
    else
        {
        iReadCount = scanf("%hhu", &ucOption);
        if(iReadCount == 0)
            {
            bReturn = false;
            }
        else
            {
            if (ucOption >= 1 && ucOption <= LIST_OPTIONS_COUNT)
                {
                if(!menuListFunctionsptr[ucOption - 1]())
                    {
                    bReturn = false;
                    }
                }
            else
                {
                printf("Invalid choice. Please try again.\n");
                bReturn = false;
                }
            }
        }

    return bReturn;
    }

/*
* menuDeleteStudent - Deletes a student from the system.
* return -  true if successful, false otherwise.
*/
static bool menuDeleteStudent(void)
    {
    uint8_t ucOption = DEF_CLEAR;
    int32_t iReadCount = DEF_CLEAR;
    bool bReturn = true;
    if(!menuPrintDeleteMenu())
        {
            bReturn = false;
        }
    else
        {
        iReadCount = scanf("%hhu", &ucOption);
        if(iReadCount == 0)
            {
            bReturn = false;
            }
        else
            {
            /* No process*/
            }
        if (ucOption >= 1 && ucOption <= DELETE_OPTIONS_COUNT)
            {
            if(!menuDeleteFunctionsptr[ucOption - 1]())
                {
                bReturn = false;
                }
            }
        else
            {
            printf("Invalid choice. Please try again.\n");
            bReturn = false;
            }
        }

    return bReturn;
    }

/*
* menuListSearchByName - Searches for a student by name.
* return -  true if successful, false otherwise.
*/
static bool menuListSearchByName(void)
    {
    uint8_t *pucName = NULL;
    pucName = (uint8_t*)malloc(MAX_NAME_LENGTH * sizeof(uint8_t));
    bool bReturn = true;
    if (pucName == NULL)
        {
        printf("Failed to allocate memory for student name.\n");
        bReturn = false;
        }
    else
    {
    printf("Search Student by Name:\n");
    if (!menuGetInput(pucName, MAX_NAME_LENGTH))
        {
            printf("Failed to get student name.\n");
            free(pucName);
            bReturn = false;
        }
    else
    {
    if (pucName[INDEX_ZERO] == NULL_CHAR)
        {
        printf("Invalid name input.\n");
        free(pucName); 
        bReturn = false;
        }
    else
        {
        if(!studentListSearchByName(pucName))
            {
            printf("Failed to search student by name.\n");
            free(pucName); 
            bReturn = false;
            }
        }

    }

    }
   

    return bReturn;
    }

/*
* menuListSortByName - Sorts students by name.
* return -  true if successful, false otherwise.
*/
static bool menuListSortByName(void)
    {
    bool bReturn = true;
    printf("List Students Sorted by Name:\n");
    if(!studentListSortByName())
        {
        printf("Failed to list students sorted by name.\n");
        bReturn = false;
        }

    return bReturn;
    }

/*
* menuListSortByRoll - Sorts students by roll number.
* return -  true if successful, false otherwise.
*/
static bool menuListSortByRoll(void)
    {
    bool bReturn = true;
    printf("List Students Sorted by Roll Number:\n");
    if(!studentListSortByRoll())
        {
        printf("Failed to list students sorted by roll number.\n");
        bReturn = false;
        }

    return bReturn;
    }

/*
* menuListSortByRank - Sorts students by rank.
* return -  true if successful, false otherwise.
*/
static bool menuListSortByRank(void)
    {
    bool bReturn = true;
    printf("List Students Sorted by Rank:\n");
    if(!studentListSortByRank())
        {
        printf("Failed to list students sorted by rank.\n");
        bReturn = false;
        }

    return bReturn;
    }

/*
* menuDeleteByName - Deletes a student by name.
* return -  true if successful, false otherwise.
*/
static bool menuDeleteByName(void)
    {
    uint8_t *ucname = NULL;
    ucname = (uint8_t*)malloc(MAX_NAME_LENGTH * sizeof(uint8_t));
    if (ucname == NULL)
        {
        printf("Failed to allocate memory for student name.\n");
        return false;
        }
    printf("Delete Student by Name:\n");
        if (!menuGetInput(ucname, MAX_NAME_LENGTH))
        {
            printf("Failed to get student name.\n");
            free(ucname);
            return false;
        }
    if (ucname[INDEX_ZERO] == NULL_CHAR)
        {
        printf("Invalid name input.\n");
        free(ucname);
        return false;
        }
    if (!studentDeleteByName(ucname))
        {
        printf("Failed to delete student by name.\n");
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
static bool menuDeleteByRoll(void)
    {
    uint32_t ulRoll = DEF_CLEAR;
    int32_t iReadCount = DEF_CLEAR;
    printf("Delete Student by Roll Number:\n");
    iReadCount = scanf("%u", &ulRoll);
    if(iReadCount == 0)
        {
            printf("Failed to read input\n");
            return false;
        }
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
static bool menuDeleteAll(void)
    {
    printf("Delete All Students:\n");
    if (!studentDeleteAll())
        {
        printf("Failed to delete all students.\n");
        return false;
        }
    return true;
    }
/*
* menuListStudentInfo - Lists information for all students.
* return -  true if successful, false otherwise.
*/
static bool menuListStudentInfo(void)
    {
    printf("List All Students:\n");
    if(!studentPrintInfo()) // Passing NULL to print all students
        {
        printf("Failed to list all students.\n");
        return false;
        }
    
    return true;
    }

/*
* menuFailSafeMode - For setting safe mode when fails.
* return -  true if successful, false otherwise.
*/
static bool menuFailSafeMode()
{
    static uint8_t s_ucFailCount = 0;
    uint8_t ucChar = 0;
    printf("Press * to continue Application\n");
    printf("Waiting for shutdown........\n");
     while (s_ucFailCount < MAX_TRY_COUNT) 
        {
        ucChar = getchar();
        if(ucChar == '*')
        {
            printf("Restart Application\n");
            return true;
        }
        s_ucFailCount++;
        sleep(WAIT_SEC);
        }
    
    return false;
}

/*
* menuRemoveNewline - Removes the newline character from the end of a string.
* return -  true if successful, false otherwise.
*/
static bool menuRemoveNewline(uint8_t* pucBuffer)
    {
    size_t len = 0;
    if (pucBuffer == NULL)
        {
        printf("Invalid input buffer.\n");
        return false;
        }
    len = strlen((char*)pucBuffer);
    if (len > 0 && pucBuffer[len - 1] == NEWLINE_CHAR)
        {
        pucBuffer[len - 1] = NULL_CHAR;
        }
    else
        {
        /* No additional action needed */
        }
    if (strlen((char*)pucBuffer) == 0)
        {
        printf("Input cannot be empty.\n");
        return false;
        }

    return true;
    }

/*
* menuCalcAverageAndGrade - Calculates average and grade for a student.
* return -  true if successful, false otherwise.
*/
static bool menuCalcAverageAndGrade(student* pstInfo)
    {
    bool bReturn = false;
    uint8_t ucGrade = 0;
     if (pstInfo == NULL)
        {
        printf("Invalid student information.\n");
        bReturn = false;
        }
        else
            {

            printf("Calculating total marks, average, grade, and rank...\n");
            if (!studentCalcSum(pstInfo, &pstInfo->ulSum))
                {
                printf("Failed to calculate sum of marks.\n");
                bReturn = false;
                }
            else
                {
                if (!studentCalcAverage(pstInfo, &pstInfo->fAvg))
                    {
                    printf("Failed to calculate average marks.\n");
                    bReturn = false;
                    }
                else
                    {
                    if (!studentCalcGrades(pstInfo, &ucGrade))
                        {
                        printf("Failed to calculate grades.\n");
                        bReturn = false;
                        }
                    else
                        {
                        bReturn = true;
                        }
                    }
                }
            }

    return bReturn;
    }
