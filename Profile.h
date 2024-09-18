/*
 * Profile.h
 * 
 * Class Description: Models the profile of a user of the social network FriendsBook.
 *                    This profile contains the following characteristics:
 *                    aba234, Amirali Bavafa, aba234@sfu.ca 27-Apr-2003.
 *       
 * Class Invariant: The userName must be a non-empty string, with a minimum length of 1 character.
 *                  It must start with a lower case letter (a to z), the rest can be any ASCII characters.              
 *
 * Author: AB
 * Last modified: Jan. 2024
 */

#ifndef PROFILE_H
#define PROFILE_H

#include <string>

using std::string;
using std::ostream;


/* This file contains the definition of the Profile class. You cannot change the content of this file. */

class Profile {
     
private:

    inline static const string defaultStrValue = "tbd";

    string userName;
    string name; 
    string email;
    string birthday;

    // Description: Sets the Profile object's userName - Private method
    // Postcondition: userName is set to aUserName if aUserName 
    //                is valid (i.e., it does not break the class invariant),
    //                otherwise it is set to defaultStrValue.
    // Reflection (for you to think about on your own - you do not need to provide an answer 
    //  as part of this Assignment 1): Why is this method not part of the public interface?
    void setUserName(const string aUserName);
    
    
public:

    // Default Constructor
    // Description: Creates a Profile object. 
    // Postcondition: userName, name, email and birthday set to defaultStrValue.
    Profile();

    // Parameterized Constructor
    // Description: Creates a Profile object with the given userName.
    // Postcondition: If aUserName is not valid, then the member attribute userName it set to defaultStrValue.
    //                All other member attributes are set to defaultStrValue. 
    Profile(string aUserName);
    
    // Parameterized Constructor
    // Description: Creates a Profile object with the given userName, name, email and birthday.
    // Postcondition: If aUserName is not valid, then the member attribute userName is set to defaultStrValue.
    //                All other member attributes are set to the given parameters, respectively.
    Profile(string aUserName, string aName, string anEmail, string aBirthday);


    // Getters and setters
    
    // Description: Returns Profile object's userName.
    string getUserName() const;
    
    // Description: Returns Profile object's name.
    string getName() const;

    // Description: Returns Profile object's email.
    string getEmail() const;

    // Description: Returns Profile object's birthday.
    string getBirthday() const;

    // Description: Returns defaultStrValue.
    static string getDefaultStrValue();
    
    // Description: Sets the Profile object's name.
    // Postcondition: name is set to aName. No need to validate aName.
    void setName(const string aName);

    // Description: Sets the Profile object's email.
    // Postcondition: email is set to anEmail. No need to validate anEmail.
    void setEmail(const string anEmail);

    // Description: Sets the Profile object's birthday.
    // Postcondition: birthday is set to aBirthday. No need to validate aBirthday.
    void setBirthday(const string aBirthday);


    // Overloaded Operators
    // Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if both Profile objects have the same userName.
    bool operator==(const Profile & rhs);

    // Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes after 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator > (const Profile & rhs);

    // Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes before 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator < (const Profile & rhs);


    // Utility methods
    // Description: Returns the first character (a lower case letter) of userName.
    char getSearchKey() const;

    // Description: Prints the content of "this" Profile object as follows:
    //              <userName>, <name>, <email>, born on <birthday>
    friend ostream & operator<<(ostream & os, const Profile & p);

};
// end of Profile.h
#endif