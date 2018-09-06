/**
 * 矩阵运算模块
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h> 
#include <time.h>

#include "input.h"

// 新结合的数字不能再次结合，用数字的第0位来标记该数字结合过
int vector_move(int *vector[], int len)
{
	int i, en_move;

	do {
		en_move = 0;
		for(i = 1; i < len; i++) {
			int *cur, *left;
			cur = vector[i];		// 当前数字地址
			left = vector[i-1];		// 前一个数字地址
			if(*cur == 0)
				continue;
			if(*left == 0) {
				*left = *cur;
				*cur = 0;
				en_move = 1;
			} else if(*left == *cur && 
					!(*left & 1) && !(*cur & 1)) {
				*left += *cur;
				*left |= 1;			// 标记该数字为新数字
				*cur = 0;
				en_move = 1;
			}
		}
	} while(en_move);

	// 清除标志位
	for(i = 0; i < len; i++)
		if(*(vector[i]) & 1)
			*(vector[i]) &= ~1;

	return 0;
}

int matrix_move(int matrix[4][4], int dir)
{
	int *vector[4];		// 标准向量
	int i, j;

	if(dir != UP && dir != DOWN && dir != LEFT && dir != RIGHT) {
		printf("input error\n");
		return -EINVAL;
	}
	switch(dir) {
	case UP:
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 4; j++)
				vector[j] = &matrix[j][i];
			vector_move(vector, 4);
		}
		break;
	case DOWN:
		for(i = 0; i < 4; i++) {
			for(j = 3; j >= 0; j--)
				vector[3-j] = &matrix[j][i];
			vector_move(vector, 4);
		}
		break;
	case LEFT:
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 4; j++)
				vector[j] = &matrix[i][j];
			vector_move(vector, 4);
		}
		break;
	case RIGHT:
		for(i = 0; i < 4; i++) {
			for(j = 3; j >= 0; j--)
				vector[3-j] = &matrix[i][j];
			vector_move(vector, 4);
		}
		break;
	}

	return 0;
}

int num_insert(int matrix[4][4])
{
	int i, j, count = 0;
	int *zarr[16] = {NULL};
	int x;		// 1个随机数

	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(matrix[i][j] == 0)
				zarr[count++] = &matrix[i][j];
	if(count == 0)
		return -1;

	srand((int)time(0));
	x = rand() % count;
	*(zarr[x]) = 2;

	return 0;
}

int matrix_cmp(int A[4][4], int B[4][4])
{
	int i, j;

	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(A[i][j] != B[i][j])
				return -1;

	return 0;
}

int num_find(int A[4][4], int num)
{
	int i, j;

	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(A[i][j] == num)
				return 1;

	return 0;
}
