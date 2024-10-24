#include <iostream>
#include <ctime>

/**
 * Este conjunto de código mostra definições e utilização do conceito de ponteiros em C/C++.
 * [Explicação do conceito de ponteiros]
 */

// Declaração das novas funções
void meuCarimbo(void);
void mudaLinha(void);
void separador(void);

int main() {
    meuCarimbo();  // Chama a função que imprime o carimbo com a data/hora e a identificação
    separador();   // Imprime um separador antes dos exemplos

    /** 
    * [Exemplo 01] 
    */
    std::cout << "--- Exemplo 01 --->" << std::endl;
    int numero = 10;
    std::cout << numero  << std::endl;
    std::cout << &numero << std::endl;
    mudaLinha();

    /** 
    * [Exemplo 02]
    */ 
    std::cout << "--- Exemplo 02 --->" << std::endl;
    int var_ex02 = 20;
    int *ptr_ex02;
    ptr_ex02 = &var_ex02; 
    std::cout << "Mostra o valor atual da variável 'var_ex02': " << var_ex02 << std::endl;
    std::cout << "Mostra o endereço de memória onde se encontra a variável 'var_ex02': " << ptr_ex02 << std::endl;
    std::cout << "Mostra o valor da variável 'var_ex02', apontada pelo ponteiro 'ptr_ex02': " << *ptr_ex02 << std::endl;
    mudaLinha();

    /** 
    * [Exemplo 03]
    */ 
    std::cout << "--- Exemplo 03 --->" << std::endl;
    char letra_ex03 = '-';		
    char *ptr_ex03;
    ptr_ex03 = &letra_ex03;
    *ptr_ex03 = '+'; 
    std::cout << "Resultado do acesso ao endereço de memória da variável 'letra_ex03': " << letra_ex03 << std::endl;
    mudaLinha();

    /** 
    * [Exemplo 05]
    */ 
    std::cout << "--- Exemplo 05 --->" << std::endl;
    int numeros[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    int *ptr = numeros;
    std::cout << "Endereço de memória onde está o primeiro elemento do 'array': " << ptr << std::endl;
    std::cout << "Valor do primeiro elemento do 'array', usando o índice: " << numeros[0] << std::endl;
    std::cout << "Valor do primeiro elemento do 'array', usando o endereço (pointer): " << *ptr << std::endl;

    ptr++;
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço:  " << *ptr << std::endl;
    ptr++;
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;

    ptr--;
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;

    std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *(ptr + 2) << std::endl;
    ptr += 3;
    std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *ptr << std::endl;

    separador();  // Imprime um separador após os exemplos
    return 0;
}

void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Ponteiros] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}

void mudaLinha(void) {
    printf("\n");
}

void separador(void) {
    for (int i = 0; i < 120; i++) {
        printf("*");
    }
    printf("\n");
}
