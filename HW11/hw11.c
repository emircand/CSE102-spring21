/** 
 *          *HOMEWORK-11*
 * File:    1901042674.C 
 * 
 * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * Date:    Spring 2021  
 * Course:  CSE102 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*global variables for dynamic allocation*/
#define N 256 
int count = 0;
int delete_count = 0;

/*Movie_Budget struct which keeps budget, year and name variables.*/
typedef struct type1 {
    int budget, year;
    char * name;
    struct type1 * next;
} Movie_Budget;

/*Movie_Name struct which keeps score, genre and name variables.*/
typedef struct type2 {
    double score;
    char * name, * genre;
    struct type2 * next;
} Movie_Name;

double ave_find (Movie_Name *head){
    /*pointer to head of the list*/
    Movie_Name *iter=head;
    double sum = 0.0;
    while (iter->next != NULL)
    {
        /*sum of all scores in the list*/
        sum = sum + iter->score;
        /*reach every element of list*/
        iter = iter->next;
    }
    return sum / (count - delete_count);
}

/*swap function for Movie_Budget type*/
Movie_Budget * swap_budget(Movie_Budget * ptr1, Movie_Budget * ptr2) {
    Movie_Budget * tmp = ptr2 -> next;
    ptr2 -> next = ptr1;
    ptr1 -> next = tmp;
    return ptr2;
}

/*swap function for Movie_Name type*/
Movie_Name * swap_name(Movie_Name * ptr1, Movie_Name * ptr2) {
    Movie_Name * tmp = ptr2 -> next;
    ptr2 -> next = ptr1;
    ptr1 -> next = tmp;
    return ptr2;
}

/*find budget and return*/
Movie_Budget * search_budget(char * name_name, Movie_Budget * head_budget) {
    Movie_Budget * temp = head_budget;

    while (temp != NULL) {
        /*if name found, break the loop and return temp*/
        if (strcmp(temp -> name, name_name) == 0) {
            break;
        } else temp = temp -> next;
    }
    return temp;
}

/*find name and return*/
Movie_Name * search_name(char * budget_name, Movie_Name * head_name) {
    Movie_Name * temp = head_name;

    while (temp != NULL) {
        /*if name found, break the loop and return temp*/
        if (strcmp(temp -> name, budget_name) == 0) {
            break;
        } else temp = temp -> next;
    }
    return temp;
}

/*print Movie_Name data types*/
void printlist_score(Movie_Name * head_name, Movie_Budget * head_budget, float belowlimit, float upperlimit) {
    Movie_Name * temp_name = head_name;
    Movie_Budget * temp_budget, * search_ = head_budget;
    int flag = 0;
    printf("----------------------------------------------------------\n");
    while (temp_name != NULL) {
        /*limits to print elements of list.*/
        if (temp_name->score >= belowlimit && temp_name->score <= upperlimit) {
            flag = 1;
            /*find budget and print budget too*/
            temp_budget = search_budget(temp_name -> name, search_);
            if (temp_budget -> budget == 0) {
                printf("%-14s ", "unknown");
            } else printf("%-14d ", temp_budget -> budget);

            printf("%-20s ", temp_name -> genre);
            printf("%-55s ", temp_budget -> name);
            printf("%-10.1f ", temp_name -> score);
            printf("%-4d ", temp_budget -> year);
            printf("\n");
        }
        temp_name = temp_name -> next;
    }
    if (flag == 0) printf("no films were found in the range...\n");
}

void printlist_allname(Movie_Name * head_name, Movie_Budget * head_budget, int belowlimit, int toplimit) {
    Movie_Name * temp_name = head_name;
    Movie_Budget * temp_budget, * search_ = head_budget;
    int i=1, flag = 0;

    printf("----------------------------------------------------------\n");
    while (temp_name != NULL) {
        /*limits to print elements of list.*/
        if (i >= belowlimit && i <= toplimit) {
            flag = 1;
            /*find budget and print budget too*/
            temp_budget = search_budget(temp_name -> name, search_);
            if (temp_budget -> budget == 0) {
                printf("%-14s ", "unknown");
            } else printf("%-14d", temp_budget -> budget);

            printf("%-20s ", temp_name -> genre);
            printf("%-55s ", temp_budget -> name);
            printf("%-10.1f ", temp_name -> score);
            printf("%-4d ", temp_budget -> year);
            printf("\n");
            if (belowlimit == toplimit && i == toplimit) break;
        }
        i++;
        temp_name = temp_name -> next;
    }
    if (flag == 0) printf("invalid line or interval values..\n");
}

