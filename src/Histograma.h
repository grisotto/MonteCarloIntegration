/*
 * Histograma.h
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include <map>
#ifndef HISTOGRAMA_H_
#define HISTOGRAMA_H_


class Histograma
{
	private:
	std::map<double, int> hist;



public:

	Histograma();
	const std::map<double, int>& getHist() const;
	void setHist(std::map<double, int>& hist);
	void printing(std::pair<char,int> the_pair);

	//get e sets gerados
//	const std::map<double, int>& getHist() const {
//		return hist;
//	}
//
//	void setHist(const std::map<double, int>& hist) {
//		this->hist = hist;
//	}
};



#endif /* HISTOGRAMA_H_ */
