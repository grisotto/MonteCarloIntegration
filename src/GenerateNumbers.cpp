/*
 * GenerateNumbers.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#include "GenerateNumbers.h"

std::random_device   GenerateNumbers::m_rd;
std::mt19937         GenerateNumbers::m_rng(GenerateNumbers::m_rd());


double GenerateNumbers::getRandomNumber(const double& rangeStart, const double& rangeEnd)
{
    std::uniform_real_distribution<> randomizer(rangeStart, rangeEnd);
    return randomizer(m_rng);
}


