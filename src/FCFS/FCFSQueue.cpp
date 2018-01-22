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


