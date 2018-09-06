/**
 * 输入模块
 */
#include <stdio.h>

#include "input.h"

int wait_input(void)
{
	char input[5];
	int dir;

again:
	scanf("%s", input);
	switch(input[0]) {
	case 'w':
		dir = UP;
		break;
	case 's':
		dir = DOWN;
		break;
	case 'a':
		dir = LEFT;
		break;
	case 'd':
		dir = RIGHT;
		break;
	default:
		printf("usage: w | s | a | d\n");
		goto again;
	}

	return dir;
}
