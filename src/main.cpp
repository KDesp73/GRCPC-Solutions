#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <set>

#include "problems.h"
#include "timer.h"
#include <fstream>
#include <streambuf>
#include <iostream>

using namespace std;

std::string readFileToString(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file." << std::endl;
		return "";
	}

	// Read the entire file into a string
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	return content;
}

void temp() {
	GRCPCProblems::problem2(readFileToString("/home/konstantinos/personal/repos/cpp/GRCPC_Solutions/samples/p2.txt"));
}

int main(int argc, char **argv){
	/**/
	double executionTime = timeFunction(temp);

	cout << "Execution time: " << executionTime << "milliseconds" << endl;


	return 0;
}


