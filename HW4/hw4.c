 /** 
  *         *HOMEWORK -4*
  * File:    1901042674.C 
  * 
  * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
  * Date:    Spring 2021  
  * Course:  CSE102 
  * 
  */

 #include<stdio.h>
 #include<math.h>

 /*global function declarations*/
void Write_Polynomial();
void Armstrong_Palindrome();
void Prime_Sum();

int main(){
    /*function calls*/
    Write_Polynomial();
    Armstrong_Palindrome();
    Prime_Sum();

    return 0;
}

/*local declarations*/
void Write_Polynomial(){
    int i, degree; 
    float coefficient;
    
    printf("\n------------------Polynomial-Write---------------------\n");
    printf("Enter your polynomial [n a_n a_n-1 a_n-2...a_0] : ");
    
    /*first input is not participated in the for loop.*/
        scanf("%d", &degree);
    
    printf("\np(x) = ");
    for ( i = degree; i >=0 ; i--)
    {   
        /*after first input, inputs taken in for-loop*/
            scanf(" %f", &coefficient);
        
        /*if statements for reel term values*/
        if (i == degree)
        {
            if (i == 1 &&  coefficient == 1)
                printf("x");
            else if (i == 1 &&  coefficient == -1)
                printf("-x");
            else if (i == 1 && (coefficient > 0 || coefficient < 0))
                printf("%.1fx",coefficient);
            else if (i == 0)
            {
                if (coefficient < 0 || coefficient > 0)
                    printf("%.1f",coefficient);
                else if (coefficient == 0)
                    printf("0");
            }
            else if (coefficient == 1)
                printf("x^%d",i);
            else if (coefficient == -1)
                printf("-x^%d",i);
            else if (coefficient > 0 || coefficient < 0)
                printf("%.1fx^%d",coefficient,i);
            else if (coefficient == 0)
                /*if coefficient value of degree is 0, degree will decrease 1*/
                degree = degree - 1;
        }
        else if (i==0)
        {
            if(coefficient < 0)
                printf("%.1f",coefficient);
            else if(coefficient > 0)
                printf("+%.1f",coefficient);
        }
        else if(i==1)
        {
            if (coefficient == -1)
                printf("-x");
            else if (coefficient == 1 )
                printf("+x");
            else if (coefficient < 0)
                printf("%.1fx",coefficient);
            else if (coefficient > 0)
                printf("+%.1fx",coefficient);
        }
        else if(i > 0)
        {
            if (coefficient == 1)
                printf("+x^%d",i);
            else if(coefficient > 0 )
                printf("+%.1fx^%d",coefficient,i);
            else if (coefficient == -1)
                printf("-x^%d",i);
            else if(coefficient < 0)
                printf("%.1fx^%d",coefficient,i);
        }
    }
    printf("\n");
}

void Armstrong_Palindrome(){
    int Armstrong_Result=0, input, Armstrong_num, Armstrong_flag, count = 0; 
    int Palindrome_reverse=0, Palindrome_num, Armstrong_Digit, Palindrome_flag, Palindrome_digit;
    char numeric;
    
    /*take an input*/
    printf("\n----------------Armstrong-Palindrome-------------------\n");
    printf("Please enter an integer number : ");
        scanf("%d", &input);
        numeric = getchar();

    while(input < 0 || (numeric != '\n'))
    {
        printf("!!invalid input!!\n");
        printf("Please enter an positive/numeric term : ");
        scanf("%d", &input);
        numeric = getchar();
    }
    /*variables which using in calculations*/
    Armstrong_num = input;
    Palindrome_num = input;

    /*counting digits of Armstrong_num*/
    for (count = 0; Armstrong_num > 0; count++)
    {
        Armstrong_num = Armstrong_num / 10;
    }
    
    Armstrong_num = input;
    /*while loop to calculate and control an armstrong number*/
    while (Armstrong_num >= 1){
        /*Armstrong_Digit to count cubes of digits mod(10)*/
        Armstrong_Digit = Armstrong_num % 10;      
        /*Armstrong number is a number that is equal to the sum of cubes of its digits*/
        Armstrong_Result = Armstrong_Result + (int) pow((double)Armstrong_Digit, (double)count);
        /*assigned new value of Armstrong_num*/
        Armstrong_num = Armstrong_num / 10;         
    }
    if (input == Armstrong_Result)
        Armstrong_flag = 1;
    else 
        Armstrong_flag = 0;
    
    
    /*palindrome numbers' reverses is equal to the original number.*/
    while (Palindrome_num >= 1)
    {
        /*Palindrome_Digit to count cubes of digits mod(10)*/
        Palindrome_digit = Palindrome_num % 10;
        /*counting reverse value of Palindrome_num*/
        Palindrome_reverse = (Palindrome_reverse * 10) + Palindrome_digit;
        /*diğer basamağa geçmek için sayıyı 10'a bölüyoruz*/
        Palindrome_num = Palindrome_num / 10;
    }
    
    /*if input is equal to the reverse of its, input is a palindrome number*/
    if (input == Palindrome_reverse)
        Palindrome_flag = 1;
    else
        Palindrome_flag = 0;
    
    /*if statement to print function's output*/
    printf("\n");
    if (Palindrome_flag == 1 && Armstrong_flag == 1){
        printf("This number is both Palindrome and Armstrong number.\n");
    }
    else if (Palindrome_flag == 0 && Armstrong_flag == 1){
        printf("This number is only Armstrong number.\n");
    }
    else if (Palindrome_flag == 1 && Armstrong_flag == 0){
        printf("This number is only Palindrome number.\n");
    }
    else if(Palindrome_flag == 0 && Armstrong_flag == 0){
        printf("This number does not satisfy any special cases\n");
    }
}

void Prime_Sum(){
    int Range_Start, Range_End, input1, input2;
    int i, j, flag=0, sum=0;
    char numeric1, numeric2;
    
    /*take inputs*/
    printf("\n--------------------Prime-Sum--------------------------\n");
    printf("Please enter first integer number : ");
        scanf("%d",&input1);
        numeric1 = getchar();
    printf("Please enter second integer number : ");
        scanf("%d",&input2);
        numeric2 = getchar();

    /*if input type is invalid, take input until it will be correct*/
    while((input1 < 0 || input2 < 0) || (numeric1 != '\n' || numeric2 != '\n'))
    {
        printf("!!invalid input!!\n");
        printf("Please enter first integer number : ");
            scanf("%d",&input1);
            numeric1 = getchar();
        printf("Please enter second integer number : ");
            scanf("%d",&input2);
            numeric2 = getchar();
    }

    /*compare inputs and assign lower to higher.*/
    if (input2 < input1)
    {
        Range_Start = input2;
        Range_End = input1;
    }
    else{
        Range_Start = input1;
        Range_End = input2;
    }

    /*for-loop to find prime numbers in the range*/
    for (i = Range_Start+1; i < Range_End; i++)
    {
        for ( j = 2; j < i; j++)
        {
            if (i == 2)
            {
                flag = 1;
                break;
            }
            else if (i % j == 0){
                flag = 0;
                break;
            }
            else 
                flag =1;
        }
        if (flag == 1)
            sum = sum + i;    
    }
    /*printing the output*/
    printf("\nSum of prime numbers between %d and %d : %d\n",Range_Start, Range_End, sum);
}