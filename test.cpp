#include <iostream>
#include "Profile.cpp"
#include "MyADT.cpp"
using namespace std;

int main(){
    MyADT members = MyADT();
    Profile newMember = Profile("amirali");

    members.insert(newMember);

    members.print();

}