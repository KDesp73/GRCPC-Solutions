#include "problems.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>

void GRCPCProblems::problem3(){
	int passed_size;
	scanf("%d", &passed_size);

	while (getchar() != '\n');

    char passed_lessons[passed_size][20]; // Assuming a maximum string length of 99 characters

    for (int i = 0; i < passed_size; i++) {
        scanf("%19s", passed_lessons[i]);
    }
	
	int required_size;
	scanf("%d", &required_size);

	while (getchar() != '\n');

    char required_lessons[required_size][20]; // Assuming a maximum string length of 99 characters

    for (int i = 0; i < required_size; i++) {
        scanf("%19s", required_lessons[i]);
    }
	
	int found = 0;
    for (int i = 0; i < required_size; i++) {
        for (int j = 0; j < passed_size; j++) {
            if (strcmp(required_lessons[i], passed_lessons[j]) == 0) {
				found++;
			}
        }
    }

    (found == required_size) ? printf("1\n") : printf("0\n"); 
    
}
