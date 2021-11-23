#include <iostream>
#include <cstdlib>
#include <string>
#include "InputValidation.h"
using namespace std;
/*
Function for Input Validation
Player Inputs an integer. Program checks if the input is valid, otherwise resets the buffer and asks the user for another input
*/
int InputValidation::inputValidation()
 {
    int input = -1;
    bool valid = false;
    do
    {

        cout << endl << "Choose an Option: " << flush;
        cin >> input;
        if (cin.good())
        {
            //everything looks good, exit the loop
            valid = true;
        }
        else
        {
            //Input is invalid, buffer state is reset
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, Please try again: " << endl;
        }
    } while (!valid);

    return (input);
    }