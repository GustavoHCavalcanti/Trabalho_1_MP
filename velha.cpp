// velha.cpp
#include "velha.hpp"

int JogoDaVelha::verificar_jogo(int matriz[3][3]) {
    // Contagem das peças "X" e "O"
    int num_x = 0, num_o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 1) num_x++;
            if (matriz[i][j] == 2) num_o++;
        }
    }

    // Verifica se o número de X e O é válido
    if (num_x < num_o || num_x > num_o + 1) {
        return -2; // Jogo impossível
    }

    // Verifica as linhas, colunas e diagonais para encontrar um vencedor
    for (int i = 0; i < 3; i++) {
        // Verifica linhas
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0) {
            return matriz[i][0]; // Retorna o vencedor
        }

        // Verifica colunas
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != 0) {
            return matriz[0][i]; // Retorna o vencedor
        }
    }

    // Verifica as diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != 0) {
        return matriz[0][0]; // Retorna o vencedor
    }
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != 0) {
        return matriz[0][2]; // Retorna o vencedor
    }

    // Verifica se há empate
    bool empate = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 0) {
                empate = false; // Se houver espaço vazio, não é empate
                break;
            }
        }
    }

    if (empate) return 0; // Jogo empatado

    // Verifica se o jogo está indefinido
    if (num_x > num_o) return -1; // Jogo indefinido

    return -2; // Jogo impossível
}