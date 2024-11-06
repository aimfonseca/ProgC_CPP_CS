#include <iostream>
#include <fstream>

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
    ifstream inputFile("Inteiros.txt");
    ofstream outputFile("1106_01.txt");
    
    if (!inputFile) {
        cerr << "Erro ao abrir o ficheiro Inteiros.txt";
        mudarLinha();
        return 1;
    }
    if (!outputFile) {
        cerr << "Erro ao abrir o ficheiro 1106_01.txt";
        mudarLinha();
        return 1;
    }
    
    int number;
    int sumPositives = 0;
    int sumNegatives = 0;
    
    while (inputFile >> number) {
        if (number > 0) {
            sumPositives += number;
        } else if (number < 0) {
            sumNegatives += number;
        }
    }
    
    outputFile << "A soma dos números positivos é: " << sumPositives << endl;
    outputFile << "A soma dos números negativos é: " << sumNegatives << endl;
    
    inputFile.close();
    outputFile.close();

    cout << "Os resultados foram guardados no ficheiro 1106_01.txt";

    mudarLinha();
    mudarLinha();
    meuCarimbo();

    return 0;
}
