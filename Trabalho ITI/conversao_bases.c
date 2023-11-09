/*
    Programa de conversão de bases
    Desenvolvido por Joao Victor Fernandes - RA: 231024967
    Introducao a Tecnologia da Informacao - BSI 2023 - 2 Periodo
*/

#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define esc 27
#define f1 0

// Função para alterar a cor do texto
void setCorTexto(int cor) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void bem_vindo() {
    system("cls");
    setCorTexto(14); // Amarelo
    printf("********************************************\n");
    printf("*                                          *\n");
    printf("*  Bem vindo ao Conversor de Bases!        *\n");
    printf("*                                          *\n");
    printf("*  Programa desenvolvido por               *\n");
    printf("*  Joao Victor Fernandes Souza             *\n");
    printf("*                                          *\n");
    printf("*  Introducao a Tecnologia da Informacao   *\n");
    printf("*  BSI 023 - 2 Periodo                     *\n");
    printf("*                                          *\n");
    printf("********************************************\n");
    setCorTexto(15); // Branco (restaura a cor padrão)
    getch();
}

void sobre() {
    system("cls");
    setCorTexto(11); // Ciano
    printf("====================================================================================\n");
    setCorTexto(14); // Amarelo
    printf("                     SOBRE O CONVERSOR DE BASES                          \n");
    setCorTexto(11); // Ciano
    printf("====================================================================================\n\n");
    setCorTexto(15); // Branco

    printf("O Conversor de Bases eh uma aplicacao desenvolvida por Joao Victor Fernandes Souza, \n");
    printf("como parte do curso de Introducao a Tecnologia da Informacao (BSI 023 - 2 Periodo).\n");
    printf("Esta aplicacao permite a conversao entre diferentes bases numericas, incluindo \n");
    printf("binario, octal, decimal e hexadecimal.\n\n");

    setCorTexto(10); // Verde
    printf("Versao: 1.0\n");
    printf("Data de Compilacao: %s, %s\n\n", __DATE__, __TIME__);
    setCorTexto(15); // Branco

    printf("====================================================================================\n\n");
    setCorTexto(15); // Branco
    system("pause");
}

