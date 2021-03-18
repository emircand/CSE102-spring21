/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include "hw2_lib.h"
#include <math.h>


/*one year is 365.242199 days without rounding.*/
#define days_of_one_year 365.242199 



int find_weekday_of_data(int day, int month, int year)
{
    /*
    *Tomohiko Sakamoto’s Algorithm - Finding the day of the week
    * */
    int WeekDayofDate=-1, flag=0; 
    /*key values for every month*/
    int MonthKey[]={0,3,2,5,0,3,5,1,4,6,2,4};
    
    /*conditions for preventing the wrong date entries.*/
    if (month < 1 || month > 12)
    {
        printf("!!!invalid date!!!\n");
    }
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12) && (day > 31 || day < 1))
    {
        printf("!!!invalid date!!!\n");
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
    {
        printf("!!!invalid date!!!\n");
    }
    else if (year % 4 != 0 && month == 2 && (day > 28 || day < 1))
    {
        printf("!!!invalid date!!!\n");
    }
    else if (year % 4 == 0 && month == 2 && (day > 29 || day < 1))
    {
        printf("!!!invalid date!!!\n");
    }

    else
    {
        /*if month is january or february, substract 1 from year. (rule of the algorithm)*/
        if(month < 3){
            year = year - 1;
        }
        /*Monday is 1, Tuesday is 2,..., Sunday is 7
        * check for leap year and necessary calculations according to the algorithm.
        */
        WeekDayofDate = (year + year/4 - year/100 + year/400 + MonthKey[month - 1] + day - 1) % 7 +1; 
    } 
    /*in conditions of invalid dates, function returns value of -1*/
    return WeekDayofDate;
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
    int Years, Months, Days, day_diff=-1, check1, check2;
    
    /*using find_weekday_of_data function for preventing invalid date entries*/
    check1 = find_weekday_of_data(start_day,start_month,start_year);
    check2 = find_weekday_of_data(end_day,end_month,end_year);
    if (check2 == -1 || check1 ==-1)
    {
        printf("!!!invalid date!!!\n");
    }
    /*conditions for correct subtraction*/
    else{  
        if (end_month < start_month){
        end_month = end_month + 12;
        }
       if ( end_day < start_day ){
           end_day = end_day + 30;
        }
        /*date subtraction*/
        Years = end_year - start_year;
        Months = end_month - start_month;
        Days = end_day - start_day;

        /*converting years and months to days, and counting days between dates*/ 
        day_diff =  (Years * days_of_one_year) + (Months * days_of_one_year/12) + Days;
    } 
    /*in conditions of invalid dates, function returns value of -1*/
    return day_diff;
}


double find_angle(double a, double b, double c)
{
    double angle, Vb, Vc;
    /*calculations to find median lengths*/
    Vb = 2*sqrt((c*c + a*a - b*b/2)/2)/3;
    Vc = 2*sqrt((a*a + b*b - c*c/2)/2)/3;
	/*after applying the cos law, the program turns angle value in radians. */
    angle = acos((a*a - Vb*Vb - Vc*Vc)/(-2 * Vb * Vc));
    return angle;
}
/*the function which is creating a frame for the table*/
void print_border(char border){
    int i;
    for ( i = 0; i < 49; i++)
    {
        printf("%c",border);
    }
    printf("\n");
}

void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
    int i,j;
    
    /*functions for the header row*/
    print_border(border);
    printf("|   ROW101   |  ROW ABCDEFG |   ROW XYZ123      |\n");
    print_border(border);

    /*functions for the rows which are including data*/
    for ( i = 0; i < 3; i++)
    {
         if(i==0){
                printf("|%5u\t\t*%-.2g\t\t*%-6d    \t|\n",r11,r12,r13);
                print_border(border);
            }
         if(i==1){
                printf("|%5u\t\t*%-.2g\t\t*%-6d    \t|\n",r21,r22,r23);
                print_border(border);
            }
         if(i==2){
                printf("|%5u\t\t*%-.2g\t\t*%-6d    \t|\n",r31,r32,r33);
                print_border(border);
            }          
    }    
}


