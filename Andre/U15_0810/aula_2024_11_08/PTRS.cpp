#include <iostream>
#include <string.h>
 
using namespace std;
 
int main() {
    // Criando um vetor de strings com alocação dinâmica
    int n;
 
    cout << "Digite o número de nomes: ";
    cin >> n;
 
    char** nomes = new char*[n];
 
    for (int i = 0; i < n; i++) {
        cout << "Digite o nome " << i+1 << ": ";
        string nome;
        cin >> nome;
        nomes[i] = new char[nome.length() + 1]; // +1 para o caractere nulo
        strcpy(nomes[i], nome.c_str());
    }
 
    // Imprimindo os nomes
    for (int i = 0; i < n; i++) {
        cout << nomes[i] << endl;
    }

    cout << "Tamanho do array em bytes antes da adicionar mais nomes: " << sizeof(nomes) << endl;
 
    int j = n + 1;
 
    for (int i = 1; i < j+n; i++) {
        cout << "Digite o nome " << i+1 << ": ";
        string nome;
        cin >> nome;
        nomes[i] = new char[nome.length() + 1]; // +1 para o caractere nulo
        strcpy(nomes[i], nome.c_str());
    }
 
    for (int i = 0; i < n+j; i++) {
        cout << nomes[i] << endl;
    }

    cout << "Tamanho do array em bytes depois da adicionar mais nome: " << sizeof(nomes) << endl;
    // // Liberando a memória
    // for (int i = 0; i < n; i++) {
    //     delete[] nomes[i];
    // }
    // delete[] nomes;
 
    return 0;
}
 