/*print Movie_Budget data types*/
void printlist_allbudget(Movie_Name * head_name, Movie_Budget * head_budget, int belowlimit, int toplimit) {
    Movie_Name * temp_name, * search_ = head_name;
    Movie_Budget * temp_budget = head_budget;
    int i=1, flag = 0;

    printf("----------------------------------------------------------\n");
    while (temp_budget != NULL) {
        /*limits to print elements of list.*/
        if (i >= belowlimit && i <= toplimit) {
            flag = 1;
            /*find name and print name too*/
            temp_name = search_name(temp_budget -> name, search_);
            if (temp_budget -> budget == 0) {
                printf("%-14s ", "unknown");
            } else printf("%-14d ", temp_budget -> budget);

            printf("%-20s ", temp_name -> genre);
            printf("%-55s ", temp_budget -> name);
            printf("%-10.1f ", temp_name -> score);
            printf("%-4d ", temp_budget -> year);
            printf("\n");
            if (belowlimit == toplimit && i == toplimit) break;
        }
        /*reach all elements of linked list*/
        i++;
        temp_budget = temp_budget -> next;
    }
    if (flag == 0) printf("invalid line or interval..\n");
    
}

void printlist_budget(Movie_Name * head_name, Movie_Budget * head_budget, int belowlimit, int upperlimit) {
    Movie_Name * temp_name, * search_ = head_name;
    Movie_Budget * temp_budget = head_budget;
    int flag = 0;

    printf("----------------------------------------------------------\n");
    while (temp_budget != NULL) {
        /*limits to print elements of list.*/
        if (temp_budget->budget >= belowlimit && temp_budget->budget <= upperlimit) {
            flag = 1;
            /*find name and print name too*/
            temp_name = search_name(temp_budget -> name, search_);
            if (temp_budget -> budget == 0) {
                printf("%-14s ", "unknown");
            } else printf("%-14d ", temp_budget -> budget);

            printf("%-20s ", temp_name -> genre);
            printf("%-55s ", temp_budget -> name);
            printf("%-10.1f ", temp_name -> score);
            printf("%-4d ", temp_budget -> year);
            printf("\n");
        }
        /*reach all elements of linked list*/
        temp_budget = temp_budget -> next;
    }
    if (flag == 0) printf("no films were found in the range...\n");
}
/*print Movie_Budget data types*/
void printlist_year(Movie_Name * head_name, Movie_Budget * head_budget, int belowlimit, int upperlimit) {
    Movie_Name * temp_name, * search_ = head_name;
    Movie_Budget * temp_budget = head_budget;
    int flag=0;

    printf("----------------------------------------------------------\n");
    while (temp_budget != NULL) {
        /*limits to print elements of list.*/
        if (temp_budget->year >= belowlimit && temp_budget->year <= upperlimit) {
            flag = 1;
            /*find name and print name too*/
            temp_name = search_name(temp_budget -> name, search_);
            if (temp_budget -> budget == 0) {
                printf("%-14s ", "unknown");
            } else printf("%-14d ", temp_budget -> budget);

            printf("%-20s ", temp_name -> genre);
            printf("%-55s ", temp_budget -> name);
            printf("%-10.1f ", temp_name -> score);
            printf("%-4d ", temp_budget -> year);
            printf("\n");
        }
        /*reach all elements of linked list*/
        temp_budget = temp_budget -> next;
    }
    if (flag == 0) printf("no films were found in the range...\n");
}

/*print menu on the console*/
void list_operations() {
    printf("----------------------------------------------------------\n");
    printf("1. List of the Sorted Data\n");
    printf("2. List of the Genres\n");
    printf("3. List of the Movies Through the Years\n");
    printf("4. List of the Movies Through the Scores\n");
    printf("5. All Information of a Single Movie\n");
    printf("6. Average of the IMDB Scores\n");
    printf("7. Frequence of the Genres\n");
    printf("8. Exit\n");
}

