#include <iostream>
#include <string>   // Inclui a biblioteca string para manipulação de strings
#include <ctime> // Inclui a biblioteca ctime para manipulação de tempo

using namespace std;

// Declaração das funções
void meuCarimbo();
void mudaLinha();

//#01 - Definição da classe

class nomeClasse{
    //#02 - declaração de membros privados (dados e funçoes) da classe
    private:
        int valorPrivado;
    //#03 - Declaração de membros publicos (dados e funçoes) da classe
    public:
        int valorPublico;

        void funcaoPublica(){
            cout << "esta e a minha primeira funcao" << endl;
        }
}; // fim da classe 'nomeClasse', com o terminador ';'

void mudaLinha();

int main(){
    //#04 - Criação de um objeto da classe 'nomeClasse'
    nomeClasse objetoNovo;

    //#05 - Acesso aos membros da classe e modificar de um objeto publico
    objetoNovo.valorPublico = 10;

    //#06- tambem podemos usar funcoes definidas dentro da classe
    objetoNovo.funcaoPublica();

    return 0;
}

void meuCarimbo();


// Funções auxiliares
void meuCarimbo() {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Ponteiros] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}

void mudaLinha() {
    printf("\n");
}