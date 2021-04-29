 /** 
  *         *HOMEWORK -6*
  * File:    1901042674.C 
  * 
  * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
  * Date:    Spring 2021  
  * Course:  CSE102 
  * 
  */
 #include<stdio.h>
 #include<stdlib.h>
 #define N 4

 /*enumerated type for direction of the movement*/
 typedef enum {
   left,
   right,
   up,
   down
 }
 Towards;

 /*Global Declarations of Functions*/
 int PuzzleSolve(int arr[][N], int Rows, int Cols);
 void randomSwap(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol);
 void BoardPrint(int arr[][N], int Rows, int Cols);
 void leftOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y);
 void rightOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y);
 void upOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y);
 void downOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y);
 void Location(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol);

 /*main part of program*/
 int main() {
   int PuzzleTable[N][N], count = 0;
   int i, j, MomRow = N - 1, MomCol = N - 1, Rows = N, Cols = N;
   srand(1000*N);

   if (N < 2 && N > 10) {
     printf("invalid N value!!");
     exit(EXIT_SUCCESS);
   }
   printf("input x, y and move on single line\n");
   printf("moves:\n0 - left\n1 - right\n2 - up\n3 - down\n\n");

   /*Creating and Filling 2D Puzzle Array*/
   for (i = 0; i < Rows; i++) {
     for (j = 0; j < Cols; j++) {
       count++;
       PuzzleTable[i][j] = count;
       PuzzleTable[N - 1][N - 1] = 0;
     }
   }
   /*Shuffling the Puzzle Array*/
   randomSwap(PuzzleTable, Rows, Cols, & MomRow, & MomCol);

   /*Printing the Puzzle Array*/
   BoardPrint(PuzzleTable, Rows, Cols);

   /*calling Location Puzzle*/
    Location(PuzzleTable, Rows, Cols, & MomRow, & MomCol);

   return 0;
 }

 int PuzzleSolve(int arr[][N], int Rows, int Cols) {
   int i, j, flag, testarr[N][N];
   int count = 1;
   for (i = 0; i < Rows; i++) {
     for (j = 0; j < Cols; j++) {
     testarr[i][j] = count;
     testarr[Rows-1][Cols-1] = 0;
     count++;
     }
    }
   for (i = 0; i < Rows; i++) {
     for (j = 0; j < Cols; j++) {
       if (testarr[i][j] == arr[i][j])
       flag = 0;
       else flag = 1; break;
     }
    }
  if (flag == 1)
    return 1;
  else return 0;
 }

 void leftOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y) {
   int temp;
   int i;
   /*replace elements of array until the value of x equals the value of *MomCol*/
   if (y == * MomRow && * MomCol > x) {
     for (i = * MomCol; i > x; i--) {
       temp = arr[ * MomRow][i];
       arr[ * MomRow][i] = arr[ * MomRow][i - 1];
       arr[ * MomRow][i - 1] = temp;
     }
   }
 }

 void rightOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y) {
   int temp;
   int i;
   /*replace elements of array until the value of x equals the value of *MomCol*/
   if (y == * MomRow && * MomCol < x) {
     for (i = * MomCol; i < x; i++) {
       temp = arr[ * MomRow][i];
       arr[ * MomRow][i] = arr[ * MomRow][i + 1];
       arr[ * MomRow][i + 1] = temp;
     }
   }
 }

 void upOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y) {
   int temp;
   int i;
   /*replace elements of array until the value of y equals the value of *MomRow*/
   if (x == * MomCol && y < * MomRow) {
     for (i = * MomRow; i > y; i--) {
       temp = arr[i][ * MomCol];
       arr[i][ * MomCol] = arr[i - 1][ * MomCol];
       arr[i - 1][ * MomCol] = temp;
     }
   }
 }

 void downOp(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol, int x, int y) {
   int temp;
   int i;
   /*replace elements of array until the value of y equals the value of *MomRow*/
   if (x == * MomCol && y > * MomRow) {
     for (i = * MomRow; i < y; i++) {
       temp = arr[i][ * MomCol];
       arr[i][ * MomCol] = arr[i + 1][ * MomCol];
       arr[i + 1][ * MomCol] = temp;
     }
   }
 }

 void randomSwap(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol) {
   int i, j, count=0, r;
   int Row = *MomRow, Col = *MomRow;
   
   /*loop - random moves on puzzle table*/
   while(count < 99999){
       for (i = 0; i < Rows; i++) {
        for (j = 0; j < Cols; j++) {
         r = rand()%4;
         if(r == 0)
            leftOp(arr, Rows, Cols, & Row, & Col, j, i);
         if(r == 1)
            rightOp(arr, Rows, Cols, & Row, & Col, j, i);
         if(r == 2)
            upOp(arr, Rows, Cols, & Row, & Col, j, i);
         if(r == 3)
            downOp(arr, Rows, Cols, & Row, & Col, j, i);
     }
     count++;
   }
   }
   /*finding 0 value on the table*/
   for (i = 0; i < Rows; i++)
     for (j = 0; j < Cols; j++) {
       if (arr[i][j] == 0) {
         * MomRow = i;
         * MomCol = j;
       }
     }
 }

 void BoardPrint(int arr[][N], int Rows, int Cols) {
   int i, j;
   /*printing the puzzle table*/
   for (i = 0; i < Rows; i++) {
     for (j = 0; j < Cols; j++) {
       if (arr[i][j] == 0) {
         /*if number is zero, the function will print "__"*/
         printf(" %3s ", "__");
       } else printf(" %3d ", arr[i][j]);
     }
     printf("\n");
   }
   printf("\n");
 }

 void Location(int arr[][N], int Rows, int Cols, int * MomRow, int * MomCol) {
   int x, y, Solve;
   Towards move;
   int mar;
   int Row = * MomRow, Col = * MomCol, i, j;

   /*take movement parameters from user*/
   printf("to exit ---> enter '100' to all parameters\n");
   printf("enter location and direction to move (x,y,0/1/2/3)> ");
   scanf("%d %d %u", & x, & y, & move);

   /*exit way for program*/
   if (x == 100 && y == 100 && move == 100) {
     exit(EXIT_SUCCESS);
   }

   /*if parameters are invalid, elements of Puzzle won't replace.*/
   if ((x < Cols && x >= 0) && (y < Rows && y >= 0)) {
     switch (move) {
     case left:
       leftOp(arr, Rows, Cols, & Row, & Col, x, y);
       break;
     case right:
       rightOp(arr, Rows, Cols, & Row, & Col, x, y);
       break;
     case up:
       upOp(arr, Rows, Cols, & Row, & Col, x, y);
       break;
     case down:
       downOp(arr, Rows, Cols, & Row, & Col, x, y);
       break;
     default:
       printf("error!!1\n");
       break;
     }
   }
   /*finding zero value and assigning as MomRow and MomCol again.*/
   for (i = 0; i < Rows; i++) {
     for (j = 0; j < Cols; j++) {
       if (arr[i][j] == 0) {
         Row = i;
         Col = j;
       }
     }
   }
   /*printing the puzzle table*/
   BoardPrint(arr, Rows, Cols);

   /*table check and loop*/
   Solve = PuzzleSolve(arr, Rows, Cols);
   if (Solve == 1)
      Location(arr, Rows, Cols, &Row, &Col);
   else printf("\n!!!!!congratulations!!!!!\nYOU WON\n");
 }