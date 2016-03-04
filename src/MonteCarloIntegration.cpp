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
 * compilar
 * g++ -Wall -g -std=c++11 MonteCarloIntegration.cpp MonteCarloCrudeN.cpp GenerateNumbersNR.h -o MonteCarlo.o
 *
 */
#include <iostream>
#include <random>


#include <string>
#include <math.h>
//#include "MonteCarloCrude.h"
#include "MonteCarloCrudeN.h"
#include <time.h>
#include <array>
#include <fstream>

using namespace std;



// prototipo das funcoes

/**
 *
 * @param x - uma funcao com apenas uma dimensao
 * @return retorna a funcao
 */
double funcao(double x);
double funcaoN(double x[], int n, double limiteX, double limiteY, double limiteZ, double step);

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



double funcaoN(double x[], int n, double limiteX, double limiteY, double limiteZ, double step) {
	 double y;
	 //   int j;
	    double gama_0 = 2.3562;
	    int a_0 = 5;
	    double c_a = 9.1439;
	    y = 0.0;


	    double raizG_0 = sqrt( pow(x[0],2) + pow(x[1],2) + pow(x[2],2)  );
	    if( raizG_0 == 0  ){

	    	y = a_0;
	    }else if(raizG_0 < 1){

	    	y = a_0 * ((  sin(gama_0*raizG_0)) / (gama_0*raizG_0)) ;

	    } else {

	    	y = c_a * (( exp( -gama_0*raizG_0)) / ( gama_0*raizG_0)) ;
	    }



	    y = pow(y,2);



	    double raiz_R =  sqrt( pow(limiteX - x[0],2) + pow(limiteY - x[1],2) + pow(limiteZ - x[2],2)  );

	    if(raiz_R >= step ){
	    	y/= raiz_R;

	    } else {
	    	y/= 2 * step;
	    }



/*
		   // return y = x[0] + x[1] + x[2];
	    //return y = pow(x[0],2) + sin(x[1]) * exp(x[2]);
*/

//	    y = 2*pow(x[0],2) + 3*pow(x[1],2) + 4*pow(x[2],2);

	    return y;
	    //	    cout << "x1: "<< x[0] <<endl;
	    //	    cout << "y1: "<< x[1] <<endl;
	    //	    cout << "z1: "<< x[2] <<endl;


}


int main() {

//	double a, b, montecarlo, erro;
//	int n;
//	int ntimes;
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
	int L = 2;
	    double aN[n_int] = { -L, -L, -L}; /* left end-points */
	
	    double bN[n_int] = { L, L, L}; /* right end-points */
	    double result;
	    int mN;




mN = 100000; // numero de iteracoes

double limiteX, limiteY, limiteZ;

double matrizMonte[L*2+1][L*2+1][L*2+1];



int aux_x, aux_y, aux_z;
aux_x = 0;
aux_y = 0;
aux_z = 0;
double step=1;




for (limiteX = -L, aux_x=0 ; limiteX <= L; limiteX+= step, ++aux_x) {
	for (limiteY = -L, aux_y=0 ; limiteY <= L; limiteY+= step, ++aux_y) {
		for (limiteZ = -L, aux_z=0 ; limiteZ <= L; limiteZ+= step, ++aux_z) {

		       result = MonteCarloCrudeN::CrudeMonteCarloN(funcaoN, aN, bN, n_int, mN,limiteX, limiteY,limiteZ);
		      //  cout << "mN: " << mN << " Resul: "<< result << endl;
		        cout << "x " << limiteX << " y "<< limiteY << " z " <<limiteZ << " Resul "<< result << endl;
		     //   cout << "a_x " << aux_x << " a_y "<< aux_y << " a_z " <<aux_z << endl;

		       matrizMonte[aux_x][aux_y][aux_z] = result;



		}
	}
}

//Pegando a hora atual e definindo no nome do arquivo
time_t now;
struct tm *now_tm;
now = time(NULL);
now_tm = localtime(&now);
int hour = now_tm->tm_hour;
int min = now_tm->tm_min;
int sec = now_tm->tm_sec;

//Criando um arquivo para coloca os dados da matriz X	Y 	Z 	Resultado
ofstream myfile;
string arquivoNome = "matriz " + to_string(hour)+ ":" + to_string(min) + ":" + to_string(sec) + ".txt";
myfile.open (arquivoNome);
myfile << "X,\t" << "Y,\t" << "Z,\t"<< "Resultado\t" << endl;


aux_x = 0;
aux_y = 0;
aux_z = 0;


for (limiteX = -L, aux_x=0 ; limiteX <= L; ++limiteX, ++aux_x) {
	for (limiteY = -L, aux_y=0 ; limiteY <= L; ++limiteY, ++aux_y) {
		for (limiteZ = -L, aux_z=0 ; limiteZ <= L; ++limiteZ, ++aux_z) {

			//escrevendo no arquivo
			myfile << limiteX <<",\t"<< limiteY << ",\t" << limiteZ << ",\t" << matrizMonte[aux_x][aux_y][aux_z]  << "\t" << endl;


		}
	}

}




	    cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

	return 0;
}



