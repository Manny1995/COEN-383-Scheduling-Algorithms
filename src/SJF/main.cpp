#include <iostream>
// #include <vector>

#include "SJF.h"
#include "../tools/process.h"
#include "../tools/tools.h"

int main() {

    SJF sjf;
    sjf.simulate(generate::generateProcessList());

}
