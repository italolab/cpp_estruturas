#ifndef MAIOR_COMPARADOR_H
#define MAIOR_COMPARADOR_H

#include "Comparador.h"

template <typename T>
class MaiorComparador : public Comparador<T> {

    public:
        int compara( T n1, T n2 ) {
            return n1 > n2;
        }
};

#endif
