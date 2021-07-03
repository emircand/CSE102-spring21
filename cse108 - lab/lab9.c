/** 
 *         *LAB - 09* 
 * File:    1901042674.C 
 * 
 * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * Date:    Spring 2021  
 * Course:  CSE108 - LAB 
 * 
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float m;
}line;

typedef struct 
{
    float midterm;
    float final;
    float homework;
}grades;

typedef struct 
{
    char name[20];
    char surname[20];
    int id;
    grades marks;
}students;

typedef struct
{
    char name[20];
    char *platform[20];
}games;


void stu_ave(students *info, int n)
{
    int i;
    float sum_midterm = 0, sum_final = 0, sum_homework = 0; 
    for (i = 0; i < n; i++)
    {
        /*this loop counts the average of all students average grades for different grade types..*/
        sum_midterm = sum_midterm + info[i].marks.midterm;
        sum_final = sum_final + info[i].marks.final;
        sum_homework = sum_homework + info[i].marks.homework;
    }
    /*print averages*/
    printf("average of midterms: %.2f\n", sum_midterm/n);
    printf("average of finals: %.2f\n", sum_final/n);
    printf("average of homework: %.2f\n", sum_homework/n);
}

void find_stu(students *info, int n)
{
    int i, ex_id, flag=0;
    printf("enter number to search: ");
    scanf("%d", &ex_id);

    for (i = 0; i < n; i++)
    {
        if (ex_id == info[i].id)
        {
            flag = 1;
            break;
        }
    }
    /*if id not foundi print error message*/
    if (flag == 0)
    {
        printf("student cannot found...\n");
    }
    /*if id found print data of student.*/
    else if(flag == 1)
    {
        printf("%s %s %d\n\n", info[i].name, info[i].surname, info[i].id);
    }
}
void find_slope_y3(line *info)
{
    /*m = y2-y1 / x2-x1*/
    info->m = (info->y2 - info->y1) / (info->x2 - info->x1);
    /*y3 = m * (x3-x2) + y2*/
    info->y3 = info->m * (info->x3 - info->x2) + info->y2;
}



int main()
{
    int n, i, j, number_games, number_platforms;
    line slope;
    

    /*part 1*/
    printf("enter x1: ");
    scanf("%f", &slope.x1);
    printf("enter y1: ");
    scanf("%f", &slope.y1);
    printf("enter x2: ");
    scanf("%f", &slope.x2);
    printf("enter y2: ");
    scanf("%f", &slope.y2);
    printf("enter x3: ");
    scanf("%f", &slope.x3);
    find_slope_y3(&slope);
    printf("%.2f\n", slope.m);
    printf("%.2f\n", slope.y3);
    
    /*part 2*/
    /*take number of students*/
    printf("enter number of students: ");
    scanf("%d", &n);
    /*create array of struct*/
    students stu[n];

    for (i = 0; i < n; i++)
    {
        /*take inputs from user...*/
        printf("enter name: ");
        scanf("%s", stu[i].name);
        printf("enter surname: ");
        scanf("%s", stu[i].surname);
        printf("enter id: ");
        scanf("%d", &stu[i].id);
        printf("enter midterm: ");
        scanf("%f", &stu[i].marks.midterm);
        printf("enter final: ");
        scanf("%f", &stu[i].marks.final);
        printf("enter homework: ");
        scanf("%f", &stu[i].marks.homework);
    }
    /*call helper functions*/
    stu_ave(stu, n);
    find_stu(stu, n);

    /*part 3*/
    /*printf("enter number of games: ");
    scanf("%d", &number_games);
    games gamelist[number_games];

    for (i = 0; i < number_games; i++)
    {
        printf("enter name of the game: ");
        fflush(stdin);
        scanf("%[^\n]%*c", gamelist[i].name);
        printf("enter number of platforms for the game: ");
        scanf("%d", &number_platforms);
        for (j = 0; j < number_platforms; j++)
        {
            printf("enter platform: ");
            scanf("%s",gamelist[i].platform[j]);
            printf("%s",gamelist[i].platform[j]);
        }
        
    }*/
    
    
   
    

}

