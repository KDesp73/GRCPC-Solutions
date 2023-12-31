// Run with: {cat ./samples/p1-10000000.txt} | ./build/GRCPCSolutions

// For 10^7 inputs:  12834.6milliseconds < 15seconds

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
	float x;
	float y;
	char id[20];
};

void GRCPCProblems::problem1(){
	int size;
	scanf("%d", &size);

	vector<Coords> coords_list;
	for(int i = 0; i < size; i++){
		Coords coords;
		scanf("%s %f %f", coords.id, &coords.x, &coords.y);
		coords_list.push_back(coords);
	}

	vector<string> passed_ids;
	vector<bool> isDominatedByAny(size, false);

	for (int i = 0; i < size; i++) {
		Coords iCoords = coords_list[i];
		for (int j = 0; j < size; j++) {
			if (iCoords.x < coords_list[j].x && iCoords.y < coords_list[j].y && (i!=j)) {
				isDominatedByAny[i] = true;
				break;
			}		
		}

		if (!isDominatedByAny[i]) {
			passed_ids.push_back(coords_list[i].id);
		}
	}

	sort(passed_ids.begin(), passed_ids.end());

	for (string id : passed_ids) {
		printf("%s ", id.c_str());
	}

	printf("\n");
}
