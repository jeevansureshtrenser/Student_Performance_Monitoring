/* student.h - student support function library */ 
/* 
* Copyright (c) Trenser Technology Solutions. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Trenser Technology Solutions license agreement. 
*/

#ifndef __INCstudenth
#define __INCstudenth
#include <stdint.h>
#include <stdbool.h>

/* 
* student structure to hold student information, including name, roll number,
* marks, address, sum of marks, average marks, grade, rank, and a pointer to
* the next student in the linked list.
*/

/* defines */

#define MAX_SUBJECTS            10U
#define MAX_NAME_LENGTH         64U
#define MAX_ADDRESS_LENGTH      256U
#define MAX_STUDENTS_OCCUPANCY  100U
#define MAX_MARK_FOR_SUBJECT    100U

#define GRADE_A 'A'
#define GRADE_B 'B'
#define GRADE_C 'C'
#define GRADE_D 'D'
#define GRADE_F 'F'

#define GRADE_A_THRESHOLD 90U
#define GRADE_B_THRESHOLD 80U
#define GRADE_C_THRESHOLD 70U
#define GRADE_D_THRESHOLD 60U
#define GRADE_F_THRESHOLD 40U
#define FIRST_RANK 1U

#define NULL_CHAR       '\0'
#define NEWLINE_CHAR    '\n'
#define INDEX_ZERO       0U


/* typedefs */

typedef struct STUDENT
    {
    uint32_t    ulRank;                 // Rank based on average marks
    uint32_t    ulRoll;          // Student Roll Number
    uint32_t    ulSum;                 // Sum of marks in all subjects
    float       fAvg;                   // Average Marks
    uint8_t     ucName[MAX_NAME_LENGTH]; // Student Name
    uint8_t     ucAddress[MAX_ADDRESS_LENGTH]; // Student Address
    uint8_t     ucMarks[MAX_SUBJECTS];  // Marks of 10 subjects
    uint8_t     ucGrade[MAX_SUBJECTS];  // Grade based on average marks
    struct STUDENT* pstNext;            // Pointer to the next structure
    } student;

/* function declarations */

bool studentAdd(student* pstInfo);
bool studentCalcAverage(student* pstInfo, float* pfAvg);
bool studentCalcSum(student* pstInfo, uint32_t* pulSum);
bool studentCalcGrades(student* pstInfo, uint8_t* pucSum);
bool studentUpdateRank(void);
bool studentGetCount(uint32_t* pulCount);
bool studentGetAvgMarksOfSubjects(uint8_t* pucAvgMarks);
bool studentDeleteByName(uint8_t* pucName);
bool studentDeleteByRoll(uint32_t ulRoll);
bool studentDeleteAll(void);
bool studentListSearchByName(uint8_t* pucName);
bool studentPrintInfo(void);
bool studentListSortByName(void);
bool studentListSortByRoll(void);
bool studentListSortByRank(void);

#endif // __INCstudenth