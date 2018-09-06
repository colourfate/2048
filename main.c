/**
 * c语言2048游戏，规则：
 * 在4x4的方格中随机放有0, 2, 4, ..., 1024的数字，按方向键移动方格，
 * 移动的规则是，相邻的数字相同则可以结合生成更大的数字，0是特殊数字
 * 若两个相同的数字之间隔着0，则数字可以越过0和另一个数字结合。数字
 * 结合后生成的新数字的位置由方向键决定，如向左，则新数字位于最左边
 * 第一个0的位置
 * 以上规则可以看做是：将矩阵分为4个向量，按指定方向移动，移动方法是
 * 每个数字按指定方向移动一格，遇到0则占据0的位置，遇到相同的数字，则
 * 与之结合；新结合生成的数字不能与其他数字结合；
 * 循环这个过程，直到4个数字都不能移动为止。
 * by colourfate 2018/09/02
 */

#include <stdio.h>
#include <string.h>

#include "display.h"
#include "input.h"
#include "matrix.h"

int main(void)
{
	int matrix[4][4] = {};
	/*
	int matrix[4][4] = {
		{2, 4, 8, 16},
		{16, 8, 4, 2},
		{2, 4, 8, 16},
		{16, 8, 4, 2},
	};
	*/
	int mat_test[4][4];
	int dir, i, en_move;

	num_insert(matrix);
	num_insert(matrix);	
	display_gameboard(matrix);
	while(1) {
		// 判断是否通关
		if(num_find(matrix, 2048)) {
			printf("you win!\n");
			return 0;
		}
		// 判断是否失败
		en_move = 0;
		memcpy(mat_test, matrix, 4*4*sizeof(int));
		for(i = 0; i < 4; i++) {
			matrix_move(mat_test, i);
			if(matrix_cmp(mat_test, matrix) < 0) {
				en_move = 1;
				break;
			}
		}
		if(!en_move) {
			printf("game over\n");
			return 0;
		}
		
		dir = wait_input();
		//printf("dir: %d\n", dir);
		matrix_move(matrix, dir);
		num_insert(matrix);
		display_gameboard(matrix);
	}
	
	return 0;
}
