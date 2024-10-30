/* Cíntia Vasconcelos */
#include <iostream>

int main() {
    /* Exemplo 01: Imprimindo valor e endereco de uma variavel inteira */
    int numero = 10;
    std::cout << "Valor da variavel 'numero': " << numero << std::endl;
    std::cout << "Endereco de memoria da variavel 'numero': " << &numero << std::endl;

    /* Exemplo 02: Usando ponteiro para acessar valor e endereco de uma variavel */
    int var_ex02 = 20;
    int *ptr_ex02 = &var_ex02; 
    std::cout << "Valor da variavel 'var_ex02': " << var_ex02 << std::endl;
    std::cout << "Endereco de memoria da variavel 'var_ex02': " << ptr_ex02 << std::endl;
    std::cout << "Valor da variavel 'var_ex02', acessado pelo ponteiro 'ptr_ex02': " << *ptr_ex02 << std::endl;

    /* Exemplo 03: Modificando o valor de uma variavel usando um ponteiro */
    char letra_ex03 = '-';
    char *ptr_ex03 = &letra_ex03;
    *ptr_ex03 = '+'; 
    std::cout << "Novo valor da variavel 'letra_ex03': " << letra_ex03 << std::endl;

    /* Exemplo 04: Trabalhando com ponteiros e arrays */
    int numeros[5] = {10, 20, 30, 40, 50};
    int *ptr = numeros; // Ponteiro para o array 'numeros'
    std::cout << "Elementos do array 'numeros': ";
    for (int i = 0; i < 5; ++i) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    /* Aritmetica de ponteiros: avancando e recuando pelo array */
    ptr++; // Avancar para o proximo elemento
    std::cout << "Endereco de memoria atual do ponteiro: " << ptr << std::endl;
    std::cout << "Valor do elemento atual: " << *ptr << std::endl;

    ptr--; // Recuar para o elemento anterior
    std::cout << "Endereco de memoria apos recuar: " << ptr << std::endl;
    std::cout << "Valor do elemento atual: " << *ptr << std::endl;

    return 0;
}
