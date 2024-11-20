#include <iostream>     // Biblioteca para entrada/saída padrão
#include <fstream>      // Biblioteca para manipulação de arquivos
#include <ctime> // Inclui a biblioteca ctime para manipulação de tempo

// Declaração das funções
void meuCarimbo();
void mudaLinha();


void mudaLinha(void)
{
    printf("\n");
}	

void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}


int main() {

    meuCarimbo();   
    mudaLinha();
    // Abre o arquivo de entrada para leitura
    std::ifstream inputFile("Inteiros.txt");
    // Cria/abre o arquivo de saída para escrita
    std::ofstream outputFile("1106_01_SA.txt");

    // Verifica se o arquivo de entrada foi aberto corretamente
    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo 'inteiros.txt'." << std::endl;
        return 1;
    }

    // Verifica se o arquivo de saída foi criado corretamente
    if (!outputFile) {
        std::cerr << "Erro ao criar o arquivo '1106_01_SA.txt'." << std::endl;
        return 1;
    }

    // Declaração das variáveis
    int number;         // Armazena cada número lido do arquivo
    int sumPositive = 0; // Acumulador para números positivos
    int sumNegative = 0; // Acumulador para números negativos

    // Loop para ler números do arquivo até o final
    while (inputFile >> number) {
        if (number > 0) {
            sumPositive += number;    // Soma números positivos
        } else if (number < 0) {
            sumNegative += number;    // Soma números negativos
        }
    }

    // Fecha o arquivo de entrada após a leitura
    inputFile.close();

    // Escreve os resultados no arquivo de saída
    outputFile << "Soma dos números positivos: " << sumPositive << std::endl;
    outputFile << "Soma dos números negativos: " << sumNegative << std::endl;

    // Fecha o arquivo de saída
    outputFile.close();

    // Mensagem de confirmação para o usuário
    std::cout << "Resultados salvos no arquivo '1106_01_SA.txt'." << std::endl;

    return 0;  // Retorna 0 indicando execução bem-sucedida
}
