#ifndef NUM_UTIL_H
#define NUM_UTIL_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define NUMUTIL_API __declspec(dllexport)
    #else
        #define NUMUTIL_API __declspec(dllimport)
    #endif
#else
    #define NUMUTIL_API
#endif

namespace numutil {

    NUMUTIL_API int sorteiaNumero();

}

#endif
