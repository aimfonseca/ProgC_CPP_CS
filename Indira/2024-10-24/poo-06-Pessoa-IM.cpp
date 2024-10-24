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

// Função para imprimir uma linha de separação com 120 asteriscos
void separador() {
    for (int i = 0; i < 120; i++) {
        std::cout << "*";
    }
    mudaLinha();  // Pula linha após imprimir os asteriscos
}

//definição da classe
class Pessoa{
    private:
        string nome;
        int idade;
        float classificacao;

    public:
        void set(string nome, int idade, float classificacao){
            this -> nome = nome;
            this -> idade = idade;
            this ->classificacao = classificacao;
        }

        void get(){
            cout << nome << " " << idade << " " << classificacao <<endl;
        }

        void podeFrequentar(){
            if( this->idade >= 20 & this->classificacao > 12){
                cout << "Pode inscrever-se" << endl;
            }

            else{
                cout << "Não se pode inscrever" << endl;
            }
        }

};

int main(){
    separador();
    meuCarimbo();

    string nome;
    int idade;
    float classificacao;

    Pessoa novaPessoa;

    cout << "---Dados: ---" << endl;
    cout << "Nome: ";
    cin >> nome;

    cout << "Idade: ";
    cin >> idade;

    cout << "Classificacao: ";
    cin >> classificacao;
    
    novaPessoa.set(nome, idade, classificacao);

    mudaLinha();
    
    novaPessoa.podeFrequentar();

    mudaLinha();

    separador();
    return 0;
}