//CSCI2421 - HM5 Patient class
//Ryan Duncan
//4-20-23
#include <iostream>
using namespace std;
#include <string>
#include <vector>

#ifndef DUNCAN_RYAN_HW5_PATIENT_H
#define DUNCAN_RYAN_HW5_PATIENT_H


//Class Patient with patient number,id, condition, priority
class Patient {
public:
    //constructor
    Patient(string i = "", string cond = "", int pr = 0)
    {
        total++; //static variable to keep track of patients numbers as they
        //come in.
        number = total;
        id = i;
        condition = cond;
        priority = pr;
    }
//variables are made public for simplicity, but you can make them private.
    static int total; //static variable
    int number;
    string id;
    string condition;
    int priority;


};


int Patient::total = 0; //static variable initialization


//Overload < operator for priority_queue to be able to compare patients objects
//based on priority
bool operator<(const Patient& p1, const Patient& p2)
{
//fill the missing code to return true or false if p1 priority is less than p2.
return p1.priority < p2.priority;
}


//Overload > operator for priority_queue to be able to compare patients objects
//based on priority
bool operator>(const Patient& p1, const Patient& p2)
{
//fill the missing code to return true or false if p1 priority is larger than p2
return p1.priority > p2.priority;

}



#endif //DUNCAN_RYAN_HW5_PATIENT_H
