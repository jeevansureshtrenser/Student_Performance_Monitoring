/*
* main.c - Main entry point for the Student Performance Monitoring System.
*
* Copyright (c) 2026 Trenser Technology Solutions. 
* 
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technology Solutions license agreement. 
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/* defines */

/* typedefs */

/* globals */

/* locals */

/* forward declarations */

/*
* studentAdd - Adds a new student to the linked list of students.
* return -  true if successful, false otherwise.
*/
int main()
    {
    while (FOREVER)
        {
        if(!menuMain())
            {
            printf("Error Running the Program.\n");
            printf("Entering to Flashing Mode\n");
            return EXIT_FAILURE;
            }
        }

    return 0;
    }

