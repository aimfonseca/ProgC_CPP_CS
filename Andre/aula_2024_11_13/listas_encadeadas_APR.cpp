#include <iostream>
#include "template.h"

using namespace std;

// As listas enccadeadas são estruturas de dados lineares que consistem numa sequência de nós, 
// onde cada nó contém um valor e um ponteiro para o próximo nó.
// Este tipo de listas é útil quando a inserção e remoção de elementos é frequente, 

/*
 * Listas Encadeadas são estruturas de dados onde cada elemento (nó) contém um valor
 * e uma referência para o próximo elemento da lista. 
 * Este tipo de lista é útil quando a inserção e remoção de elementos é frequente,
 * Esta implementação demonstra operações básicas como:
 * - Inserção de elementos no início da lista
 * - Inserção de elementos em posições específicas
 * - Remoção de elementos da lista em qualquer posição através do seu valor
 * - Visualização dos elementos
 * - Busca de valores específicos
 */

// Definição da estrutura do nó da lista
struct No {
    int valor;          // Valor armazenado no nó
    No* proximo;        // Ponteiro para o próximo nó
};

// Classe ListaEncadeada
class ListaEncadeada {
private:
    No* inicio;         // Ponteiro para o primeiro elemento

public:
    // Construtor
    ListaEncadeada() {
        inicio = NULL;  // Inicializa lista vazia
    }

    // Método para inserir elemento no início
    void inserirNoInicio(int valor) {
        No* novoNo = new No();        // Cria novo nó
        novoNo->valor = valor;         // Atribui o valor
        novoNo->proximo = inicio;      // Novo nó aponta para antigo primeiro
        inicio = novoNo;               // Início aponta para novo nó
    }

    // Método para inserir elemento numa posição específica
    void inserirNaPosicao(int valor, int posicao) {
        // Se a posição for 0, insere no início
        if (posicao == 0) {
            inserirNoInicio(valor);
            return;
        }

        No* novoNo = new No();
        novoNo->valor = valor;
        No* atual = inicio;
        int contador = 0;

        // Percorre até a posição anterior à desejada
        while (atual != NULL && contador < posicao - 1) {
            atual = atual->proximo;
            contador++;
        }

        // Verifica se a posição é válida
        if (atual != NULL) {
            novoNo->proximo = atual->proximo;
            atual->proximo = novoNo;
        }
    }

    // Remoção de elementos da lista em qualquer posição atraves do seu valor
   void remover(int valor) {
        if (inicio == NULL) {
            cout << "Lista vazia!" << endl;
            return;
        }

        // Se o elemento a ser removido é o primeiro
        if (inicio->valor == valor) {
            No* temp = inicio;
            inicio = inicio->proximo;
            delete temp;
            return;
        }

        // Procura o elemento na lista
        No* atual = inicio;
        No* anterior = NULL;
        
        while (atual != NULL && atual->valor != valor) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Se encontrou o elemento
        if (atual != NULL) {
            anterior->proximo = atual->proximo;
            delete atual;
        } else {
            cout << "Valor " << valor << " nao encontrado na lista!" << endl;
        }
    }


    // Método para exibir a lista
    void mostrar() {
        No* temp = inicio;             // Nó temporário para percorrer
        cout << "Lista: ";
        while (temp != NULL) {         // Percorre até o fim
            cout << temp->valor << " "; // Exibe valor
            temp = temp->proximo;      // Avança para próximo
        }
        cout << endl;
    }

    // Método para procurar elemento
    bool procurar(int valor) {
        No* temp = inicio;
        while (temp != NULL) {
            if (temp->valor == valor)  // Encontrou o valor
                return true;
            temp = temp->proximo;
        }
        return false;                  // Não encontrou
    }
};


int main() {
    header();

    // Cria uma lista encadeada
    ListaEncadeada lista;

    int valor;

    // Inserindo elementos
    lista.inserirNoInicio(30);
    lista.inserirNoInicio(20);
    lista.inserirNoInicio(10);
    
    // Exibir a lista antes da inserção em posição específica
    cout << "Lista antes da inserção em posição específica:" << endl;
    lista.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Inserir dados numa posição específica (valor 15, posição 1)
    lista.inserirNaPosicao(15,3);

    // Exibindo a lista
    cout << "Lista após a inserção em posição específica:" << endl;
    lista.mostrar();
    mudaLinha();
    separador();
    mudaLinha();
    
    cout << "\nQual o valor que pretende remover desta lista? " << endl;
    cin >> valor;
    mudaLinha();
    separador();
    mudaLinha();
    
    // Remover elemento da lista
    lista.remover(valor);

    // Exibir a lista após a remoção
    cout << "Lista após a remoção:" << endl;
    lista.mostrar();
    mudaLinha();
    separador();

    cout << "\nQual o valor que pretende encontrar nesta lista? " << endl;
    cin >> valor;
    mudaLinha();
    separador();
    mudaLinha();

    
    // Testar a procura de elementos através do seu valor
    cout << "A procurar pelo valor: " << valor << " --> " << (lista.procurar(valor) ? "Encontrado" : "Não encontrado") << endl;
    
    footer();

    return 0;
}
