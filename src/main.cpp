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
	GRCPCProblems::problem1();
}

int main(int argc, char **argv){
	
	double executionTime = timeFunction(temp);

	cout << "Execution time: " << executionTime << "milliseconds" << endl;

	return 0;

}


