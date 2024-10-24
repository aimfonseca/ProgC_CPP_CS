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
class Estudante{

    public:
        string nome;
        int idade;

        void mostrar(){
            cout << nome << " " << idade << endl;
        }

};

int main(){
    meuCarimbo();

    Estudante novoEstudante;

    mudaLinha();
    cout << "Insere o nome e a idade: " <<endl;
    cin >> novoEstudante.nome >> novoEstudante.idade;

    mudaLinha();
    cout << "Nov@ Estudante: " <<endl;
    novoEstudante.mostrar();
    mudaLinha();

    return 0;
}