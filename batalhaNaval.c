#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define LINHA 10 // Define tamanho das linhas do tabuleiro.
#define COLUNA 10 // Define tamanho das colunas do tabuleiro.


int main() {
    int tabuleiro[10][10]; // Define a matriz tabuleiro com 2 vetores de tamanho 10 cada.
    char cabecalho[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Define e cria um array de 1 vetor com tamenho 10.
    int tamanho = 0, sobreposicao = 0; // Variáveis boleanas de indicação de erro.
    int cone[3][5], cruz[3][5], octaedro[3][5]; // matrizes de habilidades, com 3 linhas e 5 colunas.

    printf("TABULEIRO BATALHA NAVAL\n"); // Exibe mensagem do tabuleiro.
    printf("   "); // Exibe espaçamento.
    for (int k = 0; k < COLUNA; k++){ // Percorre dados das colunas.
        printf("%c ", cabecalho[k]); // Imprime os nomes das colunas.
    }
    printf("\n"); // Pula 1 linha.

    // Imprime os dados das linhas e preenche o tabuleiro com "Água = 0".
    for (int i = 0; i < LINHA; i++) {  
        printf("%2d ", i + 1); // // Exibe os números das linhas.
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = 0;  // Preenche a água.
            printf("%d ", tabuleiro[i][j]); // Exibe a Água.
        }
        printf("\n"); // Pula 1 linha.
    }

    // Posiciona um navio de 3 posições na HORIZONTAL em 5-H-I-J.
    for (int i = 4; i < 5; i++){ // Define que a verredura na LINHA da matriz é fixa.
        for (int j = 7; j < 10; j++){ // Varre a coluna
            if (i > LINHA || i < 0 || j > COLUNA || j < 0){ // Verifica se a varredura está dentro dos limites da matriz
                printf("ERRO - Coordenadas Ultrapassam limite do Tabuleiro\n"); // Printa mensagem de erro.
                tamanho = 1; // Muda tamanho para verdadeiro
                break; // Sai do if.
            }
            if (tamanho) break; // Se tamanho é igual a verdadeiro, fecha o for.
            tabuleiro[i][j] = 3;  // Preenche com navio.
        }
    }
    tamanho = 0; // Muda a variavel tamanho para falso.
    // Posiciona um navio de 3 posições na VERTICAL em E-7-8-9.
    for (int i = 6; i < 9; i++){ // Varre a linha
        for (int j = 4; j < 5; j++){ // Define que a verredura na COLUNA da matriz é fixa.
            if (i > LINHA || i < 0 || j > COLUNA || j < 0){ // Verifica se a varredura está dentro dos limites da matriz
                printf("ERRO - Coordenadas Ultrapassam limite do Tabuleiro\n"); // Printa mensagem de erro.
                tamanho = 1; // Muda tamanho para verdadeiro
                break; // Sai do if.
            }
            if (tamanho) break; // Se tamanho é igual a verdadeiro, fecha o for.
            if (tabuleiro[i][j] == 3){ // Exibe erro se segundo navio ocupar alguma posição do primeiro.
                printf("ERRO - Campo já preenchido com Navio\n"); // Exibe mensagem de erro.
                break; // Sai do if.
            }
            tabuleiro[i][j] = 3;  // Preenche com navio.
        }
    }
    
    tamanho = 0; // Muda a variavel tamanho para falso.
    sobreposicao = 0; // Muda a variavel sobreposicao para falso.
    // Imprimir diagonal 3C-4D-5E
    for (int i = 2; i < 5; i++){ 
        for (int j = 2; j < 5; j++){
            if (i > LINHA || i < 0 || j > COLUNA || j < 0){ // Verifica se a varredura está dentro dos limites da matriz
                printf("ERRO - Coordenadas Ultrapassam limite do Tabuleiro\n"); // Printa mensagem de erro.
                tamanho = 1; // Muda tamanho para verdadeiro
                break; // Sai do if.
            }
            if (tamanho) break; // Se tamanho é igual a verdadeiro, fecha o for.
            if (i == j && tabuleiro[i][j] == 3){ // Verifica se coordenadas estão ocupadas com outro navio.
                printf("ERRO - Coordenadas já ocupadas por navio.\n"); // Exibe mensagem de erro.
                sobreposicao = 1; // Muda sopreposição para verdadeiro
                break; // Sai do if.
            }
            if (sobreposicao) break; // Se sobreposição é igual a verdadeiro, fecha o for.
            if (i == j && tabuleiro[i][j] != 3){ // Verifica e campo está livre.
                tabuleiro[i][j] = 3; // Preenche com navio.
            }
        }
    }

    tamanho = 0; // Muda a variavel tamanho para falso.
    sobreposicao = 0; // Muda a variavel sobreposicao para falso.
    // Imprimir diagonal 2I-3H-4G
    for (int i = 1; i < 4; i++){ 
        for (int j = 0; j < 10; j++){
            if (i > LINHA || i < 0 || j > COLUNA || j < 0){ // Verifica se a varredura está dentro dos limites da matriz
                printf("ERRO - Coordenadas Ultrapassam limite do Tabuleiro.\n"); // Printa mensagem de erro.
                tamanho = 1; // Muda tamanho para verdadeiro
                break; // Sai do if.
            }
            if (tamanho) break; // Se tamanho é igual a verdadeiro, fecha o for.
            if (i + j == 9 && tabuleiro[i][j] == 3){ // Verifica se coordenadas estão ocupadas com outro navio.
                printf("ERRO - Coordenadas já ocupadas por navio.\n"); // Exibe mensagem de erro.
                sobreposicao = 1; // Muda sopreposição para verdadeiro
                break; // Sai do if.
            }
            if (sobreposicao) break; // Se sobreposição é igual a verdadeiro, fecha o for.
            if (i + j == 9 && tabuleiro[i][j] != 3){ // Verifica e campo está livre.
                tabuleiro[i][j] = 3; // Preenche com navio.
            }
        }
    }

    //Cone
    int cone_linha = 0; // Variável de inicio da linha (Deve ser menor que 8).
    int cone_coluna = 0; // Variável de inicio da coluna (Deve ser menor que 6).
    for (int i = cone_linha; i < cone_linha + 3; i++){ // Percorre a linha no range definido pelo tamanho da habilidade.
        for (int j = cone_coluna; j < cone_coluna + 5; j++){  // Percorre a coluna no range definido pelo tamanho da habilidade.
            if (i == cone_linha && j == cone_coluna + 2){ // Topo do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            } else if (i == cone_linha + 1 && j >= cone_coluna + 1 && j <= cone_coluna + 3){ // Meio do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            } else if (i == cone_linha + 2 && j >= cone_coluna && j <= cone_coluna + 5){ // Base do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            }
        }
    }

    //Cruz
    int cruz_linha = 7; // Variável de inicio da linha (Deve ser menor que 8).
    int cruz_coluna = 4; // Variável de inicio da coluna (Deve ser menor que 6).
    for (int i = cruz_linha; i < cruz_linha + 3; i++){ // Percorre a linha no range definido pelo tamanho da habilidade.
        for (int j = cruz_coluna; j < cruz_coluna + 5; j++){  // Percorre a coluna no range definido pelo tamanho da habilidade.
            if (i == cruz_linha && j == cruz_coluna + 2){ // Topo do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            } else if (i == cruz_linha + 1 && j >= cruz_coluna && j <= cruz_coluna + 5){ // Meio do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            } else if (i == cruz_linha + 2 && j == cruz_coluna + 2){ // Base do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            }
        }
    }

    //Octaedro
    int octaedro_linha = 7; // Variável de inicio da linha (Deve ser menor que 8).
    int octaedro_coluna = 0; // Variável de inicio da coluna (Deve ser menor que 6).
    for (int i = octaedro_linha; i < octaedro_linha + 3; i++){ // Percorre a linha no range definido pelo tamanho da habilidade.
        for (int j = octaedro_coluna; j < octaedro_coluna + 5; j++){  // Percorre a coluna no range definido pelo tamanho da habilidade.
            if (i == octaedro_linha && j == octaedro_coluna + 2){ // Topo do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            } else if (i == octaedro_linha + 1 && j >= octaedro_coluna + 1 && j <= octaedro_coluna + 3){ // Meio do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            } else if (i == octaedro_linha + 2 && j == octaedro_coluna + 2){ // Base do cone.
                if (tabuleiro[i][j] == 3){ // Verifica se no campo há um navio.
                    tabuleiro[i][j] = 1; // Se hou ver navio, ele preenche 1, habilidade acertou navio.
                } else {tabuleiro[i][j] = 5; // Se não houver navio, ele preenche com 5, habilidade não acertou navio.
                }
            }
        }
    }

    // Exibe Tabuleiro com Navios.
    printf("\n\n"); // Pula 2 linhas.
    printf("TABULEIRO APÓS INSERÇÃO DOS\nNAVIOS E USO DAS HABILIDADES\n"); // Exibe mensagem do tabuleiro.
    printf("   "); // Exibe espaçamento.
    for (int k = 0; k < COLUNA; k++){ // Imprime os dados das colunas.
        printf("%c ", cabecalho[k]); // Exibe os nomes das colunas.
    }
    printf("\n"); // Pula 1 linha.
    for (int i = 0; i < LINHA; i++){ // Percorre as linhas da matriz.
        printf("%2d ", i + 1); // // Exibe os números das linhas.
        for (int j = 0; j < COLUNA; j++){ // Percorre as colunas da matriz.
            printf("%d ", tabuleiro[i][j]); // Exibe o tabuleiro.
        }
        printf("\n"); // Pula 1 linha.
    }

    return 0;
}
