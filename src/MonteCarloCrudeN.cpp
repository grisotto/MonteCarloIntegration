/*
 * MonteCarloCrude.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "MonteCarloCrudeN.h"
#include "Histograma.h"
 //Aqui incluo o metodo mt19937
#include "GenerateNumbers.h"
//aqui incluo o metodo do Numerical recipes
#include "GenerateNumbersNR.h"
#include "GenerateNumbersXOR.h"



double MonteCarloCrudeN::CrudeMonteCarloN(double(*fn)(double[],int,double,double,double,double),double a[], double b[], int n, int m, double limiteX, double limiteY, double limiteZ, double step) {
	double numeroU;

	double r, x[n], p;
	    int i, j;

	    //a limite inferior
	    //b limite supeior

	    //definindo qual gerador de numeros usar
	    Ran myran(104723);
//	     std::uniform_real_distribution<> dist_normal(0.0, 1.0);
//		 xorshift xor_;



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

	        	//numeroU = GenerateNumbers::getRandomNumber(0.0, 1.0);
//	        	numeroU = dist_normal(xor_);
	        	 	numeroU = myran.doub();
	            x[j] = a[j] + (b[j]-a[j]) * numeroU;
	        }

//	        std::cout << m << std::endl;
	        r = r + fn( x, n, limiteX, limiteY, limiteZ, step);
	    }
	    r = r*p/m;



	return r;
}



