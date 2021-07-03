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
#include<string.h>

/*create struct*/
typedef struct
{
    char title[50];
    char author[50];
    char subject[50];
    int year;
}Book;

int main()
{
    Book *arr, *temp;
    // variable in functions..
    int counter=0;
    char title[50], author[50], subject[50];
    int selection, i, flag = 0, j;
    int option;
    printf("1. Add New Book\n2. List Books\n3. EXIT\n\n");
    printf("choose: ");
    scanf("%d",&option);

    /*menu on the console*/
    while (option != 3)
    {
    if (counter != 0)
    {
        printf("1. Add New Book\n2. List Books\n3. EXIT\n\n");
        printf("choose: ");
        scanf("%d",&option);
    }
    switch (option)
    {
        case 1:
            if(counter > 1) free(arr);
            arr = (Book *)calloc(counter, sizeof(Book*));
            printf("Title: ");
            fflush(stdin); // cleaning the keyboard inputs
            scanf("%[^\n]%*c", arr[counter].title);

            printf("Author: ");
            fflush(stdin); // cleaning the keyboard inputs
            scanf("%[^\n]%*c", arr[counter].author);

            printf("Subject: ");
            fflush(stdin); // cleaning the keyboard inputs
            scanf("%[^\n]%*c", arr[counter].author);

            printf("Year: ");
            scanf("%d", &arr[counter].year);
            counter++;
            /*call function recursively*/
            break;
        case 2:
            //print the menu
            printf("1. Get by Title\n");
            printf("2. Get by Author\n");
            printf("3. Get by Subject\n");
            printf("4. Sorted List by Year\n");
            printf("5. List All Books\n");
            printf("6. EXIT SUBMENU\n");
            //take selection from user
            printf("\nchoose: ");
            scanf("%d",&selection);
            switch (selection)
            {
            case 1:
                    printf("enter title to search: ");
                    fflush(stdin); // cleaning the keyboard inputs
                    scanf("%[^\n]%*c", title);
                for (i = 0; i < counter; i++)
                {
                    if (strcmp(arr[i].title, title) == 0)
                    {
                        flag = 1;
                        printf("Title => %s\n", arr[i].title);
                        printf("Author => %s\n", arr[i].author);
                        printf("Subject => %s\n", arr[i].subject);
                        printf("Year => %d\n", arr[i].year);
                        printf("----------------------------------\n");
                        break;
                    }
                }
                if(flag == 0){
                        printf("not found\n");
                    }
                break;
            case 2:
                printf("enter author to search: ");
                fflush(stdin); // cleaning the keyboard inputs
                scanf("%[^\n]%*c", author);
                for (i = 0; i < counter; i++)
                {
                    if (strcmp(arr[i].author, author) == 0)
                    {
                        flag = 1;
                        printf("Title => %s\n", arr[i].title);
                        printf("Author => %s\n", arr[i].author);
                        printf("Subject => %s\n", arr[i].subject);
                        printf("Year => %d\n", arr[i].year);
                        printf("----------------------------------\n");
                        break;
                    }
                }
                if(flag == 0){
                    printf("not found\n");
                }
                break;
            case 3:
                printf("enter subject to search: ");
                fflush(stdin); // cleaning the keyboard inputs
                scanf("%[^\n]%*c", subject);
                for (i = 0; i < counter; i++)
                {
                    if (strcmp(arr[i].subject, subject) == 0)
                    {
                        flag = 1;
                        printf("Title => %s\n", arr[i].title);
                        printf("Author => %s\n", arr[i].author);
                        printf("Subject => %s\n", arr[i].subject);
                        printf("Year => %d\n", arr[i].year);
                        printf("----------------------------------\n");
                        break;
                    }
                }
                if(flag == 0){
                    printf("not found\n");
                }
                break;
            
            case 5:
                for (i = 0; i < counter; i++)
                {
                    printf("Year => %d\n", arr[i].year);
                    printf("Title => %s\n", arr[i].title);
                    printf("Author => %s\n", arr[i].author);
                    printf("Subject => %s\n", arr[i].subject);
                    printf("----------------------------------\n");
                }
                break;
            case 6:
                printf("exit from the list.\n\n");
                break;
            
            default:
                break;
            }
            break;
        case 3:
            printf("exit....\n");
            break;
        default:
            printf("invalid option... try again\n");
            break;
        }
    }
return 0;
}