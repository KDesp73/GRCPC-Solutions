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

std::string generateRandomID(int length) {
    const std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // You can modify this to include other characters
    std::string id;
    for (int i = 0; i < length; ++i) {
        id += charset[std::rand() % charset.length()];
    }
    return id;
}

void generateRandomData(int size){
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Number of inputs in the new sample
    int num_inputs = size;
    int idLength = 7; // Set the desired length of the ID

    // Create an output file stream to write the data to a file
    std::ofstream outputFile("/home/konstantinos/personal/repos/cpp/GRCPC_Solutions/samples/p1.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }

    // Set to keep track of used IDs
    std::set<std::string> usedIDs;

    // Generate a random sample and write it to the file
    outputFile << num_inputs << std::endl;
    for (int i = 0; i < num_inputs; ++i) {
        std::string id;
        do {
            id = generateRandomID(idLength); // Generates a random string as an ID
        } while (usedIDs.count(id) > 0);  // Check if the ID is already used

        double double1 = static_cast<double>(std::rand()) / RAND_MAX * 10.0;  // Generates a random double between 0 and 10
        double double2 = static_cast<double>(std::rand()) / RAND_MAX * 10.0;  // Generates a random double between 0 and 10
        outputFile << id << " " << double1 << " " << double2 << std::endl;

        usedIDs.insert(id);  // Mark the ID as used
    }

    // Close the output file
    outputFile.close();}

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
	GRCPCProblems::problem1(readFileToString("/home/konstantinos/personal/repos/cpp/GRCPC_Solutions/samples/p1.txt"));
}

int main(int argc, char **argv){
	/**/
	double executionTime = timeFunction(temp);

	cout << "Execution time: " << executionTime << "milliseconds" << endl;
	/** /
	generateRandomData(100000);
	/**/

	return 0;
}


