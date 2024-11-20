#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

// Declaração das funções
void meuCarimbo();
void mudaLinha();
void separador();
void mostrarTexto(const std::string &ficheiro);
void exemploPonteiroSimples();
void exemploPonteiroArray();
void exemploPonteiroParaPonteiro();

int main() {
    int opcao;
    std::string ficheiro = "materia.txt";

    while (true) {
        meuCarimbo();
        separador();
        std::cout << "Menu de Opcoes - Conceitos sobre Ponteiros\n";
        std::cout << "1. Exemplo de Ponteiro Simples\n";
        std::cout << "2. Exemplo de Ponteiro com Array\n";
        std::cout << "3. Exemplo de Ponteiro para Ponteiro\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        if (opcao == 4) {
            std::cout << "Encerrando o programa...\n";
            break;
        }

        // Mostrar o texto e o exemplo conforme a opção escolhida
        switch (opcao) {
            case 1:
                mostrarTexto(ficheiro);
                exemploPonteiroSimples();
                break;
            case 2:
                mostrarTexto(ficheiro);
                exemploPonteiroArray();
                break;
            case 3:
                mostrarTexto(ficheiro);
                exemploPonteiroParaPonteiro();
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
        }
        mudaLinha();
    }

    return 0;
}

// Funções auxiliares
void meuCarimbo() {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Ponteiros] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}

void mudaLinha() {
    printf("\n");
}

void separador() {
    for (int i = 0; i < 120; i++) {
        printf("*");
    }
    printf("\n");
}

void mostrarTexto(const std::string &ficheiro) {
    std::ifstream arquivo(ficheiro);
    std::string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o ficheiro " << ficheiro << std::endl;
    }
}

void exemploPonteiroSimples() {
    std::cout << "--- Exemplo de Ponteiro Simples ---\n";
    int numero = 42;
    int *ptr = &numero;
    std::cout << "Valor de numero: " << numero << std::endl;
    std::cout << "Endereco de numero: " << &numero << std::endl;
    std::cout << "Valor de numero atraves do ponteiro: " << *ptr << std::endl;
}

void exemploPonteiroArray() {
    std::cout << "--- Exemplo de Ponteiro com Array ---\n";
    int array[3] = {1, 2, 3};
    int *ptr = array;
    std::cout << "Valor do primeiro elemento: " << *ptr << std::endl;
    ptr++;
    std::cout << "Valor do segundo elemento: " << *ptr << std::endl;
    ptr++;
    std::cout << "Valor do terceiro elemento: " << *ptr << std::endl;
}

void exemploPonteiroParaPonteiro() {
    std::cout << "--- Exemplo de Ponteiro para Ponteiro ---\n";
    int valor = 100;
    int *ptr = &valor;
    int **ptr2 = &ptr;
    std::cout << "Valor de valor: " << valor << std::endl;
    std::cout << "Valor de valor atraves do ponteiro: " << *ptr << std::endl;
    std::cout << "Valor de valor atraves do ponteiro para ponteiro: " << **ptr2 << std::endl;
}
