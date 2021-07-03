/*
** hw8_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/

#include <stdio.h>
#include "hw8_lib.h"

#define WORDSIZE 1

/*if word found, return 1*/
int exactMatch(char *text, char *sub)
{
	if(*text == '\0' && *sub != '\0')
		return 0;

	if (*sub == '\0')
		return 1;

	if(*text == *sub)
		return exactMatch(text + 1, sub + 1);

	return 0;      		
}

int contains(char *text, char *sub)
{
	/* If last character of text reaches */
    if (*text == '\0')
        return 0;
  
    /* If current characters of pat and text match */
    if (*text == *sub)
        if(exactMatch(text, sub) == 1)
            return 1;
        else
          return contains(text + 1, sub);
  
    /* If current characters of pat and tex don't match */
    return contains(text + 1, sub);
}

void delete_words (FILE* infid, FILE* outfid, char* words_to_delete[WORDSIZE],  int number_of_words)
{
}

void clean_file(char* infile, char * outfile, char* words_to_delete[WORDSIZE], int number_of_words)
{
	/*declarations of file pointers*/
	FILE* infid;
	FILE* outfid;

	/*open file in wanted file modes*/
	infid = fopen(infile, "r");
	outfid = fopen(outfile, "w");

	/*function call*/
	delete_words (infid, outfid, words_to_delete, number_of_words);

	/*close files*/
	fclose(infid);
	fclose(outfid);
}

/*this function finds where the player in maze recursively*/
void recursive_finder(cell_type maze[][8], cell_type cell, int i, int j, int * row, int  * col){
	if (maze[i][j] == cell)
	{
		*row = i;
		*col = j;		
	}
	else
	{
		if(j==7 && i<7)
		{
			j=0;
			recursive_finder(maze, cell, i+1, j, row, col);
		}
		else if(j<7 && i <= 7)
		{
			recursive_finder(maze, cell, i, j+1, row, col);
		}
	}
}

/*these 4 functions movements for maze*/
int maze_left(cell_type maze[][8], int rowp, int colp){
	int retval=0; /*duvar = 0, free = 1*/
	cell_type temp;
	if(colp>1){
		/*if cell free move will happens, it won't happen in other conditions*/
		switch (maze[rowp][colp-1])
		{
		case cell_free:
			temp = maze[rowp][colp];
			maze[rowp][colp] = maze[rowp][colp-1];
			maze[rowp][colp-1] = temp;
			retval = 0;
			break;
		
		case cell_wall:
			retval = 1;
			break;
		
		case cell_target:
			retval = 2;
			break;
		}
	}
	return retval;
}

int maze_right(cell_type maze[][8], int rowp, int colp){
	int retval=0; /*duvar = 0, free = 1*/
	cell_type temp;
	if(colp<7){
		switch (maze[rowp][colp+1])
		{
		case cell_free:
			temp = maze[rowp][colp];
			maze[rowp][colp] = maze[rowp][colp+1];
			maze[rowp][colp+1] = temp;
			retval = 0;
			break;
		
		case cell_wall:
			retval = 1;
			break;
		
		case cell_target:
			retval = 2;
			break;
		}
	}
	return retval;
}

int maze_up(cell_type maze[][8], int rowp, int colp){
	int retval=0; /*duvar = 0, free = 1*/
	cell_type temp;
	if(rowp>1){
		switch (maze[rowp-1][colp])
		{
		case cell_free:
			temp = maze[rowp][colp];
			maze[rowp][colp] = maze[rowp-1][colp];
			maze[rowp-1][colp] = temp;
			retval = 0;
			break;
		
		case cell_wall:
			retval = 1;
			break;
		
		case cell_target:
			retval = 2;
			break;
		}
	}
	return retval;
}

int maze_down(cell_type maze[][8], int rowp, int colp){
	int retval=0; /*duvar = 0, free = 1*/
	cell_type temp;
	if(rowp<7){
		switch (maze[rowp+1][colp])
		{
		case 1:
			temp = maze[rowp][colp];
			maze[rowp][colp] = maze[rowp+1][colp];
			maze[rowp+1][colp] = temp;
			retval = 0;
			break;
		
		case 0:
			retval = 1;
			break;
		
		case 2:
			retval = 2;
			break;
		}
	}
	return retval;
}

/*print each element recursively*/
void print_maze(cell_type maze[][8], int i, int j){
	if(i<=7 && j<=7){
		printf("%3u ", maze[i][j]);
	}
	if (j==7 && i<7)
	{
		j=0;
		printf("\n");
		print_maze(maze, i+1, j);
	}
	else if(i <= 7 && j<7){
		print_maze(maze, i, j+1);
	}
}

int maze_move(cell_type maze[][8], cell_type player, move_type move)
{
	int i=0, j=0, ans=0, retval;
	int rowp, colp, rowtrgt, coltrgt;

	/*celli bul, move kontrol et uygunsa yap*/
	recursive_finder(maze, player, i, j, &rowp, &colp);
	/*call function which is related with movement parameter*/
	switch (move)
	{
	case 0:
		retval = maze_left(maze, rowp, colp);
		break;
	case 1:
		retval = maze_right(maze, rowp, colp);
		break;
	case 2:
		retval = maze_up(maze, rowp, colp);
		break;
	case 3:
		retval = maze_down(maze, rowp, colp);
		break;
	}
	print_maze(maze, 0, 0);

	/*game status check*/
	if (retval == 0 || retval == 1){
		ans = 0;
		printf("\n");
		if(player == 3){
			printf("enter a move: ");
			scanf("%u", &move);
			maze_move(maze, 4, move);
		} 
		else if(player == 4){
			printf("enter a move: ");
			scanf("%u", &move);
			maze_move(maze, 3, move);
		}
	}
	else if(retval == 2){
		printf("\n");
		printf("congratulations----player %u won\n",player-2);
	}
		ans = 1;
		
	return ans;
}

void towers_of_hanoi(char start_peg, char end_peg, char aux_peg, int n)
{
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", start_peg, end_peg);
        return;
    }
    towers_of_hanoi(start_peg, aux_peg, end_peg, n-1);
    printf("Move disk %d from peg %c to peg %c\n ", n, start_peg, end_peg);
    towers_of_hanoi(aux_peg, end_peg, start_peg, n-1);
}
