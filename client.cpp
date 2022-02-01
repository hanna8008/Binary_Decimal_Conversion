/*

Programmer: Hanna Zelis
Date: 30 November 2021
Program: CSC1720 Program 4 - Functional Stacks
Filename: ZelisProgram4.cpp

Description: This program uses an array-based stack to convert a binary number into an equivalent decimal
             number, then uses a linked list-based stack to conver a decimal number into an equivalent binary
             number.

Assistance Received: CSC1710/1720 C++ Textbook - "C++ Programming - Program Design Including Data Structures" (pages 1068, 1071, & 1072)

How to compile: g++ ZelisProgram4.cpp -o prog4

How to execute: ./prog4

*/



#include <iostream>
#include "myStack.h"
#include "linkedStack.h"


using namespace std;



int main()
{

    //this first part of the main function turns a binary number
    //     into a decimal number by an array-based stack

    long binaryNumber;
    int bit, decimal = 0, weight = 0;

    //creates and initializes array based-stack
    stackType<int> binaryStack(50);
    binaryStack.initializeStack();
    
    
    cout << "Enter binary number (to be converted to a decimal): ";
    cin >> binaryNumber;

    //math behind changing the binary number into a decimal number
    //     Assistance received: textbook page 1068 - helped me figure out the math component 
    //                          (did not contribute to the array based-stack component)
    while (binaryNumber > 0)
    {
        bit = binaryNumber % 10;
        binaryStack.push(bit);
        decimal = decimal + binaryStack.top() * static_cast<int>(pow(2.0, weight));
        binaryNumber = binaryNumber / 10;
        weight++;
    }
    
    cout << "Decimal = " << decimal << endl;   
    cout << endl;
    cout << endl;








    //the second part of the main function changes a decimal into
    //    a binary number by a linked list-based stack

    int userDecimal, rightBit;
    long binary;

    //creates and initializes linked list-stack
    linkedStackType<int> decimalStack;
    decimalStack.initializeStack();

    cout << "Enter a number (to be converted to binary): ";
    cin >> userDecimal;

    //math behind changing the decimal number into a binary number
    //     Assistance received: textbook page 1071 & 1072 - helped me figure out the math component
    //                          (did not contribute to the linked list-stack component)
    while (userDecimal > 0)
    {
        rightBit = userDecimal % 2;
        decimalStack.push(rightBit);
  
        userDecimal = userDecimal / 2;
    }

    //printing out the linked list-stack
    cout << "Binary = ";
    while(!decimalStack.isEmptyStack())
    {
        cout << decimalStack.top();
        decimalStack.pop();
    }
    
    cout << endl;

return 0;
}
