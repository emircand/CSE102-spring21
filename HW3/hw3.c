 /** 
  * 
  *         *HOMEWORK - 3*
  * File:    1901042674.C 
  * 
  * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
  * Date:    Spring 2021  
  * Course:  CSE102 
  * 
  */ 

#include<stdio.h>

/*function declerations*/
void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void difference_max_min ();
void bmi_calculation ();


int main(){

    /*funciton calls*/
    calculate_fibonacci_sequence();
    decide_perfect_harmonic_number();
    difference_max_min();
    bmi_calculation();

    return 0;
}

/**
 * void calculate_fibonacci_sequence()
 * 
 * The function, take a sequence value from user and create a fibonacci sequence then print.
*/

void calculate_fibonacci_sequence(){
    int Term_Number, temp, first, second, i;
    char numeric;
    
    /*function menu on the console*/
    printf("------------------------------\n");
    printf("   ...fibonacci sequence...\n");
    printf("to skip this part press '*'\n");
    printf("------------------------------\n");
    
    /*take an input*/
    printf("Please enter term(s) number : ");
        scanf("%d",&Term_Number);
        numeric = getchar();

    /*the function continue working until it gets the ‘*’ input*/
    while(numeric != '*'){
        /*if term number is negative integer or a character, user will input a new integer.*/
        while ((numeric != '\n') || (Term_Number <= 0))
        {
            if(numeric != '\n'){
                printf("please enter 'numeric' term(s) number : ");
                    scanf("%d",&Term_Number);
                    numeric = getchar();
                    if (numeric == '*')
                        break;
                    
            }
            else if (Term_Number <= 0)
            {
                printf("Please enter 'positive' term(s) number : ");
                    scanf("%d",&Term_Number);
                    numeric = getchar();
                    if (numeric == '*')
                        break; 
            }
        }

        if (numeric == '*')
            break;

        /*calculating and printing fibonacci sequence*/
        printf("Fibonacci Sequence:\n");
        
        /*to make right calculations these values re-assigned in every loop*/
        first = 1;
        second = 1;

        for ( i = 0; i < Term_Number; i++){
            temp = first;
            first = second;
            second = temp + first;
            printf("%d\n",temp); 
        }
        /*function menu on the console*/
        
        printf("------------------------------\n");
        printf("Please enter term(s) number : ");
            scanf("%d",&Term_Number);
            numeric = getchar();
    }
}

/**
 * void decide_perfect_harmonic_number()
 * 
 * The function take a positive integer from user and calculates divisors of that number.
 * Then check the condition of being perfect & harmonic number..
*/
void decide_perfect_harmonic_number(){

    int number, i, perfect_sum, count, Check_Value;
    double harmonic, harmonic_sum, subtract;
    char numeric;

    /*function menu on the console*/
    printf("\n\n------------------------------\n");
    printf("   ...PERFECT || HARMONIC...\n");
    printf("   to skip this part press '*'\n");
    printf("------------------------------\n");
   

    /*take an input*/
    printf("Please enter input number: ");
        scanf("%d",&number);
        numeric = getchar();

    /*the function continue working until it gets the ‘*’ input*/
    while(numeric != '*' )
    {
        /*to make right calculations these values re-assigned in every loop*/
        perfect_sum = 0;
        harmonic = 0.0;
        harmonic_sum = 0.0;
        count = 0;

        printf("Natural Number Divisors: ");
        for (i = 1; i <= number; i++)
        {
            if (number % i == 0)
            {
                printf("%d ",i);
            
                /*perfect number calculation according to rule, number variable does not participate in addition process.*/
                if(number != i)
                    perfect_sum = perfect_sum + i;

                /*denominator part of harmonic divisor formula*/
                harmonic_sum = harmonic_sum + (double) 1/(1.0*i);
                count++; /*count is nominator part of harmonic divisor formula*/
            }
        }
    
        printf("\nIs Perfect Number? : ");
            if (perfect_sum == number) /*if sum is equal to number variable, this number is a perfect number.*/
                printf("Yes\n");
            else
                printf("No\n");
        
        printf("Is Harmonic Divisor Number? : ");

        harmonic = (double) count / harmonic_sum; /*type casting to make right calculations with same variable type*/
        
        Check_Value = harmonic;
        
        /*this subtraction represent the decimal value of harmonic -variable in function- */
        subtract = harmonic - (double)Check_Value;  
        if (subtract <= 0.00001)
            printf("Yes\n");    
        else
            printf("No\n");
        

        printf("\n\n------------------------------\n");
        printf("Please enter input number: ");
            scanf("%d",&number);
            numeric = getchar();
    }     
}
    
