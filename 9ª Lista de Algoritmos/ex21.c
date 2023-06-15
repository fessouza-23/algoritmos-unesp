#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 100
#define MAX_PERGUNTAS 10

void fazerPerguntas(int perguntas[][1][MAX_PESSOAS], int pessoa) {
    int i, j;

    printf("Responda as perguntas com valores de 1 a 5\n");
    printf("Se desejar sair, apenas coloque 0 no questionario.\n");

    for (i = 0; i < MAX_PERGUNTAS; i++) {
        printf("Pergunta %d: ", i + 1);
        scanf("%d", &perguntas[i][0][pessoa]);

        if (perguntas[i][0][pessoa] == 0) {
            // Define todos os próximos valores como 0
            for (int k = i; k < MAX_PERGUNTAS; k++) {
                perguntas[k][0][pessoa] = 0;
            }
            break; // Sai do loop interno se a pessoa inserir 0
        }

        if (perguntas[i][0][pessoa] < 0 || perguntas[i][0][pessoa] > 5) {
            printf("Valor invalido!\n");
            i--; // Reitera a pergunta atual
        }
    }
}


void imprimirPessoa(int perguntas[][1][MAX_PESSOAS], int pessoa) {
    printf("Respostas da pessoa %d:\n", pessoa + 1);
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        printf("Pergunta %d: %d\n", i + 1, perguntas[i][0][pessoa]);
    }
    printf("\n");
}

int contarPessoasCompletas(int perguntas[][1][MAX_PESSOAS], int quantPessoas) {
    int pessoasCompletas = 0;
    for (int pessoa = 0; pessoa < quantPessoas; pessoa++) {
        int completas = 1;
        for (int i = 0; i < MAX_PERGUNTAS; i++) {
            if (perguntas[i][0][pessoa] == 0) {
                completas = 0;
                break;
            }
        }
        if (completas) {
            pessoasCompletas++;
        }
    }
    return pessoasCompletas;
}

int main(){
    int quantPessoas;

    do {
        printf("Digite a quantidade de pessoas que responderao: ");
        scanf("%d", &quantPessoas);
    } while(quantPessoas <= 0 || quantPessoas > MAX_PESSOAS);

    int perguntas[MAX_PERGUNTAS][1][MAX_PESSOAS];

    for (int i = 0; i < quantPessoas; i++) {
        system("cls");
        printf("=== Pessoa %d ===\n", i+1);
        fazerPerguntas(perguntas, i);
        printf("\n");
    }

    system("cls");
    printf("=== Respostas de cada pessoa ===\n");
    for (int i = 0; i < quantPessoas; i++) {
        imprimirPessoa(perguntas, i);
    }

    int pessoasCompletas = contarPessoasCompletas(perguntas, quantPessoas);
    printf("Numero de pessoas que responderam todas as perguntas: %d\n", pessoasCompletas);

    return 0;
}