/*count and return number of the '\n' charachters in the text*/
int counter_f(FILE * read) {
    char ch;
    int counter = 0;
    /*take first char out of the loop to control feof.*/
    ch = fgetc(read);

    while (!feof(read)) {
        if (ch == '\n') {
            counter++; /*if ch == '\n', counter will increase*/
        }
        ch = fgetc(read); /*take a new char until feof*/
    }
    return counter;
}

Movie_Budget * insert_budget(Movie_Budget ** head, Movie_Budget * node_to_insert) {
    /*insert new elements at the head of the list*/
    node_to_insert -> next = * head;
    * head = node_to_insert;
    return node_to_insert;
}

Movie_Budget * create_new_budget(int budget, char * name, int year) {
    Movie_Budget * result = malloc(sizeof(Movie_Budget)); /*allocate memory*/
    /*assign parameters to struct*/
    result -> budget = budget;
    result -> name = malloc(strlen(name) + 1); /*allocate memory for name string*/
    strcpy(result -> name, name);
    result -> year = year;
    result -> next = NULL;
    return result;
}

Movie_Name * insert_at_head_name(Movie_Name ** head, Movie_Name * node_to_insert) {
    /*insert new elements at the head of the list*/
    node_to_insert -> next = * head;
    * head = node_to_insert;
    return node_to_insert;
}

Movie_Name * create_new_name(char * genre, char * name, float score) {
    Movie_Name * result = malloc(sizeof(Movie_Name)); /*allocate memory*/
    /*assign parameters to struct*/
    result -> score = score;
    result -> name = malloc(strlen(name) + 1); /*allocate memory for name string*/
    strcpy(result -> name, name);
    result -> genre = malloc(strlen(genre) + 1); /*allocate memory for genre string*/
    strcpy(result -> genre, genre);
    result -> next = NULL;
    return result;
}
void sorting_year_descending(Movie_Budget ** head, int limit) {
    Movie_Budget ** temp;
    Movie_Budget * p1, * p2;
    int i, j, swapi_;

    /*bubble sort alghoritm to sorting by year in ascending order*/
    for (i = 0; i <= (limit - delete_count); i++) {
        /*assign head to temp in every step*/
        temp = head;
        swapi_ = 0; /*swap control variable*/

        for (j = 0; j < (limit - delete_count) - i - 1; j++) {
            /*create two pointer in temp list*/
            p1 = * temp;
            p2 = p1 -> next;

            if ((p1 -> year < p2 -> year) || (p1 -> year == p2 -> year && p1 -> budget < p2 -> budget)) {

                /* update the link after swapping */
                * temp = swap_budget(p1, p2);
                swapi_ = 1;
            }
            /*move on the list*/
            temp = & ( * temp) -> next;
        }
        /* break if the loop ended without any swap */
        if (swapi_ == 0)
            break;
    }

}

void sorting_year(Movie_Budget ** head, int limit) {
    Movie_Budget ** temp;
    Movie_Budget * p1, * p2;
    int i, j, swapi_;

    /*bubble sort alghoritm to sorting by year in ascending order*/
    for (i = 0; i <= (limit - delete_count); i++) {
        /*assign head to temp in every step*/
        temp = head;
        swapi_ = 0; /*swap control variable*/

        for (j = 0; j < (limit - delete_count) - i - 1; j++) {
            /*create two pointer in temp list*/
            p1 = * temp;
            p2 = p1 -> next;

            if ((p1 -> year > p2 -> year) || (p1 -> year == p2 -> year && p1 -> budget > p2 -> budget)) {

                /* update the link after swapping */
                * temp = swap_budget(p1, p2);
                swapi_ = 1;
            }
            /*move on the list*/
            temp = & ( * temp) -> next;
        }
        /* break if the loop ended without any swap */
        if (swapi_ == 0)
            break;
    }

}

