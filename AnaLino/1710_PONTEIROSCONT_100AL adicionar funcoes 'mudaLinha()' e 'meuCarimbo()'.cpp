#include <iostream>
#include <stdio.h>
#include <time.h>

// Declaração das funções
void mudaLinha(void);
void meuCarimbo(void);

int main() {
    
    meuCarimbo(); // Mostra o carimbo com a data e hora de execução
    mudaLinha();  // Muda de linha para separar as saídas no console

    // Exemplo de ponteiros e arrays (já estava no código original)
    std::cout << "--- Exemplo 01 --->" << std::endl;
    int numero = 10;
    std::cout << numero  << std::endl;
    std::cout << &numero << std::endl;

    std::cout << "--- Exemplo 02 --->" << std::endl;
    int var_ex02 = 20;
    int *ptr_ex02;
    ptr_ex02 = &var_ex02; 
    std::cout << "Mostra o valor atual da variável 'var_ex02': " << var_ex02 << std::endl;
    std::cout << "Mostra o endereço de memória onde se encontra a variável 'var_ex02': " << ptr_ex02 << std::endl;
    std::cout << "Mostra o valor da variável 'var_ex02', apontada pelo ponteiro 'ptr_ex02': " << *ptr_ex02 << std::endl;

    std::cout << "--- Exemplo 03 --->" << std::endl;
    char letra_ex03 = '-';		
    char *ptr_ex03;
    ptr_ex03 = &letra_ex03;
    *ptr_ex03 = '+'; 
    std::cout << "Resultado do acesso ao endereço de memória da variável 'letra_ex03': " << letra_ex03 << std::endl;

    std::cout << "--- Exemplo 05 --->" << std::endl;
    int numeros[5] = {10, 20, 30, 40, 50}; // Definir e inicializar um 'array' de números inteiros.
    for (int i = 0; i < 5; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
    int *ptr = numeros; // Definir e inicializar um 'ponteiro' para o 'array' de números inteiros.
    std::cout << "Endereço de memória onde está o primeiro elemento do 'array': " << ptr << std::endl;
    std::cout << "Valor do primeiro elemento do 'array', usando o índice (index): " << numeros[0] << std::endl;
    std::cout << "Valor do primeiro elemento do 'array', usando o endereço (pointer): " << *ptr << std::endl;

    ptr++; // Incrementar o ponteiro para avançar uma posição de memória (neste caso, dentro do 'array').
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço:  " << *ptr << std::endl;

    ptr--; // Descrementar o ponteiro para recuar uma posição de memória (neste caso, dentro do 'array').
    std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
    std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;

    std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *(ptr + 2) << std::endl;

    ptr += 3; // Incrementar o ponteiro para avançar três posições (e não 3 vezes, como nas somas tradicionais).
    std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *ptr << std::endl;

    // Adicionando o novo código solicitado:
    mudaLinha();  // Muda de linha para separar as saídas no console

    // Exibe uma mensagem para o usuário e o primeiro número do array
    std::cout << "O primeiro número do array é: " << numeros[0] << std::endl;

    // Usando o ponteiro para acessar o valor do primeiro elemento do array
    std::cout << "Usando o ponteiro, o valor apontado é: " << *ptr << std::endl;

    // Avança o ponteiro para o próximo elemento do array
    ptr++;
    std::cout << "Após avançar o ponteiro, ele aponta para: " << *ptr << std::endl;

    // Retorna o ponteiro para o primeiro elemento do array
    ptr--;
    std::cout << "Após retroceder o ponteiro, ele volta a apontar para: " << *ptr << std::endl;

    // Acessa o terceiro elemento do array usando aritmética de ponteiros
    std::cout << "O terceiro número do array, acessado com aritmética de ponteiros, é: " << *(ptr + 2) << std::endl;

    mudaLinha();  // Muda de linha para embelezar a saída
    std::cout << "Fim da execução do programa." << std::endl;

    return 0;
}

// ------------------------------------------
// Função que muda de linha quando necessário 
void mudaLinha(void)
{
    printf("\n"); // muda de linha
}

// ------------------------------------------
// Função que mostra (algumas) informações gerais 
void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];

    // Formata a data e hora atual no formato desejado
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[Ana Lino] - [ %s ]", data_hora); 
    mudaLinha(); // Muda de linha logo após o carimbo de data e hora
}