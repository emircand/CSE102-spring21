/** 
 *         *HOMEWORK - 9*
 * File:    1901042674.C 
 * 
 * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * Date:    Spring 2021  
 * Course:  CSE102 
 * 
 */

#include <stdio.h>

/*enumerated data type to seperate labels.
fill sequence with not_related value to block returning garbage value on sequence.
*/
typedef enum
{
    employee, retired, student, unemployed, other, not_related
}label_t;

/*data struct which stores customers' info*/
typedef struct
{
    char name[20];
    int age;
    label_t label;
}account_t;

/*swap function to implement row limitations and replacements on bank sequence*/
void swap(account_t info[], int i, int counter, int count_limit)
{
    account_t temp;
    int j=i;

    /**/
    if(info[i+1].label != not_related && counter > count_limit){
        do
        {
            temp = info[j];
            info[j] = info[j+1];
            info[j+1] = temp;
            j++;
        } while (info[j+1].label != not_related);
        /*recursively call and maintain the sequence*/
        swap(info, i-1, counter-1, count_limit);
    }
}


void control_sequence(account_t info[])
{
    /*
    0 label customer can join 5 times in a row, 
    1 label customer can join 3 times in row, 
    2 label customer can join 3 times in a row, 
    3 label customer can join 2 times in a row, 
    4 label customer can join 2 times in a row.
    */
   int counter=0, i=0; 

   while (i < 49 && info[i].label != not_related)
   {
       if(info[i].label == info[i+1].label)
       {
           /*
           art arda gelen label'lar birbirinin aynısıysa sayaç artar. 
           1 - 1 - 1 serisinde counter 2 döndürür. 
           0 - 0 - 0 - 0 serisinde counter 3 döndürür.
           */
           counter++;
           i++;
       }
       else if(info[i].label != info[i+1].label)
       {
           /*if different label comes consecutively, loop call swap function in true conditions*/
           if(info[i].label == 0)
           {
               swap(info, i, counter, 4);
           }
           else if(info[i].label == 1)
           {
               swap(info, i, counter, 2);
           }
           else if(info[i].label == 2)
           {
               swap(info, i, counter, 2);
           }
           else if(info[i].label == 3)
           {
               swap(info, i, counter, 1);
           }
           else if(info[i].label == 4)
           {
               swap(info, i, counter, 1);
           }
           counter = 0;
           i++;
       }
   }
}

void add_sequence(account_t info[])
{
    int count, j, i, flag;
    account_t temp;

    /*sorting sequence in order to priority of labels.*/ 
    for (i = 0; i < 49; i++)
    {
        for (j = 0; j < (49-i); j++)
        {
            if (info[j].label > info[j + 1].label)
            {
                temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            } 
        }
    }
    /*after sorting call control_sequence to check wanted conditions*/
    control_sequence(info);
}

/*this function prints the sequence*/
void print_sequence(account_t info[])
{
    int i;
    label_t sequence[51];
    printf("Current Sequence: ");
    for (i = 0; i < 51; i++)
    {
        /*condition to not print not_related value.*/
        if(info[i].label<5)
        printf("%u ", info[i].label);
    }
    printf("\n");
}

/*this function proceed the sequence. */
void proceed_sequence(account_t info[])
{
    int i;
    for (i = 0; i < 49 && info[i].label != not_related; i++)
    {
        info[i] = info[i+1];
    }
    info[49].label = not_related;
    print_sequence(info);
}

void add_account(account_t info[], int i)
{
    /*add_account function take inputs from console*/
    printf("Please enter the name of the customer : ");
    scanf("%s", info[i].name);
    printf("Please enter the age of the customer : ");
    scanf("%d", &info[i].age);
    printf("Please enter the label of the customer : ");
    scanf("%u", &info[i].label);
}

void show_account(account_t info[], int i)
{
    /*print the console proceeded label's name*/
    printf("Proceed customer is %s\n", info[i].name);
}

void account_operation(account_t info[], int i)
{
    int op;

    /*menu on the console*/
    printf("1 - Add Customer\n");
    printf("2 - Process Customer\n");
    printf("0 - to exit\n");
    scanf("%d", &op);

    if (op == 1) /*if op is equal 1, call add_account function*/
    {
        add_account(info, i);
        add_sequence(info);
        print_sequence(info);
        account_operation(info, i+1); /*recursively call menu options and functions.*/
    }
    else if(op == 2)
    {
        if (i > 0)
        {
            show_account(info, 0);
            proceed_sequence(info);
            account_operation(info, i+1);
        }
        else if(i == 0)
        {
            printf("There is not any customer in bank system sequence.\n"); 
            account_operation(info, i);
        }
    }
    else if(op == 0)
    {
        printf("the program has ended...\n");
    }
}

int main()
{
    account_t info[51];
    int i=0;
    
    /*fill sequence with not_related value to block returning garbage value on sequence.*/
    for (i = 0; i < 51; i++)
    {
        info[i].label = not_related;
    }
    /*function call*/
    account_operation(info, 0);
}