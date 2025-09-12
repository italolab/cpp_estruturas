#ifndef TESTES_H
#define TESTES_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define TESTES_API __declspec(dllexport)
    #else
        #define TESTES_API __declspec(dllimport)
    #endif
#else
    #define TESTES_API
#endif

#include "TestesResult.h"

#include <functional>
#include <vector>

class TESTES_API Testes {

    public:
        virtual vector<string> testeFuncNomes() = 0;
        virtual TestesResult* executaTeste( int testeIndice ) = 0;
        virtual TestesResult* executa() = 0;

};

#endif
