#include <iostream>
#include <string>

using namespace std;

void mudarLinha() {
    std::cout << std::endl; // Função para adicionar uma linha em branco
}

void meuCarimbo() {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    cout << "Ricardo Moreira - " << asctime(&datetime); // Imprime assinatura com o carimbo 
}

class Pessoa {
private:
    string nome;
    int idade;
    float classificacao;

public:
    // Construtor para inicializar os atributos
    Pessoa(string n, int i, float c) : nome(n), idade(i), classificacao(c) {}

    // Método para verificar se a pessoa pode frequentar o curso
    void podeFrequentar() const {
        if (classificacao > 12 && idade >= 20) {
            cout << nome << " pode inscrever-se." << endl;
        } else {
            cout << nome << " não se pode inscrever." << endl;
        }
    }
};

int main() {
    string nome;
    int idade;
    float classificacao;

    // Solicitar informações ao utilizador
    cout << "Nome: ";
    getline(cin, nome); // Usar getline para permitir nomes completos
    cout << "Idade: ";
    cin >> idade;
    cout << "Classificação: ";
    cin >> classificacao;

    // Criar instância da classe Pessoa
    Pessoa pessoa(nome, idade, classificacao);

    // Verificar se a pessoa pode ou não inscrever-se
    pessoa.podeFrequentar();

    mudarLinha()
    meuCarimbo()

    return 0;
}
