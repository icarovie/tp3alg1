#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>

using namespace std;

class Sudoku{
    public:
        int **matriz;
        int tamanho; // Tamanho da  matriz
        int I; // colunas
        int J; // Linhas

        Sudoku(int I, int J, int tamanho, int** matriz);
        bool solucionarSudoku();
        bool verificarConflitos(int linha, int coluna, int valor);
        bool verificarSeExisteElementoNaPosicao(int linha, int coluna);
        bool sudokuAindaNaoFoiSolucionado(int &linha, int &coluna);
};

#endif