void sorting_budget(Movie_Budget ** head) {
    Movie_Budget ** temp;
    Movie_Budget * p1, * p2;
    int i, j, swapi_;

    /*bubble sort alghoritm to sorting by budget in ascending order*/
    for (i = 0; i <= (count - delete_count); i++) {
        /*assign head to temp in every step*/
        temp = head;
        swapi_ = 0;

        for (j = 0; j < (count - delete_count) - i - 1; j++) {
            /*create two pointer in temp list*/
            p1 = * temp;
            p2 = p1 -> next;

            if (p1 -> budget > p2 -> budget) {

                /* update the link after swapping */
                * temp = swap_budget(p1, p2);
                swapi_ = 1;
            }
            /*move on the list*/
            temp = & ( * temp) -> next;
        }
        /* break if the loop ended without any swap */
        if (swapi_ == 0)
            break;
    }
}

void sorting_score(Movie_Name ** head) {
    Movie_Name ** temp;
    Movie_Name * p1, * p2;
    int i, j, swapi_;

    /*bubble sort alghoritm to sorting by score in ascending order*/
    for (i = 0; i <= (count - delete_count); i++) {
        /*assign head to temp in every step*/
        temp = head;
        swapi_ = 0;

        for (j = 0; j < (count - delete_count) - i - 1; j++) {
            /*create two pointer in temp list*/
            p1 = * temp;
            p2 = p1 -> next;

            if (p1 -> score > p2 -> score) {
                /* update the link after swapping */
                * temp = swap_name(p1, p2);
                swapi_ = 1;
            }
            /*move on the list*/
            temp = & ( * temp) -> next;
        }
        /* break if the loop ended without any swap */
        if (swapi_ == 0)
            break;
    }
}

void sorting_name(Movie_Budget ** head) {
    Movie_Budget ** temp;
    Movie_Budget * p1, * p2;
    int i, j, swapi_;

    /*bubble sort alghoritm to sorting by name in ascending (a to z) order*/
    for (i = 0; i <= (count - delete_count); i++) {
        /*assign head to temp in every step*/
        temp = head;
        swapi_ = 0;

        for (j = 0; j < (count - delete_count) - i - 1; j++) {
            /*create two pointer in temp list*/    
            p1 = * temp;
            p2 = p1 -> next;

            if (strcmp(p1 -> name, p2 -> name) > 0) {

                /* update the link after swapping */
                * temp = swap_budget(p1, p2);
                swapi_ = 1;
            }
            /*move on the list*/
            temp = & ( * temp) -> next;
        }
        /* break if the loop ended without any swap */
        if (swapi_ == 0)
            break;
    }
}

void sorting_genre(Movie_Name ** head) {
    Movie_Name ** temp;
    Movie_Name * p1, * p2;
    int i, j, swapi_;

    /*bubble sort alghoritm to sorting by genre in ascending (a to z) order*/
    for (i = 0; i <= (count - delete_count); i++) {
        /*assign head to temp in every step*/
        temp = head;
        swapi_ = 0;

        for (j = 0; j < (count - delete_count) - i - 1; j++) {
            /*create two pointer in temp list*/
            p1 = * temp;
            p2 = p1 -> next;

            if (strcmp(p1 -> genre, p2 -> genre) > 0) {

                /* update the link after swapping */
                * temp = swap_name(p1, p2);
                swapi_ = 1;
            }
            /*move on the list*/
            temp = & ( * temp) -> next;
        }
        /* break if the loop ended without any swap */
        if (swapi_ == 0)
            break;
    }
}

