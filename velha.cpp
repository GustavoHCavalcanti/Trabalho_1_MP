#include "velha.hpp"
#include <iostream>

int JogoDaVelha::verificar_jogo(int matriz[3][3]) {
    int num_x = 0, num_o = 0;

    // Contagem de peças X e O
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 1) num_x++;
            if (matriz[i][j] == 2) num_o++;
        }
    }

    // Depuração - Verificar número de peças
    std::cout << "X: " << num_x << " O: " << num_o << std::endl;

    // Validação do número de peças
    if (num_x - num_o > 1 || num_o - num_x > 1) {
        return -2; // Jogo impossível
    }

    // Verifica linhas, colunas e diagonais para vitória
    bool vencedor_x = false, vencedor_o = false;
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0) {
            if (matriz[i][0] == 1) vencedor_x = true;
            if (matriz[i][0] == 2) vencedor_o = true;
        }
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != 0) {
            if (matriz[0][i] == 1) vencedor_x = true;
            if (matriz[0][i] == 2) vencedor_o = true;
        }
    }

    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != 0) {
        if (matriz[0][0] == 1) vencedor_x = true;
        if (matriz[0][0] == 2) vencedor_o = true;
    }
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != 0) {
        if (matriz[0][2] == 1) vencedor_x = true;
        if (matriz[0][2] == 2) vencedor_o = true;
    }

    // Depuração - Verificar se há vencedor
    std::cout << "Vencedor X: " << vencedor_x << " Vencedor O: " << vencedor_o << std::endl;

    // Verificação de jogo impossível: 
    if ((vencedor_x && vencedor_o) || (vencedor_x && num_x <= num_o) || (vencedor_o && num_x > num_o)) {
        return -2; // Jogo impossível
    }

    // Se X venceu
    if (vencedor_x) return 1; // X venceu
    // Se O venceu
    if (vencedor_o) return 2; // O venceu

    // Verifica se há empate
    bool empate = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 0) empate = false; // Se houver uma casa vazia, não é empate
        }
    }
    if (empate) return 0; // Empate

    // Caso não tenha terminado o jogo, retorna indefinido
    return -1; // Jogo indefinido
}














