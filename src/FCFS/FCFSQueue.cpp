#ifndef FCFSQUEUE_CPP
#define FCFSQUEUE_CPP

#include <iostream>
#include <stdio.h>

#include <queue>

using namespace std;

void FCFSQueue::push(Process *newProcess) {
	
	container.push(newProcess);

}

Process *FCFSQueue::pop() {
	
	Process *top = container.front();
	container.pop();
	return top;

}

bool FCFSQueue::isEmpty() {
	return container.isEmpty();
}

void processQueue(int time) {

	for (float t = time-1; t < time; i+=0.1) {

		if (isEmpty()) {
			return;
		}

		Process *top = top();

		if (top.startTime == -1) {
			top.startTime = t;
		}

		top.duration-=0.1;
		if (top.duration == 0) {
			// process the process for the end

			pop();

		}
	}

}

void startSimulation(vector<Process *> processList) {

	int i = 0;

	for (float cur_time = 0.0; cur_time < 100; cur_time+=0.1) {

		if (i >= processList.size()) {
			break;
		}

		Process *newProc = processList[i];
		while (i < processList.size() && newProc.arrivalTime == cur_time) {
			push(newProc);
			newProc = processList[i];
		}

		if 

		Process *topProc = top();
		topProc.duration-=0.1;
		
		if (topProc.duration == 0) {
			pop();
		}

	}



}


#endif
