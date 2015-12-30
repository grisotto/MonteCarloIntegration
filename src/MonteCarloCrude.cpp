/*
 * MonteCarloCrude.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "MonteCarloCrude.h"
#include "GenerateNumbers.h"
#include "Histograma.h"

/**
 * Implementacao do histograma para verificar se as variaveis estao uniformimente distribuidas
 *Histograma h1;
 *hist2[numeroU]++;
 *h1.setHist(hist2);
 *h1.getHist();
  */

double MonteCarloCrude::CrudeMonteCarlo(double (*f)(double), double a, double b, int n,
		double& errest) {
	double r, x, u, f2s, fs;
	/* variables fs and f2s are used to estimate an error of integration */
	double numeroU;
	std::map<double, int> hist2;


	fs = 0.0;
	f2s = 0.0;

	for (int i = 1; i <= n; i = i + 1) {
		numeroU = GenerateNumbers::getRandomNumber(0.0, 1.0);
		u = numeroU;
		x = a + (b - a) * u; /**< Eq. 8.42. */
		fs = fs + f(x);
		f2s = f2s + f(x) * f(x);
	}
	r = fs * (b - a) / n; /**< Eq. 8.41. */
	/* evaluate integration error */
	fs = fs / n;
	f2s = f2s / n;
	errest = (b - a) * sqrt((f2s - fs * fs) / n);


	return r;
}



