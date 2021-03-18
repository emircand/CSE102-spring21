/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/

#include <stdio.h>
#include "hw1_lib.h"


double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
	/*
	* Trapezoidal rule integration ---> Tn = (delta/2) * (f(x1) + 2*f(x2) + 2*f(x3) + .... + f(xn))
	*/
	
	/*declarations for Trapezoidal rule integration*/
    double polynom3, IntegralSum=0.0, xdelta, NetIntegral=0.0;
	
	xdelta = xs;        
    
	/* Finding Integration Value */
	do
    {
    	polynom3=(a0*xdelta*xdelta*xdelta)+(a1*xdelta*xdelta)+(a2*xdelta)+(a3);
    	if(xdelta == xs){
    		IntegralSum= IntegralSum + polynom3;
		}
		else if(xdelta == xe){
    		IntegralSum= IntegralSum + polynom3;
		}
		else{
			IntegralSum = IntegralSum + 2 * polynom3;
		}
		xdelta = xdelta + delta;
    } while (xdelta <= xe);
    
    
    NetIntegral = delta * 0.5* IntegralSum; 
    
    return NetIntegral;
}

	/*
	* Trapezoidal rule integration ---> Tn = (delta/2) * (f(x1) + 2*f(x2) + 2*f(x3) + .... + f(xn))
	*/
double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
    /*declarations for Trapezoidal rule integration*/
	double polynom4, IntegralSum=0.0, xdelta, NetIntegral=0.0;
	
	xdelta = xs; 
	
	/* Finding Integration Value */
	       
    do
    {
    	polynom4=a0*xdelta*xdelta*xdelta*xdelta+a1*xdelta*xdelta*xdelta+a2*xdelta*xdelta+a3*xdelta+a4;
    	if(xdelta == xs){
    		IntegralSum= IntegralSum + polynom4;
		}
		else if(xdelta == xe){
    		IntegralSum= IntegralSum + polynom4;
		}
		else{
			IntegralSum = IntegralSum + 2 * polynom4;
		}
		xdelta = xdelta + delta;
    } while (xdelta <= xe);
    NetIntegral = delta*0.5* IntegralSum;
    return NetIntegral;
}

double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{
	double rootof3degree, polynom3;
	
	/*searching to the range [xs,xe] to find a root of polynom*/

	do
    {
    	/*condition of being a root for third degree polynomials --> 0 = a3 + a2*x + a1*x^2 + a0*x^3 */
    	
    	polynom3 = a3 + (a2*xs) + (a1*xs*xs) + (a0*xs*xs*xs);
    	if (polynom3 <= 0.00001 && polynom3>=-0.00001)
    	{
    		rootof3degree = xs;
    	}
    	xs = xs + 0.1;
    } while (xs <= xe);
    
    
    return rootof3degree;
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{
	double rootof4degree, polynom4;
	
	/*searching to the range [xs,xe] to find a root of polynom*/
	
	do
    {
    	/*condition of being a root for fourth degree polynomials --> 0 = a4 + a3*x + a2*x^2 + a1*x^3 + a0*x^4 */
    	
    	polynom4 = a4 + (a3*xs) + (a2*xs*xs) + (a1*xs*xs*xs) + (a0*xs*xs*xs*xs);
    	
    	if (polynom4 <= 0.00001 && polynom4>=-0.00001)
    	{
    		rootof4degree = xs;
    	}
    	xs = xs + 0.1;
    } while (xs <= xe);
    
    return rootof4degree;
}
