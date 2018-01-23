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

	float tempDur = 0;

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
			cerr << "The new process arrival time is at time" << cur_time << " and is " << newProc->arrivalTime << endl;
			push(newProc);
			i+=1;
		}


		if (isEmpty()) {
			continue;
		}

		Process *topProc = top();
		if (tempDur == 0) {
			tempDur = topProc->runTime;
		}
		topProc->runTime-= (double) 0.1;
		
		if (topProc->runTime <= 0) {
			cout << "Process arrived at " << topProc->arrivalTime << " duration was " << tempDur << 	" and exited at " << cur_time << endl;
			tempDur = 0;
			pop();
		}
	}
}


#endif