/** 
  *    void difference_max_min () 
  * 
  *    The function, find highest and lowest values
  *    into inputs and print the difference.  
  */ 
void difference_max_min (){
    /*declare variables*/
    double min, max;
    double num1, num2, num3, num4, num5;
    int i;

    /*function menu on the console*/
    printf("\n\n------------------------------\n");
    printf("   ...max-min diff...\n");
    printf("------------------------------\n");
    /*take integer/double from user*/
    printf("Please enter 5 numbers: ");
        scanf("%lg %lg %lg %lg %lg",&num1, &num2, &num3, &num4, &num5);

    printf("\n");

    /*finding maximum number*/
    if (num1 >= num2 && num1 >= num3 && num1 >= num4 && num1 >= num5){
        max = num1;
    }
    else if (num2 >= num1 && num2 >= num3 && num2 >= num4 && num2 >= num5){
        max = num2;
    }
    else if (num3 >= num1 && num3 >= num2 && num3 >= num4 && num3 >= num5){
        max = num3;
    }
    else if (num4 >= num1 && num4 >= num2 && num4 >= num3 && num4 >= num5){
        max = num4;
    }
    else if (num5 >= num1 && num5 >= num2 && num5 >= num3 && num5 >= num4){
        max = num5;
    }
    
    /*finding minimum number*/   
    if (num1 <= num2 && num1 <= num3 && num1 <= num4 && num1 <= num5){
        min = num1;
    }
    else if (num2 <= num1 && num2 <= num3 && num2 <= num4 && num2 <= num5){
        min = num2;
    }
    else if (num3 <= num1 && num3 <= num2 && num3 <= num4 && num3 <= num5){
        min = num3;
    }
    else if (num4 <= num1 && num4 <= num2 && num4 <= num3 && num4 <= num5){
        min = num4;
    }
    else if (num5 <= num1 && num5 <= num2 && num5 <= num3 && num5 <= num4){
        min = num5;
    }

    printf("Maximum number is: %g\n", max);
    printf("Minimum number is: %g\n", min);
    printf("Difference between maximum and minimum is %g\n",max-min);
}
/**
 *  void bmi_calculation ()
 *  
 *  The function take height and weight datas
 *  from user as input and calculate BMI. 
 *  
 *  - BMI = weight(kg) / ℎ𝑒𝑖𝑔ℎ𝑡^2(𝑚) -
 * 
*/
void bmi_calculation (){
    double height, weight, BMI;

    /*function menu on the console*/
    printf("\n\n------------------------------\n");
    printf("          ...bmi...\n");
    printf("------------------------------\n");
    
    /*height and weight inputs*/
    printf("please enter your height (as meter):");
        scanf("%lg",&height);
    printf("please enter your weight (as kilogram):");
        scanf("%lg",&weight);

    /*bmi calculation*/
    BMI = weight / (height * height);

    /*printing and categorization of obtained datas*/
    if (BMI < 16.0){
        printf("Your Category: Severely Underweight\n");
    }   
    else if (BMI >= 16.0 && BMI <= 18.49){
        printf("Your Category: Underweight\n");
    }    
    else if (BMI >= 18.5 && BMI <= 24.99 ){
        printf("Your Category: Normal\n");
    }   
    else if (BMI >= 25.0 && BMI <= 29.99){
        printf("Your Category: Overweight\n");
    }
    else if (BMI >= 30.0){
        printf("Your Category: Obese\n");
    }
}