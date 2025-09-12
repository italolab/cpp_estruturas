#ifndef TESTES_GRUPO_H
#define TESTES_GRUPO_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define TESTES_GRUPO_API __declspec(dllexport)
    #else
        #define TESTES_GRUPO_API __declspec(dllimport)
    #endif
#else
    #define TESTES_GRUPO_API
#endif

#include <string>

#include "Testes.h"
#include "TestesResult.h"

using namespace std;

class TESTES_GRUPO_API TestesGrupo : public Testes {

    typedef struct TFunc {
        string nome;
        function<void()> f;
    } TesteFunc;

    private:
        string nome;
        vector<TesteFunc> funcs;

    public:
        TestesGrupo( string nome );

        void add( string fname, function<void()> );
        int getQuantTestes();

        vector<string> testeFuncNomes();
        TestesResult* executaTeste( int testeIndice );
        TestesResult* executa();

};

#endif
