// For 10^5 inputs: 145.334milliseconds
// For 10^7 inputs: 14.53seconds 

#include "problems.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
// #include <string>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;

struct Coords {
	double x;
	double y;
	char id[20];
};

vector<Coords> getCoords(int size){
	vector<Coords> coords_list;

	for(int i = 0; i < size; i++){
		Coords coords;
		scanf("%s %lf %lf", coords.id, &coords.x, &coords.y);
		coords_list.push_back(coords);
		
		// cout << coords.id << " " << coords.x<< " " << coords.y << endl;
	}

	return coords_list;
}

bool isDominated(Coords c1, Coords c2){
	return (c1.x < c2.x && c1.y < c2.y);
}


void GRCPCProblems::problem1(){
	int size;
	scanf("%d", &size);

	vector<Coords> coords_list;

	for(int i = 0; i < size; i++){
		Coords coords;
		scanf("%s %lf %lf", coords.id, &coords.x, &coords.y);
		coords_list.push_back(coords);
	}

	vector<string> passed_ids;
	vector<bool> isDominatedByAny(size, false);


	for (int i = 0; i < size; i++) {
		if (isDominatedByAny[i]) {
			continue;
		}

		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			if ((coords_list[i].x < coords_list[j].x && coords_list[i].y < coords_list[j].y)) {
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
		std::cout << passed_ids.at(i);

		if (i < passed_ids.size() - 1) {
			std::cout << " ";
		}
	}

	cout << endl;
}
