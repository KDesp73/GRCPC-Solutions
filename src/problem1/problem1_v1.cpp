// Time: 0.144505milliseconds for 5 inputs
// Time: 24.08 minutes for 10^7 inputs

#include "problems.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

struct Coords {
	string id;
	double x;
	double y;
};

std::vector<std::string> splitString(const std::string& input, char del) {
    std::vector<std::string> lines;
    std::istringstream stream(input);
    std::string line;

    while (std::getline(stream, line, del)) {
        lines.push_back(line);
    }

    return lines;
}

vector<Coords> getCoords(vector<string> input, int size){
	vector<Coords> coords_list;

	for(int i = 1; i < size+1; i++){
		Coords coords;

		vector<string> args = splitString(input[i], ' ');
		
		coords_list.push_back(Coords{args[0], stod(args[1]), stod(args[2])});
	}

	return coords_list;
}

bool isDominated(Coords c1, Coords c2){
	return (c1.x < c2.x && c1.y < c2.y);
}

pair<int, vector<Coords>> parseInput(string input){
	vector<string> lines = splitString(input, '\n');

	int size = stoi(lines.at(0));

	return pair<int, vector<Coords>>(size, getCoords(lines, size));
}


void GRCPCProblems::problem1(string input){
	pair<int, vector<Coords>> p = parseInput(input);

	int size = p.first;
	vector<Coords> coords_list = p.second;

	vector<string> passed_ids;
	vector<bool> isDominatedByAny(size, false);

	for (int i = 0; i < size; i++) {
		if (isDominatedByAny[i]) {
			continue;
		}

		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			if (isDominated(coords_list[i], coords_list[j])) {
				isDominatedByAny[i] = true;
				break;
			}
		}

		if (!isDominatedByAny[i]) {
			passed_ids.push_back(coords_list[i].id);
		}
	}	

	sort(passed_ids.begin(), passed_ids.end());


	for (size_t i = 0; i < passed_ids.size(); i++) {
		std::cout << passed_ids[i];

		if (i < passed_ids.size() - 1) {
			std::cout << " ";
		}
	}
	cout << endl;
}
