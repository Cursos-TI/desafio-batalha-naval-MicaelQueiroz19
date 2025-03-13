#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define LINHA = 10;
#define COLUNA = 10; 

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10]; // Define a matriz tabuleiro com 2 vetores de tamanho 10 cada.
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Define e cria um array de 1 vetor com tamenho 10.

    printf("TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    for (int k = 0; k < 10; k++){ // Imprime os dados das colunas.
        printf("%c ", linha[k]); // Exibe os nomes das colunas.
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {  // Imprime os dados das linhas e preenche o tabuleiro com "Água - 0".
        printf("%2d ", i + 1); // // Exibe os números das linhas.
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
            printf("%d ", tabuleiro[i][j]); // Exibe a Água.
        }
        printf("\n");
    }
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    
    for (int i = 4; i < 5; i++){ // Posiciona um navio de 3 posições na HORIZONTAL em 5-H-I-J.
        for (int j = 7; j < 10; j++){ // Fixa a Linha.
            if (i > 10 || i < 0 || j > 10 || j < 0){ // Exibe erro se coordenadas ultrapassarem limite do tabuleiro.
                printf("ERRO - Coordenadas Ultrapassam limite do Tabuleiro\n");
                break;
            }
            tabuleiro[i][j] = 3;
        }
    }

    for (int i = 2; i < 5; i++){ // Posiciona um navio de 3 posições na VERTICAL em E-3-4-5.
        for (int j = 4; j < 5; j++){ // Fixa a Coluna.
            if (i > 10 || i < 0 || j > 10 || j < 0){ // Exibe erro se coordenadas ultrapassarem limite do tabuleiro.
                printf("ERRO - Coordenadas Ultrapassam limite do Tabuleiro\n");
                break;
            }else if (tabuleiro[i][j] == 3){ // Exibe erro se segundo navio ocupar alguma posição do primeiro.
                printf("ERRO - Campo já preenchido com Navio\n");
                break;
            }
            tabuleiro[i][j] = 3;
        }
    }
    

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("\n\n");
    printf("TABULEIRO APÓS INSERÇÃO DOS NAVIOS\n");
    printf("   ");
    for (int k = 0; k < 10; k++){ // Imprime os dados das colunas
        printf("%c ", linha[k]); // Exibe os nomes das colunas
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++){
        printf("%2d ", i + 1); // // Exibe os números das linhas.
        for (int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
