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

//	fcfsDriver(data);
//	sjfDriver(data);
	strDriver(data);

	return 1;
}