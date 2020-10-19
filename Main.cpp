/*Racy Halterman
C++ Fall 2020
Due: October 19th
Lab 4 Introduction to C++ Programming
Design and write a C++ program that inputs a series of hourly temperature from a file, and outputs a bar chart
(using stars) of the temperatures. The stars should represent 3 degrees, so that the graph can fit onto the page.
*/

//Random note, the results round down. For instance, 2 shows up as 0 stars. 8 shows up as 2 stars. Etc.

#include <iostream>
#include <string>
#include <iomanip> //Including the necessary libraries
#include <fstream>
#include <cmath> /* You may not even need this library, but I like to include it with any sort of code that calculates
 Just so that things run smoothly.*/

using namespace std; 

int main()
{
    float temperature;
    char ranchar;

    ifstream inData; // These lines allow the file to be opened.
    inData.open("Temps.txt");

    cout << "Temperatures:" << endl;
    /*The line below displays a sort of guide to what the stars mean, the first "setw(6)" allows the different temperatures 
    to be displayed to the left of the graph without issue.*/
    cout << setw(10) << "-30" << setw(9) << '0' << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;
   
    while (inData >> temperature)
    {  //This while loop is what allows the different temperatures to be repeated.
        cout << setw(8) << temperature;
        //This prints the temperature, and makes the last character, from the first character (including spaces), equal 6 spaces.
        int tempDiv3 = temperature / 3;
        /*This gives the number of stars needed for each temperature, as each star is equal to 3 degrees.
         It also allows the stars to be equal to an integer, rather than a floating number.*/
        for (int i = -30 / 3; i <= 120 / 3; i++) //The i++ is what allows the stars to be repeated the correct amount of times
        {   //This for loop with the following nested if/else statements allows the stars to be printed across the screen.

            if (i == 0)
            { //This prints the | at the 0 mark, so that it is clear what is positive and what is negative.
                cout << '|';
            }
            else if (tempDiv3 < 0 && i >= tempDiv3 && i < 0 && tempDiv3 >= -10)
            { //This allows negative temperatures to be printed across the screen, from the right to the left.
                cout << '*';
            }
            else if (tempDiv3 > 0 && i <= tempDiv3 && i > 0 && tempDiv3 <= 40)
            { //This allows positive temperatures to be printed across the screen from the "0" mark.
                cout << '*';
            }
            else
            { /*This small, yet very important piece of code makes the places float where they do. For instance, if
              you were to remove this piece of code, the | would not be floating at the 0 space.*/
                cout << ' ';
            }
        }
        if (tempDiv3 > 40)
        {
            cout << "Bad Data";
        }
        if (tempDiv3 < -10)
        {
            cout << "Bad Data";
        }
        cout << endl;
    }
        inData.close(); //Closes the data file.
    return 0;
}