void list_by_score(Movie_Name * head) {
    int l_or_g, flag = 0;
    float in_score;
    Movie_Name * temp;
    temp = head;
    printf("enter a score: ");
    scanf("%f", & in_score);

    printf("less (0) or greater (1) %.1f: ", in_score);
    scanf("%d", & l_or_g);
    /*switch case operation to reach right menu*/
    switch (l_or_g) {
    case 0:
        while (temp != NULL) {
            if (temp -> score <= in_score) {
                flag = 1;
                /*if movie's score is in the interval, print movie's name to console*/
                printf("%-50s ", temp -> name);
                printf("\n");
            }
            temp = temp -> next;
        }
        break;
    case 1:
        while (temp != NULL) {
            if (temp -> score >= in_score) {
                flag = 1;
                /*if movie's score is in the interval, print movie's name to console*/
                printf("%-50s ", temp -> name);
                printf("\n");
            }
            temp = temp -> next;
        }
        break;

    default:
        printf("invalid choice... returning the submenu...\n");
        break;
    }
    /*if program not found a movie, print try again and call function again..*/
    if (flag == 0) {
        printf("try again...\n");
        list_by_score(head);
    }
}
void list_by_year(Movie_Budget * head) {
    int in_year, u_or_s, flag = 0;
    Movie_Budget * temp;
    temp = head;
    printf("enter a year: ");
    scanf("%d", & in_year);

    printf("until (0) or since (1) %d: ", in_year);
    scanf("%d", & u_or_s);

    switch (u_or_s) {
    case 0:
        while (temp != NULL) {
            if (temp -> year <= in_year) {
                flag = 1;
                /*if movie's year is in the interval, print movie's name to console*/
                printf("%-50s ", temp -> name);
                printf("\n");
            }
            temp = temp -> next;
        }
        break;
    case 1:
        while (temp != NULL) {
            if (temp -> year >= in_year) {
                flag = 1;
                /*if movie's year is in the interval, print movie's name to console*/
                printf("%-50s ", temp -> name);
                printf("\n");
            }
            temp = temp -> next;
        }
        break;

    default:
        printf("invalid choice... returning the submenu...\n");
        break;
    }
    /*if program not found a movie (when flag == 0), print try again and call function again..*/
    if (flag == 0) {
        printf("try again...\n");
        list_by_year(head);
    }
}

void single_movie(Movie_Budget * head_budget, Movie_Name * head_name) {
    char * name;
    int flag = 0;
    Movie_Budget * temp = head_budget;
    Movie_Name * temp_name, * search_ = head_name;

    name = malloc(sizeof(char) * 100); /*allocate memory for name string*/

    printf("please enter the name of the movie: ");
    fflush(stdin);/*clean the keyboard input*/
    scanf(" %[^\n]%*c", name); /*take a movie name to search*/

    while (temp != NULL) {
        if (strcmp(name, temp -> name) == 0) {
            /*if movie found, break the loop and exit from the list*/
            flag = 1;

            printf("budget: ");
            if (temp -> budget == 0) {
                printf(" %s\n", "unknown");
            } else printf(" %d\n", temp -> budget);
            /*search movie's other elements and print the console*/
            temp_name = search_name(temp -> name, search_);

            printf("genre : ");
            printf(" %-s\n", temp_name -> genre);
            printf("name  : ");
            printf(" %s\n", temp -> name);
            printf("score : ");
            printf(" %.1f\n", temp_name -> score);
            printf("year  : ");
            printf(" %d\n", temp -> year);
            break;
        }
        temp = temp -> next;
    }
    /*print error message in negative conditions*/
    if (flag == 0) {
        printf("the movie which you entered couldn't find in the list\n");
        single_movie(head_budget, head_name);
    }
    free(name);
}

void frequency_of_genres(Movie_Name * head, char ** genres, int genre_limit, int n) {
    int i, j, counter = 0;
    Movie_Name * tmp;
    for (i = 0; i < genre_limit; i++) {
        tmp = head;
        counter = 0;
        for (j = 0; j < n; j++) {
            /*if element of genres array and list of genre are same, counter will increase..*/
            if (strcmp(genres[i], tmp -> genre) == 0) {
                counter++;
            }
            tmp = tmp -> next;
        }
        /*print the frequence of selected genre..*/
        printf("%-10s: %d\n", genres[i], counter);
    }
}

/*print elements of genres array*/
void print_genres(char ** genres, int counter) {
    int i;
    for (i = 0; i < counter; i++) {
        printf("%s\n", genres[i]);
    }
}

/*if movie names appears twice, update the list with new one for budget type*/
Movie_Budget * delete_budget(Movie_Budget * head_budget, char * name) {
    Movie_Budget * temp;
    Movie_Budget * iter = head_budget;
    int limit = 0;

    while (iter -> next != NULL) {
        if (strcmp(iter -> next -> name, name) == 0) {
            /*list type is FILO so first appearence is new one, other appearences are old ones.*/
            if (limit != 0) {
                temp = iter -> next;
                iter -> next = iter -> next -> next;
                /*delete the node*/
                free(temp);
                limit++;
            } else limit++;
        } else iter = iter -> next;
    }
    return head_budget;
}

