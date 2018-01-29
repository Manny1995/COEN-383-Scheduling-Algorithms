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

FCFSQueue::FCFSQueue(vector<Process *>processList) {
	for (int i = 0; i < processList.size(); i++) {
		push(processList[i]);
	}
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


#endif
