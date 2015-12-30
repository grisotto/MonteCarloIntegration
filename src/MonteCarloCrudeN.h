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
    static double CrudeMonteCarloN(double(*fn)(double[],int),double a[], double b[], int n, int m);

};




#endif /* MONTECARLOCRUDEN_H_ */
