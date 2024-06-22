#include <time.h>
#include <iostream>
#include "sortingAlgs.h"
#define TAM 20
using namespace std;

void preencher_aleatorio(int vetor[], int tam, int maximo = 100)
{
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % maximo + 1;
    }
}

void mostrar_array(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << ", ";
    }
    cout << endl;
}


int main()
{
    srand(time(NULL));
    int vetor[TAM];

    preencher_aleatorio(vetor, TAM);

    mergeSort(vetor,0,TAM -1);
    //quickSort(vetor, 0, TAM - 1);
    mostrar_array(vetor, TAM);

    return 0;
}