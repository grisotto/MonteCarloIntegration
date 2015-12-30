/*
 * MonteCarloCrude.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "MonteCarloCrudeN.h"
#include "GenerateNumbers.h"
#include "Histograma.h"



double MonteCarloCrudeN::CrudeMonteCarloN(double(*fn)(double[],int),double a[], double b[], int n, int m) {
	double numeroU;

	double r, x[n], p;
	    int i, j;

	    r = 0.0;
	    p = 1.0;

	// step 1: calculate the common factor p
	    for (j = 0; j < n; j = j+1)
	      {
	         p = p*(b[j]-a[j]);
	      }

	// step 2: integration
	    for (i = 1; i <= m; i=i+1)
	    {
	//      calculate random x[] points
	        for (j = 0; j < n; j = j+1)
	        {
	        	numeroU = GenerateNumbers::getRandomNumber(0.0, 1.0);
	            x[j] = a[j] + (b[j]-a[j]) * numeroU;
	        }
	        r = r + fn(x,n);
	    }
	    r = r*p/m;



	return r;
}



