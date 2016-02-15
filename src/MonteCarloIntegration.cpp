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
//http://www.cs.dartmouth.edu/~wjarosz/publications/dissertation/appendixA.pdf


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
usado pelo chrome - xorshift128+						XX - Implementado GenerateNumbersXOR.h
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
//#include "MonteCarloCrude.h"
#include "MonteCarloCrudeN.h"
#include <time.h>
#include <array>

using namespace std;



// prototipo das funcoes

/**
 *
 * @param x - uma funcao com apenas uma dimensao
 * @return retorna a funcao
 */
double funcao(double x);
double funcaoN(double x[], int n, int limiteX, int limiteY, int limiteZ);

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
// estou usando a funcao do Alex Godunov
//	    for (j = 0; j < n; j = j+1)
//	      {
//	         y = y + x[j];
//	      }
//	    y = pow(y,2);

	    /** resultado analitico
	     * Wolfram: "http://www.wolframalpha.com/input/?i=int+x+%2B+y+%2B+z+dx+dy+dz%2C+x%3D0+to+1%2C+y%3D0+to+1%2C+z%3D0+to+1"
	     */


double funcaoN(double x[], int n, int limiteX, int limiteY, int limiteZ){
	 double y;
	    int j;
	    double gama_0 = 2.3562;
	    int a_0 = 5;
	    double c_a = 9.1439;
	    y = 0.0;

	    double raizG_0 = sqrt( pow(limiteX,2) + pow(limiteY,2) + pow(limiteZ,2)  );
	    if( raizG_0 == 0  ){

	    	y = a_0;
	    }else if(raizG_0 < 1){

	    	y = a_0 * ((  sin(gama_0*raizG_0)) / (gama_0*raizG_0)) ;

	    }else {

	    	y = c_a * (( exp( -gama_0*raizG_0)) / ( gama_0*raizG_0)) ;
	    }

	    y = pow(y,2);

	    double raiz_R =  sqrt( pow(x[0] - limiteX,2) + pow(x[1] - limiteY,2) + pow(x[2] - limiteZ,2)  );

	    if(raiz_R >= 1 ){
	    	y/= raiz_R;

	    }else {
	    	y/= 2 * 1;
	    }





//	    y = 2*pow(x[0],2) + 3*pow(x[1],2) + 4*pow(x[2],2);

	    return y;
	    //	    cout << "x1: "<< x[0] <<endl;
	    //	    cout << "y1: "<< x[1] <<endl;
	    //	    cout << "z1: "<< x[2] <<endl;


}


int main() {

	double a, b, montecarlo, erro;
	int n;
	int ntimes;
	clock_t tStart = clock();
	// definindo a precisao de quando mostra os resultados
	cout.precision(5);
	cout.setf(ios::fixed | ios::showpoint);




	/**
	 * Teste 1- 1 dimensão com CrudeMonteCarlo
	 *  I = x dx
	 *  a = 0.0
	 *  b = 10.0
	 *  n = 2
	 *  ntimes = 10
	 */

//	a = 0.0;
//	b = 10.0;
//	n = 2;
//	ntimes = 16;

 /** Usando método MonteCarloCrude
  *
  */
//	for (int var = 0; var <= ntimes; ++var) {
//
//		montecarlo = MonteCarloCrude::CrudeMonteCarlo(funcao, a, b, n, erro);
//
//		cout <<"N: " << n << " Monte: "<< montecarlo << " Erro:"<< erro << endl;
//		n = n * 2;
//	}

	const int n_int = 3;       /* define how many integrals */

	    double aN[n_int] = { -2.0, -2.0, -2.0}; /* left end-points */
	    double bN[n_int] = { 2.0, 2.0, 2.0}; /* right end-points */
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
ntimes = 3;

mN = 8;

int limiteX, limiteY, limiteZ;
int L = 8;
double matrizMonte[L][L][L];
for (limiteX = 0; limiteX < L; ++limiteX) {
	for (limiteY = 0; limiteY < L; ++limiteY) {
		for (limiteZ = 0; limiteZ < L; ++limiteZ) {

		       result = MonteCarloCrudeN::CrudeMonteCarloN(funcaoN, aN, bN, n_int, mN,limiteX, limiteY,limiteZ);
		        cout << "mN: " << mN << " Resul: "<< result << endl;
		        cout << "x " << limiteX << " y "<< limiteY << " z " <<limiteZ << endl;

		        matrizMonte[limiteX][limiteY][limiteZ] = result;



		}
	}
}






	    cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

	return 0;
}



