
#ifndef ITERADOR_H
#define ITERADOR_H

#ifdef _WIN32
	#if BUILDING_DLL
		#define ITERADOR_API __declspec(dllexport)
	#else
		#define ITERADOR_API __declspec(dllimport)
	#endif
#else
	#define ITERADOR_API
#endif

#include "../Objeto.h"

class ITERADOR_API Iterador {

	public:
	    virtual bool temProx() = 0;
		virtual Objeto* prox() = 0;

};

#endif
