#include <iostream>     // Biblioteca para entrada/saída padrão
#include <fstream>      // Biblioteca para manipulação de arquivos
#include <ctime> // Inclui a biblioteca ctime para manipulação de tempo
#include <vector>
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
    std::ifstream inputFile("InteirosPositivos.txt");
    std::ofstream outputFileA("1106_02A.txt");
    std::ofstream outputFileB("1106_02B.txt");

    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo 'InteirosPositivos.txt'." << std::endl;
        return 1;
    }
    if (!outputFileA || !outputFileB) {
        std::cerr << "Erro ao criar os arquivos de saída." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int number;
    int sum = 0;
    int count = 0;

    // Ler os números e armazená-los no vetor
    while (inputFile >> number) {
        numbers.push_back(number);
        sum += number;
        count++;
    }
    inputFile.close();

    if (count == 0) {
        std::cerr << "O arquivo está vazio." << std::endl;
        return 1;
    }

    // Calcular o valor médio
    double average = static_cast<double>(sum) / count;

    // Separar números com base na média e gravá-los nos arquivos correspondentes
    for (int num : numbers) {
        if (num < average) {
            outputFileA << num << std::endl;
        } else {
            outputFileB << num << std::endl;
        }
    }

    outputFileA.close();
    outputFileB.close();

    std::cout << "Processamento concluído. Resultados salvos nos arquivos '1106_02A.txt' e '1106_02B.txt'." << std::endl;

    return 0;
}
