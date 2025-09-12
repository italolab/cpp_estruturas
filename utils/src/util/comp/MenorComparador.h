#ifndef MENOR_COMPARADOR_H
#define MENOR_COMPARADOR_H

#include "Comparador.h"

template <typename T>
class MenorComparador : public Comparador<T> {

    public:
        int compara( T n1, T n2 ) {
            return n1 < n2;
        }
};

#endif
