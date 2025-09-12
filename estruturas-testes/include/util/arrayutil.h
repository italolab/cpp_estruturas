#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define ARRAY_UTIL_API __declspec(dllexport)
    #else
        #define ARRAY_UTIL_API __declspec(dllimport)
    #endif
#else
    #define ARRAY_UTIL_API
#endif

#include "comp/Comparador.h"

namespace arrayutil {

    ARRAY_UTIL_API bool verificaSeArraysIguais( int*, int*, int );

    ARRAY_UTIL_API int* copiaVetor( int*, int );

    ARRAY_UTIL_API void selectionSort( int*, int );

    ARRAY_UTIL_API void inversoSelectionSort( int*, int );

}

#endif