/*if movie names appears twice, update the list with new one for name type*/
Movie_Name * delete_name(Movie_Name * head_name, char * name) {
    Movie_Name * temp;
    Movie_Name * iter = head_name;
    int limit = 0;

    while (iter -> next != NULL) {
        if (strcmp(iter -> next -> name, name) == 0) {
            /*list type is FILO so first appearence is new one, other appearences are old ones.*/
            if (limit != 0) {
                temp = iter -> next;
                iter -> next = iter -> next -> next;
                /*delete the old node*/
                free(temp);
                delete_count++;
                limit++;
            } else limit++;
        } else iter = iter -> next;
    }
    return head_name;
}

int main() {
    FILE * fptr;
    Movie_Budget * head_budget = NULL, * temp_budget;
    Movie_Name * head_name = NULL, * temp_name;
    char * name, * genre, * budget, * year, * score, ** genres;
    double score_f, ave;
    int i, budget_i, year_i, operation, selection;
    int flag_genre, temp_genre = 0, j;

    int belowlimit, upperlimit, choice;
    double start, end;

    /*fill linked list from the text*/
    fptr = fopen("Movies.txt", "r");

    /*memory allocation for file reading*/
    name = malloc(sizeof(char) * N);
    genre = malloc(sizeof(char) * N);
    budget = malloc(sizeof(char) * N);
    year = malloc(sizeof(char) * N);
    score = malloc(sizeof(char) * N);
    /*memory allocation for 2D genres array and elements of this array*/
    genres = malloc(N * sizeof(char * ));
    for (i = 0; i < N; i++) {
        genres[i] = malloc(N * sizeof(char));
    }
    /*count new lines in the file and create a loop with return value*/
    count = counter_f(fptr);
    /*return cursor the top of the file*/
    fseek(fptr, 0, SEEK_SET);

    /*skip first line in the text*/
    fscanf(fptr, " %[^,],%[^,],%[^,],%[^,],%[^\n,]", budget, genre, name, score, year);

    for (i = 0; i < count; i++) {
        /*take ',' seperated strings with fscanf*/
        fscanf(fptr, "%[^,],%[^,],%[^,],%[^,],%[^\n,]", budget, genre, name, score, year);
        /*coverting strings to integer and float to list*/
        budget_i = atoi(budget);
        year_i = atoi(year);
        score_f = atof(score);
        /*keep name of genres*/
        flag_genre = 0;
        for (j = 0; j < temp_genre; j++) {
            if (strcmp(genres[j], genre) == 0) {
                flag_genre = 1;
                break;
            }
        }
        if (flag_genre == 0) {
            strcpy(genres[temp_genre], genre);
            temp_genre++;
        }
        /*create new node every step*/
        temp_budget = create_new_budget(budget_i, name, year_i);
        temp_name = create_new_name(genre, name, score_f);

        /*add new node to head in every step*/
        insert_budget( & head_budget, temp_budget);
        insert_at_head_name( & head_name, temp_name);


        /*update list if movie name repeats in the list*/
        head_budget = delete_budget(head_budget, temp_budget -> name);
        head_name = delete_name(head_name, temp_name -> name);

        /*sorting head_budget by year after every step of insertion, in descending order..*/
        sorting_year_descending( & head_budget, i);
    }
    /*program run until user press '8'*/
    while (operation != 8) {
        /*print the menu*/
        list_operations();
        printf("Please Select an Operation: ");
        scanf("%d", & operation);
        printf("----------------------------------------------------------\n");
        /*switch - case operations to reach functions with inputs from user.*/
        switch (operation) {
        case 1:
            printf("1.Budget\n2.Genre\n3.Name\n4.Score\n5.Year\n\nSelect Sorting Type: ");
            scanf("%d", & selection);
            switch (selection) {
            case 1:
                sorting_budget( & head_budget);
                printf("1. Single Choice\n2. Multiple Chocie\nPlease Select an Operation: ");
                scanf("%d", & choice);
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", & belowlimit);
                    printlist_allbudget(head_name, head_budget, belowlimit, belowlimit);
                    break;
                case 2:
                    printf("Enter start value: ");
                    scanf("%d", & belowlimit);
                    printf("Enter end value: ");
                    scanf("%d", & upperlimit);
                    printf("Movies between %d and %d, sorted by budget\n",belowlimit, upperlimit);
                    printlist_budget(head_name, head_budget, belowlimit, upperlimit);
                    break;
                default:
                    printf("invalid value: returning the submenu..\n");
                    break;
                }
                break;
            case 2:
                sorting_genre( & head_name);
                printf("1. Single Choice\n2. Multiple Chocie\nPlease Select an Operation: ");
                scanf("%d", & choice);
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", & belowlimit);
                    printlist_allname(head_name, head_budget, belowlimit, belowlimit);
                    break;
                case 2:
                    printf("Enter start value: ");
                    scanf("%d", & belowlimit);
                    printf("Enter end value: ");
                    scanf("%d", & upperlimit);
                    printf("Movies between %d and %d, sorted by genre\n",belowlimit, upperlimit);
                    printlist_allname(head_name, head_budget, belowlimit, upperlimit);
                    break;
                default:
                    printf("invalid value: returning the submenu..\n");
                    break;
                }
                break;
            case 3:
                sorting_name( & head_budget);
                printf("1. Single Choice\n2. Multiple Chocie\nPlease Select an Operation: ");
                scanf("%d", & choice);
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", & belowlimit);
                    printlist_allbudget(head_name, head_budget, belowlimit, belowlimit);
                    break;
                case 2:
                    printf("Enter start line: ");
                    scanf("%d", & belowlimit);
                    printf("Enter end line: ");
                    scanf("%d", & upperlimit);
                    printf("Movies between %d and %d, sorted by name\n",belowlimit, upperlimit);
                    printlist_allbudget(head_name, head_budget, belowlimit, upperlimit);
                    break;
                default:
                    printf("invalid value: returning the submenu..\n");
                    break;
                }
                break;
            case 4:
                sorting_score( & head_name);
                printf("1. Single Choice\n2. Multiple Chocie\nPlease Select an Operation: ");
                scanf("%d", & choice);
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", & belowlimit);
                    printlist_allname(head_name, head_budget, belowlimit, belowlimit);
                    break;
                case 2:
                    printf("Enter start value: ");
                    scanf("%lg", & start);
                    printf("Enter end value: ");
                    scanf("%lg", & end);
                    printf("Movies between %g and %g, sorted by score\n",start, end);
                    printlist_score(head_name, head_budget, start, end);
                    break;
                default:
                    printf("invalid value: returning the submenu..\n");
                    break;
                }
                break;
            case 5:
                sorting_year( & head_budget, count);
                printf("1. Single Choice\n2. Multiple Chocie\nPlease Select an Operation: ");
                scanf("%d", & choice);
                switch (choice) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", & belowlimit);
                    printlist_allbudget(head_name, head_budget, belowlimit, belowlimit);
                    break;
                case 2:
                    printf("Enter start value: ");
                    scanf("%d", & belowlimit);
                    printf("Enter end value: ");
                    scanf("%d", & upperlimit);
                    printf("Movies between %d and %d, sorted by year\n",belowlimit, upperlimit);
                    printlist_year(head_name, head_budget, belowlimit, upperlimit);
                    break;
                default:
                    printf("invalid value: returning the submenu..\n");
                    break;
                }
                break;
            default:
                printf("invalid option: returning the submenu..\n");
                break;
            }
            break;
        case 2:
            print_genres(genres, temp_genre);
            break;
        case 3:
            list_by_year(head_budget);
            break;
        case 4:
            list_by_score(head_name);
            break;
        case 5:
            single_movie(head_budget, head_name);
            break;
        case 6:
            /*print average scores of movies to the console*/
            printf("Average of IMDB scores: %.2f\n", ave_find(head_name));
            break;
        case 7:
            frequency_of_genres(head_name, genres, temp_genre, (count - delete_count));
            break;
        case 8:
            printf("have a good day...\n"); /*exit condition*/
            break;
        default:
            printf("TRY AGAIN!!!\n"); /*if input is invalid, the program prints error message..*/
            break;
        }
    }
    /*free memory*/
    free(name);
    free(genre);
    free(budget);
    free(year);
    free(score);
    free(genres);
    free(head_name);
    free(head_budget);
    /*close the file*/
    fclose(fptr);
    return 0;
}