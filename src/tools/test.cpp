#include "process.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    vector<Process*> plist = generateProcessVector(100);

    /*
    for (int i = 0 ; i < 100 ; ++i) {
        plist.push_back(new Process());
    }
    */

    for (int i = 0 ; i < plist.size() ; ++i) {
        cout << plist[i]->arrivalTime << endl;
    }
    
    sort(plist.begin(), plist.end(), processPtrCompare);
    cout << endl;
    
    for (int i = 0 ; i < plist.size() ; ++i) {
        cout << plist[i]->arrivalTime << endl;
    }
    
    plist.clear();
    
    return 0;
    
}
