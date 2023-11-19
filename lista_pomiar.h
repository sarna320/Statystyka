#ifndef LISTA_POMIAR_H
#define LISTA_POMIAR_H

#include <iostream>
#include<pomiar.h>

struct Lista_Pomiar {
    Pomiar *pierwsza; // wskaźnik na początek listy
    void dodaj_pomiar(double **tab2, int w_, int k_);
    void usun_liste();
    Lista_Pomiar(); // konstruktor
};

#endif // LISTA_POMIAR_H
