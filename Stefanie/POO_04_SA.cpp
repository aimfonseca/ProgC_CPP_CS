#include <iostream>
#include <string> // Inclui a biblioteca string para manipulação de strings
#include <ctime>  // Inclui a biblioteca ctime para manipulação de tempo

using namespace std;

// Declaração das funções
void meuCarimbo();
void mudaLinha();

// Definição da classe
class utilizador
{
private:
    string nome = "Stefanie";
    string palavraPasse = "abc123def456";

public:
    void set(string nome, string palavraPasse)
    {
        this->nome = nome;
        this->palavraPasse = palavraPasse;
    }

    void get()
    {
        cout << "Nome: " << nome << " | Palavra-passe: " << palavraPasse << endl;
    }
};

// Funções auxiliares
void meuCarimbo()
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [POO] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}

void mudaLinha()
{
    printf("\n");
}

int main()
{
    utilizador novo_obj;
    string novoNome, novaPalavraPasse;

    // Exibe os dados iniciais do objeto
    meuCarimbo();
    novo_obj.get();

    // Solicita ao usuário que insira um novo nome e nova palavra-passe
    cout << "Digite o novo nome (sem espacos): ";
    cin >> novoNome;

    cout << "Digite a nova palavra-passe (sem espacos): ";
    cin >> novaPalavraPasse;

    // Define os novos valores no objeto
    novo_obj.set(novoNome, novaPalavraPasse);

    // Exibe os dados atualizados do objeto
    meuCarimbo();
    novo_obj.get();

    return 0;
}
