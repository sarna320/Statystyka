#ifndef POMIAR_H
#define POMIAR_H

#include<cmath>

struct Pomiar {
    double suma;
    double srednia;
    double odchylenie;
    double wariancja;
    double max;
    double min;
    double mediana;
    Pomiar *nastepna; // wskaźnik na następny element
    Pomiar(); // konstruktor
    void licz(double **tab2,int w_,int k_);
    void licz_max(double **tab2,int w_,int k_);
    void licz_min(double **tab2,int w_,int k_);
    void licz_suma(double **tab2,int w_,int k_);
    void licz_srednia(int w_);
    void licz_odchylenie(double **tab2, int w_, int k_);
    void licz_wariancja(double **tab2,int w_,int k_);
    void licz_mediana(double **tab2,int w_,int k_);
    void sortujTablice(double tablica[], int rozmiar);
};

#endif // POMIAR_H
