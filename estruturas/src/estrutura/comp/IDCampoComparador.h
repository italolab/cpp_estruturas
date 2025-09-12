#ifndef ID_CAMPO_COMPARADOR_H
#define ID_CAMPO_COMPARADOR_H

#ifdef _WIN32
	#if BUILDING_DLL
		#define ID_CAMPO_COMPARADOR_API __declspec(dllexport)
	#else
		#define ID_CAMPO_COMPARADOR_API __declspec(dllimport)
	#endif
#else
	#define ID_CAMPO_COMPARADOR_API
#endif

#include "CampoComparador.h"

class ID_CAMPO_COMPARADOR_API IDCampoComparador : public CampoComparador {
	
	private:
		int id;
					
	public:
		IDCampoComparador( int );
		
		int compara( Objeto* );
	
};

#endif
