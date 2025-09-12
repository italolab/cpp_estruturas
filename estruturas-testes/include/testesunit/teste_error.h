#ifndef TESTE_ERROR_H
#define TESTE_ERROR_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define TESTE_ERROR_API __declspec(dllexport)
    #else
        #define TESTE_ERROR_API __declspec(dllimport)
    #endif
#else
    #define TESTE_ERROR_API
#endif

#include <stdexcept>
#include <iostream>

using namespace std;

class TESTE_ERROR_API teste_error : public runtime_error {

    public:
        teste_error( string msg );

};

#endif
