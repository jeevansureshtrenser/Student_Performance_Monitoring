/* student.c - student function library */ 
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
/* defines */ 

/* typedefs */ 

/* globals */ 
static student* pstHead = NULL; // Head of the linked list of students
/* locals */ 

/* forward declarations */ 

/*
* studentAdd - Adds a new student to the linked list of students.
* return -  true if successful, false otherwise.
*/
bool studentAdd(student* pstInfo)
    {
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
        student* pstCurrent = pstHead;
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
    if (pstInfo == NULL || pulSum == NULL)
        {
        printf("Invalid input to studentCalcSum.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    for (uint8_t i = 0; i < MAX_SUBJECTS; i++)
        {
        ulSum += pstInfo->ucMarks[i];
        }
    *pulSum = ulSum;
    if (*pulSum > MAX_SUBJECTS * 100)
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
    if (*pfAvg < 0 || *pfAvg > 100)
        {
        printf("Calculated average is out of valid range (0-100).\n");
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
    if (pstInfo == NULL || pucGrade == NULL)
        {
        printf("Invalid input to studentCalcGrades.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    if (pstInfo->fAvg >= GRADE_A_THRESHOLD)
        {
        *pucGrade = GRADE_A;
        }
    else if (pstInfo->fAvg >= GRADE_B_THRESHOLD)
        {
        *pucGrade = GRADE_B;
        }
    else if (pstInfo->fAvg >= GRADE_C_THRESHOLD)
        {
        *pucGrade = GRADE_C;
        }
    else if (pstInfo->fAvg >= GRADE_D_THRESHOLD)
        {
        *pucGrade = GRADE_D;
        }
    else
        {
        *pucGrade = GRADE_F;
        }
    if (*pucGrade > GRADE_F || *pucGrade < GRADE_A)
        {
        printf("Calculated grade is out of valid range.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    return true;
    }

/*
* studentUpdateRank - Updates the rank of all students.
* return -  true if successful, false otherwise.
*/
bool studentUpdateRank(void)
    {
    if (pstHead == NULL)
        {
        printf("No students available to update rank.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
    student* pstCurrent = pstHead;
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
        uint32_t ulRank = 1;
        student* pstOther = pstHead;
        while (pstOther != NULL)
            {
            if (pstOther->fAvg > pstCurrent->fAvg)
                {
                ulRank++;
                }
            pstOther = pstOther->pstNext;
            }
        pstCurrent->ulRank = ulRank;
         if (pstCurrent->ulRank == 0)
            {
            printf("Calculated rank is out of valid range.\n");
            return false;
            }
        else
            {
            /* No additional action needed */
            }
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
    student* pstCurrent = pstHead;
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
    student* pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        for (uint8_t i = 0; i < MAX_SUBJECTS; i++)
            {
            ulTotalMarks[i] += pstCurrent->ucMarks[i];
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
    for (uint8_t i = 0; i < MAX_SUBJECTS; i++)
        {
        pucAvgMarks[i] = (uint8_t)(ulTotalMarks[i] / ulCount);
         if (pucAvgMarks[i] > 100)
            {
            printf("Calculated average marks for subject %d is out of valid range.\n", i + 1);
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
    if (pucName == NULL)
        {
        printf("Invalid name input.\n");
        return false;
        }
    student* pstCurrent = pstHead;
    student* pstPrevious = NULL;
    while (pstCurrent != NULL)
        {
        if (strcmp((char*)pstCurrent->pucName, (char*)pucName) == 0)
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
    free(pucName);
    return false;
    }

/*
* studentDeleteByRoll - Deletes a student by roll number.
* return -  true if successful, false otherwise.
*/
bool studentDeleteByRoll(uint32_t ulRoll)
    {
    student* pstCurrent = pstHead;
    student* pstPrevious = NULL;
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
            printf("Student with roll number %d deleted successfully.\n", ulRoll);
            return true;
            }
        pstPrevious = pstCurrent;
        pstCurrent = pstCurrent->pstNext;
        }
    printf("Student with roll number %d not found.\n", ulRoll);
    return false;
    }
/*
* studentDeleteAll - Deletes all students from the list.
* return -  true if successful, false otherwise.
*/
bool studentDeleteAll(void)
    {
    student* pstCurrent = pstHead;
    while (pstCurrent != NULL)
        {
        student* pstTemp = pstCurrent;
        pstCurrent = pstCurrent->pstNext;
        free(pstTemp);
        }
    pstHead = NULL;
    return true;
    }

bool studentListSearchByName(uint8_t* pucName)
    {
    if (pucName == NULL)
        {
        printf("Invalid name input.\n");
        return false;
        }
        student* pstCurrent = pstHead;
    if (pstCurrent == NULL)
        {
        printf("No students available to search.\n");
        return false;
        }
    while (pstCurrent != NULL)
        {
        if (strncmp((char*)pstCurrent->pucName, (char*)pucName, MAX_NAME_LENGTH) == 0)
            {
            printf("Student found:\n");
            if (!studentPrintInfo(pstCurrent))
                {
                printf("Failed to print student information.\n");
                return false;
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

bool studentPrintInfo(student* pstInfo)
    {
    if (pstInfo == NULL)
        {
        printf("No student information available to print.\n");
        return false;
        }
    else
        {/* No additional action needed */
        }
 student* pstCurrent = pstHead;
    if (pstCurrent == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    else
        {/* No additional action needed */
        }
    
    while (pstCurrent != NULL)
        {
        
        printf("Name: %s, Roll: %d, Average: %.2f, Grade: %c, Rank: %d\n",
               pstCurrent->pucName,
               pstCurrent->ulRoll,
               pstCurrent->fAvg,
               pstCurrent->ucGrade,
               pstCurrent->ulRank);
        pstCurrent = pstCurrent->pstNext;
        }
    return true;
    }

/** studentListSortByRoll - Sorts the student list by roll number.
* return -  true if successful, false otherwise.
*/
bool studentListSortByRoll(void)
    {
        student* pstCurrent = pstHead;
        student* pstTemp = pstHead->pstNext;
    if (pstCurrent == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    else
        {

        /* No additional action needed */
        }
        while (pstCurrent != NULL)
        {

                if(pstTemp->ulRoll < pstCurrent->ulRoll)
                {
                    // Swap the student information
                    student temp = *pstCurrent;
                    *pstCurrent = *pstTemp;
                    *pstTemp = temp;
                }
            pstCurrent = pstCurrent->pstNext;

        }
    if(studentPrintInfo(pstHead))
        {
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
        student* pstCurrent = pstHead;
        student* pstTemp = pstHead->pstNext;
    if (pstCurrent == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
        while (pstCurrent != NULL)
        {
            if(strcmp((char*)pstTemp->pucName, (char*)pstCurrent->pucName) < 0)
            {
                // Swap the student information
                student temp = *pstCurrent;
                *pstCurrent = *pstTemp;
                *pstTemp = temp;
            }
            pstCurrent = pstCurrent->pstNext;
        }
        if(studentPrintInfo(pstHead))
        {
        return true;
        }
    else
        {
        printf("Failed to print student information after sorting.\n");
        }
        return false;
    }

bool studentListSortByRank(void)
    {
        student* pstCurrent = pstHead;
        student* pstTemp = pstHead->pstNext;
    if (pstCurrent == NULL)
        {
        printf("No students available to list.\n");
        return false;
        }
    else
        {
        /* No additional action needed */
        }
        while (pstCurrent != NULL)
        {
                if(pstTemp->ulRank < pstCurrent->ulRank)
                {
                    // Swap the student information
                    student temp = *pstCurrent;
                    *pstCurrent = *pstTemp;
                    *pstTemp = temp;
                }
            pstCurrent = pstCurrent->pstNext;
        }
    if(studentPrintInfo(pstHead))
        {
        return true;
        }
    else
        {
        printf("Failed to print student information after sorting.\n");
        return false;
        }
    return true;
    }
