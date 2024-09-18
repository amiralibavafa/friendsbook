/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application.
 *
 * In this version, we use our MyADT class.
 *
 * Author: Software developer A
 * Modified on: Jan. 2024
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;

/* NOTE:
Using "getline(cin >> ws, theUserName);"
removes all leading whitespace -> ws     
*/

void join(MyADT & theMembers) {
    string theUserName = "";
    string theName = "";
    string theEmail = "";
    string theBirthday = "";

    // Create a new member profile
    cout << "Please, enter a userName (first character must be a lower case letter) : ";  
    getline(cin >> ws, theUserName);
    Profile testMember(theUserName);

    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( testMember.getUserName() == Profile::getDefaultStrValue( ) )
        cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
    else {
        Profile * target = theMembers.search(testMember);
        if ( target == nullptr ) {
            cout << "Please, enter your name : ";
            getline(cin >> ws, theName);
            cout << "Please, enter your email : ";  
            getline(cin >> ws, theEmail);
            cout << "Please, enter your birthday : "; 
            getline(cin >> ws, theBirthday);      
            Profile theMember(theUserName, theName, theEmail, theBirthday);
            // Add new member profile to list
            if ( theMembers.insert(theMember) )
                // Report to user
                cout << "Member: " << "'" << theMember.getUserName() << "'" << " has successfully joined FriendsBook." << endl;
            else
                cout << "Member: " << "'" << theMember.getUserName() << "'" << " was unable to joined FriendsBook (she/he may already be a member?)" << endl;
        }
        else
            cout << "Member: " << "'" << testMember.getUserName() << "'" << " was unable to joined FriendsBook (she/he may already be a member?)" << endl;
    }

    return;
}


void leave(MyADT & theMembers) {
    string theUserName = "";

    cout << "Please, enter the username of the member that is leaving: ";
    getline(cin >> ws, theUserName);
    Profile toBeRemoved(theUserName);

    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( toBeRemoved.getUserName() == Profile::getDefaultStrValue( ) )
        cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
    else {
        // Remove friend from FriendsBook
        if ( theMembers.remove(toBeRemoved) )
            cout << "Friend : " << "'" << toBeRemoved.getUserName() << "'" << " has now left this social network." << endl;
        else
            cout << "Friend : " << "'" << toBeRemoved.getUserName() << "'" << " is not a member of this social network!" << endl;
    }
    return;
}

 
void search(MyADT & theMembers) {
    string theUserName = "";
    
    // Create a new member profile
    cout << "Please, enter the username of the member you are looking for: ";   
    getline(cin >> ws, theUserName);
    Profile theMember(theUserName);

    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( theMember.getUserName() == Profile::getDefaultStrValue( ) )
         cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
   else {
        // Search
        Profile * target = theMembers.search(theMember);

        if ( target != nullptr )
            // Report to user
            cout << "Member: " << "'" << target->getUserName() << "'" << " has been successfully found in FriendsBook." << endl;
        else
            cout << "'" << theUserName << "'" << " is not a member of FriendsBook." << endl;
    }

    return;
} 


void modify(MyADT & theMembers) {    
    string newString = "";
    string theUserName = "";
 
    cout << "Please, enter the username of the profile to be modified: ";  
    cin >> theUserName;
    cin.ignore(256, '\n');
    Profile theMember(theUserName);
    
    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( theMember.getUserName() == Profile::getDefaultStrValue( ) )
        cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
    else {
        // Search
        Profile * target = theMembers.search(theMember);
        if ( target != nullptr ) {
            // Modify
            cout << "Modifying member's name " << "'" << target->getName() << "'" << endl;
            cout << "Please enter new name for this profile (press ENTER to skip): ";
            getline(cin, newString);
            if ( !newString.empty() ) target->setName(newString);
    
            cout << "Modifying member's email " << "'" << target->getEmail() << "'" << endl;
            cout << "Please, enter the new email of this member (press ENTER to skip): ";   
            getline(cin, newString);
            if ( !newString.empty() ) target->setEmail(newString);
            
            cout << "Modifying member's birthday " << "'" << target->getBirthday() << "'" << endl;
            cout << "Please, enter the new birthday of this member(press ENTER to skip): ";  
            getline(cin, newString);
            if ( !newString.empty() ) target->setBirthday(newString);        
        
        } else
            cout << "Member : " << "'" << theMember.getUserName() << "'" << " is not a member of FriendsBook." << endl;
    }
  
    return;
}

void print(MyADT & theMembers) {
    
    cout << "Printing FriendsBook" << endl;
    cout << "\nThere are now " << theMembers.getElementCount() << " friends in FriendsBook." << endl;
    theMembers.print();
    
    return;
}

int main() {

    // Variables declaration
    MyADT members = MyADT(); 
    bool done = false;
    char input = 0;
        
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }

    }

    return 0;
}