/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include "hw1_io.h"


void write_polynomial3(double a0, double a1, double a2, double a3)
{
	/*conditions for printing the expected output as like as in PDF. */	
	if (a0 != 0.0)
	{
		if (a0 <= 1.49 && a0 >= 0.50)
		{
			printf("x^3");
		}
		else if (a0>=-1.49 && a0<=-0.50)
		{
			printf("-x^3");
		}
		else {
			printf("%1.fx^3",a0);
		}
	}
	if (a1!=0)
	{
		if (a1 <= 1.49 && a1 >= 0.50)
		{
			printf("+x^2");
		}
		else if (a1>=-1.49 && a1<=-0.50)
		{
			printf("-x^2");
		}
		else if (a1>0.0)
		{
			printf("+%1.fx^2",a1);
		}
		else if (a1<0.0)
		{
			printf("%1.fx^2",a1);
		}
	}
	if (a2!=0.0)
	{
		if (a2 <= 1.49 && a2 >= 0.50)
		{
			printf("+x");
		}
		else if (a2>=-1.49 && a2<=-0.50)
		{
			printf("-x");
		}
		else if (a2>0.0)
		{
			printf("+%1.fx",a2);
		}
		else if (a2<0.0)
		{
			printf("%1.fx",a2);
		}
	}
	if (a3!=0.0)
	{
		if (a3>0.0)
		{
			printf("+%1.f\n",a3);
		}
		else if (a3<0.0)
		{
			printf("%1.f\n",a3);
		}
	}
}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
	/*conditions for printing the expected output as like as in PDF.*/
	if (a0 != 0.0)
	{
		if (a0 <= 1.49 && a0 >= 0.50)
		{
			printf("x^4");
		}
		else if (a0>=-1.49 && a0<=-0.50)
		{
			printf("-x^4");
		}
		else
		{
			printf("%1.fx^4",a0);
		}
	}
	if (a1 != 0.0)
	{
		if (a1 <= 1.49 && a1 >= 0.50)
		{
			printf("+x^3");
		}
		else if (a1>=-1.49 && a1<=-0.50)
		{
			printf("-x^3");
		}
		else if (a1>0.0)
		{
			printf("+%1.fx^3",a1);
		}
		else if (a1<0.0)
		{
			printf("%1.fx^3",a1);
		}
	}
	if (a2!=0.0)
	{
		if (a2 <= 1.49 && a2 >= 0.50)
		{
			printf("+x^2");
		}
		else if (a2>=-1.49 && a2<=-0.50)
		{
			printf("-x^2");
		}
		else if (a2>0.0)
		{
			printf("+%1.fx^2",a2);
		}
		else if (a2<0.0)
		{
			printf("%1.fx^2",a2);
		}
	}
	if (a3!=0.0)
	{
		if (a3 <= 1.49 && a3 >= 0.50)
		{
			printf("+x");
		}
		else if (a3>=-1.49 && a3<=-0.50)
		{
			printf("-x");
		}
		else if (a3>0.0)
		{
			printf("+%1.fx",a3);
		}
		else if (a3<0.0)
		{
			printf("%1.fx",a3);
		}
	}
	if (a4!=0.0)
	{
		if (a4>0.0)
		{
			printf("+%1.f\n",a4);
		}
		else if (a4<0.0)
		{
			printf("%1.f\n",a4);
		}
	}
}
