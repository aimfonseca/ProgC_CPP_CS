#include <iostream>
#include "template.h"

using namespace std;

/*
 * Pilhas são estruturas de dados que seguem o princípio LIFO (Last In, First Out),
 * onde o último elemento a entrar é o primeiro a sair.
 * Semelhante a uma pilha de pratos, onde o último prato colocado é o primeiro a ser retirado.
 * A remoção de elementos é feita no topo da pilha segundo o princípio LIFO.
 *
 * Esta implementação demonstra operações básicas como:
 * - Push (adicionar elementos no topo da pilha)
 * - Pop (remover elementos do topo da pilha)
 * - Visualizar elementos
 * - Verificar se um elemento existe 
 */

// Definição da estrutura do nó da pilha
struct No {
    int valor;      // Valor armazenado no nó
    No* proximo;    // Ponteiro para o próximo nó
};

// Classe Pilha
class Pilha {
private:
    No* topo;       // Ponteiro para o topo da pilha

public:
    // Método construtor
    Pilha() {
        topo = NULL;    // Inicia pilha vazia
    }

    // Método para adicionar elemento no topo da pilha (PUSH)
    void push(int valor) {
        No* novoNo = new No();    // Cria novo nó
        novoNo->valor = valor;     // Atribui o valor
        novoNo->proximo = topo;    // Novo nó aponta para o antigo topo
        topo = novoNo;            // Atualiza o topo
        cout << "Push: " << valor << " adicionado ao topo da pilha" << endl;
    }

    // Método para remover elemento do topo da pilha (POP)
    void pop() {
        if (topo == NULL) {
            cout << "Pilha vazia!" << endl;
            return;
        }

        No* temp = topo;          // Armazena o nó do topo
        topo = topo->proximo;     // Atualiza o topo
        cout << "Pop: " << temp->valor << " removido do topo da pilha" << endl;
        delete temp;              // Libera a memória
    }

    // Método para mostrar a pilha
    void mostrar() {
        No* temp = topo;
        cout << "Pilha (do topo para base): ";
        while (temp != NULL) {
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << endl;
    }

    // Método para procurar elemento
    bool procurar(int valor) {
        No* temp = topo;
        while (temp != NULL) {
            if (temp->valor == valor)
                return true;
            temp = temp->proximo;
        }
        return false;
    }
};

int main() {
    header();

    Pilha pilha;
    int valor;

    // Adicionando elementos na pilha
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    mudaLinha();
    separador();
    mudaLinha();

    // Exibir a pilha inicial
    cout << "Pilha inicial:" << endl;
    pilha.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Adicionar novo elemento
    cout << "Introduza um valor para adicionar à pilha: ";
    cin >> valor;
    pilha.push(valor);   
    mudaLinha();
    separador();
    mudaLinha();
    cout << "Introduza mais um valor para adicionar à pilha: ";
    cin >> valor;
    pilha.push(valor);
    mudaLinha();
    separador();
    mudaLinha();

    cout << "Pilha após adição:" << endl;
    pilha.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Remover elemento
    cout << "Testar pop para remover o elemento do topo da pilha... LIFO" << endl;
    pilha.pop();
    mudaLinha();
    separador();
    mudaLinha();
    
    cout << "Pilha após remoção:" << endl;
    pilha.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Procurar elemento
    cout << "Digite um valor para procurar na pilha: ";
    cin >> valor;
    mudaLinha();
    separador();
    mudaLinha();

    cout << "A procurar pelo valor " << valor << "\nValor " << valor << ": "
         << (pilha.procurar(valor) ? "Encontrado" : "Não encontrado") << endl;

    footer();
    return 0;
}
