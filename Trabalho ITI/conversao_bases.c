#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define esc 27
#define f1 0

/*
    Programa de conversão de bases
    Desenvolvido por Joao Victor Fernandes - RA: 231024967
    Introducao a Tecnologia da Informacao - BSI 2023 - 2 Periodo
*/

void setCorTexto(int cor) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void bem_vindo() {
  system("cls");
  printf("Bem vindo ao conversor de bases!\n"
         "Programa desenvolvido por Joao Victor Fernandes Souza\n"
         "Introducao a Tecnologia da Informacao - BSI 023 - 2 Periodo\n");
  getch();
}

void binario_octal() {
  char binario[100];
  int decimal = 0, octal = 0, i = 0, resto;

  system("cls");

  setCorTexto(11); // azul claro
  printf("BINARIO ");
  setCorTexto(15); // branco (6 tbm eh branco)
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("OCTAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero binario: ");
  scanf("%s", binario);

  for (i = 0; binario[i] != '\0'; i++) {
    if (binario[i] != '0' && binario[i] != '1') {
      printf("Erro: O numero digitado nao eh binario.\n");
      getch();
      return;
    }
  }

  for (i = 0; binario[i] != '\0'; i++) {
    decimal = decimal * 2 + (binario[i] - '0');
  }

  i = 1;
  while (decimal != 0) {
    resto = decimal % 8;
    octal += resto * i;
    decimal /= 8;
    i *= 10;
  }

  printf("O numero binario %s em octal eh %d.\n", binario, octal);
  getch();
}

