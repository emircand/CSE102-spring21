/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/


#include <stdio.h>
#include "hw8_lib.h"

void test_clean_file () 
{
	char *infile = "input.txt";
	char *outfile = "output.txt";
	int number_of_words;

}


void test_maze_move ()
{
	move_type move;
	/*create maze*/
	cell_type maze[8][8] = {
		{0, 0, 0, 0, 0, 0, 0, 0 },
		{0, 1, 3, 1, 1, 4, 0, 0 },
		{0, 1, 0, 0, 1, 0, 0, 0 },
		{0, 1, 1, 0, 1, 0, 0, 0 },
		{0, 0, 1, 0, 1, 0, 0, 0 },
		{0, 0, 1, 0, 1, 1, 1, 0 },
		{0, 0, 1, 1, 2, 0, 1, 0 },
		{0, 0, 0, 0, 0, 0, 0, 0 }
	};
	/*valid moves for application*/
	printf("\nleft: 0\nright: 1\nup: 2\ndown: 3\n");
	/*function call to print maze*/
	print_maze(maze, 0, 0);
	printf("\n");
	printf("enter a move: ");
	scanf("%u", &move);
	/*function call to move in maze*/
	maze_move(maze, cell_p1, move);
}


void test_towers_of_hanoi ()
{
	int n=5;
	char start_peg = 'S', end_peg = 'E', aux_peg = 'A';
	towers_of_hanoi(start_peg, end_peg, aux_peg, n);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	/*test_clean_file ();*/
	test_maze_move ();

	/*i only write recursive implementation of tower of hanoi*/
	test_towers_of_hanoi ();
	return (0);
} /* end main */
