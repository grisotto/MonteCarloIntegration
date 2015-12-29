/*
 * MonteCarloCrude.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "MonteCarloCrude.h"
#include "GenerateNumbers.h"

double MonteCarloCrude::CrudeMonteCarlo(double (*f)(double), double a, double b, int n,
		double& errest) {

	double r, x, u, f2s, fs;
	/* variables fs and f2s are used to estimate an error of integration */


	fs = 0.0;
	f2s = 0.0;

	for (int i = 1; i <= n; i = i + 1) {
		u = GenerateNumbers::getRandomNumber(0.0, 1.0);
		x = a + (b - a) * u;
		fs = fs + f(x);
		f2s = f2s + f(x) * f(x);
	}
	r = fs * (b - a) / n;
	/* evaluate integration error */
	fs = fs / n;
	f2s = f2s / n;
	errest = (b - a) * sqrt((f2s - fs * fs) / n);
	return r;
}



