


#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include "../tools/tools.h"
#include "FCFSQueue.h"

using namespace std;


void printProcessList(vector<Process *> &processList) {

	cout << "\tP name\t|\tArrival\t|\tDur\t|\tPri" << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (int i = 0; i < processList.size(); i++) {

		Process *p = processList[i];
		cout << "\t" << p->identifier << "\t|\t" << p->arrivalTime << "\t|\t" << p->runTime << "\t|\t" << p->priority << endl;  
	}

	cout << "---------------------------------------------------------------" << endl;
	cout << "\n" << endl;
}

void startSimulation(FCFSQueue &model) {

	int i = 0;


	string timeGraph = "";


	float aggregateResponseTime = 0.0;
	float aggregateWaitingTime = 0.0;
	float aggregateTurnaroundTime = 0.0;
	float jobsFinished = 0.0;
	float jobsStarted = 0;


	for (int quanta = 0; quanta < 100; quanta++) {

		string timeGraph = "";
		for (float slice = 0.0; slice < 1.0; slice = slice+0.1) {
			Process *top = model.top();

			if (top->arrivalTime == true) {
				float waitingTime = ((float) quanta + slice) - top->arrivalTime;
			}

			if (model.isEmpty() || top == NULL || top->arrivalTime > ((float) quanta + slice)) {
				timeGraph+='-';
			}
			else {

				if (top->started == false) {
					top->started = true;

					// waiting time = amount of time ready to run but not running
					float waitingTime = ((float) quanta + slice) - top->arrivalTime;

					// responsse time = first response to command
					float responseTime = ((float) quanta + slice) - top->arrivalTime;

					aggregateWaitingTime+=waitingTime;
					aggregateResponseTime+=responseTime;


					jobsStarted+=1.0;
				}

				top->runTime -= 0.1;
				timeGraph+=top->identifier;

				if (top->runTime <= 0.1) {

					// turnaround time = time finished execution - arrival time
					float turnaroundTime = ((float) quanta + slice) - top->arrivalTime;

					aggregateTurnaroundTime=turnaroundTime;

					model.pop();
					jobsFinished+=1.0;
				}
			}
		}

		cout << "Quanta " << quanta << ":	" << timeGraph << endl;
	}


	cout << "Stats" << endl;
	cout << "----------------" << endl;
	cout << "Avg response time is " << aggregateResponseTime/jobsStarted << endl;
	cout << "Avg waiting time is " << aggregateResponseTime/jobsStarted << endl;
	cout << "Avg Turnaround time is " << aggregateTurnaroundTime / jobsFinished << endl;
	cout << "Throughoutput is " << jobsFinished / 100.0 << endl;

}


int main(int argc, char* argv[]) {

	for (int i = 0; i < 5; i++) {

		cout << "Simulation #" << i+1 << endl;
		vector<Process *> processList = generate::generateProcessList();
		printProcessList(processList);
		cout << "Starting First Come First Serve" << endl;

		FCFSQueue model(processList);
		startSimulation(model);
	}
	return 1;
}

