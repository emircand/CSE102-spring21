/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"

void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
	double p0 ,p1, p2, p3, p4, p5, p6;
	/*switch-case to make a choosen operation*/
	switch (op)
	{
	case '+':
		/*sum of coefficients*/
		*a3 = *a3 + *b3;
		*a2 = *a2 + *b2;
		*a1 = *a1 + *b1;
		*a0 = *a0 + *b0;
		break;
	case '-':
		/*subtract of coefficients*/
		*a3 = *a3 - *b3;
		*a2 = *a2 - *b2;
		*a1 = *a1 - *b1;
		*a0 = *a0 - *b0;
		break;
	case '*':
		/*multiplication of polynomials*/
	 	p6 = *a3 * *b3;
    	p5 = (*a3 * *b2) + (*b3 * *a2);
    	p4 = (*a2 * *b2) + (*a1 * *b3) + (*a3 * *b1);
    	p3 = (*a2 * *b1) + (*a1 * *b2) + (*a3 * *b0) + (*a0 * *b3);
    	p2 = (*a2 * *b0) + (*a0 * *b2) + (*a1 * *b1);
    	p1 = (*a1 * *b0) + (*a0 * *b1);
    	p0 = (*a0 * *b0);

    	*a3 = p6;
    	*a2 = p5;
    	*a1 = p4;
    	*a0 = p3;
    	*b3 = p2;
    	*b2 = p1;
    	*b1 = p0;
		break;
	default:
		printf("\n!!invalid operator type!!\n");
		break;
	}
}

void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	double d0, d1, d2, d3, euclidian_distance=0, x1=0, x2, y1=0, y2, z1=0, z2, a1=0, a2;
	double X_sum = 0.0, Y_sum = 0.0, Z_sum = 0.0, A_sum = 0.0;
	int i, count=0;

	printf("-----%s-----\n","4D vectors");
	
	for (i = 0; i < N; i++)
	{
		/*take input from console*/
		printf("enter vector coordinates %d> ",i+1);
		scanf("%lf %lf %lf %lf",&x2,&y2,&z2,&a2);
		/*premature exit*/
		if (x2 == -1 && y2 == -1 && z2 == -1 && a2 == -1)
			break;

		if (i==0)
		{
			x1 = x2;
			y1 = y2;
			z1 = z2;
			a1 = a2;
		}
		else{
			/*calculating distance of consecutive points.*/
			d0 = x2 - x1;
			d1 = y2 - y1;
			d2 = z2 - z1;
			d3 = a2 - a1;
			/*function call*/
			distance_between_4d_points (d0, d1, d2, d3, &euclidian_distance);
			if (*longest_distance <= euclidian_distance)
				*longest_distance = euclidian_distance;
			/*sum of axis*/	
			X_sum = X_sum + x1 + x2;
			Y_sum = Y_sum + y1 + y2;
			Z_sum = Z_sum + z1 + z2;
			A_sum = A_sum + a1 + a2;
			x1 = x2;
			y1 = y2;
			z1 = z2;
			a1 = a2;
		}
		count++;
	}
	/*average of points*/
	*mean_a0 = X_sum / count;
	*mean_a1 = Y_sum / count;
	*mean_a2 = Z_sum / count;
	*mean_a3 = A_sum / count;
}

void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
	/*4D ---> sqrt((x1-x0)^2+(y1-y0)^2+(z1-z0)^2+(a1-a0)^2)*/
	*euclidian_distance = sqrt(fabs(d0*d0 + d1*d1 + d2*d2 + d3*d3));
}

void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
	int seat_A = 1, seat_B = 1, seat_C = 1, seat_D = 1, seat_E = 1, i;
	int temp_A, temp_B, temp_C, temp_D, temp_E;
	int grupA, grupB, grupC, grupD, grupE;

	/*to make true divisons on every step, party variables assigned to temp variables.*/
	temp_A = *partyA, temp_B = *partyB, temp_C = *partyC, temp_D = *partyD, temp_E = *partyE;
	grupA = *partyA, grupB = *partyB, grupC = *partyC, grupD = *partyD, grupE = *partyE;

	printf("-----%s-----\n","D'hont method");
	
	/*counting seats using the d'hont method*/
	while (numberOfSeats >=1)
	{
		if (temp_A >= temp_B && temp_A >= temp_C && temp_A >= temp_D && temp_A >= temp_E) /*comparing votes to find the highest value*/
		{
			seat_A++;	
			temp_A = grupA / seat_A;	/*d'hont method*/
		}
		else if (temp_B >= temp_A && temp_B >= temp_C && temp_B >= temp_D && temp_B >= temp_E)	/*comparing votes to find the highest value*/
		{
			seat_B++;
			temp_B = grupB / seat_B;	/*d'hont method*/
		}
		else if (temp_C >= temp_A && temp_C >= temp_B && temp_C >= temp_D && temp_C >= temp_E)	/*comparing votes to find the highest value*/
		{
			seat_C++;
			temp_C = grupC / seat_C;	/*d'hont method*/
		}
		else if (temp_D>= temp_A && temp_D>= temp_B && temp_D>= temp_C && temp_D>= temp_E)	/*comparing votes to find the highest value*/
		{
			seat_D++;
			temp_D = grupD / seat_D;	/*d'hont method*/
		}
		else if (temp_E >= temp_A && temp_E >= temp_B && temp_E >= temp_C && temp_E >= temp_D)	/*comparing votes to find the highest value*/
		{
			seat_E++;
			temp_E = grupE / seat_E;	/*d'hont method*/
		}
		numberOfSeats--;
	}
	/*minus one of counters will give number of seats..
	*party variables return as seat numbers.*/
	*partyA = seat_A - 1;
	*partyB = seat_B - 1;
	*partyC = seat_C - 1;
	*partyD = seat_D - 1;
	*partyE = seat_E - 1;
}

