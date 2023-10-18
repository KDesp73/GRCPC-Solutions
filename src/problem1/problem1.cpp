// Run with: {cat ./samples/p1.txt} | ./build/GRCPCSolutions

// For 10^5 inputs: 145.334milliseconds
// For 10^7 inputs: 16792.5milliseconds

#include "problems.h"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct Coords {
	double x;
	double y;
	char id[20];
};

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
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			if (coords_list[i].x < coords_list[j].x && coords_list[i].y < coords_list[j].y) {
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
		std::cout << passed_ids.at(i) << " ";
	}

	cout << endl;
}
