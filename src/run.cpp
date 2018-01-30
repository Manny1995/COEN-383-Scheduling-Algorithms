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

using namespace std;



int main(int argc, char* argv[]) {

	vector< vector<Process *> > data = generate::generateSimulationData();


	// Some of the models directly modify the simulated data in their implementation.
	// To avoid these changes propogating to the next simulation, generate::getCopiedData
	// creates a **deep copy** of the generated data.
	fcfsDriver(generate::getCopiedData(data));
	sjfDriver(generate::getCopiedData(data));
	strDriver(generate::getCopiedData(data));

	return 1;
}