#ifndef OBJETO_H
#define OBJETO_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define OBJETO_API __declspec(dllexport)
    #else
        #define OBJETO_API __declspec(dllimport)
    #endif
#else
	#define OBJETO_API
#endif

class OBJETO_API Objeto {
		
};

#endif
