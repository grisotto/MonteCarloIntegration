/*
 * Histograma.h
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#ifndef HISTOGRAMA_H_
#define HISTOGRAMA_H_


class Histograma
{
	std::map<int, int> hist;

public:
//
//	++hist[dist(mt)];
//
//	 for (auto p : hist) {
//		           cout << p.first << " : " << string(p.second/100, '*') << '\n';
//		       }

	const std::map<int, int>& getHist() const;

	void gerarHist();

	void setHist(const std::map<int, int>& hist);
};



#endif /* HISTOGRAMA_H_ */
