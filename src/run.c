// Immanuel Amirtharaj


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


// Import all the classes and stuff

using namespace std;



int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Error, need the right arguments" << endl;
		cout << "Choose fcfs, sjf, str, rr, hpfs1, or hpfs2" << endl;
		return -1;
	}

	string choice = string(argv[1]);

	if (choice == "fcfs") {

	}
	else if (choice == "sjf") {

	}
	else if (choice == "str") {

	}
	else if (choice == "rr") {

	}
	else if (choice == "hpfs1") {

	}
	else if (choice == "hpfs2") {

	}
	else {
		cout << "invalid choice " << endl;
		cout << "Choose fcfs, sjf, str, rr, hpfs1, or hpfs2" << endl;
	}


	return 1;
}