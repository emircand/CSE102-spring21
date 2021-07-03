/** 
 *         *LAB - 08* 
 * File:    1901042674.C 
 * 
 * Author:  Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * Date:    Spring 2021  
 * Course:  CSE108 - LAB 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

//declare structs
typedef struct
{
    float elems;
    float determ;
}matrix;

void print_matrix(matrix initial_matrix[][3]) {
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            //print each elems
            printf("%7.4f ", initial_matrix[i][j].elems);
        }
        printf("\n");
    }
    
}
void determinant_of_matrix(matrix* initial_matrix){
}


void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix){

}

typedef struct
{
    //coefficent values
    double c1, c2;
}third_order_polynomial;

typedef struct
{
    double coefficient_val;
}polynomial;


polynomial get_integral(third_order_polynomial p1[4], third_order_polynomial p2[4], int a, int b)
{
    polynomial *result;
    double sum; 

    //multiplication of polynomials
    sum = ((p1[0].c1 * p2[0].c2) / 6);
    sum = sum + ( ( (p1[0].c1 * p2[1].c2) + (p1[1].c1 * p2[0].c2) )/ 5);
    sum = sum + ( ( (p1[0].c1 * p2[2].c2) + (p1[2].c1 * p2[0].c2) + (p1[1].c1 * p2[1].c2) )/ 4);
    sum = sum + ( ( (p1[0].c1 * p2[3].c2) + (p1[3].c1 * p2[0].c2) + (p1[2].c1 * p2[1].c2) + (p1[1].c1 * p2[2].c2))/ 3);
    sum = sum + ( ( (p1[1].c1 * p2[3].c2) + (p1[3].c1 * p2[1].c2) + (p1[2].c1 * p2[2].c2) )/ 2);
    sum = sum + ( ( (p1[2].c1 * p2[3].c2) + (p1[3].c1 * p2[2].c2) )/ 1);

    //return result
    *result = (sum * b) - (sum * a);
    return *result;
}






int main(){

    matrix initial_matrix[3][3];
    third_order_polynomial p1[4], p2[4];

    int i, a, b;
    polynomial *result;

    //fill matrix
    initial_matrix[0][0].elems = 1.0000;
    initial_matrix[0][1].elems = 0.9134; 
    initial_matrix[0][2].elems = 0.2785; 
    initial_matrix[1][0].elems = 0.9058; 
    initial_matrix[1][1].elems = 0.6324; 
    initial_matrix[1][2].elems = 0.5469; 
    initial_matrix[2][0].elems = 0.1270;  
    initial_matrix[2][1].elems = 0.0975; 
    initial_matrix[2][2].elems = 0.9575;  
    //print matrix
    print_matrix(initial_matrix);

    //take input for part 3
    printf("enter 3rd degree polynomial: ");

    for (i = 0; i < 4; i++)
    {
        scanf("%lf",&p1[i].c1);
    }

    printf("enter 3rd degree polynomial: ");
    for (i = 0; i < 4; i++)
    {
        scanf("%lf",&p2[i].c2);
    }

    //take an interval
    printf("input start value: ");
    scanf("%d",&a);
    printf("input end value: ");
    scanf("%d",&b);

    //function call
    get_integral(p1, p2, a, b);

    printf("result of integral %f \n", result);

    return 0;
}
