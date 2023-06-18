#include <stdio.h>
#include <stdlib.h>

int main() {
    float v[12][12], soma, media;
    int n, i, j;
    char c;

    scanf("%d", &n);
    scanf("%c", &c);
    if (c == 'S') {
        for(i = 0; i < 12; i++) {
            for(j = 0; j < 12; j++) {
                soma += v[i][j];
            }
        }
        printf("%.2f\n");
    } else {
        media = soma / 12.0;
        printf("%.2f\n", media);
    }

    return 0;
}