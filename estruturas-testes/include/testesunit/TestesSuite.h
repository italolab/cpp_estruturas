#ifndef SUITE_DE_TESTES_H
#define SUITE_DE_TESTES_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define SUITE_DE_TESTES_API __declspec(dllexport)
    #else
        #define SUITE_DE_TESTES_API __declspec(dllimport)
    #endif
#else
    #define SUITE_DE_TESTES_API
#endif

#include <string>

#include "Testes.h"
#include "TestesGrupo.h"
#include "TestesResult.h"

using namespace std;

class SUITE_DE_TESTES_API TestesSuite : public Testes {

    private:
        vector<TestesGrupo*> testesVect;

    public:
        void add( TestesGrupo* );

        vector<string> testeFuncNomes();
        TestesResult* executaTeste( int testeIndice );
        TestesResult* executa();

};

#endif
