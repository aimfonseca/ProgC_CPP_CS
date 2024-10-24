#include <iostream>
#include <string>   // Inclui a biblioteca string para manipulação de strings
#include <ctime> // Inclui a biblioteca ctime para manipulação de tempo

using namespace std;

// Declaração das funções
void meuCarimbo();
void mudaLinha();

//#01 - Definição da classe

class estudante{
    //#03 - Declaração de membros publicos (dados e funçoes) da classe
    public:
        string nome;
        int idade;

        void mostrar(){
            cout << nome << " " << idade << endl;
        }
}; // fim da classe 'nomeClasse', com o terminador ';'

void mudaLinha();

int main(){
    //#04 - Criação de um objeto da classe 'nomeClasse'
    estudante novoEstudante;

   cin >> novoEstudante.nome >> novoEstudante.idade;
   novoEstudante.mostrar();

    return 0;
}

void meuCarimbo();


// Funções auxiliares
void meuCarimbo() {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [POO] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}

void mudaLinha() {
    printf("\n");
}