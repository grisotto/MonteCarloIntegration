/*
 * GenerateNumbers.h
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#ifndef GENERATENUMBERS_H_
#define GENERATENUMBERS_H_

#include <random>
class GenerateNumbers
{
static std::random_device       m_rd;
    static std::mt19937         m_rng;
public:
    static double getRandomNumber(const double& rangeStart, const double& rangeEnd);
};



#endif /* GENERATENUMBERS_H_ */
