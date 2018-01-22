

#include "Process.h"

Process::Process() {
	startTime = 0;
	duration = 0;
	priority = 0;
}


Process::Process(float start, float dur, int prio) {
	startTime = start;
	duration = dur;
	priority = prio;
}
