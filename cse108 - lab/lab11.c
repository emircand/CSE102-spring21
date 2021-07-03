#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    float number;
    char* name;
    struct node *next;
};

int counter = 0; /*to make bubble sorting*/

void insert_end(struct node **head, int val, float num, char* name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
    /*increase counter in every step*/
    counter++;
}

void printList_withLoop(struct node *head)
{
    //iterate the entire linked list and print the data with loop
    struct node* temp = head;
    
    while(temp != NULL)
    {
        printf("%d -> %f -> %s\n",temp->data, temp->number, temp->name);
        temp = temp->next;
    }
}

void printList_withRecursive(struct node *list) {
   
   //iterate the entire linked list and print the data with recursive
    struct node *temp = list;
    if(temp != NULL)
    {
        printf("%d -> %f -> %s\n",temp->data, temp->number, temp->name);
        printList_withRecursive(temp->next);
    }
}


void sortedInsert(struct node** head_ref, struct node* new_node)
{
   // Sort according to string into the node struct.
   // It's name is "name".
   // You will sort ascending order.
    struct node** temp;
    struct node *p1, *p2, *tmp;
    int i, j, swapped;

     /*increase counter in every step*/
    counter++;

    /* Make next of new node as head */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref) = new_node;

    for (i = 0; counter; i++) {
  
        temp = head_ref;
        swapped = 0;
  
        for (j = 0; j < counter - i - 1; j++) {
  
            p1 = *temp;
            p2 = p1->next;
  
            if (strcmp(p1->name, p2->name)>0) {
  
                /* update the link after swapping */
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
 
 
/* A utility function to create a new node */
struct node* newNode(int new_data, float num, char* name_)
{
    /* allocate node */
    struct node *new = (struct node*)malloc(sizeof(struct node)); 
    
    /* put in the data  */
    new->data = new_data;
    new->number = num;
    new->name = name_;
    new->next = NULL;

    return new;
}


bool search(struct node* head, int x)
{
    // Search according to "data" which defined in node struct.
	// You will control x number comparision with "data" which struct element.
    struct node *temp = head;
    int flag = 0;
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;  
}

int main()
{
    struct node *head = NULL;
    struct node* new_node;
    
    insert_end(&head,10,5.5,"hello1");
    insert_end(&head,20,5.5,"hello2");
    insert_end(&head,30,5.5,"hello3");

    printf("---------------------------\n");
    printf("Print List with Loop: \n");
    printList_withLoop(head);

    new_node = newNode(1,5.5, "a");
    sortedInsert(&head, new_node);
    
    new_node = newNode(3,5.5, "c");
    sortedInsert(&head, new_node);

    
    new_node = newNode(2,5.5, "d");
    sortedInsert(&head, new_node);
    
    new_node = newNode(2,5.5, "b");
    sortedInsert(&head, new_node);
    
    printf("---------------------------\n");
    printf("Print List with Recursive: \n");
    printList_withRecursive(head);
    
    printf("---------------------------\n");
    printf("Is 20 belong this linked list?: " );
    printf(search(head, 20) ? "YES \n" : "NO \n");
    
    printf("---------------------------\n");
    printf("Is 18 belong this linked list?: " );
    printf(search(head, 18) ? "YES \n" : "NO \n");
    return 0;
}