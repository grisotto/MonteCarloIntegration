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
    static double CrudeMonteCarloN(double(*fn)(double[],int,int,int,int) ,double a[], double b[], int n, int m,int limiteX, int limiteY, int limiteZ);

};




#endif /* MONTECARLOCRUDEN_H_ */
