/** 
  *         *LAB - 04* 
  * File:    1901042674.C 
  * 
  * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
  * Date:    Spring 2021  
  * Course:  CSE108 - LAB 
  * 
  */
#include<stdio.h>

 void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier);
 void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double b0);

 int main(){
    /*variable declarations*/
    unsigned int m1, m2;
    unsigned int *multiplicand= &m1, *multiplier=&m2;
    
    double p1_3, p1_2, p1_1, p1_0, p2_3, p2_2, p2_1, p2_0;
    double *a3 = &p1_3, *a2 = &p1_2, *a1 = &p1_1, *a0 = &p1_0; /*polinom katsayılarının adresi atandı*/
    double *b3 = &p2_3, *b2 = &p2_2, *b1 = &p2_1, b0;  /*polinom katsayılarının adresi atandı*/
    
    
    /*take inputs for multiplicand and multiplier variables*/
    printf("------------------------------------------\n");
    printf("enter a multiplicand: ");
    scanf("%u", &m1);
    
    printf("enter a multiplier: ");
    scanf("%u", &m2);

    /*function call*/
    russian_multiplication(multiplicand, multiplier);

    printf("%u is result of russian multiplication\n%u is last multiplier\n", m1, m2);

    printf("------------------------------------------\n");

    /*take inputs for coefficient variables*/
    printf("enter a first polynomial [a3,a2,a1,a0]: ");
    scanf("%lf %lf %lf %lf",&p1_3, &p1_2, &p1_1, &p1_0);
    printf("enter a first polynomial [b3,b2,b1,b0]: ");
    scanf("%lf %lf %lf %lf",&p2_3, &p2_2, &p2_1, &p2_0);
    b0=p2_0;
    /*function call*/
    multiply_polynomials(a3, a2, a1, a0, b3, b2, b1, b0);
    /*printing the function's output*/
    printf("(%.1fx^6) + (%.1fx^5) + (%.1fx^4) + (%.1fx^3) + (%.1fx^2) + (%.1fx) + (%.1f)\n", p1_3, p1_2, p1_1, p1_0, p2_3, p2_2, p2_1);
    return 0;
}

void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier){
    unsigned int result=0;
    while(*multiplier > 0)
    {                
        if(*multiplier % 2 != 0)
        {
            result = result + *multiplicand;
            *multiplicand = *multiplicand * 2;  /*double of the multiplicand*/         
            *multiplier = (*multiplier-1) / 2;  /*half of the multiplier*/
        }
        else{
            *multiplicand = *multiplicand * 2;  /*double of the multiplicand*/         
            *multiplier = *multiplier / 2;  /*half of the multiplier*/ 
        }
    }
    *multiplicand = result;
}


void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double b0){
    double p6, p5, p4, p3, p2, p1, p0;
    p6 = *a3 * *b3;
    p5 = (*a3 * *b2) + (*b3 * *a2);
    p4 = (*a2 * *b2) + (*a1 * *b3) + (*a3 * *b1);
    p3 = (*a2 * *b1) + (*a1 * *b2) + (*a3 * b0) + (*a0 * *b3);
    p2 = (*a2 * b0) + (*a0 * *b2) + (*a1 * *b1);
    p1 = (*a1 * b0) + (*a0 * *b1);
    p0 = (*a0 * b0);

    *a3 = p6;
    *a2 = p5;
    *a1 = p4;
    *a0 = p3;
    *b3 = p2;
    *b2 = p1;
    *b1 = p0;
}