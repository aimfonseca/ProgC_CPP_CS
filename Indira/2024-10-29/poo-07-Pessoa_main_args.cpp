#include <iostream>
#include <ctime>   // Para manipulação de data e hora

using namespace std;

// Função para imprimir uma nova linha
void mudaLinha() {
    cout << endl;
}

// Função para imprimir o carimbo com a data e hora atuais
void meuCarimbo() {
    time_t tempo_atual = time(nullptr);  // Obtém o tempo atual
    tm* tempo_local = localtime(&tempo_atual);  // Converte para a hora local
    char data_hora[64];  // String para armazenar a data e hora

    // Formata a data e hora no formato "dd-mm-yyyy hh:mm:ss"
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);

    // Imprime o carimbo com as informações
    cout << "\n[UFCD_U15] - [POO] - [Indira] - [ " << data_hora << " ]";
    mudaLinha();  
}

// Função para imprimir uma linha de separação com 120 asteriscos
void separador() {
    for (int i = 0; i < 120; i++) {
        cout << "*";
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
           cout << "O/A " << nome << " -> ";

            if( idade >= 20 && classificacao > 12){
                cout << "Pode inscrever-se" << endl;
            }

            else{
                cout << "Nao se pode inscrever" << endl;
            }
        }

};

int main(int argc, char* argv[]) {
    // Verificar se foram passados argumentos, argc indica quantos argumentos foram sendo que o 1º argumento (argv[0]=nome_do_programa)
    if (argc != 4) {
        cerr << "Tente novamente: ./nomedoprograma nome idade classificacao" << endl;
        return 1;
    }

    separador();
    meuCarimbo();
    mudaLinha();

    string nome = argv[1];
    int idade = atoi(argv[2]); //converte string para inteiro
    float classificacao = atof(argv[3]); //convert string para float

    Pessoa novaPessoa;
/*
    cout << "---Insira os Dados: ---" << endl;
    cout << "Nome: ";
    cin >> nome;

    cout << "Idade: ";
    cin >> idade;

    cout << "Classificacao: ";
    cin >> classificacao;
*/

    
    novaPessoa.set(nome, idade, classificacao);

    mudaLinha();
    
    novaPessoa.podeFrequentar();

    mudaLinha();

    separador();
    return 0;
}