void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
	double change_varx, change_vary, slope12, slope13, slope23;
	/*slopes of (x1,y1) - (x2,y2) , (x1,y1) - (x3,y3) and (x2,y2) - (x3,y3)*/
	printf("-----%s-----\n","order 2D points");
	slope12 = (*y2 - *y1) / (*x2 - *x1);
	slope13 = (*y3 - *y1) / (*x3 - *x1);
	slope23 = (*y3 - *y2) / (*x3 - *x2);
	/*comparing slopes*/
	if (slope12 < 0 && slope13 < 0){
			if (slope13 > slope12){
				change_varx = *x2;
				change_vary = *y2;
				*x2 = *x3;
				*y2 = *y3;
				*x3 = change_varx;
				*y3 = change_vary;
			}
			else if ((slope12 == slope13) && *y3 > *y2){
				change_varx = *x2;
				change_vary = *y2;
				*x2 = *x3;
				*y2 = *y3;
				*x3 = change_varx;
				*y3 = change_vary;
			}
	}
	else if (slope12 < 0 && slope13 > 0){
		if (slope23 >= 0)
		{
			change_varx = *x2;
			change_vary = *y2;
			*x2 = *x3;
			*y2 = *y3;
			*x3 = change_varx;
			*y3 = change_vary;
		}
	}
	else if (slope12 >= 0 && slope13 >= 0){
		
		if(slope13 > slope12){
			change_varx = *x2;
			change_vary = *y2;
			*x2 = *x3;
			*y2 = *y3;
			*x3 = change_varx;
			*y3 = change_vary;
		}
		else if ((slope12 == slope13) && *y3 < *y2){
			change_varx = *x2;
			change_vary = *y2;
			*x2 = *x3;
			*y2 = *y3;
			*x3 = change_varx;
			*y3 = change_vary;
		}
	}
	else if ((slope12 >= 0 && slope13 <= 0))
	{
		if (slope23 < 0)
		{
			change_varx = *x2;
			change_vary = *y2;
			*x2 = *x3;
			*y2 = *y3;
			*x3 = change_varx;
			*y3 = change_vary;
		}
		else if(slope23 == 0 && *x3 < *x2)
		{
			change_varx = *x2;
			change_vary = *y2;
			*x2 = *x3;
			*y2 = *y3;
			*x3 = change_varx;
			*y3 = change_vary;
		}
	}	
}

void number_encrypt (unsigned char* number)
{
	char b7=0, b6=0, b5=0, b4=0, b3=0, b2=0, b1=0, b0=0;
	printf("-----%s-----\n","number encrypt");
	/*function calls*/
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
}

void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
	int i=0, num, temp;
	num = (int) number;
	/*convertion: decimal to binary
	* Divide the number by 2.
	* Get the integer quotient for the next iteration.
	* Get the remainder for the binary digit.
	* Repeat the steps until the quotient is equal to 0.
	*/
	while (i<=7)
	{
		if (num % 2 == 0){
            temp = 0;
            num = num / 2;
        }	
		else{
            temp = 1;
            num = (num-1) / 2;
        }
		if (i==0)
			*b0 = temp;
		else if (i==1)
			*b1 = temp;
		else if (i==2)
			*b2 = temp;
		else if (i==3)
			*b3 = temp;
		else if (i==4)
			*b4 = temp;
		else if (i==5)
			*b5 = temp;
		else if (i==6)
			*b6 = temp;
		else if (i==7)
			*b7 = temp;

        temp = 0;
		i++;
	}
}

void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{
	char temp, temp2;
	int i, decimal = 0 ;
	/*Change bit-7 with bit-2, bit-6 with bit-3, bit-5 with bit-0, bit 4 with bit-1.
	7 6 5 4 3 2 1 0 --> 2 3 0 1 6 7 4 5*/
	temp = b7;
	b7 = b2;
	b2 = temp;
	temp = b6;
	b6 = b3;
	b3 = temp;
	temp = b5;
	b5 = b0;
	b0 = temp;
	temp = b4;
	b4 = b1;
	b1 = temp;
	/*two circular left shift:
	* 2 3 0 1 6 7 4 5 --> 0 1 6 7 4 5 2 3
	*/
	temp = b7;
	temp2 = b6;
	b7 = b5;
	b6 = b4;
	b5 = b3;
	b4 = b2;
	b3 = b1;
	b2 = b0;
	b1 = temp;
	b0 = temp2;
	/*
	*convertion: binary to decimal 
	* The decimal number is equal to the sum of binary digits (dn) times their power of 2 (2^n):
	*/
	for (i = 0; i < 8; i++)
	{
		if (i==0)
			decimal = decimal + b0 * 1;
		else if (i==1)
			decimal = decimal + b1 * (2);
		else if (i==2)
			decimal = decimal + b2 * (2*2);
		else if (i==3)
			decimal = decimal + b3 * (2*2*2);
		else if (i==4)
			decimal = decimal + b4 * (2*2*2*2);
		else if (i==5)
			decimal = decimal + b5 * (2*2*2*2*2);
		else if (i==6)
			decimal = decimal + b6 * (2*2*2*2*2*2);
		else if (i==7)
			decimal = decimal + b7 * (2*2*2*2*2*2*2);
	}
	/*decimal value assigned, as unsigned char type, to *number*/
	*number = decimal;
}