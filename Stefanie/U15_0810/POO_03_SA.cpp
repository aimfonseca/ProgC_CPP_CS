#include <iostream>
#include <string>   // Inclui a biblioteca string para manipulação de strings
#include <ctime> // Inclui a biblioteca ctime para manipulação de tempo

using namespace std;

// Declaração das funções
void meuCarimbo();
void mudaLinha();


//#01 - Definição da classe

class utilizador{
    //#03 - Declaração de membros publicos (dados e funçoes) da classe
    private:
        string nome = "Stefanie";
        string palavraPasse = "abc123def456";

    public:
        void set(string nome, string palavraPasse){
            this->nome = nome;
            this->palavraPasse = palavraPasse;
        }

        void get(){
            cout << nome << " " << palavraPasse << endl;
        }
}; // fim da classe 'nomeClasse', com o terminador ';'

void mudaLinha();

int main(){
   
   utilizador novo_obj;
   novo_obj.get();
   novo_obj.set("Ana", "abc286");
   novo_obj.get();
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