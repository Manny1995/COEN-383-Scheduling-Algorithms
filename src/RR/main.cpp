#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include "../tools/tools.h"
#include "rrDriver.h"

using namespace std;

int main(int argc, char* argv[]) {

    rrDriver(generate::generateSimulationData());

	return 1;
}