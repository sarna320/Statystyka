#include "pomiar.h"

Pomiar::Pomiar()
{
    this->nastepna = 0; // konstruktor
    this->suma=0;
    this->max=0;
    this->min=0;
    this->mediana=0;
    this->odchylenie=0;
    this->wariancja=0;
    this->srednia=0;
}

void Pomiar::licz(double **tab2,int w_,int k_)
{
    // problem ten mozna by rozwiazac znacznie efektywniej, ale w celach
    //projektowo-edukacyjnych wszystkie akcje, zostaly rozdzielone na rozne funkcje
    licz_max(tab2,w_,k_);
    licz_min(tab2,w_,k_);
    licz_suma(tab2,w_,k_);
    licz_srednia(w_);
    licz_wariancja(tab2,w_,k_);
    licz_odchylenie(tab2,w_,k_);
    licz_mediana(tab2,w_,k_);

}

void Pomiar::licz_max(double **tab2,int w_,int k_)
{
    this->max=tab2[0][k_]; // pierwsza zmienna w kolumnie jako max

    for (int i = 0; i < w_; ++i)
    {
        if(tab2[i][k_]>this->max) // sprawdzanie czy istnieje wieksza
        {
            this->max=tab2[i][k_]; // jesli tak to zostaje podmieniona
        }
    }
}

void Pomiar::licz_min(double **tab2,int w_,int k_)
{
    this->min=tab2[0][k_]; // pierwsza zmienna w kolumnie jako min

    for (int i = 0; i < w_; ++i)
    {
        if(tab2[i][k_]<this->min) // sprawdzanie czy istnieje mniejsza
        {
            this->min=tab2[i][k_]; // jesli tak to zostaje podmieniona
        }
    }
}

void Pomiar::licz_suma(double **tab2,int w_,int k_)
{
    for (int i = 0; i < w_; ++i)
    {
        this->suma+=tab2[i][k_]; // liczenie sumy
    }

}

void Pomiar::licz_srednia(int w_)
{
        this->srednia=suma/w_; // w glownej funkcji licz najpierw musi zostac policzona suma, a dopiero nastepnie srednia
}

void Pomiar::licz_wariancja(double **tab2,int w_,int k_)
{
    for (int i = 0; i < w_; ++i)
    {
        this->wariancja+=pow((tab2[i][k_]-this->srednia),2); // liczenie wariancji
    }

    this->wariancja=this->wariancja/w_;

}

void Pomiar::licz_odchylenie(double **tab2,int w_,int k_)
{
    for (int i = 0; i < w_; ++i)
    {
        this->odchylenie+=pow((tab2[i][k_]-this->srednia),2); // liczenie odchylenia
    }

    this->odchylenie=sqrt(this->odchylenie/w_);

}

void Pomiar::sortujTablice(double tablica[], int rozmiar) // algorytm babelkowy
{
    for (int i = 0; i < rozmiar - 1; i++)
    {
        for (int j = 0; j < rozmiar - i - 1; j++)
        {
            if (tablica[j] > tablica[j + 1])
            {
                // Zamiana miejscami, jeśli elementy są w złym porządku
                double temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

void Pomiar::licz_mediana(double **tab2,int w_,int k_)
{
    double tab[w_];

    for (int i = 0; i < w_; ++i)
    {
        tab[i]=tab2[i][k_]; // utworzenie pomocniczej tablicy ktora sklada sie jedynie z kolumny
    }

    Pomiar::sortujTablice(tab,w_); // posortowanie jej

    //obliczenie mediany
    if(w_%2==0)
    {
        this->mediana=(tab[w_ / 2 - 1] + tab[w_ / 2]) / 2;
    }

    else
    {
        this->mediana=tab[(w_ - 1) / 2];
    }

}
