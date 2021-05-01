/** 
 *         *HOMEWORK -7*
 * File:    1901042674.C 
 * 
 * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * Date:    Spring 2021  
 * Course:  CSE102 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*global function declarations*/
void fix_spelling_error(char * dict_name, char * txt_name); /* pointer pointer to allow pointer to be changed */
void find_best_correction(FILE * reader, char word[99], char sub[99]);
int matchRate(char word[99], char sub[99]);

void fix_spelling_error2(char * dict_name, char * txt_name);
void find_best_correction2(FILE * reader, char word[99], char sub[99]);

int main() {
   /*assigning filenames to stings*/
   char dict_name[20] = "dictionary.txt", txt_name[20] = "text.txt";
   
   /*function call*/
   fix_spelling_error(dict_name, txt_name);

   /* bonus part: 
   *  fix_spelling_error2(dict_name, txt_name);
   */

  printf("Emircan Demirel - 1901042674\nprogram has finished\nPlease open Text File\n");

   return 0;
}

/*this function returns match ratio of two strings*/
int matchRate(char word[99], char sub[99]) {
   int i, flag = 0;

   for (i = 0; i < 99; i++) {
      /*if element is not same, flag increases*/
      if (word[i] != sub[i]) {
         flag++;
      }
   }
   return flag;
}
/*this function compares two strings and returns best match*/
void find_best_correction(FILE * reader, char word[99], char sub[99]) {
   char scanvalue[99], arr[2][99];
   int control, ch3, j = 0;

   rewind(reader);
   control = fscanf(reader, "%s", scanvalue);
   while (control != EOF) {
      control = fgetc(reader);
      ch3 = control;
      if (ch3 == ' ' || ch3 == '\n') {
         scanvalue[j] = '\0';
         j = 0;
         if (strlen(word) == strlen(scanvalue)) 
         {
            if (matchRate(word, scanvalue) == 0) /*if word is correct, sub will return correct value*/ 
            {
               strcpy(sub, scanvalue);
               break;
            } 
            else if (matchRate(word, scanvalue) == 1) 
            {
               strcpy(sub, scanvalue);
            }
         }
         memset(scanvalue, '\0', 99);
      } else {
         scanvalue[j++] = ch3;
      }
   }
}

void fix_spelling_error(char * dict_name, char * txt_name) {
   int i = 0, j = 0, ch1, ch2, control1, control2;
   char word[99], sub[99];
   FILE * reader, * changer;

   /*fill strings with '\0' to not make comparisons with garbage values*/
   memset(word, '\0', 99);
   memset(sub, '\0', 99);

   /*file open*/
   changer = fopen(txt_name, "r+");
   reader = fopen(dict_name, "r");

   /*function will work if file is not NULL*/
   if (changer != NULL && reader != NULL) {
      /*control statement for EOF situtation and take input from text*/
      control1 = fgetc(changer);
      ch1 = control1;
      while (control1 != EOF) {
         /*if char is not a letter, word string will be closed*/
         if (ch1 == ' ' || ch1 == ',' || ch1 == '/' || ch1 == '.' || ch1 == '-' || ch1 == '?' || ch1 == '"') {
            word[i] = '\0';
            i = 0;

            /*control statement for EOF situtation and take input from dictionary*/
            control2 = fgetc(reader);
            ch2 = control2;
            while (control2 != EOF) {
               control2 = fgetc(reader);
               ch2 = control2;

               /*if char is blank or new line, sub string will be closed*/
               if (ch2 == ' ' || ch2 == '\n') {
                  sub[j] = '\0';
                  j = 0;
                  /*conditions to compare and find match of word from dictionary*/
                  if (strlen(word) == strlen(sub)) {
                     if (matchRate(word, sub) == 1) {
                        /*searching continue in find_best_correction*/
                        find_best_correction(reader, word, sub);
                        /*move cursor back and overwrite it*/
                        fseek(changer, -(strlen(sub) + 1), SEEK_CUR);
                        /*print the best match to text*/
                        fprintf(changer, "%s", sub);
                        break; /*exit*/
                     }
                     if (matchRate(word, sub) == 0) {
                        break; /*if word is correct, skip*/
                     }
                  }
                  /*fill string with '\0'*/
                  memset(sub, '\0', 99);
               } else {
                  /*assign values to string*/
                  sub[j++] = ch2;
               }
            }
            /*fill string with '\0'*/
            memset(sub, '\0', 99);
            /*move cursor beginning of the file*/
            rewind(reader);
            memset(word, '\0', 99);
         } else if (ch1 >= 97 && ch1 <= 122) {
            /*assign values to string*/
            word[i++] = ch1;
         }
         /*take a new char from file*/
         control1 = fgetc(changer);
         ch1 = control1;
      }
      /*close files*/
      fclose(reader);
      fclose(changer);
   }

}

