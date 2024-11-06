#include <iostream>
#include <fstream>
#include <vector>
#include <numeric> // Para std::accumulate
#include "template.h"

using namespace std;

int main() {
    header();
    ifstream inputFile("InteirosPositivos.txt");
    if (!inputFile) {
        cerr << "Erro ao abrir o ficheiro 'InteirosPositivos.txt'. Certifique-se de que o arquivo está no diretório correto." << endl;
        return 1;
    }

    // Array dinâmico usando vetor
    vector<int> numeros;
    int numero;

    // Lê cada número do arquivo e o armazena no vetor
    while (inputFile >> numero) {
        numeros.push_back(numero);
    }

    inputFile.close();

    // Verifica se há números no vetor antes de calcular a média
    if (numeros.empty()) {
        cout << "O ficheiro está vazio ou não contém números válidos." << endl;
        return 1;
    }

    // Calcula a média dos números
    int soma = accumulate(numeros.begin(), numeros.end(), 0);
    double media = static_cast<double>(soma) / numeros.size();

    // Exibe o valor médio
    cout << "A media dos numeros no ficheiro e: " << media << endl;



    // Abre os arquivos de saída
    ofstream outputFileA("1106_02A_APR.txt");
    ofstream outputFileB("1106_02B_APR.txt");

    if (!outputFileA || !outputFileB) {
        cerr << "Erro ao abrir os arquivos de saída '1106_02A_APR.txt' ou '1106_02B_APR.txt'." << endl;
        return 1;
    }

    // Grava os números em cada arquivo conforme o critério
    for (int num : numeros) {
        if (num < media) {
            outputFileA << num << endl; // Menor que a média
        } else {
            outputFileB << num << endl; // Maior ou igual à média
        }
    }

    // Fecha os arquivos de saída
    outputFileA.close();
    outputFileB.close();
    footer();

    return 0;
}
