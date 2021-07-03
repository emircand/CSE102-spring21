/**
 * @file 1901042674.c
 * @author Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * @date 2021-06-15
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*global declarations of counter variables*/
int count_anto = 0, count_syno = 0;

/*linked list type which stores words*/
typedef struct s_a {
  char meaning[30];
  struct s_a * next;
}
syno_anto;

/*linked list for synonyms' list*/
typedef struct synonymlist {
  char word[30];
  int val;
  bool result;
  syno_anto * ptr;
  struct synonymlist * next;
}
synonym_t;

/*linked list for antonyms' list*/
typedef struct antonymlist {
  char word[30];
  int val;
  bool result;
  syno_anto * ptr;
  struct antonymlist * next;
}
antonym_t;

/*count number of the newlines in .txt files*/
int counter_newline(FILE * read) {
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

syno_anto * insert_syno_anto(syno_anto * head, syno_anto * node_to_insert) {
  /*insert new elements at the head of the list*/
  node_to_insert -> next = head;
  head = node_to_insert;
  return node_to_insert;
}

/*create new node for syno_anto linked list type*/
syno_anto * create_syno_anto(char * word) {
  syno_anto * result = malloc(sizeof(syno_anto));
  strcpy(result -> meaning, word);
  result -> next = NULL;
  return result;
}

synonym_t * insert_synonym_t(synonym_t ** head, synonym_t * node_to_insert) {
  /*insert new elements at the head of the list*/
  node_to_insert -> next = * head;
  * head = node_to_insert;
  return node_to_insert;
}

/*create new node for synonym linked list type*/
synonym_t * create_synonym_list(char * word, char( * synonyms)[25], int k) {
  synonym_t * result = malloc(sizeof(synonym_t));
  syno_anto * root = NULL, * iter;

  while (k >= 0) {
    /*store synonyms which recorded the file in linked list */
    iter = create_syno_anto(synonyms[k]);
    root = insert_syno_anto(root, iter);
    k--;
  }
  /*store main word in every line*/
  strcpy(result -> word, word);
  result -> ptr = root;
  /*
  the smaller a number, the more likely it is to be divided into any number.
  for this reason, those who have not been asked will be in a narrower and smaller range.
  */
  result -> val = rand() % 5 + 1;
  /*next pointer is null*/
  result -> next = NULL;
  return result;
}

antonym_t * insert_antonym_t(antonym_t ** head, antonym_t * node_to_insert) {
  /*insert new elements at the head of the list*/
  node_to_insert -> next = * head;
  * head = node_to_insert;
  return node_to_insert;
}

/*create new node for synonym linked list type*/
antonym_t * create_antonym_list(char * word, char( * synonyms)[25], int k) {
  antonym_t * result = malloc(sizeof(antonym_t));
  syno_anto * root = NULL, * iter;

  while (k >= 0) {
    /*store antonyms which recorded the file in linked list */
    iter = create_syno_anto(synonyms[k]);
    k--;
    root = insert_syno_anto(root, iter);
  }
  strcpy(result -> word, word);
  result -> ptr = root;
  /*
  the smaller a number, the more likely it is to be divided into any number.
  for this reason, those who have not been asked will be in a narrower and smaller range.
  */
  result -> val = rand() % 5 + 1;
  /*next pointer is null*/
  result -> next = NULL;

  return result;
}

void read_synonym_file(char * txt, synonym_t ** head_synonym) {
  FILE * fptr;
  synonym_t * temp;
  char word_[30], dummy[5], line[256], * take, synonyms[10][25];
  char delimit[] = " \t\r\n\v\f";
  int i, k = 0;

  /*open file*/
  fptr = fopen(txt, "rt");
  if (fptr == NULL) {
    /*if file cannot opened print error message on the console*/
    printf("read txt cannot opened...\n");
  } else {
    /*count newline and create loop*/
    count_syno = counter_newline(fptr);
    fseek(fptr, SEEK_SET, 0);
    for (i = 0; i < count_syno; i++) {
      /*take whole line*/
      fgets(line, 999, fptr);
      /*divide line to smal strings with the help of strtok func and delimiters*/
      take = strtok(line, delimit);
      strcpy(word_, take);
      take = strtok(NULL, delimit);
      strcpy(dummy, take);
      /*take synonyms until null, and store them in string array*/
      take = strtok(NULL, delimit);
      while (take != NULL) {
        strcpy(synonyms[k], take);
        k++;
        take = strtok(NULL, delimit);
      }
      /*create new node and add to head*/
      temp = create_synonym_list(word_, synonyms, k);
      * head_synonym = insert_synonym_t(head_synonym, temp);
      /*for new steps reset k variable*/
      k = 0;
    }
    /*close file*/
    fclose(fptr);
  }
}

void read_antonym_file(char * txt, antonym_t ** head_antonym) {
  FILE * fptr;
  antonym_t * temp;
  char word_[30], dummy[5], line[256], * take, antonyms[10][25];
  char delimit[] = " \t\r\n\v\f";
  int i, k = 0;
  /*open file*/
  fptr = fopen(txt, "rt");
  if (fptr == NULL) {
    /*if file cannot opened print error message on the console*/
    printf("read txt cannot opened...\n");
  } else {
    /*count newline and create loop*/
    count_anto = counter_newline(fptr);
    fseek(fptr, SEEK_SET, 0);
    for (i = 0; i < count_anto; i++) {
      /*take whole line*/
      fgets(line, 999, fptr);
      /*divide line to smal strings with the help of strtok func and delimiters*/
      take = strtok(line, delimit);
      strcpy(word_, take);
      take = strtok(NULL, delimit);
      strcpy(dummy, take);
      /*take antonyms until null, and store them in string array*/
      take = strtok(NULL, delimit);
      while (take != NULL) {
        strcpy(antonyms[k], take);
        k++;
        take = strtok(NULL, delimit);
      }
      /*create new node and add to head*/
      temp = create_antonym_list(word_, antonyms, k);
      * head_antonym = insert_antonym_t(head_antonym, temp);
      /*for new steps reset k variable*/
      k = 0;
    }
    /*close file*/
    fclose(fptr);
  }
}

void print_synonym_to_txt(synonym_t * head, char * txt) {
  synonym_t * iter = head;
  syno_anto * temp;

  FILE * fptr;

  /*open txt file in write mode*/
  fptr = fopen(txt, "w");
  /*traverse in the list and write every node in desired format*/
  while (iter != NULL) {
    fprintf(fptr, "%s = ", iter -> word);
    temp = iter -> ptr;
    while (temp != NULL && temp -> next != NULL) {
      fprintf(fptr, "%s ", temp -> meaning);
      temp = temp -> next;
    }
    /*next pointer*/
    iter = iter -> next;
    fprintf(fptr, "\n");
  }
  fclose(fptr);
}

void print_antonym_to_txt(antonym_t * head, char * txt) {
  antonym_t * iter = head;
  syno_anto * temp;

  FILE * fptr;
  /*open txt file in write mode*/
  fptr = fopen(txt, "w");
  /*traverse in the list and write every node in desired format*/
  while (iter != NULL) {
    fprintf(fptr, "%s <> ", iter -> word);
    temp = iter -> ptr;
    while (temp != NULL && temp -> next != NULL) {
      fprintf(fptr, "%s ", temp -> meaning);
      temp = temp -> next;
    }
    /*next pointer*/
    iter = iter -> next;
    fprintf(fptr, "\n");
  }
  fclose(fptr);
}

void get_antonym(antonym_t * head) {
  /*head->ptr is a pointer which keeps synonyms or antonyms list*/
  syno_anto * head_synolist = head -> ptr, * temp_synolist;
  char input[30];
  int flag = 0, button;
  /*take input from user*/
  printf("your answer: ");
  scanf("%s", input);
  /*traverse in the list and search exact match*/
  while (head_synolist != NULL) {
    if (strcmp(head_synolist -> meaning, input) == 0) {
      /*if true, print message on the console*/
      printf("CORRECT\n");
      flag = 1;
      break;
    } else {
      /*if false, go to next element of list*/
      if (head_synolist -> next != NULL) {
        head_synolist = head_synolist -> next;
      } else break;
    }
  }
  /*if user wrong print message on the console and ask the user if user wants to add his/her answer to the list*/
  if (flag == 0) {
    printf("WRONG\nif you want to add your answer to antonyms of %s press (1), else press (0)\n", head -> word);
    scanf("%d", & button);

    if (button == 1) {
      /*for words that are known correctly, randomly assign a number that is less likely to divide any number*/
      head -> val = rand() % 100 + 20;
      head -> result = true;
      temp_synolist = create_syno_anto(input);
      head -> ptr = insert_syno_anto(head -> ptr, temp_synolist);
    } else {
      /*for words that are not known by user, randomly assign a number that is more likely to divide any number*/
      head -> val = rand() % 5 + 5;
    }
  } else {
    /*for words that are known correctly, randomly assign a number that is less likely to divide any number*/
    head -> val = rand() % 100 + 20;
    head -> result = true;
  }
}

void random_choice_antonym(antonym_t * head) {
  int r, i;
  antonym_t * iter = head;

  while (iter -> next != NULL) {
    /*random number in every step (may cause an error)*/
    r = rand() % 100;
    if (r % iter -> val == 0) {
      /*print the word which is randomly accessed*/
      printf("What is the antonym of '%s'? \n", iter -> word);
      /*call the function to take input from user*/
      get_antonym(iter);
      break;
    }
    /*traverse in the list*/
    iter = iter -> next;
  }

}

void get_synonym(synonym_t * head) {
  syno_anto * head_synolist = head -> ptr, * temp_synolist;
  synonym_t * iter = head;
  char input[30];
  int flag = 0, button;

  /*take input from user*/
  printf("enter a synonym: ");
  scanf("%s", input);
  /*traverse in the list and search exact match*/
  while (head_synolist != NULL) {
    /*if true, print message on the console*/
    if (strcmp(head_synolist -> meaning, input) == 0) {
      printf("CORRECT\n");
      flag = 1;
      break;
    }
    /*if false, go to next element of list*/
    else {
      if (head_synolist -> next != NULL) {
        head_synolist = head_synolist -> next;
      } else break;
    }
  }
  /*if user wrong print message on the console and ask the user if user wants to add his/her answer to the list*/
  if (flag == 0) {
    printf("WRONG\nif you want to add your answer to synonyms of %s press (1), else press (0)\n", head -> word);
    scanf("%d", & button);

    if (button == 1) {
      /*for words that are known correctly, randomly assign a number that is less likely to divide any number*/
      head -> val = rand() % 100 + 20;
      head -> result = true;
      temp_synolist = create_syno_anto(input);
      head -> ptr = insert_syno_anto(head -> ptr, temp_synolist);
    } else {
      /*for words that are not known by user, randomly assign a number that is more likely to divide any number*/
      head -> result = false;
      iter -> val = rand() % 5 + 5;
    }
  } else {
    /*for words that are known correctly, randomly assign a number that is less likely to divide any number*/
    head -> val = rand() % 100 + 20;
    head -> result = true;
  }
}

void random_choice_synonym(synonym_t * head) {
  int r, i;
  synonym_t * iter = head;

  while (iter -> next != NULL) {
    /*we select a random number and divide it by the number in the list. 
    small numbers in the list are more likely to be divided into any number than large ones.
    the priority ranking is:
    1- not asked questions
    2- incorrectly answered questions
    3- correctly answered questions 
    */
    r = rand() % 100;
    if (r % iter -> val == 0) {
      /*print the word which is randomly accessed*/
      printf("What is the synonym of '%s'? \n", iter -> word);
      get_synonym(iter);
      break;
    }
    iter = iter -> next;
  }

}

void search_syno(synonym_t * head) {
  synonym_t * iter = head;
  syno_anto * new_syno;
  char word[30], input[30];
  int flag = 0;

  printf("enter a word from list to add new synonym: ");
  scanf("%s", word);

  while (iter != NULL) {
    if (strcmp(iter -> word, word) == 0) {
      printf("enter new synonym for %s: ", iter -> word);
      scanf("%s", input);
      /*create synonym struct type and insert head of the list*/
      new_syno = create_syno_anto(input);
      iter -> ptr = insert_syno_anto(iter -> ptr, new_syno);
      flag = 1;
      break;
    }
    iter = iter -> next;
  }
  if (flag == 0) {
    /*if word cannot found in the list, call function again*/
    printf("word cannot found in the list please try another word..\n");
    search_syno(head);
  }
}

void search_anto(antonym_t * head) {
  antonym_t * iter = head;
  syno_anto * new_anto;
  char word[30], input[30];
  int flag = 0;

  printf("enter a word from list to add new antonym: ");
  scanf("%s", word);

  while (iter != NULL) {
    if (strcmp(iter -> word, word) == 0) {
      printf("enter new antonym for %s: ", iter -> word);
      scanf("%s", input);
      /*create antonym struct type and insert head of the list*/
      new_anto = create_syno_anto(input);
      iter -> ptr = insert_syno_anto(iter -> ptr, new_anto);
      flag = 1;
      break;
    }
    iter = iter -> next;
  }
  if (flag == 0) {
    /*if word cannot found in the list, call function again*/
    printf("word cannot found in the list please try another word..\n");
    search_anto(head);
  }
}

void checkfile(char * username, synonym_t * head_syno, antonym_t * head_anto) {
  FILE * fp = fopen(username, "rb");
  synonym_t * iter_syno = head_syno, * tmp1;
  antonym_t * iter_anto = head_anto, * tmp2;
  int num, i;
  char word[30];

  if (fp == NULL) {
    printf("the user did not log in beforehand...\n");
  } else {
    /*read from binary file to synonym list*/
    for (i = 0; i < count_syno; i++) {
      fread(word, 30 * sizeof(char), 1, fp);
      fread( & num, sizeof(int), 1, fp);
      tmp1 = head_syno;
      if (strcmp(iter_syno -> word, word) != 0) {
        while (tmp1 != NULL) {
          if (strcmp(word, tmp1 -> word) != 0) {
            tmp1 = tmp1 -> next;
          } else break;
        }
      }
      if (num == 1) {
        /*change variables according to binary file*/
        tmp1 -> result = true;
        /*for words that are known correctly, randomly assign a number that is less likely to divide any number*/
        tmp1 -> val = rand() % 100 + 20;
      } else {
        /*change variables according to binary file*/
        tmp1 -> result = false;
        /*for words that are not known by user, randomly assign a number that is more likely to divide any number*/
        tmp1 -> val = rand() % 5 + 5;
      }
      iter_syno = iter_syno -> next;
    }
    /*read from binary file to antonym list*/
    for (i = 0; i < count_anto; i++) {
      fread(word, 30 * sizeof(char), 1, fp);
      fread( & num, sizeof(int), 1, fp);
      tmp2 = head_anto;
      if (strcmp(iter_anto -> word, word) != 0) {
        while (tmp2 != NULL) {
          if (strcmp(word, tmp2 -> word) != 0) {
            tmp2 = tmp2 -> next;
          } else break;
        }
      }
      if (num == 1) {
        /*change variables according to binary file*/
        tmp2 -> result = true;
        /*for words that are known correctly, randomly assign a number that is less likely to divide any number*/
        tmp2 -> val = rand() % 100 + 20;
      } else {
        /*change variables according to binary file*/
        tmp2 -> result = false;
        /*for words that are not known by user, randomly assign a number that is more likely to divide any number*/
        tmp2 -> val = rand() % 5 + 5;
      }
      iter_anto = iter_anto -> next;
    }
  }
  /*close file*/
  if (fp != NULL) fclose(fp);
}

void write_binary_file(char * username, antonym_t * head_anto, synonym_t * head_syno) {
  FILE * fp;
  synonym_t * iter_syno = head_syno;
  antonym_t * iter_anto = head_anto;
  int num;
  /*open file*/
  fp = fopen(username, "wb");
  /*traverse in synonyms list*/
  while (iter_syno != NULL) {
    /*write main word to list and write 1/0 according to bool operator.*/
    fwrite(iter_syno -> word, 30 * sizeof(char), 1, fp);
    if (iter_syno -> result == true) num = 1;
    else num = 0;
    fwrite( & num, sizeof(int), 1, fp);
    iter_syno = iter_syno -> next;
  }
  /*traverse in antonyms list*/
  while (iter_anto != NULL) {
    /*write main word to list and write 1/0 according to bool operator.*/
    fwrite(iter_anto -> word, 30 * sizeof(char), 1, fp);
    if (iter_anto -> result == true) num = 1;
    else num = 0;
    fwrite( & num, sizeof(int), 1, fp);
    iter_anto = iter_anto -> next;
  }
  /*close file*/
  fclose(fp);
}

int main() {
  int selection, q_sequence = 0;
  srand(time(NULL));
  char username[20];
  antonym_t * head_antonym = NULL, * temp_anto;
  synonym_t * head_synonym = NULL, * temp_syno;

  /*read txt files*/
  read_synonym_file("synonyms.txt", & head_synonym);
  read_antonym_file("antonyms.txt", & head_antonym);

  /*menu operations*/
  printf("enter username: ");
  scanf("%s", username);
  /*combine strings to create binary file*/
  strcat(username, ".worddat");

  /*read binary file and search user's data in file*/
  checkfile(username, head_synonym, head_antonym);

  while (selection != 4) {
    printf("------------------------------------\n");
    printf("#1. Question&Answer\n#2. Add a Synonym of a Word\n#3. Add an Antonym of a Word\n#4. Exit\n");
    printf("your choice: ");
    scanf("%d", & selection);
    printf("------------------------------------\n");

    switch (selection) {
    case 1:
      /*ask questions in a sequence*/
      if (q_sequence == 0) {
        /*call function to randomly select synonym*/
        random_choice_synonym(head_synonym);
        q_sequence = 1;
      } else {
        /*call function to randomly select antonym*/
        random_choice_antonym(head_antonym);
        q_sequence = 0;
      }
      break;
    case 2:
      /*call search_syno function to add new word*/
      search_syno(head_synonym);
      break;
    case 3:
      /*call search_anto function to add new word*/
      search_anto(head_antonym);
      break;
    case 4:
      /*update files*/
      print_antonym_to_txt(head_antonym, "antonyms.txt");
      print_synonym_to_txt(head_synonym, "synonyms.txt");
      write_binary_file(username, head_antonym, head_synonym);
      printf("have a good day\n");
      break;
    default:
      break;
    }
  }
  /*free the memory*/
  free(head_antonym);
  free(head_synonym);
  return 0;
}