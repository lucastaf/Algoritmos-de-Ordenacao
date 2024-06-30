#include <iostream>
#include <cstdlib>
#include <ctime>
#include "testeDeasempenho.cpp"
#include "sortingAlgs.h"

using namespace std;

void menu()
{
    cout << "Bem vindo ao algoritmos de ordenacao" << endl;
    cout << endl;
    cout << "1. Teste automatico de algoritmos de ordenacao" << endl;
    cout << "2. Teste QuickSort" << endl;
    cout << "3. Teste InsertionSort" << endl;
    cout << "4. Teste SelectionSort" << endl;
    cout << "5. Teste BubbleSort" << endl;
    cout << "6. Teste MergeSort" << endl;
    cout << "7. Teste ShellSort" << endl;
    cout << "8. Historico" << endl;
    cout << "9. Configuracoes" << endl;
    cout << "0. Sair" << endl;
    cout << "" << endl;
}

string tipoVetorToStr(int tipo)
{
    switch (tipo)
    {
    case vetorAleatorio:
        return "Aleatório";
        break;
    case melhorCaso:
        return "Melhor Caso";
        break;
    case piorCaso:
        return "Pior Caso";
        break;
    }

    return "Indefinido";
}

void configuracoes(int &TAM, int &nVetores, bool &exibir, int &tipoVetor)
{
    bool config = true;
    int controle;

    while (config)
    {
        cout << "Menu de configuracoes, digite uma opcao:" << endl;
        cout << "1. Quantidade de vetores: " << nVetores << endl;
        cout << "2. Tamanho dos vetores: " << TAM << endl;
        cout << "3. Tipo de vetor: " << tipoVetorToStr(tipoVetor) << endl;
        cout << "4. Exibir vetor: " << (exibir ? "Sim" : "Nao") << endl;
        cout << "5. Limpar historico" << endl;
        cout << "0. Sair" << endl
             << endl;
        cout << "Escolha uma opcao: ";
        cin >> controle;

        switch (controle)
        {
        case 1:
            cout << "Digite a nova quantidade de vetores: ";
            cin >> nVetores;
            cout << "Quantidade de vetores atualizada para: " << nVetores << endl;
            break;
        case 2:
            cout << "Digite o novo tamanho dos vetores: ";
            cin >> TAM;
            cout << "Tamanho dos vetores atualizado para: " << TAM << endl;
            break;
        case 3:
            cout << "Digite o novo tipo de vetor (0: aleatório, 1: ordenado, 2:invertido): ";
            cin >> tipoVetor;
            cout << "Tipo de vetor atualizado para: " << tipoVetorToStr(tipoVetor) << endl;
            break;
        case 4:
            exibir = !exibir;
            cout << "Exibir vetor configurado para: " << (exibir ? "Sim" : "Nao") << endl;
            break;
        case 5:
            // Limpar histórico
            if (limparHistorico())
            {
                cout << "Historico limpo com sucesso!" << endl;
            }
            else
            {
                cout << "Erro ao limpar historico." << endl;
            }
            break;
        case 0:
            config = false;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }
}

void testeOrdenaçãoType(int fillID, void (*algOrdenacao)(int[], int), string nomeAlgOrdenacao, int TAM, int nVetores)
{
    switch(fillID){
        case vetorAleatorio:
            testeOrdenacao(preencher_aleatorio, "Aleatorio", algOrdenacao, nomeAlgOrdenacao, TAM, nVetores);
        break;
        case melhorCaso:
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor Caso", algOrdenacao, nomeAlgOrdenacao, TAM, nVetores);
        break;
        case piorCaso:
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior Caso", algOrdenacao, nomeAlgOrdenacao, TAM, nVetores);
        break;
    }
}

int main()
{
    bool interface = true, exibir = false;
    srand(time(NULL));
    int controle, nVetores = 10, TAM = 100000, tipoVetor = vetorAleatorio;

    while (interface)
    {
        cout << "“\e[1;1H\e[2J";
        menu();
        cout << "Escolha uma opcao: ";
        cin >> controle;
        cout << "“\e[1;1H\e[2J";

        switch (controle)
        {
        case 1:
            cout << "Teste automatico ainda nao implementado." << endl;

            testeOrdenacao(preencher_aleatorio, "Aleatorio", bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor caso", bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", quickSortWrapper, "QuickSort", TAM, nVetores);
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor caso", quickSortWrapper, "QuickSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", quickSortWrapper, "QuickSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", insertionSort, "InsertionSort", TAM, nVetores);
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor caso", insertionSort, "InsertionSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", insertionSort, "InsertionSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", selectionSort, "SelectionSort", TAM, nVetores);
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor caso", selectionSort, "SelectionSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", selectionSort, "SelectionSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", mergeSortWrapper, "MergeSort", TAM, nVetores);
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor caso", mergeSortWrapper, "MergeSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", mergeSortWrapper, "MergeSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", shellSort, "ShellSort", TAM, nVetores);
            testeOrdenacao(gerarMelhorCasoCrescente, "Melhor caso", shellSort, "ShellSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", shellSort, "ShellSort", TAM, nVetores);

            break;
        case 2:

            testeOrdenaçãoType(tipoVetor, quickSortWrapper, "QuickSort", TAM, nVetores);
            break;
        case 3:

            testeOrdenaçãoType(tipoVetor, insertionSort, "InsertionSort", TAM, nVetores);
            break;
        case 4:

            testeOrdenaçãoType(tipoVetor, selectionSort, "SelectionSort", TAM, nVetores);
            break;
        case 5:

            testeOrdenaçãoType(tipoVetor, bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);
            break;
        case 6:

            testeOrdenaçãoType(tipoVetor, mergeSortWrapper, "MergeSort", TAM, nVetores);
            break;
        case 7:

            testeOrdenaçãoType(tipoVetor, shellSort, "ShellSort", TAM, nVetores);
            break;
        case 8:
            int aux;
            mostrarHistorico();
            cin >> aux;
            break;
        case 9:
            cout << "Configuracoes." << endl;
            configuracoes(TAM, nVetores, exibir, tipoVetor);

            break;
        case 0:
            interface = false;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}
