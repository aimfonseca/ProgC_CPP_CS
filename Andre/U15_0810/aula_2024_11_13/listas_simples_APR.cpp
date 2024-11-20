#include <iostream>
#include "template.h"


using namespace std;

// Listas simples ou arrays como mais comumente são conhecidas são uma estrutura de dados linear 
// que consiste numa sequência de elementos, onde cada elemento é armazenado numa posição sequencial.
// Ou seja, o primeiro elemento é armazenado na posição 0, o segundo na posição 1, e assim por diante.
// Cada vez que um novo elemento é adicionado, o tamanho da lista aumenta uma unidade e ele é adicionado no final da lista.
// A principal vantagem das listas é que elas são fáceis de implementar e de aceder.
// Porém, são ineficientes para inserções e remoções em posições intermediárias.
// Por isso, para listas com muitos elementos, é mais eficiente usar uma estrutura de dados mais complexa, como uma lista encadeada.

// Segue abaixo um exemplo da implementação e utilização de uma lista simples/array em C++:
class Lista {
private:
    int elementos[100];     // Array para armazenar 100 elementos no máximo
    int tamanho;           // Variavel para controlar o tamanho atual

public:
    // Método Construtor
    Lista() {
        tamanho = 0;       // Inicia lista com tamanho 0
    }

    // Adiciona elemento no final da lista e faz o incremento do indice para preparar o array para receber outro valor
    void adicionar(int valor) {
        if (tamanho < 100) {
            elementos[tamanho] = valor;
            tamanho++;
        }
    }

    // Remove último elemento decrementando o indice onde ele se encontra
    void remover() {
        if (tamanho > 0) {
            tamanho--;
        }
    }

    // Método para exibir todos os elementos existentes na lista
    void mostrar() {
        cout << "Lista: ";
        for (int i = 0; i < tamanho; i++) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }

    // Método para procurar o elemento na lista através do seu valor
    bool buscar(int valor) {
        for (int i = 0; i < tamanho; i++) {
            if (elementos[i] == valor) {
                return true;
            }
        }
        return false;
    }

    // Retorna tamanho atual da lista
    int getTamanho() {
        return tamanho;
    }
};

int main() {
    header();

    // Cria um objeto lista simples/array
    Lista minhaLista;
    int valor;

    // Adicionar elementos à lista
    minhaLista.adicionar(10);
    minhaLista.adicionar(20);
    minhaLista.adicionar(30);

    // Mostrar o tamanho atual da lista
    cout << "Tamanho atual: " << minhaLista.getTamanho() << endl;
    // Mostrar os elementos que a lista atualmente possui
    minhaLista.mostrar();
    separador();
    mudaLinha();

    cout << "\nQual o valor que pretende encontrar nesta lista? " << endl;
    cin >> valor;
    separador();
    mudaLinha();

    // Testar a procura de elementos através do seu valor
    cout << "A procurar pelo valor: " << valor << " --> " << (minhaLista.buscar(valor) ? "Encontrado" : "Não encontrado") << endl;
    mudaLinha();
    separador();
    mudaLinha();

    // Remover o ultimo elemento da lista  utilizando o método remover
    minhaLista.remover();

    // Mostrar os elementos que a lista possui após a remoção do ultimo elemento
    cout << "\nConteúdo da lista após remoção de um elemento:" << endl;
    minhaLista.mostrar();

    footer();

    return 0;
}
