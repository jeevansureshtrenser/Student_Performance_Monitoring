/*
* main.c - Main entry point for the Student Performance Monitoring System.
*
*
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
        // Loop until user exits the program
        if (!menuMain())
            {
            printf("Exiting the program.\n");
            break; // Exit the loop and end the program
            }
        }

    return 0;
    }

