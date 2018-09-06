/**
 * 显示模块
 */
#include <stdio.h>

int display_gameboard(int matrix[4][4])
{
	int i, j;

	printf("-----------------------------\n");
	for(i = 0; i < 4; i++) {
		printf("|");
		for(j = 0; j < 4; j++) {
			if(matrix[i][j] == 0)
				printf("      |");
			else
				printf(" %4d |", matrix[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");

	return 0;
}

