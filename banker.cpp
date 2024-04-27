// CJ Varga
// 4/26/2024
// Bankers algorithm homework assignment
// Reads from input.txt and calculates
// If the resource chart in it is a safe state


#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// all get functions return -1 if resource
// is not found

// get A B or C of resource allocated to a Process
int getAlloc(int process, char type){
    int spaces;
    // identify how many numbers traversed
    // to get to right resource
    if (type == 'A') spaces = 0;
    if (type == 'B') spaces = 1;
    if (type == 'C') spaces = 2;

    // return error if process unknown
    if (process <= -1) return -1;
    if (process >= 5) return -1;
    // added number of spaces per line
    // to get to correct process/row
    if (process >= 1){
        spaces += 9;
        spaces += (6*(process-1));
    }

    ifstream input("input.txt");
    string grabber;
    int counter = 0;

    // traverse numbers until resource reached
    while (input>>grabber){
        if (counter == spaces){
            input.close();
            return (int)grabber[0] - int('0');
        }
        ++counter;

        //prevent infinite loop
        if (counter >= 200){
            input.close();
            return -1;
        }
    }
    input.close();
    return -1;
}

// get max A B or C of Process
int getMax(int process, char type){
    int spaces;
    // identify how many numbers traversed
    // to get to right resource
    if (type == 'A') spaces = 3;
    if (type == 'B') spaces = 4;
    if (type == 'C') spaces = 5;

    // return error if process unknown
    if (process <= -1) return -1;
    if (process >= 5) return -1;
    // added number of spaces per line
    // to get to correct process/row
    if (process >= 1){
        spaces += 9;
        spaces += (6*(process-1));
    }

    ifstream input("input.txt");
    string grabber;
    int counter = 0;

    // traverse numbers until resource reached
    while (input>>grabber){
        if (counter == spaces){
            input.close();
            return (int)grabber[0] - int('0');
        }
        ++counter;

        //prevent infinite loop
        if (counter >= 200){
            input.close();
            return -1;
        }
    }
    input.close();
    return -1;
}

// get available resources from txt
// only accurate at start of algorithm
int getAvail(char type){
    int spaces;
    // identify how many numbers traversed
    // to get to right resource
    if (type == 'A') spaces = 6;
    if (type == 'B') spaces = 7;
    if (type == 'C') spaces = 8;

    ifstream input("input.txt");
    string grabber;
    int counter = 0;

    // traverse numbers until resource reached
    while (input>>grabber){
        if (counter == spaces){
            input.close();
            return (int)grabber[0] - int('0');
        }
        ++counter;

        //prevent infinite loop
        if (counter >= 10){
            input.close();
            return -1;
        }
    }
    input.close();
    return -1;
}


int main(){
    int A = getAvail('A');
    int B = getAvail('B');
    int C = getAvail('C');
    // bitmap of processes. If 0, the
    // associated process is skipped when
    // checking for process to complete next
    bool pFlags[] = {1,1,1,1,1};
    // flag to loop only if a process was
    // able to be trated safely, 0 if unsafe
    bool safetyFlag = 0;

    do{
        for (int currentP = 0; currentP<5; ++currentP){
        if (pFlags[currentP] == 1){
            // if all resources more than
            // max resources of process
            if (A >= getMax(currentP,A) &&
            B >= getMax(currentP,B) &&
            C >= getMax(currentP,C)){
                // add process's resources
                // to usable ones
                A += getAlloc(currentP,A);
                B += getAlloc(currentP,B);
                C += getAlloc(currentP,C);
                // change bitmap to prevent
                // unneeded repeats
                pFlags[currentP] = 0;
                // currently safe state
                // allow another loop
                safetyFlag = 1;

                cout << "Treated process";
                cout << currentP << "\n\n";
            }
            }
        }


        if (safetyFlag == 0){
            cout << "No other process can be ";
            cout << "treated. The state is unsafe\n";
            return 0;
        }
        safetyFlag = 0;
        // if any process have not had
        // resources allocated to them,
        // keep looping
    } while (pFlags[0] == 1 ||
    pFlags[1] == 1 ||
    pFlags[2] == 1 ||
    pFlags[3] == 1 ||
    pFlags[4] == 1);

    // all processes dealt with
    cout << "\nThe system is in a safe state\n";
    return 0;
}

