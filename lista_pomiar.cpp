#include "lista_pomiar.h"

Lista_Pomiar::Lista_Pomiar()
{
    pierwsza = 0; // konstruktor
}

void Lista_Pomiar::dodaj_pomiar(double **tab2,int w_,int k_)
{
    Pomiar *nowa = new Pomiar;    // tworzy nowy element listy
    nowa->licz(tab2, w_, k_);    // wypełniamy naszymi danymi

    if (pierwsza==0) // sprawdzamy czy to pierwszy element listy
    {
        // jeżeli tak to nowy element jest teraz początkiem listy
        pierwsza = nowa;
    }

    else
    {
        // w przeciwnym wypadku wędrujemy na koniec listy
        Pomiar *temp = pierwsza;

        while (temp->nastepna)
        {
            // znajdujemy wskaźnik na ostatni element
            temp = temp->nastepna;
        }

        temp->nastepna = nowa;  // ostatni element wskazuje na nasz nowy
        nowa->nastepna = 0;     // ostatni nie wskazuje na nic
    }
}


void Lista_Pomiar::usun_liste()
{
    Pomiar *obecny = pierwsza;

    while(obecny)
    {
        Pomiar *temp = pierwsza;
        obecny = obecny->nastepna;
        delete temp;
    }

    pierwsza=nullptr;
}
