#include <iostream>
#include <time.h>

// Função que muda de linha
void mudaLinha() {
    std::cout << "=============================" << std::endl;
}

// Função que mostra algumas informações gerais
void meuCarimbo() {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    std::cout << "\n[Ana Pereira] - [ " << data_hora << " ]" << std::endl;
    mudaLinha();
}

int main() {
    meuCarimbo();
    mudaLinha();
    
    /** O teu código de exemplos de ponteiros */
    std::cout << "--- Exemplo 01 --->" << std::endl;
    int numero = 10;
    std::cout << numero  << std::endl;
    std::cout << &numero << std::endl;
    mudaLinha();
    
    std::cout << "--- Exemplo 02 --->" << std::endl;
    int var_ex02 = 20;
    int *ptr_ex02;
    ptr_ex02 = &var_ex02;
    std::cout << "Mostra o valor atual da variável 'var_ex02': " << var_ex02 << std::endl;
    std::cout << "Mostra o endereço de memória onde se encontra a variável 'var_ex02': " << ptr_ex02 << std::endl;
    std::cout << "Mostra o valor da variável 'var_ex02', apontada pelo ponteiro 'ptr_ex02': " << *ptr_ex02 << std::endl;
    mudaLinha();
    
    std::cout << "--- Exemplo 03 --->" << std::endl;
    char letra_ex03 = '-';
    char *ptr_ex03;
    ptr_ex03 = &letra_ex03;
    *ptr_ex03 = '+';
    std::cout << "Resultado do acesso ao endereço de memória da variável 'letra_ex03': " << letra_ex03 << std::endl;
    mudaLinha();
    
    std::cout << "--- Exemplo 04 --->" << std::endl;
    // int k, *p;
    // *p = 10;
    // std::cout << *p  << std::endl; // Atenção ao erro de 'execução' (runtime).
    mudaLinha();
    
    std::cout << "--- Exemplo 05 --->" << std::endl;
    int numeros[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
    int *ptr = numeros;
    std::cout << "Endereço de memória onde está o primeiro elemento do 'array': " << ptr << std::endl;
    std::cout << "Valor do primeiro elemento do 'array', usando o índice (index): " << numeros[0] << std::endl;
    std::cout << "Valor do primeiro elemento do 'array', usando o endereço (pointer): " << *ptr << std::endl;
    mudaLinha();
    
    ptr++;
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;
    ptr++;
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;
    ptr--;
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *(ptr + 2) << std::endl;
    ptr += 3;
    std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *ptr << std::endl;
    mudaLinha();
    
    meuCarimbo();
    
    return 0;
}
