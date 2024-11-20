#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;

void mudarLinha() {
    cout << endl; // Função para adicionar uma linha em branco
}

void meuCarimbo() {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    cout << "Ricardo Moreira - " << asctime(&datetime); // Imprime assinatura com o carimbo 
}

int main() { 
    ifstream inputFile("InteirosPositivos.txt"); // Abre o ficheiro de entrada
    ofstream outputFileA("1106_02A.txt"); // Abre o ficheiro de saída A
    ofstream outputFileB("1106_02B.txt"); // Abre o ficheiro de saída B
    
    if (!inputFile) { // Verifica se o ficheiro de entrada foi aberto com sucesso
        cerr << "Erro ao abrir o ficheiro InteirosPositivos.txt";
        mudarLinha();
        return 1;
    }
    if (!outputFileA || !outputFileB) { // Verifica se os ficheiros de saída foram abertos com sucesso
        cerr << "Erro ao abrir os ficheiros de saída.";
        mudarLinha();
        return 1;
    }
    
    vector<int> numbers; // Vetor para armazenar os números
    int number;
    int sum = 0;
    
    while (inputFile >> number) { // Lê os números do ficheiro
        numbers.push_back(number);
        sum += number;
    }
    
    double average = static_cast<double>(sum) / numbers.size(); // Calcula a média
    
    for (int num : numbers) {   // Escreve os números no ficheiro de saída correspondente
        if (num < average) {
            outputFileA << num << endl;
        } else {
            outputFileB << num << endl;
        }
    }
    
    // Fecha os ficheiros
    inputFile.close();
    outputFileA.close();
    outputFileB.close();

    cout << "Foram guardados todos os números menores do que o valor médio em 1106_02A.txt e os restantes em 1106_02B.txt";

    mudarLinha();
    mudarLinha();
    meuCarimbo();

    return 0;
}
