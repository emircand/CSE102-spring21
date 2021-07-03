 /** 
  * File:    1901042674.C 
  * 
  * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
  * Date:    Spring 2021  
  * Course:  CSE108 - LAB 
  * 
  */

#include<stdio.h>

/*function declarations*/
int find_max_distance(int num_inputs);
void find_odd_average();

int main(){
    /*variable declrations*/
    int numbers, Max;
    
    
    printf("-----------------------\n");
    printf("***this function will find the maximum difference between two consecutive user entered numbers and print***\n");
    
    /*take an input*/
    printf("Please enter number of the 'input':");
    scanf("%d", &numbers);

    Max = find_max_distance(numbers); /*function call*/
    
    printf("\nMax distance between two consecutive numbers: %d \n",Max); /*print the function's return value*/
    
    printf("-----------------------\n");
    printf("***these function will calculate the average of the positive odd numbers entered***\n");
    
    find_odd_average();
    
}
/**
 * This function will read num_inputs integers from the console 
(assume the user enters only integers). It will find the maximum 
 difference between two consecutive user entered numbers, and print 
 and return the result. The function must contain a single loop.
*/
int find_max_distance(int num_inputs){
    int i, number1, number2, temp, Max_Dist;
    printf("Please enter %d numbers: ",num_inputs);
    
    number1 = 0;
    for (i = 1; i <= num_inputs; i++)
    {   
        /*take an input*/
        printf("\n%d : ", i);
        scanf("%d",&number2);

        if (i==1)
        {
            Max_Dist = number2 - number1; /*first subtract is assigned as Max_Dist to compare other values*/
            number1 = number2; /*sıralı işlem yapmak için number1, number2 olarak atandı.*/
        }
        else{
            temp = number2 - number1;
            if (Max_Dist <= temp)
            {
                Max_Dist = temp; /*if max dist smaller than temp variable, Max_Dist will be change*/
            }
            number1 = number2; /*sıralı işlem yapmak için number1, number2 olarak atandı.*/
        }
    }
   return Max_Dist; 
}
/**
 * This function will read positive integers from the console 
 (assume only integer inputs). It will read numbers until user enters -1. 
 Your function will calculate the average of the positive odd numbers 
 entered. The function must contain a single loop.
*/

void find_odd_average(){
    int count=1, Odd_Counter=0, number_input, sum=0;
    double average; 
    
    printf("Please enter positive numbers (end -1 to stop entering): \n");
    
    /*do-while loop to take inputs until user press -1*/
    do
    {
        /*take an input*/
        printf("%d: ",count);
            scanf("%d",&number_input);
        
        /*control statement for Even/Odd test*/
        if(number_input > 0 && number_input % 2 != 0){
            sum = sum + number_input;       /*if number_input is odd, variable participated on addition*/
            Odd_Counter++;
        }
        count++;
    } while (number_input != -1);
        
        /*average of odd numbers*/
        average = (double) sum / (double) Odd_Counter;

    /*print the average value*/    
    printf("Average of odd numbers: %g\n", average);
}