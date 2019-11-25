#include <iostream>

#include "Sudoku.hpp"

using namespace std;

Sudoku::Sudoku(int I, int J, int tamanho, int** matriz){
    this->I = I;
    this->J = J;
    this->tamanho = tamanho;
    this->matriz = matriz;
}

bool Sudoku::solucionarSudoku(){
    int linha, coluna;

    // Se o sudoku já tiver sido solucionado
    if (!sudokuAindaNaoFoiSolucionado(linha, coluna)) {
        return true;
    }

    /*
    * Primeiro vou ver se posso colocar o valor naquela posição,
    * Caso eu possa, eu resolvo a proxima atribuição, e se eu não conseguir
    * Eu uso o Backtrack para tentar de novo
    */
    int valor = 1;
    while(valor <= tamanho){
        if(!verificarConflitos(linha,coluna,valor)){
            matriz[linha][coluna] = valor;

            if(solucionarSudoku())
                return true;
            
            matriz[linha][coluna] = 0;
        }
     valor++;
    }
    return false;
}

bool Sudoku::sudokuAindaNaoFoiSolucionado(int &linha, int &coluna) {
    linha = 0;
    coluna = 0;

    while(linha <  tamanho){
        while(coluna < tamanho){
            if (matriz[linha][coluna] == 0)
                return true;
            coluna++;
        }
        linha++;
    }
    return false;
}

bool Sudoku::verificarConflitos(int linha, int coluna, int valor){
    bool conflitoLinha = false;
    bool conflitoColuna = false;
    bool conflitoQuadrante = false;
    bool existeElemento = verificarSeExisteElementoNaPosicao(linha,coluna);

    // Verifico se há  conflito na linha
    for (int coluna = 0; coluna < tamanho; coluna++) {
        int posicao = matriz[linha][coluna];
        if ( posicao == valor){ conflitoLinha = true; }
    }

    // Verifico se há conflito na coluna
    for (int linha = 0; linha < tamanho; linha++) {
        int posicao = matriz[linha][coluna];
        if (posicao == valor) { conflitoColuna = true;}
    }

    // Verifico se há conflito no quadrante
    for (int x = 0; x < J; x++) {
        for (int y = 0; y < I; y++) {
            if (matriz[x + linha - linha % J][y + coluna - coluna % I] == valor) {
                conflitoQuadrante = true;
            }
        }
    }
    return ( conflitoLinha || conflitoColuna || conflitoQuadrante ||existeElemento);
}

bool Sudoku::verificarSeExisteElementoNaPosicao(int linha, int coluna){
    return (matriz[linha][coluna] == 0) ? false : true;
}