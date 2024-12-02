// testa_velha.cpp
#include <iostream>
#include "velha.hpp"

void teste_vencedor_x() {
    int matriz[3][3] = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    };
    int resultado = JogoDaVelha::verificar_jogo(matriz);
    if (resultado == 1) {
        std::cout << "Teste passou: O vencedor é X\n";
    } else {
        std::cout << "Teste falhou\n";
    }
}

void teste_vencedor_o() {
    int matriz[3][3] = {
        {2, 2, 2},
        {0, 1, 0},
        {1, 0, 1}
    };
    int resultado = JogoDaVelha::verificar_jogo(matriz);
    if (resultado == 2) {
        std::cout << "Teste passou: O vencedor é O\n";
    } else {
        std::cout << "Teste falhou\n";
    }
}

void teste_empate() {
    int matriz[3][3] = {
        {1, 2, 1},
        {2, 1, 2},
        {2, 1, 1}
    };
    int resultado = JogoDaVelha::verificar_jogo(matriz);
    if (resultado == 0) {
        std::cout << "Teste passou: O jogo empatou\n";
    } else {
        std::cout << "Teste falhou\n";
    }
}

void teste_indefinido() {
    int matriz[3][3] = {
        {1, 2, 0},
        {1, 0, 0},
        {2, 0, 0}
    };
    int resultado = JogoDaVelha::verificar_jogo(matriz);
    if (resultado == -1) {
        std::cout << "Teste passou: O jogo está indefinido\n";
    } else {
        std::cout << "Teste falhou\n";
    }
}

void teste_impossivel() {
    int matriz[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    int resultado = JogoDaVelha::verificar_jogo(matriz);
    if (resultado == -2) {
        std::cout << "Teste passou: O jogo é impossível\n";
    } else {
        std::cout << "Teste falhou\n";
    }
}

int main() {
    teste_vencedor_x();
    teste_vencedor_o();
    teste_empate();
    teste_indefinido();
    teste_impossivel();
    return 0;
}