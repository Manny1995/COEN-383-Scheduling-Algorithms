


#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include "../tools/tools.h"
#include "FCFSQueue.h"

using namespace std;

int main(int argc, char* argv[]) {

	FCFSQueue model;
	model.startSimulation(generate::generateProcessList());

	return 1;
}

