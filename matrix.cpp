#include "matrix.h"

bool licz_w_k(int &w, int &k)
{
    ifstream file("123.txt"); // otwieramy plik
    // todo mozna dac nazwe pliku jak parametr
    string sent; // deklarujemy zmienna pomoconicza

    if (!file)
    {
        return false;
    }

    while (getline(file, sent))
    {
        //todo mozna sprawdzac czy podany plik jest odpowiednio zformatowany i jesli nie to go sformatowac
        w++; // zliczamy ilosc wierszy
    }

    for (int i = 0; i < sent.size(); i++)
    {
        if(sent[i]==' '&&sent[i+1]<=57&&sent[i+1]>=49)// sprawdzam czy nastepny znak jest liczba( zabezpieczenie przed wieloma spacjami)
        {
            k++; // zakldam ze wszystkie dane se odpowiednie formatowanie to znaczy liczby sa odzielone odsiebie spacjami a nowe wiersze zaczynaja od nowej lini
        }
    }

    k++; // trzeba zwiekszyc o 1

    file.close(); // zamykam plik na ktorym pracowalem
    return true;
}

void stworz_tablice(int &w, int &k,double **tab2)
{
    double liczba; // zmienna pomocnicza
    ifstream file("123.txt"); // otwieramy plik
    string sent; // deklarujemy zmienna pomoconicza

    for ( int i = 0; i < w; ++i )
    {
        tab2[i] = new double [k]; //alokacja pamieci
        for ( int j = 0; j < k; ++j)
        {
            //wpisanie wartosci do tablicy
            file>>liczba;
            tab2[i][j]=liczba;
        }
    }

    file.close(); // zamykam plik na ktorym pracowalem

}

void znisze_tablice(int &w, int &k, double **&tab2)
{
    //zniszcz tab2
    for ( int i(0); i < w; ++i )
    {
        delete [] tab2[i]; //uwolnienie pamieci
    }

    delete [] tab2; //uwolnienie pamieci
    tab2 = NULL;
}
