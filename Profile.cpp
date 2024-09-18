/*
 * Profile.cpp
 * 
 * Class Description: Models the profile of a user of the social network FriendsBook.
 *                    This profile contains the following characteristics:
 *                    userName, name (first and last name), email address and birthday.
 *       
 * Class Invariant: The userName must be a non-empty string, with a minimum length of 1 character.
 *                  It must start with a lower case letter (a to z), the rest can be any ASCII characters.              
 *
 * Author: AL
 * Last modified: Jan. 2024
 */

#include <iostream>
#include <string>
#include <locale> 
#include <cctype>
#include "Profile.h"

using std::cout;
using std::endl;
using std::locale;
using std::ostream;


/* This file contains the implementation of the Profile class. You cannot change the content of this file. */

// Default Constructor
// Description: Creates a Profile object. 
// Postcondition: userName, name, email and birthday set to defaultStrValue.        
Profile::Profile() : userName(defaultStrValue), name(defaultStrValue), email(defaultStrValue), birthday(defaultStrValue) {

   //cout << "Profile::default constructor" << endl;   // For testing purposes ... and curiosity
               
}

// Parameterized Constructor
// Description: Creates a Profile object with the given userName.
// Postcondition: If aUserName is not valid, then the member attribute userName it set to defaultStrValue.
//                All other member attributes are set to defaultStrValue.           
Profile::Profile(string aUserName) : name(defaultStrValue), email(defaultStrValue), birthday(defaultStrValue) {

    this->setUserName(aUserName); 
               
}

// Parameterized Constructor
// Description: Creates a Profile object with the given userName, name, email and birthday.
// Postcondition: If aUserName is not valid, then the member attribute userName is set to defaultStrValue.
//                All other member attributes are set to the given parameters, respectively.
Profile::Profile(string aUserName, string aName, string anEmail, string aBirthday) : 
                 name(aName), email(anEmail), birthday(aBirthday) {
    this->setUserName(aUserName);                 
}    
    

// Getters and setters

// Description: Returns Profile object's userName.
string Profile::getUserName() const {
    return userName;
}
    
// Description: Returns Profile object's name.
string Profile::getName() const {
    return name;
}

// Description: Returns Profile object's email.
string Profile::getEmail() const {
    return email;
}

// Description: Returns Profile object's birthday.
string Profile::getBirthday() const {
    return birthday;
}

// Description: Returns defaultStrValue.
string Profile::getDefaultStrValue() {
    return defaultStrValue;
}

// Description: Sets the Profile object's userName - Private method
// Postcondition: userName is set to aUserName if aUserName 
//                is valid (i.e., it does not break the class invariant),
//                otherwise it is set to defaultStrValue.
// Reflection (for you to think about on your own - you do not need to provide an answer 
//  as part of this Assignment 1): Why is this method not part of the public interface?
void Profile::setUserName(const string aUserName) {
    locale loc;

    if ( !aUserName.empty() && (isalpha(aUserName[0], loc) ) && (islower(aUserName[0]) ) )
        userName.assign(aUserName);
    else
        userName.assign(defaultStrValue);                   
}

// Description: Sets the Profile object's name.
// Postcondition: name is set to aName. No need to validate aName.
void Profile::setName(const string aName) {
    name.assign(aName);
}

// Description: Sets the Profile object's email.
// Postcondition: email is set to anEmail. No need to validate anEmail.
void Profile::setEmail(const string anEmail) {
    email.assign(anEmail);
}

// Description: Sets the Profile object's birthday.
// Postcondition: birthday is set to aBirthday. No need to validate aBirthday.
void Profile::setBirthday(const string aBirthday) {
    birthday.assign(aBirthday);
}


// Overloaded Operators
// Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if both Profile objects have the same userName.
bool Profile::operator==(const Profile & rhs) {
    
    // Compare both Profile objects
    return ( this->userName == rhs.getUserName() ); 

} 


// Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
//              Profile object, i.e., the userName of "this" Profile object goes after 
//              the userName of "rhs" Profile object when ordered in ascending alpha order.
bool Profile::operator > (const Profile & rhs) {

   return ( this->userName > rhs.getUserName() ); 
} 

// Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
//              Profile object, i.e., the userName of "this" Profile object goes before 
//              the userName of "rhs" Profile object when ordered in ascending alpha order.
bool Profile::operator < (const Profile & rhs) {
    
   return ( this->userName < rhs.getUserName() ); 
} 


// Utility methods
// Description: Returns the first character (a lower case letter) of userName.
char Profile::getSearchKey( ) const {

    return this->getUserName()[0];
    
} 

// Description: Prints the content of "this" Profile object as follows:
//              <userName>, <name>, <email>, born on <birthday>
ostream & operator<<(ostream & os, const Profile & p) {

    os << p.userName << ", " << p.name << ", " << p.email << ", born on " << p.birthday << endl;    
    return os;
    
} 

// end of Profile.cpp