/*
 * MonteCarloCrudeN.h
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#ifndef MONTECARLOCRUDEN_H_
#define MONTECARLOCRUDEN_H_


class MonteCarloCrudeN
{

public:
    static double CrudeMonteCarloN(double(*fn)(double[],int,double,double,double,double) ,double a[], double b[], int n, int m,double limiteX, double limiteY, double limiteZ, double step);

};




#endif /* MONTECARLOCRUDEN_H_ */
