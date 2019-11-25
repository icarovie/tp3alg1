// Icaro Henrique Vieira
// 2018046556
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>
#include "Sudoku.hpp"

using namespace std;

int main(int argc, char **argv) {
    int **matriz;
    int tamanho;
    int I;
    int J;
    bool existeSolucaoSudoku;

    // Abro o arquivo
    char* file = argv[1];
    ifstream dados(file);

    dados >> tamanho;
    dados >> I;
    dados >> J;

    // Monto a matriz do Sudoku
    matriz = new int *[tamanho];
    for (int i = 0; i < tamanho; i++) {
        matriz[i] = new int[tamanho];
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            dados >> matriz[i][j];
            cout << matriz[i][j];
        }
        cout << endl;
    }
    cout << "------------------------" <<endl;
    Sudoku *sudoku = new Sudoku(I,J,tamanho,matriz);

    // Verifico se existe solução
    existeSolucaoSudoku = sudoku->solucionarSudoku();
    //(existeSolucaoSudoku == true) ? cout << "solucao" << endl : cout << "sem solucao" << endl;

    // Imprimo a matriz solucionada
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            cout << sudoku->matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}