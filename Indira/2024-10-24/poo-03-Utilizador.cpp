#include <iostream>
#include <ctime>   // Para manipulação de data e hora

using namespace std;

// Função para imprimir uma nova linha
void mudaLinha() {
    std::cout << std::endl;
}

// Função para imprimir o carimbo com a data e hora atuais
void meuCarimbo() {
    std::time_t tempo_atual = std::time(nullptr);  // Obtém o tempo atual
    std::tm* tempo_local = std::localtime(&tempo_atual);  // Converte para a hora local
    char data_hora[64];  // String para armazenar a data e hora

    // Formata a data e hora no formato "dd-mm-yyyy hh:mm:ss"
    std::strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);

    // Imprime o carimbo com as informações
    std::cout << "\n[UFCD_U15] - [POO] - [Indira] - [ " << data_hora << " ]";
    mudaLinha();  // Chama a função para pular linha
}

//definição da classe
class Utilizador{
    private:
        string nome = "Antonio";
        string palavrapasse = "abc123def456";

    public:
        void set(string nome, string palavraPasse){
            this -> nome = nome;
            this -> palavrapasse = palavraPasse;
        }

        void get(){
            cout << nome << " " << palavrapasse << endl;
        }

};

int main(){
    meuCarimbo();

    Utilizador novo_obj;

    mudaLinha();
    novo_obj.get();
    novo_obj.set("Indira", "def123abc456");

    mudaLinha();
    novo_obj.get();
    mudaLinha();

    return 0;
}