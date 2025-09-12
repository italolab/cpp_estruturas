#ifndef READ_UTIL_H
#define READ_UTIL_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define READUTIL_API __declspec(dllexport)
    #else
        #define READUTIL_API __declspec(dllimport)
    #endif
#else
    #define READUTIL_API
#endif

#include <iostream>

namespace readutil {

    READUTIL_API std::string readLine( std::string msg );

    READUTIL_API int readInt( std::string msg, std::string errorMsg );

    READUTIL_API int readDouble( std::string msg, std::string errorMsg );

}

#endif
