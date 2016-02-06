/*
 * GenerateNumbers.h
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#ifndef GENERATENUMBERSNR_H_
#define GENERATENUMBERSNR_H_
/**
 * Press, Teukolsky, Vetterling, Flannery
 * NUMERICAL RECIPES - The Art of Scientific Computing - Third Edition (2007)
 * p. 342 / 343
 */
//irei adicionar o seed conforme /dev/random
#include <random>

typedef int Int; // 32 bit integer
typedef unsigned int Uint;

typedef long long int Llong; // 64 bit integer
typedef unsigned long long int Ullong;

typedef double Doub; // default floating type
typedef long double Ldoub;

struct Ran {
	Ullong u,v,w;
	//eu uso o seed como random_device 
	std::random_device       m_rd;
	Ran(Ullong j) : v(4101842887655102017LL), w(1) {
//		j =  m_rd();
		u = j ^ v; int64();
		v = u; int64();
		w = v; int64();
	}
	inline Ullong int64() {
		u = u * 2862933555777941757LL + 7046029254386353087LL;
		v ^= v >> 17; v ^= v << 31; v ^= v >> 8;
		w = 4294957665U*(w & 0xffffffff) + (w >> 32);
		Ullong x = u ^ (u << 21); x ^= x >> 35; x ^= x << 4;
		return (x + v) ^ w;
	}
	//Esta funcao doub, retorna um valor entre 0.0 a 1.0
	inline Doub doub() { return 5.42101086242752217E-20 * int64(); }
	inline Uint int32() { return (Uint)int64(); }
};




#endif /* GENERATENUMBERSNR_H_ */
