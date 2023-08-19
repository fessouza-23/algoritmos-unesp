#include <stdio.h>

int main() {
    int n, i, j = 0, aux[1][3], cont;

    do {
        printf("Digite quantas datas serao lidas: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    int data[n][3];

    printf("Digite a data (dd/mm/aaaa)\n");
    for (i = 0; i < n; i++) {
        printf("Data %d: ", i+1);
        scanf("%d/%d/%d", &data[i][j], &data[i][j+1], &data[i][j+2]);
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (data[i][2] > data[j][2]) {
                for (cont = 0; cont < 3; cont++) {
                    aux[0][cont] = data[j][cont];
                    data[j][cont] = data[i][cont];
                    data[i][cont] = aux[0][cont];
                }
            } else if (data[i][1] > data[j][1] && data[i][2] == data[j][2]) {
                for (cont = 0; cont < 3; cont++) {
                    aux[0][cont] = data[j][cont];
                    data[j][cont] = data[i][cont];
                    data[i][cont] = aux[0][cont];
                }
            } else if (data[i][0] > data[j][0] && data[i][1] == data[j][1] && data[i][2] == data[j][2]) {
                for (cont = 0; cont < 3; cont++) {
                    aux[0][cont] = data[j][cont];
                    data[j][cont] = data[i][cont];
                    data[i][cont] = aux[0][cont];
                }
            }
        }
    }

    for (i = 0, j = 0; i < n; i++) {
        printf("%d/%d/%d\n", data[i][j], data[i][j+1], data[i][j+2]);
    }

    return 0;
}
