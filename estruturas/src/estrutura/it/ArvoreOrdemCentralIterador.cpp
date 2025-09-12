
#include "ArvoreOrdemCentralIterador.h"

ArvoreOrdemCentralIterador::ArvoreOrdemCentralIterador( Arv* raiz ) {
    perc = menorEsq( raiz );
    vaiParaBaixo = true;
    vemDaEsquerda = false;
}

bool ArvoreOrdemCentralIterador::temProx() {
    return perc != nullptr;
}

Objeto* ArvoreOrdemCentralIterador::prox() {
    if ( perc == nullptr )
        return nullptr;

    Arv* aux = perc;
    if ( vaiParaBaixo ) {
        if ( perc->esq == nullptr && perc->dir == nullptr ) {
            if ( perc == perc->pai->esq ) {
                perc = perc->pai;
                vaiParaBaixo = false;
                vemDaEsquerda = true;
            } else {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = false;
            }
        } else {
            if ( perc->dir == nullptr ) {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = false;
            } else {
                perc = menorEsq( perc->dir );
            }
        }
    } else {
        if ( vemDaEsquerda ) {
            if ( perc->dir == nullptr ) {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = true;
            } else {
                perc = menorEsq( perc->dir );
            }
        } else {
            perc = paiNaoIterado( perc );
            vaiParaBaixo = true;
        }
    }
    aux->iterado = true;
    return aux->dados;
}

Arv* ArvoreOrdemCentralIterador::paiNaoIterado( Arv* perc ) {
    if ( perc == nullptr )
        return nullptr;

    if ( perc->pai != nullptr )
        vemDaEsquerda = ( perc == perc->pai->esq ? true : false );

    Arv* p = perc->pai;
    bool iterado = ( p != nullptr ? p->iterado : false );
    while( p != nullptr && iterado ) {
        if ( p->pai != nullptr )
            vemDaEsquerda = ( p == p->pai->esq ? true : false );

        p = p->pai;
        iterado = ( p != nullptr ? p->iterado : false );
    }

    return p;
}

Arv* ArvoreOrdemCentralIterador::menorEsq( Arv* perc ) {
    if ( perc == nullptr )
        return nullptr;

    Arv* p = perc;
    p->iterado = false;
    while( p->esq != nullptr ) {
        p = p->esq;
        p->iterado = false;
    }
    return p;
}





