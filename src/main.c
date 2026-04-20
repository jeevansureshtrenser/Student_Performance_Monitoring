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
    uint8_t ucFailSafeMode = 0;
    while (FOREVER)
        {
        // Loop until user exits the program
        if( ucFailSafeMode == 1)
            {
            if(!FailSafeMode())
            {
                printf("Exit the application\n");
                return 0;
            }
            sleep(WAIT_SEC);
            }
        else
            {
            if(!menuMain())
                {
                printf("Error Running the Program.\n");
                printf("Entering to Flashing Mode\n");
                ucFailSafeMode = 1;
                }
            }

        }

    return 0;
    }

