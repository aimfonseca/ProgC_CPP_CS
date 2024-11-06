#include <iostream>
#include <fstream>
#include "template.h"

using namespace std;

int main() {
    header();
    ifstream inputFile("Inteiros.txt"); // Abre o ficheiro para leitura
    if (!inputFile) {
        cerr << "Erro ao abrir o ficheiro 'Inteiros.txt'." << endl;
        return 1;
    }

    int num;
    int somaPositivos = 0;
    int somaNegativos = 0;

    // Lê cada número do ficheiro e soma conforme o seu sinal
    while (inputFile >> num) {
        if (num > 0) {
            somaPositivos += num; // Soma os números positivos
        } else if (num < 0) {
            somaNegativos += num; // Soma os números negativos
        }
    }

    // Fecha o ficheiro
    inputFile.close();

    // Exibe os resultados
    cout << "Soma dos numeros positivos: " << somaPositivos << endl;
    cout << "Soma dos numeros negativos: " << somaNegativos << endl;
    footer();
    return 0;
}
