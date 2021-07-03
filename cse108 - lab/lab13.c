#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct list{
    char country[20];
    char capital[20];
    int population;
    bool driving_side;
    struct list *next;
}node2;

typedef struct {
    char country[20];
    char capital[20];
    int population;
    bool driving_side;
}node1;

node2 * create_node(char *country_, char *capital_, int population_, bool drive_){
    /*allocate memory*/
    node2 * temp = malloc(sizeof(node2));
    /*assign parameters to sstruct*/
    strcpy(temp->country, country_);
    strcpy(temp->capital, capital_);
    temp->population = population_;
    temp->driving_side = drive_;
    /*next pointer will be null*/
    temp->next = NULL;
    return temp;
}

node2* add_end(node2 ** head, node2 * node_to_insert) {
    /*insert new elements at the head of the list*/
    node_to_insert -> next = * head;
    * head = node_to_insert;
    return node_to_insert;
}



int main(){
    FILE *fp_read, *fp_write;
    node1 *arr;

    int option, i, counter=0, temp, exit_con = 0;
    node1 *ap, *apb;
    node2 *iter, *head_list=NULL;

    fp_write = fopen("array.txt","wt");

    while (option != 5)
    {
        /*take input from user for menu operations*/
        printf("1: Enter new record\n2: Write to the file\n3: Read from the file\n4: Print the linked list\n5: Exit\n");
        printf("your choice: ");
        scanf("%d", &option);
        
        /*switch-case operation to reach menu*/
        switch (option)
        {
        case 1:
            exit_con = 0;
            while(exit_con != 1){
                counter++;
                ap = (node1 *)calloc(counter, sizeof(node1));
                for (i = 0; i < counter-1; i++)
                {
                    /*assign elements of apb to ap*/
                    ap[i] = apb[i];
                }
                printf("Country Name: ");
                fflush(stdin);/*clean the keyboard input*/
                scanf(" %[^\n]%*c", ap[counter-1].country); /*take a variable*/
                printf("Capital: ");
                fflush(stdin);/*clean the keyboard input*/
                scanf(" %[^\n]%*c", ap[counter-1].capital); /*take a variable*/
                printf("Population of %s: ",ap[counter-1].country);
                scanf("%d",&ap[counter-1].population);
                printf("Do people in %s drive on the right side? (Yes: 1, No:0): ", ap[counter-1].country);
                scanf("%d", &temp);

                if (temp == 1)
                {
                    ap[counter - 1].driving_side = true;
                }
                else ap[counter - 1].driving_side = false;

                /*keep apb for next operations..*/
                apb = ap; 
                printf("if you want to exit press 1, to continue press 0: ");
                scanf("%d", &exit_con);
            }   
            break;
        
        case 2:
            for (i = 0; i < counter; i++)
            {
                /*for loop to write elements of array to .txt*/
                if (ap[i].driving_side == 1) /*if bool variable is true print right, else print left*/
                {
                    fprintf(fp_write, "%s %s %d %s\n", apb[i].country, apb[i].capital, apb[i].population, "right");
                }
                else fprintf(fp_write, "%s %s %d %s\n", apb[i].country, apb[i].capital, apb[i].population, "left");

            }
            fclose(fp_write);
            break;
        case 3:
            fp_read = fopen("array.txt", "rt");
            int population_, temp_var;
            char country_[20], capital[20];
            bool drive_;
            for (i = 0; i < counter; i++)
            {
                iter = NULL;
                /*read from the file each line*/
                fscanf(fp_read, "%s %s %d %d\n", country_, capital, &population_, &temp_var);
                drive_ = temp;
                /*create and add to node*/
                iter = create_node(country_, capital, population_, drive_);
                add_end(&head_list, iter);
            }
            break;
        case 4:
            iter = head_list;
            /*if iter null, break*/
            while(iter != NULL)
            {
                /*print elements to console*/
                printf("Country: %-20s ", iter->country);
                printf("Capital: %-20s ", iter->capital);
                printf("Population : %-15d", iter->population);
                printf("Driving Side: ");
                if (iter->driving_side == 1)
                {
                    printf("right\n");
                }
                else printf("left\n");

                iter = iter->next;
            }
            fclose(fp_read);
            break;
        case 5:
            printf("have a good day..\n");
            break;
        default:
            printf("invalid entry..\n");
            break;
        }
    }
    free(head_list);
    return 0;
}