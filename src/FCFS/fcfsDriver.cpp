

#ifndef FCFSDRIVER_CPP
#define FCFSDRIVER_CPP

#include "FCFSQueue.h"


#include <iostream>
#include <stdio.h>

#include <vector>
#include "fcfsDriver.h"
#include "../tools/process.h"

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

	bool finished = false;
	int quanta = 0;
	float rem = 0.0;

	while (!finished) {

		string timeGraph = "";

		float tempTurnaroundTime = 0.0;
		for (float slice = 0.0; slice < 1.0; slice = slice+0.1) {
			Process *top = model.top();

			if (quanta > 100 && top->started == false) {
				// timeGraph+="-";
				finished = true;
				rem = slice;
				break;
			}

			if (model.isEmpty() || top == NULL || top->arrivalTime > ((float) quanta + slice)) {
				timeGraph+='-';
			}
			else {

				// start the process because it is in beginning of queue at arrival time
				if (top->started == false) {
					top->started = true;


					// response time = start time - arrival time
					float responseTime = ((float) quanta + slice) - top->arrivalTime;

					aggregateResponseTime+=responseTime;


					// increment the jobs started
					jobsStarted+=1.0;
				}

				// decrement runtime
				top->runTime -= 0.1;
				tempTurnaroundTime+=0.1;

				// add process to the time graph
				timeGraph+=top->identifier;

				// when runtime hits this, then the process is done
				if (top->runTime <= 0.1) {

					// waiting time = time finished execution - arrival time
					float waitingTime = ((float) quanta + slice) - top->arrivalTime;

					// because nonpreemptive guarantees staying in the CPU, we can just use the duration of the process as the turnaround time
					float turnaroundTime = top->timeLeft;

					aggregateTurnaroundTime+=turnaroundTime;
					aggregateWaitingTime+=waitingTime;

					model.pop();

					// increments the jobs finished
					jobsFinished+=1.0;
				}
			}

		}

		cout << "Quanta " << quanta << ":	" << timeGraph << endl;
		quanta++;

	}


	cout << "Stats" << endl;
	cout << "----------------" << endl;
	cout << "Avg response time is " << aggregateResponseTime/jobsFinished << endl;
	cout << "Avg waiting time is " << aggregateWaitingTime/jobsFinished << endl;
	cout << "Avg Turnaround time is " << aggregateTurnaroundTime / jobsFinished << endl;
	cout << "Throughoutput is " << jobsFinished / ((float) quanta + rem) << endl;

}


void fcfsDriver(vector<vector<Process *> > batch) {
	for (int i = 0; i < batch.size(); i++) {

		cout << "Simulation #" << i+1 << endl;
		vector<Process *> processList = batch[i];
		printProcessList(processList);
		cout << "Starting First Come First Serve" << endl;
		FCFSQueue model(processList);
		startSimulation(model);
	}
}

#endif