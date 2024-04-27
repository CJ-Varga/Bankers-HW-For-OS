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
    return 0;
}

// get max A B or C of Process
int getMax(int process, char type){
    return 0;
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
            return (int)grabber[0];
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

}

