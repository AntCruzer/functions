// INCLUDES (OK)
#include <stdio.h>



#pragma warning(disable: 4996) 



// FUNCTION PROTOTYPES
int getNum(void);
bool rangeChecker(int value, int minNum, int maxNum);
int powerCalculation(int base, int exponent);



int main(void)
{
    // CONSTANTS
    const int CHOICE_1 = 1;
    const int CHOICE_2 = 2;
    const int CHOICE_3 = 3;
    const int CHOICE_4 = 4;
    const int MIN_BASE = 1;
    const int MAX_BASE = 25;
    const int MIN_EXP = 1;
    const int MAX_EXP = 5;

    // VARIABLES
    int userChoice = 0;
    int inputBase = 0;
    int inputExp = 0;
    int power = 0;
    bool inRangeBase = false;
    bool inRangeExp = false;

    while (userChoice != CHOICE_4)
    {
        // DISPLAY MENU
        printf("\nPower Menu:\n"
                "   1. Change base\n"
                "	2. Change exponent\n"
                "	3. Display base raised to exponent\n"
                "	4. Exit program\n"
                "Option? ");

        // OBTAIN USER CHOICE
        userChoice = getNum();

        // OPTION: CHANGE BASE
        if (userChoice == CHOICE_1)
        {
            printf("Input base value: ");                                       // prompt user input
                inputBase = getNum();                                           // obtain user input
                inRangeBase = rangeChecker(inputBase, MIN_BASE, MAX_BASE);      // perform range check

                // invalid range?
                if (inRangeBase == false)                                       
                {
                    printf("Error: value not within 1 - 25\n");
                    inputBase = 1;                                              // set default
                }
                printf("--------------------------------------------------\n");
        }
        // OPTION 2: CHANGE EXPONENT
        else if (userChoice == CHOICE_2)    
        {
            printf("Input exponent value: ");                                   // prompt user input
            inputExp = getNum();                                                // obtain user input
            inRangeExp = rangeChecker(inputExp, 1, 5);                          // perform range check

            // invalid range
            if (inRangeExp == false)   
            {
                printf("Error: value not within 1 - 5\n");        
                inputExp = 1;                                                   // set default
            }
            printf("--------------------------------------------------\n");

        }
        // OPTION 3: CALCULATE POWER
        else if (userChoice == CHOICE_3)
        {
            power = powerCalculation(inputBase, inputExp);
            printf("Base of %d raised to the exponent %d equals %d.\n", inputBase, inputExp, power); // output power
            printf("--------------------------------------------------\n");

        }
        else if (userChoice != CHOICE_1 && userChoice != CHOICE_2 && userChoice != CHOICE_3 && userChoice != CHOICE_4)
        {
            printf("Invalid entry\n");
            printf("--------------------------------------------------\n");

        }
    }
    
    printf("Exiting....");
    return 0;
}



/*
*   Function:       getNum()
*   Parameters:     void
*   Returns:        int number
*   Description:    This function gets an integer values from the user. 
                    If the user enters a valid integer, the value is stored
                    in the return value. If the user-entered value is not valid,
                    -1 is returned.
*/
int getNum(void)
{
    char record[121] = { 0 }; /* record stores the string */
    int number = 0;

    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
     * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
         * the system, set number to -1 */
        number = -1;
    }
    return number;
}



/*
*   Function:       rangeChecker()
*   Parameters:     int value
*                   int minNum
*                   int maxNum       
*   Returns:        int: 0 if value is out of range, 1 if value is within acceptable range.
*   Description:    This function  determines whether of not value 
*                   is within the acceptable range.
*/
bool rangeChecker(int value, int minNum, int maxNum)
{
    if (minNum <= value)  // within acceptable range?
    {
        if (value <= maxNum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}



/*
*   Function:       powerCalculation()
*   Parameters:     int base
*                   int exponent      
*   Returns:        int: calculated power
*   Description:    This function takes two parameters (int base, int exponent) 
*                   and calculates the power.
*/
int powerCalculation(int base, int exponent)
{
    // initialize variables
    int i = 0;
    int power = 1;

    while (i < exponent)
    {
        power = power * base;
        i++;
    }
    return power;
}