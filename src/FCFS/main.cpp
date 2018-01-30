// Immanuel Amirtharaj
// main.cpp

#include "../tools/tools.h"
#include "fcfsDriver.h"

using namespace std;

int main(int argc, char* argv[]) {

	fcfsDriver(generate::generateSimulationData());

	return 1;
}

