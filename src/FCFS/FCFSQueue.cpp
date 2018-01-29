#ifndef FCFSQUEUE_CPP
#define FCFSQUEUE_CPP

#include "FCFSQueue.h"

#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include <queue>

using namespace std;

FCFSQueue::FCFSQueue() {


}


void FCFSQueue::push(Process *newProcess) {
	
	container.push(newProcess);

}

void FCFSQueue::pop() {

	if (isEmpty()) {
		return;
	}
	
	container.pop();

}

Process *FCFSQueue::top() {

	if (container.empty()) {
		return NULL;
	}

	return container.front();
}

bool FCFSQueue::isEmpty() {
	return container.empty();
}

void FCFSQueue::startSimulation(vector<Process *> processList) {

	int i = 0;


	int jobsStarted = 0;
	double totalResponseTime = 0;
	double totalTurnaroundTime = 0;
	int jobsFinished = 0;

	double tempDur = 0;

	string timeGraph = "";

	for (Process *c : processList) {
	//	cerr << "This is " << c->arrivalTime << endl;
	}

	for (double cur_time = 0.0; cur_time < 100; cur_time+=0.1) {

		if (i >= processList.size()) {
			break;
		}

		Process *newProc = processList[i];
		// add new processes to queue
		while (i < processList.size() && (float) newProc->arrivalTime == (float) cur_time) {
			newProc = processList[i];
			cerr << "The new process started at " << cur_time << ", arrival time is " << newProc->arrivalTime << " and run time is " << newProc->runTime << " and priority is " << newProc->priority << endl;
			push(newProc);
			i+=1;
		}


		if (isEmpty()) {
			continue;
		}

		Process *topProc = top();
		timeGraph+=topProc->identifier;



		if (topProc->hasStarted() == false) {
			jobsStarted+=1;
			totalResponseTime+=topProc->startExecution(cur_time);
		}

		topProc->runTime-= (double) 0.1;
		
		if (topProc->runTime <= 0) {

			totalTurnaroundTime+=topProc->finishExecution(cur_time);
			jobsFinished+=1;
			cout << "Process " << topProc->identifier << " finished at " << cur_time << endl;
			pop();
		}
	}

	cout << "Stats" << endl;
	cout << "----------------" << endl;
	cout << "Avg response time is " << totalResponseTime/jobsStarted << endl;
	cout << "Avg waiting time is 0 (because first come first serve)" << endl;
	cout << "Avg Turnaround time is " << totalTurnaroundTime / jobsFinished << endl;
	cout << "Throughoutput is " << jobsFinished / 100.0 << endl;
	cout << "Time graph is " << timeGraph << endl;
}


#endif
