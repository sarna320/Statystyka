#include "interfejs.h"

void wyswietl_liste(Lista_Pomiar *pierwsza)
{
    // wskaznik na pierszy element listy
    Pomiar *temp = pierwsza->pierwsza;
    int i=1;

    // przewijamy wskazniki na nastepne elementy
    while (temp)
    {
        cout<<"Pomiar"<<i<<endl;
        i++;
        cout << "suma: " << temp->suma << " srednia: " << temp->srednia
             << " odchylenie: " << temp->odchylenie << " wariancja: " << temp->wariancja
             << " max: " << temp->max << " min: " << temp->min
             << " mediana: " << temp->mediana <<endl<<endl;
        temp = temp->nastepna;
    }
}

void drukuj_tablice(int &w, int &k,double **tab2)
{
    for ( int i = 0; i < w; ++i, cout<<endl )
    {
        for ( int j = 0; j < k; ++j)
        {
            cout<<tab2[i][j]<<'\t';
        }
    }
    cout<<endl;
}

bool interfejs()
{

    int w=0, k=0; // ilosc wierszy i kolumn
    if(licz_w_k(w,k)==false) // liczenie w i k
    {
        cout<<"Nie udalo sie znalezc pliku\n";
    }

    double **tab2 = new double *[w]; //alokacja pamieci dla macierzy z pomiarami
    stworz_tablice(w, k, tab2); // stworzenie tablicy danego pliku
    drukuj_tablice(w, k, tab2); // wydrukowanie stworzonej tablicy

    Lista_Pomiar *baza = new Lista_Pomiar; // lista jednokierunkowa z wszyskimi pomiarami

    for (int i = 0; i < k; ++i)// dla znanej wczesniej ilosc wierszy w macierzy, iterujemy po kolumnach i dodajemy pomiary
    {
        baza->dodaj_pomiar(tab2,w,i); // w funkcji dodaj pomiar nastepuje wyliczanie wszyskitch zmiennych struktury Pomiar
    }

    wyswietl_liste(baza); // wyswietlamy wyniki dla kazdego z pomiarow
    znisze_tablice(w, k, tab2); // zwalniamy pamiec
    baza->usun_liste(); // zwalniamy pamiec

}
