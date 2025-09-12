#ifndef TESTES_RESULT_H
#define TESTES_RESULT_H

#ifdef _WIN32
    #if BUILDING_DLL
        #define TESTES_RESULT_API __declspec(dllexport)
    #else
        #define TESTES_RESULT_API __declspec(dllimport)
    #endif
#else
    #define TESTES_RESULT_API
#endif

#include <string>

using namespace std;

class TESTES_RESULT_API TestesResult {

    private:
        string msg;
        int quantErros;

    public:
        TestesResult( string msg, int quantErros );
        string getMensagem();
        int getQuantErros();

};

#endif
