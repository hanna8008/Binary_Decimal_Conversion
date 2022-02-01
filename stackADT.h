/*

Programmer: Hanna Zelis
Date: 19 November 2021
Program: CSC1720 Lab 12 - Stacks
Filename: stackADT.h

Description: This file contain class template for the stackADT type, which includes both the header file information and it would include the implementation information but all the methods are pure virtual methods. 

Assistance Received: N/A

How to compile: g++ stackADT.h

How to execute: does not need to be executed

*/

//Header file: stackADT.h 

#ifndef H_StackADT
#define H_StackADT 
  
template <class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
      //Method to initialize the stack to an empty state.
      //Postcondition: Stack is empty
     
    virtual bool isEmptyStack() const = 0;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    virtual bool isFullStack() const = 0;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    virtual void push(const Type& newItem) = 0;
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    virtual Type top() const = 0;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    virtual void pop() = 0;
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.
};
        
#endif
