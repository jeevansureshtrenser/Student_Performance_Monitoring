/* student.c - student function library */ 
/* 
* Copyright (c) 2026 Trenser Technology solutions. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technology solution license agreement. 
*/

/* includes */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* defines */ 

/* typedefs */ 

/* globals */ 
static student* pstHead = NULL; // Head of the linked list of students

/* locals */ 

/* forward declarations */ 
static bool studentPrintMarks(student* pstInfo);
static bool studentPrintGrades(student* pstInfo);

/*
* studentAdd - Adds a new student to the linked list of students.
* return -  true if successful, false otherwise.
*/
bool studentAdd(student* pstInfo)
    {
    student* pstCurrent = NULL;
    if (pstInfo == NULL)
        {
        printf("Invalid student information provided.\n");
        return false;
        }
        if (pstHead == NULL)
        {
            pstHead = pstInfo;
            pstHead->pstNext = NULL; // Initialize the next pointer to NULL
        }
    else
        {
        pstCurrent = pstHead;
        while (pstCurrent->pstNext != NULL)
            {
            pstCurrent = pstCurrent->pstNext;
            }
        pstCurrent->pstNext = pstInfo;
        pstInfo->pstNext = NULL; // Initialize the next pointer to NULL
        }
    return true;
    }

/*
* studentCalcSum - Calculates the sum of marks for a student.
* return -  true if successful, false otherwise.
*/
bool studentCalcSum(student* pstInfo, uint32_t* pulSum)
    {
    uint32_t ulSum = 0;
    uint8_t ucCount = 0;
    if (pstInfo == NULL || pulSum == NULL)
        {
        printf("Invalid input to studentCalcSum.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    for (ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
        {
        ulSum += pstInfo->ucMarks[ucCount];
        }
    *pulSum = ulSum;
    if (*pulSum > (MAX_SUBJECTS * MAX_MARK_FOR_SUBJECT))
        {
        printf("Calculated sum of marks is out of valid range.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    return true;
    }

/*
* studentCalcAverage - Calculates the average of marks for a student.
* return -  true if successful, false otherwise.
*/
bool studentCalcAverage(student* pstInfo, float* pfAvg)
    {

    if (pstInfo == NULL || pfAvg == NULL)
        {
        printf("Invalid input to studentCalcAverage.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    if (pstInfo->ulSum == 0)
        {
        printf("Sum of marks is zero, cannot calculate average.\n");
        return false;
        }
    *pfAvg = (float)pstInfo->ulSum / MAX_SUBJECTS;
    if (*pfAvg < 0 || *pfAvg > MAX_MARK_FOR_SUBJECT)
        {
        printf("Calculated average is out of valid range (0-%u).\n", MAX_MARK_FOR_SUBJECT);
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    return true;
    }

/*
* studentCalcGrades - Calculates the grade for a student.
* return -  true if successful, false otherwise.
*/
bool studentCalcGrades(student* pstInfo, uint8_t* pucGrade)
    {
    uint8_t ucCount = 0;
    if (pstInfo == NULL || pucGrade == NULL)
        {
        printf("Invalid input to studentCalcGrades.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    (void)pucGrade; // Suppress unused variable warning
    for ( ucCount= 0; ucCount < MAX_SUBJECTS; ucCount++)
        {
        if (pstInfo->ucMarks[ucCount] > MAX_MARK_FOR_SUBJECT)
            {
            printf("Calculated grade is out of valid range.\n");
            return false;
            }
        else if (pstInfo->ucMarks[ucCount] >= GRADE_A_THRESHOLD && pstInfo->ucMarks[ucCount] <= MAX_MARK_FOR_SUBJECT)
            {
            pstInfo->ucGrade[ucCount] = GRADE_A;
            }
        else if (pstInfo->ucMarks[ucCount] >= GRADE_B_THRESHOLD)
            {
            pstInfo->ucGrade[ucCount] = GRADE_B;
            }
        else if (pstInfo->ucMarks[ucCount] >= GRADE_C_THRESHOLD)
            {
            pstInfo->ucGrade[ucCount] = GRADE_C;
            }
        else if (pstInfo->ucMarks[ucCount] >= GRADE_D_THRESHOLD)
            {
            pstInfo->ucGrade[ucCount] = GRADE_D;
            }
        else
            {
            pstInfo->ucGrade[ucCount] = GRADE_F;
            }
        }
    return true;
    }

/*
* studentUpdateRank - Updates the rank of all students.
* return -  true if successful, false otherwise.
*/
bool studentUpdateRank(void)
    {
    uint32_t ulRank = FIRST_RANK;
    student* pstCurrent = NULL;
    student* pstOther = NULL;
     if (pstHead == NULL)
        {
        printf("No students available to update rank.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    if (pstHead == NULL)
        {
        printf("No students available to update rank.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    pstCurrent = pstHead;
    if (pstCurrent == NULL)
        {
        printf("No students available to update rank.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    while (pstCurrent != NULL)
        {
        ulRank = FIRST_RANK; // Reset rank for each student
        pstOther = pstHead;
        while (pstOther != NULL)
            {
            if (pstOther->fAvg > pstCurrent->fAvg)
                {
                ulRank++;
                }
            pstOther = pstOther->pstNext;
            }
        pstCurrent->ulRank = ulRank;
        pstCurrent = pstCurrent->pstNext;
        }
        
    return true;
    }

/*
* studentGetCount - Gets the count of students.
* return -  true if successful, false otherwise.
*/

bool studentGetCount(uint32_t* pulCount)
    {
    uint32_t ulCount = 0;
    student* pstCurrent = NULL;
    if (pstHead == NULL)
        {
        printf("No students available to get the count.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    if (pulCount == NULL)
        {
        printf("Invalid input to studentGetCount.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        ulCount++;
        pstCurrent = pstCurrent->pstNext;
        }
    *pulCount = ulCount;
    if (*pulCount > MAX_STUDENTS_OCCUPANCY || *pulCount == 0)
        {
        printf("Calculated student count is out of valid range.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    return true;
    }

/*
* studentGetAvgMarksOfSubjects - Calculates the average marks for each subject.
* return -  true if successful, false otherwise.
*/
bool studentGetAvgMarksOfSubjects(uint8_t* pucAvgMarks)
    {
    uint32_t ulCount = 0;
    student* pstCurrent = NULL;
    uint8_t ucCount = 0;
    uint32_t ulTotalMarks[MAX_SUBJECTS] = {0};
    if (pucAvgMarks == NULL)
        {
        printf("Invalid input to studentGetAvgMarksOfSubjects.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        for (ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
            {
            ulTotalMarks[ucCount] += pstCurrent->ucMarks[ucCount];
            }
        ulCount++;
        pstCurrent = pstCurrent->pstNext;
        }
    if (ulCount == 0)
        {
        printf("No students available to calculate average marks.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    for (ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
        {
        pucAvgMarks[ucCount] = (uint8_t)(ulTotalMarks[ucCount] / ulCount);
         if (pucAvgMarks[ucCount] > MAX_MARK_FOR_SUBJECT)
            {
            printf("Calculated average marks for subject %d is out of valid range.\n", ucCount + 1);
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
* studentDeleteByName - Deletes a student by name.
* return -  true if successful, false otherwise.
*/
bool studentDeleteByName(uint8_t* pucName)
    {
    student* pstCurrent = NULL;
    student* pstPrevious = NULL;
    if (pucName == NULL)
        {
        printf("Invalid name input.\n");
        return false;
        }
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        if (strcmp((char*)pstCurrent->ucName, (char*)pucName) == 0)
            {
            if (pstPrevious == NULL)
                {
                pstHead = pstCurrent->pstNext;
                }
            else
                {
                pstPrevious->pstNext = pstCurrent->pstNext;
                }
            free(pstCurrent);
            printf("Student with name %s deleted successfully.\n", pucName);
            return true;
            }
        pstPrevious = pstCurrent;
        pstCurrent = pstCurrent->pstNext;
        }
    printf("Student with name %s not found.\n", pucName);

    return false;
    }

/*
* studentDeleteByRoll - Deletes a student by roll number.
* return -  true if successful, false otherwise.
*/
bool studentDeleteByRoll(uint32_t ulRoll)
    {
    student* pstCurrent = NULL;
    student* pstPrevious = NULL;
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        if (pstCurrent->ulRoll == ulRoll)
            {
            if (pstPrevious == NULL)
                {
                pstHead = pstCurrent->pstNext;
                }
            else
                {
                pstPrevious->pstNext = pstCurrent->pstNext;
                }
            free(pstCurrent);
            printf("Student with roll number %u deleted successfully.\n", ulRoll);
            return true;
            }
        pstPrevious = pstCurrent;
        pstCurrent = pstCurrent->pstNext;
        }
    printf("Student with roll number %u not found.\n", ulRoll);

    return false;
    }

/*
* studentDeleteAll - Deletes all students from the list.
* return -  true if successful, false otherwise.
*/
bool studentDeleteAll(void)
    {
    student* pstCurrent = NULL;
    student* pstTemp = NULL;
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        pstTemp = pstCurrent;
        pstCurrent = pstCurrent->pstNext;
        free(pstTemp);
        }
    pstHead = NULL;

    return true;
    }

/*
* studentListSearchByName - Searches for a student by name.
* return -  true if successful, false otherwise.
*/
bool studentListSearchByName(uint8_t* pucName)
    {
    student* pstCurrent = NULL;
    if (pucName == NULL)
        {
        printf("Invalid name input.\n");
        return false;
        }
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    pstCurrent = pstHead;
    while(pstCurrent != NULL)
        {
        if(strncmp((char*)pstCurrent->ucName, (char*)pucName, MAX_NAME_LENGTH) == 0)
            {
            printf("Student found:\n");
            printf("Name: %s | Roll: %u | Average: %.2f | Rank: %u | Address: %s |\n",
               pstCurrent->ucName,
               pstCurrent->ulRoll,
               pstCurrent->fAvg,
               pstCurrent->ulRank,
               pstCurrent->ucAddress
               );
            if(studentPrintMarks(pstCurrent))
                {
                if(!studentPrintGrades(pstCurrent))
                    {
                    printf("Failed to print grades for student %s.\n", pstCurrent->ucName);
                    }
                else
                    {
                        /* No additional action needed */
                    }
                }
            else
                {
                printf("Failed to print marks for student %s.\n", pstCurrent->ucName);
                }
            return true;
            }
        pstCurrent = pstCurrent->pstNext;
        }
    printf("Student with name %s not found.\n", pucName);

    return false;
    }

/** studentPrintInfo - Displays information for a single student.
* return -  true if successful, false otherwise.
*/
bool studentPrintInfo(void)
    {
    student* pstCurrent = NULL;
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        printf("Name: %s | Roll: %u | Average: %.2f | Rank: %u | Address: %s |\n",
               pstCurrent->ucName,
               pstCurrent->ulRoll,
               pstCurrent->fAvg,
               pstCurrent->ulRank,
               pstCurrent->ucAddress
               );
        if(studentPrintMarks(pstCurrent))
            {
            if(!studentPrintGrades(pstCurrent))
                {
                printf("Failed to print grades for student %s.\n", pstCurrent->ucName);
                }
            else
                {
                    /* No additional action needed */
                }
            }
        else
            {
            printf("Failed to print marks for student %s.\n", pstCurrent->ucName);
            }
        pstCurrent = pstCurrent->pstNext;
        }

    return true;
    }

/** studentListSortByRoll - Sorts the student list by roll number.
* return -  true if successful, false otherwise.
*/
bool studentListSortByRoll(void)
    {
    student* pstCurrent = NULL;
    student* pstTemp = NULL;
    student temp = {0};
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    if(pstHead->pstNext == NULL)
        {
        printf("One student available to list.\n");
        return false;
        }
        pstCurrent = pstHead;
        pstTemp = pstHead->pstNext;
        while (pstCurrent != NULL)
        {
            while (pstTemp != NULL)
            {
            if(pstTemp->ulRoll < pstCurrent->ulRoll)
            {
                // Swap the student information
                temp = *pstCurrent;
                *pstCurrent = *pstTemp;
                *pstTemp = temp;
            }
            pstTemp = pstTemp->pstNext;
            }
        pstCurrent = pstCurrent->pstNext;

        }
    if(studentPrintInfo())
        {
        printf("Students sorted by roll number successfully.\n");
        return true;
        }
    else
        {
        printf("Failed to print student information after sorting.\n");
        }

    return false;
    }

/** studentListSortByName - Sorts the student list by name.
* return -  true if successful, false otherwise.
*/
bool studentListSortByName(void)
    {
    student* pstCurrent = NULL;
    student* pstTemp = NULL;
    student temp = {0};
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    if(pstHead->pstNext == NULL)
        {
        printf("Only one student available\n");
        return false;
        }
    pstCurrent = pstHead;
    pstTemp = pstCurrent;
    while (pstCurrent != NULL)
        {
        while (pstTemp != NULL)
            {
            if(strncmp((char*)pstTemp->ucName, (char*)pstCurrent->ucName, MAX_NAME_LENGTH) < 0)
            {
                // Swap the student information
                temp = *pstCurrent;
                *pstCurrent = *pstTemp;
                *pstTemp = temp;
            }
            pstTemp = pstTemp->pstNext;
            }
        pstCurrent = pstCurrent->pstNext;
        pstTemp = pstCurrent; // Reset temp to current for the next iteration
        }
        if(studentPrintInfo())
        {
        printf("Students sorted by name successfully.\n");
        return true;
        }
    else
        {
        printf("Failed to print student information after sorting.\n");
        }

        return false;
    }

/** studentListSortByRank - Sorts the student list by rank.
* return -  true if successful, false otherwise.
*/
bool studentListSortByRank(void)
    {
    student* pstCurrent = NULL;
    student* pstTemp = NULL;
    student temp = {0};
    if(pstHead == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    if(pstHead->pstNext == NULL)
        {
        printf("Only one student available\n");
        return false;
        }
    pstCurrent = pstHead;
    pstTemp = pstHead->pstNext;
    while(pstCurrent != NULL)
        {
            while(pstTemp != NULL)
            {
            if(pstTemp->ulRank < pstCurrent->ulRank)
                {
                    // Swap the student information
                    temp = *pstCurrent;
                    *pstCurrent = *pstTemp;
                    *pstTemp = temp;
                }
            pstTemp = pstTemp->pstNext;
            }
            pstCurrent = pstCurrent->pstNext;
            pstTemp = pstCurrent; // Reset temp to current for the next iteration
        }
    if(studentPrintInfo())
        {
        printf("Students sorted by rank successfully.\n");
        return true;
        }
    else
        {
        printf("Failed to print student information after sorting.\n");
        return false;
        }

    return true;
    }

/** studentPrintMarks - Prints marks for a student.
* return -  true if successful, false otherwise.
*/
static bool studentPrintMarks(student* pstInfo)
    {
    uint8_t ucCount = 0;
    if (pstInfo == NULL)
        {
        printf("Invalid student information provided.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    for (ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
        {
        printf("Subject %d: %u\n", ucCount + 1, pstInfo->ucMarks[ucCount]);
        }

    return true;
    }

/** studentPrintGrades - Prints grades for a student.
* return -  true if successful, false otherwise.
*/
static bool studentPrintGrades(student* pstInfo)
    {
    uint8_t ucCount = 0;
    if (pstInfo == NULL)
        {
        printf("Invalid student information provided.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    for (ucCount = 0; ucCount < MAX_SUBJECTS; ucCount++)
        {
        printf("Subject %d Grade: %c\n", ucCount + 1, pstInfo->ucGrade[ucCount]);
        }

    return true;
    }
