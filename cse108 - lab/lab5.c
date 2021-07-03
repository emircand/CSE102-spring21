/** 
  *         *LAB - 05* 
  * File:    1901042674.C 
  * 
  * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
  * Date:    Spring 2021  
  * Course:  CSE108 - LAB 
  * 
  */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void expression0 (int x, int *result)
{
    /* calculation of the expression0 for the value of x*/
    /*x^2+5*/
    int sum0 = 0, i;
    sum0 = sum0 + pow(i,2) + 5;
    *result = sum0;
}
void expression1 (int x, int *result)
{
    /* calculation of the expression1 for the value of x*/
    /*2x+1*/
    int sum1 = 0, i;
    sum1 = sum1 + (2 * i) + 1;
    *result = sum1;
}
void expression2 (int x, int *result)
{
    /* calculation of the expression2 for the value of x*/
    /*x^2*/
    int sum2 = 0, i;
    sum2 = sum2 + pow(i,2);
    *result = sum2;
}
void addition(void (*func)(int, int *), int *sum, int n)
{
    /* obtaining the calculations for a single expression and return the result */
    int i;

    for (i = n; i >=0; i--)
    {
        func(n, sum);
    }
}
void calculation (int  *sumArray, int n)
{
    /* Obtaining the summations and assinging them to sumArray respectively*/
    addition(*expression0, sumArray, n);
    printf("Sum of expression0: %ls\n",sumArray);
    addition(*expression1, sumArray, n);
    printf("Sum of expression1: %ls\n",sumArray);
    addition(*expression2, sumArray, n);
    printf("Sum of expression2: %ls\n",sumArray);
}

void createArray(int (*array)[10]){
    srand(time(NULL));
    int randomNumber = rand () %90 + 10;
    int i,j, arr[10][10];

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d \n",randomNumber);
            arr[i][j]=randomNumber;
        }
    }
    
}
int main ()
{
    /* Declaring array, reading “n”, obtaining the results by using functions, and printing them. Nothing else.*/
    int n, sum;

    printf("n: ");
    scanf("%d",&n);
    calculation (&sum, n);
    return 0;
}