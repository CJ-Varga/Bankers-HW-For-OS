# Bankers-HW-For-OS
Bankers algorithm simple program for operating systems class

input.txt stores resources allocated and available, as well as the max amounts possible to be held by each process. Ifstream is used to get these values in the 3 get functions in banker.cpp. Main operates on these values and uses the banker's algorithm to determine if the values stated in the input file lead to a safe state. If the available resources are equal to or greater a process's max resources intake, the process is treated and the resources allocated to that process are freed to be allocated elsewhere. example.txt is an example output of the program. "Current" is the current available resources of types A B and C. P# Max is the max number of the respective resources for a given process.
