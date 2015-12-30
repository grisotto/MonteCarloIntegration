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

#include <iostream>
#include <random>


#include <string>
#include <math.h>
#include "MonteCarloCrude.h"

using namespace std;



// prototipo das funcoes

/**
 *
 * @param x - uma funcao com apenas uma dimensao
 * @return retorna a funcao
 */
double funcao(double x);

double funcao(double x) {
	double y;

	y = x;

	return y;
}


int main() {
//	map<int, int> hist;

	double a, b, montecarlo, erro;
	int n;
	int ntimes;

	// definindo a precisao de quando mostra os resultados
	cout.precision(6);
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
	ntimes = 6;
 /** Usando método MonteCarloCrude
  *
  */
	for (int var = 0; var < ntimes; ++var) {

		montecarlo = MonteCarloCrude::CrudeMonteCarlo(funcao, a, b, n, erro);

		cout <<"N: " << n << " Monte: "<< montecarlo << " Erro:"<< erro << endl;
		n = n * 2;
	}

	return 0;
}

//****** Parte que print um historiograma para mostrar que consigo gerar uma distribuicao uniforme
//	    for (int i = 0; i < 20000; ++i){
//	    	//number = dist(mt);
//	    	++hist[dist(mt)];
//
//	        //cout << number << " ";
//
//	    }
//	    cout << endl;
//
//	    for (auto p : hist) {
//	           cout << p.first << " : " << string(p.second/100, '*') << '\n';
//	       }

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
