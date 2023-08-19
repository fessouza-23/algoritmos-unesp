#include <stdio.h>
#define max 40

int main() {
    int v[max], i, num, acimaMd, abaixoMd, maiorNota, menorNota;
    char resp;
    float media, soma;

    do {
        soma = media = acimaMd = abaixoMd = maiorNota = 0;
        menorNota = 10;

        do {
            printf("Quantos alunos são? obs: [max = 40]\n");
            scanf("%d", &num);
        } while (num <= 0 || num > 40);

        for (i = 0; i < num; i++) {
            printf("Nota aluno %d: ", i + 1);
            scanf("%d", &v[i]);
            soma += v[i];
            (v[i] > 5) ? acimaMd++ : 0;
            (v[i] < 5) ? abaixoMd++ : 0;
            (v[i] < menorNota) ? menorNota = v[i] : 0;
            (v[i] > maiorNota) ? maiorNota = v[i] : 0;
        }

        media = soma / num;

        printf("Media da sala: %.2f\n", media);
        printf("Alunos abaixo da media: %.2f%%\n", (float)(abaixoMd * 100) / num);
        printf("Alunos acima da media: %.2f%%\n", (float)(acimaMd * 100) / num);
        printf("Razao entre maior e menor valor: %d / %d\n", maiorNota, menorNota);

        do {
            printf("Executa novamente? Sim(S)/Nao(N)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');

    return 0;
}
