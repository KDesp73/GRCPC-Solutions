#include "problems.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

void GRCPCProblems::problem2(){
	int rows, cols;

	scanf("%d %d", &rows, &cols);

	// Create a dynamic 2D character array
    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(cols * sizeof(char));
    }

    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }





	/*
    // Display the grid data
    printf("Parsed Grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    */


    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}
