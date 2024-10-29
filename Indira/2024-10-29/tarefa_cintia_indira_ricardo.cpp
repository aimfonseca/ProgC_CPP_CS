/* Cíntia Vasconcelos - Indira - Ricardo*/
#include <iostream>
#include <string>
#include <ctime>
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
    cout << "\n[UFCD_U15] - [POO] - [Cintia - Indira - Ricardo] - [ " << data_hora << " ]";
    mudaLinha();  
}

// Função para imprimir uma linha de separação com 120 asteriscos
void separador() {
    for (int i = 0; i < 120; i++) {
        cout << "*";
    }
    mudaLinha();  // Pula linha após imprimir os asteriscos
}

 
/* Definição da classe 'Pessoa' */
class Pessoa {
private:
    string nome;
    int idade;
    float classificacao;
 
public:
    /* Construtor da classe Pessoa */
    Pessoa(const string& nome, int idade, float classificacao) : nome(nome), idade(idade), classificacao(classificacao) {}
 
    /* Método para verificar se a pessoa pode frequentar o curso */
    void podeFrequentar() {
        if (classificacao > 12 && idade >= 20) {
            cout << nome << " pode inscrever-se." << endl;
        } else {
            cout << nome << " nao se pode inscrever." << endl;
        }
    }
};
 
int main() {
    separador();
    meuCarimbo();
    mudaLinha();

    /* Criação de uma nova instância da classe 'Pessoa' */
    string nome;
    int idade;
    float classificacao;
 
    /* Solicita os dados da pessoa */
    cout << "Digite o nome: ";
    getline(cin, nome);
    cout << "Digite a idade: ";
    cin >> idade;
    cout << "Digite a classificacao: ";
    cin >> classificacao;
    mudaLinha();
 
    /* Criação do objeto 'pessoa' e chamada do método 'podeFrequentar' */
    Pessoa pessoa(nome, idade, classificacao);
    pessoa.podeFrequentar();
 
    /* Imprime assinatura personalizada */
    mudaLinha();
    separador();
 
    return 0;
}