/*Bonus Part: Adopting functions to this part*/
void find_best_correction2(FILE * reader, char word[99], char sub[99]){
   char scanvalue[99], arr[2][99];
   int control, ch3, j = 0;

   rewind(reader);
   control = fscanf(reader, "%s", scanvalue);
   while (control != EOF) {
      control = fgetc(reader);
      ch3 = control;
      if (ch3 == ' ' || ch3 == '\n') {
         scanvalue[j] = '\0';
         j = 0;
         if (strlen(word) == strlen(scanvalue)) 
         {
            if (matchRate(word, scanvalue) == 0) 
            {
               strcpy(sub, scanvalue);
               break;
            } 
            else if (matchRate(word, scanvalue) == 2)
            {
               strcpy(sub, scanvalue);
            }
         }
         memset(scanvalue, '\0', 99);
      } 
      else 
      {
         scanvalue[j++] = ch3;
      }
   }
}

void fix_spelling_error2(char * dict_name, char * txt_name){
      int i = 0, j = 0, ch1, ch2, control1, control2;
   char word[99], sub[99];
   FILE * reader, * changer;

   /*fill strings with '\0' to not make comparisons with garbage values*/
   memset(word, '\0', 99);
   memset(sub, '\0', 99);

   /*file open*/
   changer = fopen(txt_name, "r+");
   reader = fopen(dict_name, "r");

   /*function will work if file is not NULL*/
   if (changer != NULL && reader != NULL) {
      /*control statement for EOF situtation and take input from text*/
      control1 = fgetc(changer);
      ch1 = control1;
      while (control1 != EOF) {
         /*if char is not a letter, word string will be closed*/
         if (ch1 == ' ' || ch1 == ',' || ch1 == '/' || ch1 == '.' || ch1 == '-' || ch1 == '?' || ch1 == '"') {
            word[i] = '\0';
            i = 0;

            /*control statement for EOF situtation and take input from dictionary*/
            control2 = fgetc(reader);
            ch2 = control2;
            while (control2 != EOF) {
               control2 = fgetc(reader);
               ch2 = control2;

               /*if char is blank or new line, sub string will be closed*/
               if (ch2 == ' ' || ch2 == '\n') {
                  sub[j] = '\0';
                  j = 0;
                  /*conditions to compare and find match of word from dictionary*/
                  if (strlen(word) == strlen(sub)) {
                     if (matchRate(word, sub) == 2) {
                        /*searching continue in find_best_correction*/
                        find_best_correction2(reader, word, sub);
                        /*move cursor back and overwrite it*/
                        fseek(changer, -(strlen(sub) + 1), SEEK_CUR);
                        /*print the best match to text*/
                        fprintf(changer, "%s", sub);
                        break; /*exit*/
                     }
                     if (matchRate(word, sub) == 0) {
                        break; /*if word is correct, skip*/
                     }
                  }
                  /*fill string with '\0'*/
                  memset(sub, '\0', 99);
               } else {
                  /*assign values to string*/
                  sub[j++] = ch2;
               }
            }
            /*fill string with '\0'*/
            memset(sub, '\0', 99);
            /*move cursor beginning of the file*/
            rewind(reader);
            memset(word, '\0', 99);
         } else if (ch1 >= 97 && ch1 <= 122) {
            /*assign values to string*/
            word[i++] = ch1;
         }
         /*take a new char from file*/
         control1 = fgetc(changer);
         ch1 = control1;
      }
      /*close files*/
      fclose(reader);
      fclose(changer);
   }
}