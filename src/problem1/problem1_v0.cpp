#include "problems.h"
#include <cstdio>
#include <iostream>
#include <sstream>
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

vector<Coords> getCoords(int size){
	vector<Coords> coords_list;

	for(int i = 0; i < size; i++){
		string input, str;
		getline(cin, input);

		stringstream ss(input);
		Coords coords;
		for (int i = 0; getline(ss, str, ' '); i++) {
			switch (i) {
				case 0:
					coords.id = str;
					break;
				case 1:
					coords.x = stod(str);
					break;
				case 2:
					coords.y = stod(str);
					break;
				default:
					break;
			}	
		}
		coords_list.push_back(coords);
	}

	return coords_list;
}

bool isDominated(Coords c1, Coords c2){
	return (c1.x < c2.x && c1.y < c2.y);
}


void GRCPCProblems::problem1(){
	string size_str;
	getline(cin, size_str);
	int size = stoi(size_str);

	vector<Coords> coords_list = getCoords(size);

	vector<string> passed_ids;
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j) continue;
			if(isDominated(coords_list.at(i), coords_list.at(j))){
				goto next;	
			} 
		}
		passed_ids.push_back(coords_list.at(i).id);
next:
		continue;
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
