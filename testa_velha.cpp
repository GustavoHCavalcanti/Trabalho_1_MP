#include "velha.hpp"
#include <gtest/gtest.h>

TEST(VencedorX, VerificaVitoriaX) {
    int matriz[3][3] = {{1, 1, 1}, {0, 2, 0}, {2, 0, 0}};
    JogoDaVelha jogo; // Cria um objeto da classe
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, 1); // X venceu
}

TEST(VencedorO, VerificaVitoriaO) {
    int matriz[3][3] = {{2, 2, 2}, {0, 1, 0}, {1, 0, 0}};
    JogoDaVelha jogo;
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, 2); // O venceu
}

TEST(Empate, VerificaEmpate) {
    int matriz[3][3] = {{1, 2, 1}, {1, 2, 2}, {2, 1, 1}};
    JogoDaVelha jogo;
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, 0); // Jogo empatado
}

TEST(JogoIndefinido, VerificaJogoIndefinido) {
    int matriz[3][3] = {{1, 2, 0}, {1, 0, 2}, {2, 1, 0}};
    JogoDaVelha jogo;
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, -1); // Jogo indefinido
}

TEST(JogoImpossivel, VerificaJogoImpossivel) {
    int matriz[3][3] = {{1, 1, 1}, {2, 2, 2}, {0, 0, 0}};
    JogoDaVelha jogo;
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, -2); // Jogo impossível
}

TEST(VencedorXHorizontal, VerificaVitoriaHorizontalX) {
    int matriz[3][3] = {{1, 1, 1}, {2, 2, 0}, {0, 0, 0}};
    JogoDaVelha jogo;
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, 1); // X venceu na linha 1
}

TEST(VencedorOVertical, VerificaVitoriaVerticalO) {
    int matriz[3][3] = {{1, 2, 1}, {1, 2, 0}, {0, 2, 0}};
    JogoDaVelha jogo;
    int resultado = jogo.verificar_jogo(matriz);
    EXPECT_EQ(resultado, 2); // O venceu na coluna 2
}