void binario_decimal() {
  char binario[100];
  int decimal = 0, i = 0, resto;

  system("cls");

  setCorTexto(11); // azul claro
  printf("BINARIO ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("DECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero binario: ");
  scanf("%s", binario);

  for (i = 0; binario[i] != '\0'; i++) {
    if (binario[i] != '0' && binario[i] != '1') {
      printf("Erro: O numero digitado nao eh binario.\n");
      getch();
      return;
    }
  }

  for (i = 0; binario[i] != '\0'; i++) {
    decimal = decimal * 2 + (binario[i] - '0');
  }

  printf("O numero binario %s em decimal eh %d.\n", binario, decimal);
  getch();
}

void binario_hexadecimal() {
  char binario[100];
  int decimal = 0, i = 0, resto;
  char hexadecimal[100];
  int index = 0;

  system("cls");

  setCorTexto(11); // azul claro
  printf("BINARIO ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("HEXADECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero binario: ");
  scanf("%s", binario);

  for (i = 0; binario[i] != '\0'; i++) {
    if (binario[i] != '0' && binario[i] != '1') {
      printf("Erro: O numero digitado nao eh binario.\n");
      getch();
      return;
    }
  }

  for (i = 0; binario[i] != '\0'; i++) {
    decimal = decimal * 2 + (binario[i] - '0');
  }

  while (decimal != 0) {
    resto = decimal % 16;
    if (resto < 10) {
      hexadecimal[index] = resto + '0';
    } else {
      hexadecimal[index] = resto + 'A' - 10;
    }
    index++;
    decimal /= 16;
  }
  hexadecimal[index] = '\0';

  int start = 0;
  int end = index - 1;
  while (start < end) {
    char temp = hexadecimal[start];
    hexadecimal[start] = hexadecimal[end];
    hexadecimal[end] = temp;
    start++;
    end--;
  }

  printf("O numero binario %s em hexadecimal eh %s.\n", binario, hexadecimal);
  getch();
}

void octal_binario() {
  char octal[100];
  char binary[100];
  int i, j;

  system("cls");

  setCorTexto(10); // verde
  printf("OCTAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(14); // amarelo
  printf("BINARIO\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero octal: ");
  scanf("%s", octal);

  for (i = 0; octal[i] != '\0'; i++) {
    if (octal[i] < '0' || octal[i] > '7') {
      printf("Erro: O numero digitado nao eh octal.\n");
      getch();
      return;
    }
  }

  for (i = 0, j = 0; octal[i] != '\0'; i++, j += 3) {
    switch (octal[i]) {
    case '0':
      binary[j] = '0';
      binary[j + 1] = '0';
      binary[j + 2] = '0';
      break;
    case '1':
      binary[j] = '0';
      binary[j + 1] = '0';
      binary[j + 2] = '1';
      break;
    case '2':
      binary[j] = '0';
      binary[j + 1] = '1';
      binary[j + 2] = '0';
      break;
    case '3':
      binary[j] = '0';
      binary[j + 1] = '1';
      binary[j + 2] = '1';
      break;
    case '4':
      binary[j] = '1';
      binary[j + 1] = '0';
      binary[j + 2] = '0';
      break;
    case '5':
      binary[j] = '1';
      binary[j + 1] = '0';
      binary[j + 2] = '1';
      break;
    case '6':
      binary[j] = '1';
      binary[j + 1] = '1';
      binary[j + 2] = '0';
      break;
    case '7':
      binary[j] = '1';
      binary[j + 1] = '1';
      binary[j + 2] = '1';
      break;
    }
  }
  binary[j] = '\0';

  printf("O numero octal %s em binario eh %s.\n", octal, binary);
  getch();
}

void octal_decimal() {
  char octal[100];
  int decimal = 0;
  int i;

  system("cls");

  setCorTexto(10); // verde
  printf("OCTAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("DECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero octal: ");
  scanf("%s", octal);

  for (i = 0; octal[i] != '\0'; i++) {
    if (octal[i] < '0' || octal[i] > '7') {
      printf("Erro: O numero digitado nao eh octal.\n");
      getch();
      return;
    }
  }

  for (i = 0; octal[i] != '\0'; i++) {
    decimal = decimal * 8 + (octal[i] - '0');
  }

  printf("O numero octal %s em decimal eh %d.\n", octal, decimal);
  getch();
}

void octal_hexadecimal() {
  char octal[100];
  char hexadecimal[100];
  int decimal = 0;
  int i, j = 0;

  system("cls");

  setCorTexto(10); // verde
  printf("OCTAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("HEXADECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero octal: ");
  scanf("%s", octal);

  for (i = 0; octal[i] != '\0'; i++) {
    if (octal[i] < '0' || octal[i] > '7') {
      printf("Erro: O numero digitado nao eh octal.\n");
      getch();
      return;
    }
  }

  for (i = 0; octal[i] != '\0'; i++) {
    decimal = decimal * 8 + (octal[i] - '0');
  }

  while (decimal != 0) {
    int remainder = decimal % 16;
    if (remainder < 10) {
      hexadecimal[j++] = remainder + '0';
    } else {
      hexadecimal[j++] = remainder + 'A' - 10;
    }
    decimal /= 16;
  }
  hexadecimal[j] = '\0';

  int start = 0;
  int end = j - 1;
  while (start < end) {
    char temp = hexadecimal[start];
    hexadecimal[start] = hexadecimal[end];
    hexadecimal[end] = temp;
    start++;
    end--;
  }

  printf("O numero octal %s em hexadecimal eh %s.\n", octal, hexadecimal);
  getch();
}

bool isDecimal(const char *number) {
  int length = strlen(number);
  for (int i = 0; i < length; i++) {
    if (number[i] < '0' || number[i] > '9') {
      return false;
    }
  }
  return true;
}

void decimal_binario() {
  char decimal[100];
  char binary[100];
  int i = 0;

  system("cls");

  setCorTexto(12); // azul
  printf("DECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(14); // amarelo
  printf("BINARIO\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero decimal: ");
  scanf("%s", decimal);

  if (!isDecimal(decimal)) {
    printf("Erro: O numero digitado nao eh decimal.\n");
    getch();
    return;
  }

  int number = atoi(decimal);
  if (number == 0) {
    binary[0] = '0';
    binary[1] = '\0';
  } else {
    while (number != 0) {
      binary[i] = (number % 2) + '0';
      number /= 2;
      i++;
    }
    binary[i] = '\0';
  }

  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = binary[start];
    binary[start] = binary[end];
    binary[end] = temp;
    start++;
    end--;
  }

  printf("O numero decimal %s em binario eh %s.\n", decimal, binary);
  getch();
}

void decimal_octal() {
  char decimal[100];
  char octal[100];
  int i = 0;

  system("cls");

  setCorTexto(10); // verde
  printf("HEXADECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("OCTAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero decimal: ");
  scanf("%s", decimal);

  if (!isDecimal(decimal)) {
    printf("Erro: O numero digitado nao eh decimal.\n");
    getch();
    return;
  }

  int number = atoi(decimal);
  if (number == 0) {
    octal[0] = '0';
    octal[1] = '\0';
  } else {
    while (number != 0) {
      octal[i] = (number % 8) + '0';
      number /= 8;
      i++;
    }
    octal[i] = '\0';
  }

  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = octal[start];
    octal[start] = octal[end];
    octal[end] = temp;
    start++;
    end--;
  }

  printf("O numero decimal %s em octal eh %s.\n", decimal, octal);
  getch();
}

void decimal_hexadecimal() {
  char decimal[100];
  char hexadecimal[100];
  int i = 0;

  system("cls");

  setCorTexto(12); // azul
  printf("DECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // magenta
  printf("HEXADECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero decimal: ");
  scanf("%s", decimal);

  if (!isDecimal(decimal)) {
    printf("Erro: O numero digitado nao eh decimal.\n");
    getch();
    return;
  }

  int number = atoi(decimal); // converte string decimal para int
  if (number == 0) {
    hexadecimal[0] = '0';
    hexadecimal[1] = '\0';
  } else {
    while (number != 0) {
      int remainder = number % 16;
      if (remainder < 10) {
        hexadecimal[i] = remainder + '0';
      } else {
        hexadecimal[i] = remainder - 10 + 'A';
      }
      number /= 16;
      i++;
    }
    hexadecimal[i] = '\0';
  }

  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = hexadecimal[start];
    hexadecimal[start] = hexadecimal[end];
    hexadecimal[end] = temp;
    start++;
    end--;
  }

  printf("O numero decimal %s em hexadecimal eh %s.\n", decimal, hexadecimal);
  getch();
}

int isHexadecimal(char *hexadecimal) {
  for (int i = 0; hexadecimal[i] != '\0'; i++) {
    if (!((hexadecimal[i] >= '0' && hexadecimal[i] <= '9') ||
          (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') ||
          (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f'))) {
      return false; // Não é um caractere hexadecimal válido
    }
  }
  return true; // É um número hexadecimal válido
}

void hexadecimal_binario() {
  char hexadecimal[100];
  char binario[400] = "";
  int i = 0;

  system("cls");

  setCorTexto(13); // magenta
  printf("HEXADECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(14); // amarelo
  printf("BINARIO\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero hexadecimal: ");
  scanf("%s", hexadecimal);

  if (!isHexadecimal(hexadecimal)) {
    printf("Erro: O numero digitado nao eh hexadecimal.\n");
    getch();
    return;
  }

  // Tabela de conversão de hexadecimal para binário
  char *hexToBin[] = {"0000", "0001", "0010", "0011", "0100", "0101",
                      "0110", "0111", "1000", "1001", "1010", "1011",
                      "1100", "1101", "1110", "1111"};

  int length = strlen(hexadecimal);
  for (int j = 0; j < length; j++) {
    char hexDigit = hexadecimal[j];
    int decimal;

    if (hexDigit >= '0' && hexDigit <= '9') {
      decimal = hexDigit - '0';
    } else {
      decimal = hexDigit - 'A' + 10;
    }

    strcat(binario, hexToBin[decimal]);
  }

  printf("O numero hexadecimal %s em binario eh %s.\n", hexadecimal, binario);
  getch();
}

void hexadecimal_octal() {
  char hexadecimal[100];
  char octal[100] = "";

  system("cls");

  printf("HEXADECIMAL PARA OCTAL\n\n");

  printf("Digite um numero hexadecimal: ");
  scanf("%s", hexadecimal);

  // Validando se é um número hexadecimal válido
  if (!isHexadecimal(hexadecimal)) {
    printf("Erro: O numero digitado nao eh hexadecimal.\n");
    getch();
    return;
  }

  // Tabela de conversão de hexadecimal para binário
  char *hexToBin[] = {"0000", "0001", "0010", "0011", "0100", "0101",
                      "0110", "0111", "1000", "1001", "1010", "1011",
                      "1100", "1101", "1110", "1111"};

  // Convertendo hexadecimal para octal
  int length = strlen(hexadecimal);
  for (int i = 0; i < length; i++) {
    char hexDigit = hexadecimal[i];
    int decimal;

    if (hexDigit >= '0' && hexDigit <= '9') {
      decimal = hexDigit - '0';
    } else if (hexDigit >= 'A' && hexDigit <= 'F') {
      decimal = hexDigit - 'A' + 10;
    } else {
      decimal = hexDigit - 'a' + 10;
    }

    strcat(octal, hexToBin[decimal]);
  }

  // Convertendo binário para octal
  length = strlen(octal);
  int octalDigit = 0;
  for (int i = 0; i < length; i += 3) {
    octalDigit = 0;
    for (int j = 0; j < 3; j++) {
      if (i + j < length) {
        octalDigit = octalDigit * 2 + (octal[i + j] - '0');
      }
    }
    printf("%d", octalDigit);
  }

  printf("\n");
  getch();
}

void hexadecimal_decimal() {
  char hexadecimal[100];
  int decimal = 0;

  system("cls");

  setCorTexto(13); // magenta
  printf("HEXADECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("DECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero hexadecimal: ");
  scanf("%s", hexadecimal);

  if (!isHexadecimal(hexadecimal)) {
    printf("Erro: O numero digitado nao eh hexadecimal.\n");
    getch();
    return;
  }

  int length = strlen(hexadecimal);
  for (int i = 0; i < length; i++) {
    char hexDigit = hexadecimal[i];
    int digit;

    if (hexDigit >= '0' && hexDigit <= '9') {
      digit = hexDigit - '0';
    } else {
      digit = hexDigit - 'A' + 10;
    }

    decimal = decimal * 16 + digit;
  }

  printf("O numero hexadecimal %s em decimal eh %d.\n", hexadecimal, decimal);
  getch();
}

void menuBinario() {
  char op;

  do {
    system("cls");
    printf("\e[?25l");
    printf("================================  MENU BINARIO  "
           "=======================================\n");
    printf("Da base binaria, para qual base deseja converter?\n");
    printf("|ESC - Voltar |\n");
    printf("1 - Octal\n");
    printf("2 - Decimal\n");
    printf("3 - Hexadecimal\n");
    op = getch();

    switch (op) {
    case '1':
      binario_octal();
      break;

    case '2':
      binario_decimal();
      break;

    case '3':
      binario_hexadecimal();
      break;

    case esc:
      return;
      break;
    }
  } while (op != esc);
}

void menuOctal() {
  char op;

  do {
    system("cls");
    printf("\e[?25l");
    printf("================================  MENU OCTAL  "
           "=======================================\n");
    printf("Da base octal, para qual base deseja converter?\n");
    printf("|ESC - Voltar |\n");
    printf("1 - Binario\n");
    printf("2 - Decimal\n");
    printf("3 - Hexadecimal\n");
    op = getch();

    switch (op) {
    case '1':
      octal_binario();
      break;

    case '2':
      octal_decimal();
      break;

    case '3':
      octal_hexadecimal();
      break;

    case esc:
      return;
      break;
    }
  } while (op != esc);
}

void menuDecimal() {
  char op;

  do {
    system("cls");
    printf("\e[?25l");
    printf("================================  MENU DECIMAL  "
           "=======================================\n");
    printf("Da base decimal, para qual base deseja converter?\n");
    printf("|ESC - Voltar |\n");
    printf("1 - Binario\n");
    printf("2 - Octal\n");
    printf("3 - Hexadecimal\n");
    op = getch();

    switch (op) {
    case '1':
      decimal_binario();
      break;

    case '2':
      decimal_octal();
      break;

    case '3':
      decimal_hexadecimal();
      break;

    case esc:
      return;
      break;
    }
  } while (op != esc);
}

void menuHexadecimal() {
  char op;

  do {
    system("cls");
    printf("\e[?25l");
    printf("================================  MENU HEXADECIMAL  "
           "=======================================\n");
    printf("Da base hexadecimal, para qual base deseja converter?\n");
    printf("|ESC - Voltar |\n");
    printf("1 - Binario\n");
    printf("2 - Octal\n");
    printf("3 - Decimal\n");
    op = getch();

    switch (op) {
    case '1':
      hexadecimal_binario();
      break;

    case '2':
      hexadecimal_octal();
      break;

    case '3':
      hexadecimal_decimal();
      break;

    case esc:
      return;
      break;
    }
  } while (op != esc);
}

void menu() {
  char op;

  do {
    system("cls");
    printf("\e[?25l");
    printf("================================  MENU  "
           "=======================================\n");
    printf("De qual base deseja converter?\n");
    printf("|ESC - Sair | F1 - Sobre o Programa|\n");
    printf("1. Binario\n");
    printf("2. Octal\n");
    printf("3. Decimal\n");
    printf("4. Hexadecimal\n");
    op = getch();

    switch (op) {
    case '1':
      menuBinario();
      break;

    case '2':
      menuOctal();
      break;

    case '3':
      menuDecimal();
      break;

    case '4':
      menuHexadecimal();
      break;

    case esc:
      printf("\nSaindo do programa...\n\n");
      system("pause");
      break;

    case f1:
      // sobre();
      break;

    default:
      break;
    }
  } while (op != esc);
}

int main() {
  bem_vindo();
  menu();
}