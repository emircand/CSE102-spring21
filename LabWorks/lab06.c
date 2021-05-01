/** 
  *         *LAB - 06* 
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
#include<string.h>

/*Global Function Declarations*/
double average_finder(int *Arr, int row, int column);

void intervew (const char* s1, const char* s2, char* s3);

int main()
{
    int arr1[3][5], arr2[4][9];
    double avArr1=0, avArr2=0;
    int i, j, counti = 0, countj = 0;
    const char *s1 = "abcdefg", *s2 = "1234";
    char *s3 = malloc(strlen(s1)+strlen(s2)+1);
    
    /*counting elements of arrays*/
    for (i = 0; i < 4; i++)
    {
        counti++;
        for(j = 1; j < 6; j++){
            countj++;
            arr1[i][j-1] = 2 * (countj) * (countj) - 3;
            printf("%d ",arr1[i][j-1]);
        }
        printf("\n");
    }
    printf("\n");
    counti = 0;     /*reset counter values*/
    countj = 0;
    for (i = 0; i < 4; i++)
    {
        counti++;
        for(j = 1; j < 10; j++){
            countj++;
            arr2[i][j-1] = 2 * (countj) * (countj) - 3;
            printf("%d ",arr2[i][j-1]);
        }
        printf("\n");
    }
    
    /*function call*/
    avArr1 = average_finder((int *)arr1, 3, 5);
    avArr2 = average_finder((int *)arr2, 4, 9);

    printf("\n");
    /*output ---> part1*/
    printf("average of array 1> %.1f\n",avArr1);
    printf("average of array 2> %.1f\n",avArr2);
    
    intervew(s1, s2, s3);


    return 0;
}
void intervew (const char* s1, const char* s2, char* s3){
    int i=0, j=0, element=0;

    while (i < strlen(s1) && j < strlen(s2))
    {   
        /*assign s1 and and s2 to s3*/
        s3[element] = s1[i];
        element++;
        i++;
        s3[element] = s2[j];
        element++;
        j++;
    }

    while (i < strlen(s1))
    {   
        /*fazla değerleri atama*/
        s3[element] = s1[i];
        element++;
        i++;
    }

    while (i < strlen(s2))
    {
        /*fazla değerleri atama*/
        s3[element] = s2[j];
        element++;
        j++;
    }
    puts(s3);
}

double average_finder(int *Arr, int row, int column){
    double average=0, sum=0;
    int i, j;

    /*summary of all elements*/
    for (i = 0; i < row; i++)
      for (j = 0; j < column; j++)
        sum = sum + *((Arr+i*column) + j);

    /*average of matrix*/             
    average = sum / (row * column);
    return average; /*returning avreage value*/
}

