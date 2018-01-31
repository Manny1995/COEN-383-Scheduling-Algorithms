#include <iostream>
#include <stdio.h>
#include "../tools/tools.h"
#include "HPFS_NP_driver.h"
#define NUM_QUANTA 100

using namespace std;

int main(int argc, char* argv[]) {
    vector<Process *> processList = generate::generateProcessList();
    simulate_hpfs_non_preemptive(processList);
	return 1;
}

