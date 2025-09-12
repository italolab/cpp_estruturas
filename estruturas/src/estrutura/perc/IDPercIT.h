#ifndef ID_PERC_IT_H
#define ID_PERC_IT_H

#ifdef _WIN32
	#if BUILDING_DLL
		#define ID_PERC_IT_API __declspec(dllexport)
	#else
		#define ID_PERC_IT_API __declspec(dllimport)
	#endif
#else
	#define ID_PERC_IT_API
#endif

#include "PercIT.h"
#include "../Objeto.h"

class ID_PERC_IT_API IDPercIT : public PercIT {

    public:
        void percorre( Objeto* );

};

#endif
