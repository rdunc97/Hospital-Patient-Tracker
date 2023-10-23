//CSCI2421 - HM5 Main file
//Ryan Duncan
//4-20-23

#include <iostream>
#include <vector>
#include "Patient.h"
#include <queue>
#include <string>

int main() {
    //create the vector, 'array', of type Patients
    vector<Patient> array;
    bool keepAdding = true;
    //add initial objects to vector
    while (keepAdding) {

        string id;
        string condition;
        int pri;

        //user input
        cout << "enter patient id: " << endl;
        getline(cin, id);


        cout << "enter patient condition: " << endl;
        getline(cin,condition);


        cout << "enter patient priority: " << endl;
        cin >> pri;

        //create objects with id, condition, and priority
        Patient newPatient(id, condition, pri);
        //push back objects into vector
        array.push_back(newPatient);

        //give user choice to keep adding objects or not
        char choice;
        cout << "Keep adding patients? 'y' or 'n': " << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 'n') {
            keepAdding = false;
        }
    }

    //create priority queue with type Patient, vector of patient objects, using a comparator
    priority_queue<Patient, vector<Patient>, greater<>> minHeap(array.begin(), array.end());



    //some variable initialization for switch
    int menu, newPri;
    string newId, newCondition;
    Patient newPatient;
    //initialize copy of priority queue so we can pop when printing but maintain structure
    priority_queue<Patient, vector<Patient>, greater<>> copy(array.begin(), array.end());

    while (true) {
        //menu options
        cout << "Please enter a choice 1 - 4..." << endl;
        cout << "1:Add new patient to priority queue" << endl;
        cout << "2:Dispatch a patient with highest priority to be seen. Display patient information..." << endl;
        cout << "3:Print the heap contents..." << endl;
        cout << "4:EXIT" << endl;
        cin >> menu;
        if (menu == 4)
            break;
        switch (menu) {
            case 1:
                //add new patient to priority queue

                //user input for new patient
                cout << "enter patient id: " << endl;
                cin.ignore();
                getline(cin,newId);

                cout << "enter patient condition: " << endl;
                getline(cin, newCondition);

                cout << "enter patient priority: " << endl;
                cin>>newPri;

                //define the object w new information
                newPatient = Patient(newId,newCondition,newPri);
                //push the new object into the min heap
                minHeap.push(newPatient);


                break;

            case 2:
                //Dispatch patient with the highest priority
                cout << "Now serving patient: " << minHeap.top().id << ", " << "Condition: " << minHeap.top().condition << ", " << "Priority: " << minHeap.top().priority << endl;

                //pop each one dispatched so the next in line can be served
                minHeap.pop();
                break;

            case 3:
                //print heap contents

                //set copy of heap made equal to minHeap
                copy = minHeap;
                while (!copy.empty()) {
                    //until queue is empty print out the patient queue information
                    cout << "Patient ID = " << copy.top().id << " , " << "Condition = " << copy.top().condition
                         << " , " << "Priority = " << copy.top().priority << endl;
                    copy.pop();
                }

                break;


                default:
                        cout << "enter a valid choice" << endl;

        }
        }
return 0;
    }