// Funções de verificação
bool isBinario(const char *number) {
  int length = strlen(number);
  for (int i = 0; i < length; i++) {
    if (number[i] != '0' && number[i] != '1') {
      return false;
    }
  }
  return true;
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

bool isOctal(const char *number) {
  int length = strlen(number);
  for (int i = 0; i < length; i++) {
    if (number[i] < '0' || number[i] > '7') {
      return false;
    }
  }
  return true;
}

bool isHexadecimal(const char *number) {
  int length = strlen(number);
  for (int i = 0; i < length; i++) {
    if (!((number[i] >= '0' && number[i] <= '9') ||
          (number[i] >= 'A' && number[i] <= 'F') ||
          (number[i] >= 'a' && number[i] <= 'f'))) {
      return false;
    }
  }
  return true;
}

// Funções de conversão
void binario_octal() {
  char binario[100];

  system("cls");

  // Cor do Texto de Titulo
  setCorTexto(11); // azul claro
  printf("BINARIO ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("OCTAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero binario: ");
  scanf("%s", binario);

  if (!isBinario(binario)) {
    printf("Erro: O numero digitado nao eh binario.\n");
    getch();
    return;
  }

  int length = strlen(binario);
  int zeros_padding = length % 3;

  // Adiciona zeros à esquerda para tornar o número binário múltiplo de 3
  if (zeros_padding > 0) {
    zeros_padding = 3 - zeros_padding;
    length += zeros_padding;
    memmove(binario + zeros_padding, binario, strlen(binario) + 1);
    memset(binario, '0', zeros_padding);
  }

  printf("O numero binario %s em octal eh: ", binario);

  // Converte grupos de 3 dígitos binários para octal
  for (int i = 0; i < length; i += 3) {
    int grupo = 0;
    for (int j = 0; j < 3; j++) {
      grupo = grupo * 2 + (binario[i + j] - '0');
    }
    printf("%d", grupo);
  }

  printf("\n");
  getch();
}

void binario_decimal() {
  char binario[100];
  int decimal = 0;

  system("cls");

  // Cor do Texto de Titulo
  setCorTexto(11); // azul claro
  printf("BINARIO ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("DECIMAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero binario: ");
  scanf("%s", binario);

  if (!isBinario(binario)) {
    printf("Erro: O numero digitado nao eh binario.\n");
    getch();
    return;
  }

  // Converte o número binário para decimal
  for (int i = 0; binario[i] != '\0'; i++) {
    decimal = decimal * 2 + (binario[i] - '0');
  }

  printf("O numero binario %s em decimal eh %d.\n", binario, decimal);
  getch();
}

void binario_hexadecimal() {
  char binario[100];
  char hexadecimal[100];
  int length, index = 0;

  system("cls");

  // Cor do Texto de Titulo
  setCorTexto(11); // azul claro
  printf("BINARIO ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("HEXADECIMAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero binario: ");
  scanf("%s", binario);

  if (!isBinario(binario)) {
    printf("Erro: O numero digitado nao eh binario.\n");
    getch();
    return;
  }

  // Adiciona zeros à esquerda para tornar o número binário múltiplo de 4
  length = strlen(binario);
  int zeros_padding = length % 4;
  if (zeros_padding > 0) {
    zeros_padding = 4 - zeros_padding;
    length += zeros_padding;
    memmove(binario + zeros_padding, binario, strlen(binario) + 1);
    memset(binario, '0', zeros_padding);
  }

  // Converte grupos de 4 dígitos binários para hexadecimal
  for (int i = 0; i < length; i += 4) {
    int grupo = 0;
    for (int j = 0; j < 4; j++) {
      grupo = grupo * 2 + (binario[i + j] - '0');
    }
    if (grupo < 10) {
      hexadecimal[index++] = grupo + '0';
    } else {
      hexadecimal[index++] = grupo - 10 + 'A';
    }
  }
  hexadecimal[index] = '\0';

  printf("O numero binario %s em hexadecimal eh %s.\n", binario, hexadecimal);
  getch();
}

void octal_binario() {
  char octal[100];
  char binary[400]; // Pode haver até 3 bits para cada dígito octal
  int i, j = 0;

  system("cls");

  // Cor do Texto de Titulo
  setCorTexto(10); // verde
  printf("OCTAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(14); // amarelo
  printf("BINARIO\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero octal: ");
  scanf("%s", octal);

  if (!isOctal(octal)) {
    printf("Erro: O numero digitado nao eh octal.\n");
    getch();
    return;
  }

  // Converte cada dígito octal para 3 bits binários
  for (i = 0; octal[i] != '\0'; i++) {
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
    j += 3;
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

  // Cor do Texto de Título
  setCorTexto(10); // verde
  printf("OCTAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("DECIMAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero octal: ");
  scanf("%s", octal);

  if (!isOctal(octal)) {
    printf("Erro: O numero digitado nao eh octal.\n");
    getch();
    return;
  }

  // Converte o número octal para decimal
  for (i = 0; octal[i] != '\0'; i++) {
    decimal = decimal * 8 + (octal[i] - '0');
  }

  printf("O numero octal %s em decimal eh %d.\n", octal, decimal);
  getch();
}

void octal_hexadecimal() {
  char octal[100];
  char hexadecimal[100];
  int i, j = 0;

  system("cls");

  // Cor do Texto de Título
  setCorTexto(10); // verde
  printf("OCTAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // rosa
  printf("HEXADECIMAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero octal: ");
  scanf("%s", octal);

  if (!isOctal(octal)) {
    printf("Erro: O numero digitado nao eh octal.\n");
    getch();
    return;
  }

  // Convertendo o número octal para hexadecimal diretamente
  for (i = 0; octal[i] != '\0'; i++) {
    int digit = octal[i] - '0';
    j = j * 8 + digit;
  }

  i = 0;

  // Convertendo o valor j para hexadecimal
  while (j != 0) {
    int remainder = j % 16;
    if (remainder < 10) {
      hexadecimal[i++] = remainder + '0';
    } else {
      hexadecimal[i++] = remainder - 10 + 'A';
    }
    j /= 16;
  }

  // Adicionando o caractere nulo ao final da string hexadecimal
  hexadecimal[i] = '\0';

  // Revertendo a string hexadecimal para a ordem correta
  int start = 0;
  int end = i - 1;
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

void decimal_binario() {
  char decimal[100];
  char binary[100];
  int i = 0;

  system("cls");

  // Cor do Texto de Título
  setCorTexto(12); // azul
  printf("DECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(14); // amarelo
  printf("BINARIO\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero decimal: ");
  scanf("%s", decimal);

  if (!isDecimal(decimal)) {
    printf("Erro: O numero digitado nao eh decimal.\n");
    getch();
    return;
  }

  int number = atoi(decimal);
  // Se o número for zero, o binário também é zero
  if (number == 0) {
    binary[0] = '0';
    binary[1] = '\0';
  } else {
    // Converte o número decimal para binário
    while (number != 0) {
      binary[i] = (number % 2) + '0';
      number /= 2;
      i++;
    }
    binary[i] = '\0';
  }

  // Reverte a string binária para a ordem correta
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

  // Cor do Texto de Título
  setCorTexto(10); // verde
  printf("DECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("OCTAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero decimal: ");
  scanf("%s", decimal);

  if (!isDecimal(decimal)) {
    printf("Erro: O numero digitado nao eh decimal.\n");
    getch();
    return;
  }

  int number = atoi(decimal);

  // Se o número for zero, o octal também é zero
  if (number == 0) {
    octal[0] = '0';
    octal[1] = '\0';
  } else {
    // Converte o número decimal para octal
    while (number != 0) {
      octal[i] = (number % 8) + '0';
      number /= 8;
      i++;
    }
    octal[i] = '\0';
  }

  // Reverte a string octal para a ordem correta
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

  // Cor do Texto de Título
  setCorTexto(12); // azul
  printf("DECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(13); // magenta
  printf("HEXADECIMAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero decimal: ");
  scanf("%s", decimal);

  if (!isDecimal(decimal)) {
    printf("Erro: O numero digitado nao eh decimal.\n");
    getch();
    return;
  }

  int number = atoi(decimal); // Converte a string decimal para int

  // Se o número for zero, o hexadecimal também é zero
  if (number == 0) {
    hexadecimal[0] = '0';
    hexadecimal[1] = '\0';
  } else {
    // Converte o número decimal para hexadecimal
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

  // Reverte a string hexadecimal para a ordem correta
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

void hexadecimal_binario() {
  char hexadecimal[100];
  char binario[400] = "";
  int i = 0;

  system("cls");

  // Cor do Texto de Título
  setCorTexto(13); // magenta
  printf("HEXADECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(14); // amarelo
  printf("BINARIO\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero hexadecimal: ");
  scanf("%s", hexadecimal);

  if (!isHexadecimal(hexadecimal)) {
    printf("Erro: O numero digitado nao eh hexadecimal.\n");
    getch();
    return;
  }

  int length = strlen(hexadecimal);
  for (int j = 0; j < length; j++) {
    char hexDigit = hexadecimal[j];
    char binDigit[5] =
        ""; // Cada dígito hexadecimal é convertido em 4 dígitos binários

    // Converte caractere hexadecimal para valor binário de 4 bits
    switch (hexDigit) {
    case '0':
      strcpy(binDigit, "0000");
      break;
    case '1':
      strcpy(binDigit, "0001");
      break;
    case '2':
      strcpy(binDigit, "0010");
      break;
    case '3':
      strcpy(binDigit, "0011");
      break;
    case '4':
      strcpy(binDigit, "0100");
      break;
    case '5':
      strcpy(binDigit, "0101");
      break;
    case '6':
      strcpy(binDigit, "0110");
      break;
    case '7':
      strcpy(binDigit, "0111");
      break;
    case '8':
      strcpy(binDigit, "1000");
      break;
    case '9':
      strcpy(binDigit, "1001");
      break;
    case 'A':
    case 'a':
      strcpy(binDigit, "1010");
      break;
    case 'B':
    case 'b':
      strcpy(binDigit, "1011");
      break;
    case 'C':
    case 'c':
      strcpy(binDigit, "1100");
      break;
    case 'D':
    case 'd':
      strcpy(binDigit, "1101");
      break;
    case 'E':
    case 'e':
      strcpy(binDigit, "1110");
      break;
    case 'F':
    case 'f':
      strcpy(binDigit, "1111");
      break;
    }

    // Concatena o valor binário correspondente ao dígito hexadecimal
    strcat(binario, binDigit);
  }

  printf("O numero hexadecimal %s em binario eh %s.\n", hexadecimal, binario);
  getch();
}

void hexadecimal_octal() {
  char hexadecimal[100];
  char octal[100] = "";
  int i, j = 0;

  system("cls");

  setCorTexto(10); // magenta
  printf("HEXADECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("DECIMAL\n\n");

  setCorTexto(15); // branco

  printf("Digite um numero hexadecimal: ");
  scanf("%s", hexadecimal);

  // Validando se é um número hexadecimal válido
  if (!isHexadecimal(hexadecimal)) {
    printf("Erro: O numero digitado nao eh hexadecimal.\n");
    getch();
    return;
  }

  int length = strlen(hexadecimal);

  // Loop reverso para pegar cada dígito hexadecimal
  for (i = length - 1; i >= 0; i--) {
    int decimal = 0;

    // Convertendo dígito hexadecimal para decimal
    if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
      decimal = hexadecimal[i] - '0';
    } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
      decimal = hexadecimal[i] - 'A' + 10;
    } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
      decimal = hexadecimal[i] - 'a' + 10;
    }

    int octalDigit[3] = {0};
    int index = 2;

    while (decimal > 0) {
      octalDigit[index] = decimal % 8;
      decimal /= 8;
      index--;
    }

    // Adicionando dígitos octais ao resultado
    for (int k = 0; k < 3; k++) {
      octal[j++] = octalDigit[k] + '0';
    }
  }

  // Removendo zeros à esquerda desnecessários
  int start = 0;
  while (octal[start] == '0' && start < j - 1) {
    start++;
  }

  printf("O numero hexadecimal %s em octal eh: ", hexadecimal);
  for (int k = start; k < j; k++) {
    printf("%c", octal[k]);
  }
  printf("\n");
  getch();
}

void hexadecimal_decimal() {
  char hexadecimal[100];
  int decimal = 0;

  system("cls");

  // Cor do Texto de Título
  setCorTexto(13); // magenta
  printf("HEXADECIMAL ");
  setCorTexto(15); // branco
  printf("PARA ");
  setCorTexto(12); // azul
  printf("DECIMAL\n\n");

  // Cor do restante do Texto
  setCorTexto(15); // branco

  printf("Digite um numero hexadecimal: ");
  scanf("%s", hexadecimal);

  if (!isHexadecimal(hexadecimal)) {
    printf("Erro: O numero digitado nao eh hexadecimal.\n");
    getch();
    return;
  }

  // Converte o número hexadecimal para decimal
  int length = strlen(hexadecimal);
  for (int i = 0; i < length; i++) {
    char hexDigit = hexadecimal[i];
    int digit;

    // Converte caractere hexadecimal para valor decimal
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
      break;

    case f1:
      sobre();
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