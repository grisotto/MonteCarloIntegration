//============================================================================
// Name        : Monte_carlo.cpp
// Author      : Rafael
// Version     :
// Copyright   : MIT
// Description : Hello World in C++, Ansi-style
// referencias:
// 1 - http://ta.twi.tudelft.nl/mf/users/oosterle/oosterlee/lec8-hit-2009.pdf
// 2 - Sadiku. M.N.O - Numeral Techniques in Electromagnetics with MATLAB
// 3 - http://ww2.odu.edu/~agodunov/computing/programs/cpp/dmc_int1.cpp
// 4 - https://github.com/s9w/articles/blob/master/perf%20cpp%20random.md - comparacao entre os metodos de gerar numeros aleatorios


// AJUDOU SOBRE GERAR DOUBLE:
//http://stackoverflow.com/questions/32071721/error-in-using-mt19937-with-random-device-as-static-class-members
//http://physics.clarku.edu/courses/125/gtcdraft/chap11.pdf
//http://stackoverflow.com/questions/24334012/best-way-to-seed-mt19937-64-for-monte-carlo-simulations
//


/*
Artigos sobre geracao de aleatorios e monte carlo
http://journals.aps.org/pre/abstract/10.1103/PhysRevE.75.066701
 */
/*
Metodos para gerar aleatorios:
usado pelo chrome - xorshift128+
padrao do c++ 11 - mt19937 								XX - Implementado GenerateNumbers.h
descrito pelo numerical recipes pg 366- Ran 			XX - Implementado GenerateNumbersNR.h
 */


/*
 * Testar pelo método analitico as integrais
 * http://www.wolframalpha.com/examples/Integrals.html
 */

/** Alguns codigos fontes de MonteCarlo
 * http://ww2.odu.edu/~agodunov/computing/programs/cpp/dmc_int1.cpp
 * http://ww2.odu.edu/~agodunov/computing/programs/cpp/mc_int_nd.cpp
 */


/** tipos de metodos para integrar com o MonteCarlo
 * https://www.unige.ch/sciences/astro/files/2713/8971/4086/3_Paltani_MonteCarlo.pdf
 * -Strafiel sampling
 * -Importance sampling
 */
//============================================================================

/*
 * Adicionar novas formas de gerar numeros aleatorios
 * implementar novos metodos de monte carlo, importance
 */
#include <iostream>
#include <random>


#include <string>
#include <math.h>
#include "MonteCarloCrude.h"
#include "MonteCarloCrudeN.h"

using namespace std;



// prototipo das funcoes

/**
 *
 * @param x - uma funcao com apenas uma dimensao
 * @return retorna a funcao
 */
double funcao(double x);
double funcaoN(double x[], int n);

/**
 * Voce define a funcao que deve ser integrada
 * @param x Parametro de entrada da funcao
 * @return
 */
double funcao(double x) {
	double y;
	/**
	 * I = x dx
	 * resultado analitico: "http://www.wolframalpha.com/input/?i=int+x+dx+from+0+to+10"
	 */
	y = x;

	return y;
}

double funcaoN(double x[], int n){
	 double y;
	    int j;
	    y = 0.0;

// estou usando a funcao do Alex Godunov
//	    for (j = 0; j < n; j = j+1)
//	      {
//	         y = y + x[j];
//	      }
//	    y = pow(y,2);

	    /** resultado analitico
	     * Wolfram: "http://www.wolframalpha.com/input/?i=int+x+%2B+y+%2B+z+dx+dy+dz%2C+x%3D0+to+1%2C+y%3D0+to+1%2C+z%3D0+to+1"
	     */
	    y = x[0] + x[1] + x[2];

	    return y;


}


int main() {

	double a, b, montecarlo, erro;
	int n;
	int ntimes;

	// definindo a precisao de quando mostra os resultados
	cout.precision(4);
	cout.setf(ios::fixed | ios::showpoint);

	/**
	 * Teste 1- 1 dimensão com CrudeMonteCarlo
	 *  I = x dx
	 *  a = 0.0
	 *  b = 10.0
	 *  n = 2
	 *  ntimes = 10
	 */

	a = 0.0;
	b = 10.0;
	n = 2;
	ntimes = 16;

 /** Usando método MonteCarloCrude
  *
  */
	for (int var = 0; var <= ntimes; ++var) {

		montecarlo = MonteCarloCrude::CrudeMonteCarlo(funcao, a, b, n, erro);

		cout <<"N: " << n << " Monte: "<< montecarlo << " Erro:"<< erro << endl;
		n = n * 2;
	}
	const int n_int = 3;       /* define how many integrals */

	    double aN[n] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; /* left end-points */
	    double bN[n] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; /* right end-points */
	    double result;
	    int mN;


	/**
	 * Teste 2 - 6 dimensoes com CrudeMonteCarloN
	 * I =
	 * n_int = 6 numeros de integrais
	 * aN = 0.0 para todas as dimensoes
	 * bN = 1.0 para todas as dimensoes
	 * mN = 2
	 * ntimes = 20
	 * m ^ntimes
	 */

mN = 2;
ntimes = 20;

for (int var = 0; var <= ntimes; ++var) {
	       result = MonteCarloCrudeN::CrudeMonteCarloN(funcaoN, aN, bN, n_int, mN);
	        cout << "mN: " << mN << " Resul: "<< result <<endl;
	        mN = mN*2;

}



	return 0;
}


// Parte para gerar os aleatorios
//	double number;
//	//pegando o seed de um dispositivo, assim toda vez que executar o codigo devera alterar o seed e assim a sequencia.?
//	random_device seed_origem;
//	mt19937_64 mt; //metodo para gerar os numeros aleatorios
//	mt.seed(seed_origem()); //definindo o seed pelo device
//
//	//gerando uma distribuicao uniforme
//	uniform_real_distribution<double> dist_double(0.0, 1.0);
//
//
//	//cout << dist(mt()) << endl;
//	number = dist_double(mt);
//	return number;
//
//}

//std::mt19937_64 prng;
//seed = std::random_device{}();
//prng.seed(seed);
