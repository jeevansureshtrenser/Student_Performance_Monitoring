#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
    {
    while (FOREVER)
        {
        // Loop until user exits the program
        if (!menuMain())
        {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit the loop and end the program
        }
        }

    return 0;
    }
