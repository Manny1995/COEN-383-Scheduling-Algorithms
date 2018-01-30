#include <iostream>
#include <queue>
#include <cmath>

#include "SJF.h"

using namespace std;

bool byRunTime(Process* a, Process* b) {
    return (a->runTime < b->runTime);
}


void printProcessList(list<Process *> processList,
                      list<float> turnaroundTimes = list<float>(),
                      list<float> responseTimes = list<float>()) {
    
    list<Process*>::iterator iter;
    list<float>::iterator taIter;
    list<float>::iterator resIter;
    
    if (turnaroundTimes.empty()) {
        cout << "\tP name\t|\tArrival\t|\tDur\t|\tPri" << endl;
        cout << "---------------------------------------------------------------" << endl;
    } else {
        cout << "\tP name\t|\tArrival\t|\tDur\t|\tPri\t|\tTA\t|\tRes" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;
    }
    
    if (turnaroundTimes.empty()) {
        for (iter  = processList.begin() ; iter != processList.end() ; ++iter) {
            cout << "\t" << (*iter)->identifier
            << "\t|\t" << (*iter)->arrivalTime
            << "\t|\t" << (*iter)->runTime
            << "\t|\t" << (*iter)->priority << endl;
        }
    } else {
        for (iter  = processList.begin(), taIter = turnaroundTimes.begin(), resIter = responseTimes.begin();
             iter != processList.end() ;
             ++iter, ++taIter, ++resIter) {
            cout << "\t" << (*iter)->identifier
            << "\t|\t" << (*iter)->arrivalTime
            << "\t|\t" << (*iter)->runTime
            << "\t|\t" << (*iter)->priority
            << "\t|\t" << *taIter
            << "\t|\t" << *resIter
            << endl;
        }
    }
    
    if (turnaroundTimes.empty()) {
        cout << "---------------------------------------------------------------" << endl;
    } else {
        cout << "-------------------------------------------------------------------------------------------------" << endl;
    }
    
    cout << "\n" << endl;

}

void printProcessMap(list<Process*> pList) {
    
    cout << "Process Map" << endl;
    float currentTime = 0.0;
    Process* currentProcess;
    Process* runningProcess;
    bool processActive = false;
    float startTime;
    queue<Process*> waitingQueue;
    
    list<Process*>::iterator iter;
    string graph = "";
    for (iter = pList.begin(); iter != pList.end(); ++iter) {
        
        while ((*iter)->arrivalTime > currentTime) {
            currentTime += 0.1;
            graph += '-';
        }
        
        startTime = currentTime;
        
        while ((*iter)->runTime + startTime > currentTime) {
            graph += (*iter)->identifier;
            currentTime += 0.1;
        }
        
    }
    
    cout << graph.length() << endl;
    cout << ceil(graph.length() / 10) << endl;
    for (int quanta = 0; quanta <= ceil(graph.length() / 10); quanta++) {
        cout << "Quanta " << quanta << ":\t" << graph.substr(quanta * 10, 10) << endl;
    }
    
}


SJF::SJF() {
}


SJF::~SJF() {
}


list<Process*> SJF::sjfSort(list<Process*> pList) {
    
    //float currentQuanta = 0;
    list<Process*>::iterator iter = pList.begin();
    list<Process*>::iterator reference = pList.begin();
    list<Process*> sjfDeque;
    list<Process*> currentProcesses;
    
    while (iter != pList.end()) {
        
        while ((iter != pList.end()) && ((*iter)->arrivalTime == (*reference)->arrivalTime)) {
            currentProcesses.push_back(*iter++);
        }
        
        reference = iter;
        
        currentProcesses.sort(byRunTime);
        
        if (!currentProcesses.empty()) {
            sjfDeque.insert(sjfDeque.end(), currentProcesses.begin(), currentProcesses.end());
        }
        
        currentProcesses.clear();
        
    }
    
    return sjfDeque;
    
}


void SJF::simulate(vector<Process*> processList) {

    list<Process*> processes;
    Process* currentProcess;
    char currentChar = 'A';
    float totalTime = 0;
    int i = 0;
    float startTime = processList[0]->arrivalTime;
    
    // only log the processes that will start before the
    // 100 quanta mark
    while (totalTime + startTime < 100) {
        currentProcess = processList[i++];
        currentProcess->identifier = currentChar++;
        totalTime += currentProcess->runTime;
        processes.push_back(currentProcess);
    }
    
    cout << "Processes as they will be handled" << endl;
    list<Process*> processesSorted = sjfSort(processes);
    printProcessList(processesSorted);
    
    calculateStatistics(processesSorted);
    printProcessMap(processesSorted);
    
    return;
    
}


void SJF::calculateStatistics(list<Process*> pList) {
    
    cout << "Statistics Report:" << endl;
    
    int totalProcesses = pList.size();
    float totalWaitTime = 0;
    float totalTurnaroundTime = 0;
    float totalResponseTime = 0;
    float currentTime = 0.0;
    list<float> waitTimes;
    list<float> turnaroundTimes;
    list<float> responseTimes;
    
    list<Process*>::iterator iter;
    float startProcessesTime = 0;
    for (iter = pList.begin() ; iter != pList.end() ; ++iter) {
        
        if (iter == pList.begin()) {
            waitTimes.push_back(0);
            responseTimes.push_back(0);
            turnaroundTimes.push_back((*iter)->runTime);
            currentTime = (*iter)->runTime + (*iter)->arrivalTime;
            startProcessesTime = (*iter)->arrivalTime;
            
            totalTurnaroundTime += (currentTime + (*iter)->runTime) - (*iter)->arrivalTime;
        } else {
            waitTimes.push_back(currentTime - startProcessesTime);
            responseTimes.push_back(currentTime - (*iter)->arrivalTime);
            turnaroundTimes.push_back((currentTime + (*iter)->runTime) - (*iter)->arrivalTime);
            currentTime = (*iter)->runTime + currentTime;
            
            totalWaitTime +=
            totalTurnaroundTime += (currentTime + (*iter)->runTime) - (*iter)->arrivalTime;
            totalResponseTime += currentTime - (*iter)->arrivalTime;
        }
        
    }
    
    printProcessList(pList, turnaroundTimes, responseTimes);
    
    cout << "Average turnaround time: " << totalTurnaroundTime / totalProcesses << endl;
    cout << "Average wait time: " << totalResponseTime / totalProcesses << endl;
    cout << "Average reponse time: " << totalResponseTime / totalProcesses << endl;
    cout << "\n" << endl;

}
