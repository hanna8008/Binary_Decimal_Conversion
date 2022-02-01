/*

Programmer Hanna Zelis
Date: 19 November 2021
Program: CSC1720 Lab 12 - Stacks
Filename: myStack.h

Description: Thi file contains class template for the stackADT type, which includes both the header file information and the implementation information.

Assistance Received from: N/A

How to compile: g++ myStack.h

How to execute: does not need to be executed as this class is included in the ArrayStackTest.cpp file and will execute when that file executes.

*/

//Header file: myStack.h
 
#ifndef H_StackType 
#define H_StackType
 
#include <iostream> 
#include <cassert>
#include <cmath>

#include "stackADT.h"
 
using namespace std;

template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&); 
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.

    void reverseStack(stackType<Type> &otherStack);
      //Function to copy an existing stack into another 
      //existing stack in reverse order.
      //Postcondition: The second list that was receiving the 
      //        the reverse copy of the first list is outputted.

    void binary();

    stackType(int stackSize = 100); 
      //constructor
      //Create an array of the size stackSize to hold 
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base
      //               address of the array, stackTop = 0, and  
      //               maxStackSize = stackSize.

    stackType(const stackType<Type>& otherStack); 
      //copy constructor

    ~stackType(); 
      //destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack 
      //               elements is deleted.

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list;       //pointer to the array that holds the
                      //stack elements

    void copyStack(const stackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};


template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}//end isEmptyStack

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
} //end isFullStack

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the 
                                    //top of the stack
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);      //if stack is empty, 
                                //terminate the program
    return list[stackTop - 1];  //return the element of the
                                //stack indicated by 
                                //stackTop - 1
}//end top

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;      //decrement stackTop 
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to 
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new Type[maxStackSize];  //create the array to
                                    //hold the stack elements
}//end constructor

template <class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied 
                    //by the array
}//end destructor

template <class Type>
void stackType<Type>::copyStack
                (const stackType<Type>& otherStack)
{ 
    delete [] list;	
    maxStackSize = otherStack.maxStackSize;	
    stackTop = otherStack.stackTop;	
	  
    list = new Type[maxStackSize];

        //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
} //end copyStack


template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

template <class Type>
const stackType<Type>& stackType<Type>::operator=
                            (const stackType<Type>& otherStack)
{ 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
} //end operator=         


template <class Type>
void stackType<Type>::reverseStack(stackType<Type> &otherStack)
{
   delete [] otherStack.list;


   otherStack.list = new Type[maxStackSize];


   int counter = 0;



   //Copies a stack into otherStack. This allows for the counter
   //     to see how many items were put into the otherStack
   for (int j = 0; j < stackTop; j++)
   {
      otherStack.list[j] = list[j];
      counter++;
   }



   //Takes the top of the newly copied stack and sets its index 
   //     to the value of the counter. This will become the last index
   //     of the array. This way, the first index of the array 
   //     is the bottom value of the stack
   for (int i = counter; i > 0; i--)
   {
      otherStack.list[i] = otherStack.top();
      otherStack.pop(); 
   }


   //This outputs the array that holds the reverse of the stack being copied
   for (int i = 1; i < counter + 1; i++)
   {
      cout << otherStack.list[i] << " ";
   }    

    cout << endl;


} //end of reverseStack

template <class Type>
void stackType<Type>::binary()
{
/*   newList.list = new Type[maxStackSize];

   stackType<Type> newList

   int counter = 0;


   for (int j = 0; j < stackTop; j++)
   {
      counter++;
   }

   for (int i = counter; i > 0; i--)
   {
      newList[i] = newList.top();
      newList.pop();
   }

   for (int i = 1; i < counter + 1; i++)
   {
      cout << newList[i] << " ";
   }

   cout << endl;
*/

   stackType<Type> newStack;

   Type topItem;

   int counter = 0;

   while (this-> isEmptyStack() == false)
   {

      topItem = this-> top();
      counter++;
      this-> pop();
      newStack.push(topItem);

   }

   stackType<Type> newStackCopy;

   newStackCopy = newStack;

   double addOn;
   double sum = 0;

//   topItem = newStackCopy.top();

   for (int i = 0; i < counter; i++)
      {
//         topItem = newStackCopy.top();
  
         if (newStackCopy.top() == 0)
            addOn = 0;
         
         else if (newStackCopy.top() == 1)
            addOn = pow(2, i);

         cout << "addOn = " << addOn << endl;

         sum = sum + addOn;
         newStackCopy.pop();
      }
  
   cout << "Decmial number = " << sum << endl;

}



#endif
