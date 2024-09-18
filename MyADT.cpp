/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: AL and Amirali Bavafa ID:301546506
 * Last modified on: Jan. 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() {
   //cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   //initialize the element array to hold pointer to each letter
   for (int i = 0 ; i < MAX_ALPHA ; i++){
      //Set the first index as nulptr so it wont allocate unnecessary 
      elements[i] = nullptr;
      //elements[i][0] = Profile();
      elementCount[i] = 0;
   }
   
   
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   //cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   // Copy each element from rhs to the current object
   for (unsigned int i = 0; i < MAX_ALPHA; ++i) {
        elementCount[i] = rhs.elementCount[i];
        elements[i] = new Profile[MAX_ELEMENTS];

        for (unsigned int j = 0; j < elementCount[i]; j++) {
            elements[i][j] = rhs.elements[i][j];
        }
    }
   
}  

// Overloaded assignment operator - Covered in Lab 4
MyADT & MyADT::operator=(const MyADT& rhs) {
   // cout << "MyADT::operator= executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this overloaded assignment = operator is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
   // Check for self-assignment
   if (this != &rhs) {
      // Deallocate any resources owned by the left-hand side
      removeAll();

      // Perform deep copy of the elements from rhs to *this
      for (int i = 0; i < MAX_ALPHA; i++) {
         elementCount[i] = rhs.elementCount[i];

         // Allocate memory for elements[i] and copy the elements
         elements[i] = new Profile[MAX_ELEMENTS];
         for (int j = 0; j < MAX_ELEMENTS; j++) {
            elements[i][j] = rhs.elements[i][j];
         }
      }
   }

   // Return *this to support chaining of assignments
   return *this;

}
    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
  
   for (int i = 0 ; i < MAX_ALPHA ; i++){
      delete elements[i];
   }
   
}  


// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {
   int totalCount = 0;
   for (int i = 0; i < MAX_ALPHA; i++){
      totalCount += elementCount[i];
   }
   return totalCount;
}


// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {
    // Find the appropriate index 'i' based on the first letter of the userName
    int i = newElement.getSearchKey() - 'a';

    if (elements[i] == nullptr){
      elements[i] = new Profile[MAX_ELEMENTS];
    }

    // Find an empty slot for the new element
    int j = 0;
    while (j < MAX_ELEMENTS && elements[i][j] == Profile::getDefaultStrValue()) {
        j++;
    }

    // Check if there is space in the array for the new element
    if (j < MAX_ELEMENTS) {
        elements[i][j] = newElement;
        elementCount[i]++;  // Increment the element count for this group

        //setting the next available element as DefaultSTR for future inserts
        if (j++ < MAX_ELEMENTS){
            elements[i][j++] = Profile();
        }
        return true;        // Insertion successful
    } else {
        return false;       // Unable to insert due to maximum capacity reached
    }
}  

// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  
bool MyADT::remove(const Profile& toBeRemoved) {

   //finding the target profile's first letter index
   int i = toBeRemoved.getSearchKey() - 'a';

   //keep going in the elements array untill we find the target user name
   int j = 0;
   while (j < MAX_ELEMENTS && elements[i][j].getUserName() != toBeRemoved.getUserName()){
      j++;
   }

   //check that we found the element and have overceeded the MAXELEMENTS 
   if (j < MAX_ELEMENTS){
      elements[i][j] = Profile::getDefaultStrValue();
      elementCount[i]--;
      return true;
   }

   //profile hasnt been found or there was perhaps an error removal unsuccessful
   else{
      return false;
   }

   
}  


// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
    
    for (int i = 0; i < MAX_ALPHA; i++){
         for (int j = 0; j < MAX_ALPHA; j++){
            elements[i][j] = Profile::getDefaultStrValue();
            elementCount[i]--;
         }
    }

}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    Profile * found = nullptr;

    //finding the first letter index
    int i = target.getSearchKey() - 'a';

    //search that section in order to find the profile
    for (int j = 0; j < MAX_ELEMENTS; j++){
         if (elements[i][j] == target){
            found = &elements[i][j];
            break;
         }
    }
    return found;
}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {
  
   for (int i = 0 ; i < MAX_ALPHA ; i++){
      for (int j = 0 ; j < MAX_ELEMENTS; j++){
         if (elements[i][j].getUserName() != Profile::getDefaultStrValue()){
            cout<< elements[i][j] << endl;
         }
      }
   }
} 

//  End of implementation file
