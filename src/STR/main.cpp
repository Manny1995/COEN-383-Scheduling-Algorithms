//Main for Shortest Time Remaining 
//Tasmine Hackson
//Santa Clara University 
//COEN 383 Project 2
#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include "../tools/tools.h"
#include "STR.h"

using namespace std;

int main(int argc, char* argv[]) {

	STR model;
	model.startSimulation(generate::generateProcessList());

	return 1;
}