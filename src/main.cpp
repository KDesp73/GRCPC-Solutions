#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <fstream>
#include <streambuf>
#include <iostream>

#include "problems.h"
#include "timer.h"
#include "problem1/utils.h"

using namespace std;


void wrapper() {
	GRCPCProblems::problem1();
}

int main(int argc, char **argv){
	double executionTime = timeFunction(wrapper);
	cout << "Execution time: " << executionTime << "milliseconds" << endl;
	
	return 0;
}


