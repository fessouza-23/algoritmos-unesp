#include <iostream>
#include <conio.h>

int main() {
    char choice;

    do {
        // Limpa a tela
        system("cls");

        // Exibe o menu
        std::cout << "Menu de Opcoes" << std::endl;
        std::cout << "1. Opcao 1" << std::endl;
        std::cout << "2. Opcao 2" << std::endl;
        std::cout << "3. Opcao 3" << std::endl;
        std::cout << "0. Sair" << std::endl;

        // Aguarda a entrada do usuário
        choice = _getch();

        // Executa a ação com base na escolha
        switch (choice) {
            case '1':
                // Código para a Opção 1
                std::cout << "Opcao 1 selecionada." << std::endl;
                _getch();
                break;
            case '2':
                // Código para a Opção 2
                std::cout << "Opcao 2 selecionada." << std::endl;
                _getch();
                break;
            case '3':
                // Código para a Opção 3
                std::cout << "Opcao 3 selecionada." << std::endl;
                _getch();
                break;
            case '0':
                // Encerra o programa
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                // Mensagem de opção inválida
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                _getch();
                break;
        }
    } while (choice != '0');

    return 0;
}
