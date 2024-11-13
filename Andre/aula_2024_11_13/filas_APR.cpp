#include <iostream>
#include "template.h"

using namespace std;

/*
 * Filas são estruturas de dados que seguem o princípio FIFO (First In, First Out),
 * onde o primeiro elemento a entrar é o primeiro a sair.
 * Semelhante a uma fila de pessoas, onde quem chega primeiro é atendido primeiro.
 * A remoção de elementos é feita no início da fila segundo o princípio FIFO. First In, First Out.
 * 
 * Esta implementação demonstra operações básicas como:
 * - Enfileirar / Push (adicionar elementos no fim da fila)
 * - Desenfileirar / Pop (remover elementos do início da fila)
 * - Visualizar elementos da fila
 * - Verificar se um elemento existe na fila
 */

// Definição da estrutura do nó da fila
struct No {
    int valor; // Valor armazenado no nó
    No* proximo; // Ponteiro para o próximo nó
};

// Classe Fila 
class Fila {
private:
    No* inicio;     // Ponteiro para o primeiro elemento
    No* fim;        // Ponteiro para o último elemento

public:
    // Método construtor
    Fila() {
        inicio = NULL; // Inicia fila vazia (inicio/cabeça/head)
        fim = NULL; // Inicia o ponteiro para o último elemento como nulo, indicando que a fila está vazia. (fim/cauda/tail)
    }

    // Método para adicionar elemento no fim da fila também conhecido como PUSH
    void enfileirar(int valor) {
        No* novoNo = new No(); // Cria novo nó
        novoNo->valor = valor; // Atribui o valor
        novoNo->proximo = NULL; // O novo nó será o último, então não há próximo nó.

        // Se a fila está vazia, o novo nó será o primeiro e o último
        if (fim == NULL) {
            inicio = novoNo;
            fim = novoNo;

        // Se a fila não está vazia, o novo nó será o último
        } else {
            fim->proximo = novoNo; // O próximo nó do último nó será o novo nó
            fim = novoNo; // Atualiza o ponteiro para o último elemento
        }
    }

    // Método para remover elemento do início da fila também conhecido como POP
    void desenfileirar() {
        if (inicio == NULL) {
            cout << "Fila vazia!" << endl;
            return;
        }

        No* temp = inicio; // Nó temporário para armazenar o nó a ser removido
        inicio = inicio->proximo; // Atualiza o ponteiro para o próximo nó
        
        // Se o elemento removido era o último da fila, atualiza o ponteiro para o último elemento
        if (inicio == NULL) {
            fim = NULL;
        }
        
        delete temp; // Libera a memória do nó removido
    }

    // Método para mostrar a fila
    void mostrar() {
        No* temp = inicio; // Nó temporário para percorrer a fila
        cout << "Fila: "; 

        // Loop para percorrer a fila e exibir os valores
        while (temp != NULL) {
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << endl;
    }

    // Método para procurar elemento
    bool procurar(int valor) {
        No* temp = inicio;
        while (temp != NULL) {
            if (temp->valor == valor) // Se o valor for encontrado retorna true
                return true;
            temp = temp->proximo; // Avança para o próximo nó
        }
        return false;
    }
};

int main() {
    header();

    Fila fila;
    int valor;

    // Adicionando elementos na fila
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);

    // Exibir a fila inicial
    cout << "Fila inicial:" << endl;
    fila.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Adicionar novo elemento
    cout << "Introduza um valor para adicionar à fila: ";
    cin >> valor;
    fila.enfileirar(valor);

    cout << "Fila após adição:" << endl;
    fila.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Remover elemento
    cout << "Efetuar pop para remover o primeiro elemento da fila... FIFO" << endl;
    fila.desenfileirar();
    
    cout << "Fila após remoção:" << endl;
    fila.mostrar();
    mudaLinha();
    separador();
    mudaLinha();

    // Procurar elemento
    cout << "Digite um valor para procurar na fila: ";
    cin >> valor;
    mudaLinha();
    separador();
    mudaLinha();

    cout << "A procurar pelo valor " << valor << "\nValor " << valor << ": "
         << (fila.procurar(valor) ? "Encontrado" : "Não encontrado") << endl;

    footer();
    return 0;
}
