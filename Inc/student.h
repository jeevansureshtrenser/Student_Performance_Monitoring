/* student.h - student support function library */ 
/* 
* Copyright (c) Trenser Technologies. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technologies license agreement. 
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

#define MAX_SUBJECTS 10U
#define MAX_NAME_LENGTH 50U
#define MAX_ADDRESS_LENGTH 100U
#define MAX_STUDENTS_OCCUPANCY 100U

#define GRADE_A 'A'
#define GRADE_B 'B'
#define GRADE_C 'C'
#define GRADE_D 'D'
#define GRADE_F 'F'

#define GRADE_A_THRESHOLD 90.0f
#define GRADE_B_THRESHOLD 80.0f
#define GRADE_C_THRESHOLD 70.0f
#define GRADE_D_THRESHOLD 60.0f
#define GRADE_F_THRESHOLD 40.0f


/* typedefs */

typedef struct STUDENT
    {
    uint8_t     *pucName;               // Student Name
    uint32_t    ulRoll;                 // Student Roll Number
    uint8_t     ucMarks[MAX_SUBJECTS];  // Marks of 10 subjects
    uint8_t     *pucAddress;            // Student Address (Dynamic size)
    uint32_t    ulSum;                  // Sum of marks
    float       fAvg;                   // Average Marks
    uint8_t     ucGrade;                // Grade based on average marks
    uint32_t    ulRank;                 // Rank based on average marks
    struct STUDENT* pstNext;            // Pointer to the next student in the 
                                        // linked list
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
bool PrintStudentInfo(student* pstInfo);

#endif // __INCstudenth