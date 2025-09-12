#ifndef PERC_IT_H
#define PERC_IT_H

#ifdef _WIN32
	#if BUILDING_DLL
		#define PERC_IT_API __declspec(dllexport)
	#else
		#define PERC_IT_API __declspec(dllimport)
	#endif
#else
	#define PERC_IT_API
#endif

#include "../Objeto.h"

class PERC_IT_API PercIT {

	public:
		virtual void processa( Objeto* ) = 0;

};

#endif
