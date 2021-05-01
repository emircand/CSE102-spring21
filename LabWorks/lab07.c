/** 
 *         *LAB - 07* 
 * File:    1901042674.C 
 * 
 * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * Date:    Spring 2021  
 * Course:  CSE108 - LAB 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int check_palindrome(int  a[],  int  n, int i){
    int ans;
    if (n > 0)
    {
        /*condition control*/
        if (a[n] == a[i])
        {
            /*recursive call*/
            check_palindrome(a, n-1, i+1);
            ans = 1;
        }
        else if(a[n] != a[i]){
            ans = 0;
        }
    }
    return ans;
}

int search_element(int  arr[],  int  input_number, int s){
    if (s > 0)
    {
        /*if element found, func returns 1. else continue to search*/
        if (arr[s] == input_number)
        {
            return 1;
        }
        else return search_element(arr, input_number, s-1);
    }
    else return 0;
}

float cos_find(int n, float x ){
    float cos_result;

    /*max limit of counting*/
    if (n < 2)
    {
        /*operation and recursive call*/
        cos_result = (1 - (x*x)/((2*n-1)-2*n)) * cos_find(n+1, x);
    }
    else return 1;
}



int main(){
    int i, pal[50], number, n=0, palindrome, control = 0; /*variables for check palindrome function*/

    int elem[20], r, random_input, j, s=19, result;

    int cos_n=1;
    float cos_x=7;

    /*take set of numbers from user*/
    printf("enter numbers >>> ");
    for (i = 0; i < 50; i++)
    {
        scanf("%d", &number);
        if (number >= 0)
        {
            pal[i] = number;
            n++;
        }
        else
        {
            break;
        }
    }
    palindrome = check_palindrome(pal, n, control);

    if (palindrome == 1)
    {
        printf("Your input is not a palindrome\n");
    }
    else if (palindrome == 0)
    {
        printf("Your input is a palindrome\n");
    }    
        
    

    /**/
    printf("\n\n\nrandom array: ");
    /*assigning and printing elements of array*/
    for (j = 0; j < 20; j++)
    {  
        r = rand()%101;
        elem[j] = r;
        printf("%d ", elem[j]);

    }
    /*randomly select a number and print*/
    random_input = rand()%101;
    printf("\nrandom input : %d\n", random_input);
    
    /*function call*/
    result = search_element(elem, random_input, s);
    
    /*function's return value*/
    if (result == 1)
    {
        printf("input number is in the given array\n");
    }
    else
    {
        printf("number is not found in the array\n");
    }
    
    /**/
    printf("\n\nresult of cosine operation: %.1f\n",cos_find(cos_n, cos_x));

    
    


    
return 0;
}