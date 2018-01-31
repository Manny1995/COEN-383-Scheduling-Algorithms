// Immanuel Amirtharaj


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


// Import all the classes and stuff
#include "tools/tools.h"
#include "tools/process.h"
#include "FCFS/fcfsDriver.h"
#include "SJF/sjfDriver.h"
#include "STR/strDriver.h"
#include "RR/rrDriver.h"
#include "HPFS/HPFS_NP_driver.h"
#include "HPFS/HPFS_P_driver.h"

using namespace std;


void help() {
		cout << "all 	- run all 6 algorithms" << endl;
		cout << "fcfs 	- first come first serve" << endl;
		cout << "sjf 	- shortest job first" << endl;
		cout << "str 	- shortest time remaining" << endl;
		cout << "rr 	- round robin" << endl;
		cout << "hpf1	- highest priority first non-preemptive" << endl;
		cout << "hpf2	- highest priority first preemptive" << endl;
}

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Please enter an argument:" << endl;
		help();
		return -1;
	}

	vector< vector<Process *> > data = generate::generateSimulationData();

	string choice = string(argv[1]);

	if (choice == "all") {

		// Some of the models directly modify the simulated data in their implementation.
		// To avoid these changes propogating to the next simulation, generate::getCopiedData
		// creates a **deep copy** of the generated data.
		fcfsDriver(generate::getCopiedData(data));
		sjfDriver(generate::getCopiedData(data));
		strDriver(generate::getCopiedData(data));
		rrDriver(generate::getCopiedData(data));
		hpfsNpDriver(generate::getCopiedData(data));

	}
	else if (choice == "fcfs") {
		fcfsDriver(data);
	}
	else if (choice == "sjf") {
		sjfDriver(data);
	}
	else if (choice == "str") {
		strDriver(data);
	}
	else if (choice == "rr") {
		rrDriver(data);
	}
	else if (choice == "hpf1") {
		hpfsNpDriver(generate::getCopiedData(data));

	}
	else if (choice == "hpf2") {
		hpfsPDriver(generate::getCopiedData(data));

	}
	else {
		cout << "Invalid argument, please try again!" << endl;
		help();
	}

	return 1;

}