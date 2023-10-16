
#include "problems.h"
#include "timer.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv){
	double executionTime = timeFunction(GRCPCProblems::problem1);

	cout << "Execution time: " << executionTime << "milliseconds" << endl;
	return 0;
}
