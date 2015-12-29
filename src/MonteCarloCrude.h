/*
 * MonteCarloCrude.h
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#ifndef MONTECARLOCRUDE_H_
#define MONTECARLOCRUDE_H_


class MonteCarloCrude
{

public:
    static double CrudeMonteCarlo(double (*f)(double), double a, double b, int n,
    		double& errest);

};




#endif /* MONTECARLOCRUDE_H_ */
