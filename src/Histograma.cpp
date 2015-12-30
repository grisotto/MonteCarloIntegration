/*
 * Histograma.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "Histograma.h"
#include <map>
#include <iostream>
#include <string>

Histograma::Histograma(void){
	std::cout << "Criado o histagrama as" << std::endl;
}

void Histograma::setHist(std::map<double, int>& hist){


	this->hist = hist;

}

const std::map<double, int>& Histograma::getHist() const{

	for (auto p : hist) {
	    std::cout << p.first << " : " << std::string(p.second/10, '*') << '\n';
			       }
	return hist;
}

//void printing(std::pair<char,int> the_pair){
//	std::cout << the_pair.first << " " << the_pair.second << std::endl;
//}




