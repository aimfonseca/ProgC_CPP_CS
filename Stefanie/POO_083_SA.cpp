#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Classe Pessoa, que armazena informações sobre uma pessoa e possui métodos para exibir informações e verificar se a pessoa pode se inscrever
class Pessoa
{

private:
    string nome;
    int idade;
    float classificacao;

public:
    // Método para definir os atributos da pessoa
    void set(const string &nome, int idade, float classificacao)
    {
        this->nome = nome;
        this->idade = idade;
        this->classificacao = classificacao;
    }

    // Exibe informações da pessoa
    void exibirInformacoes() const
    {
        cout << "Nome da pessoa: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Classificacao: " << classificacao << endl;
    }

    // Verifica se a pessoa pode se inscrever com base na classificação e idade
    void verificarInscricao() const
    {
        if (classificacao > 12 && idade >= 20)
        {
            cout << "Pode inscrever-se" << endl;
        }
        else
        {
            cout << "Nao se pode inscrever" << endl;
        }
    }
};

// Função para exibir o carimbo com a data, hora e outras informações
void meuCarimbo()
{
    time_t tempo_atual = time(NULL);                  // Obtem o tempo atual do sistema
    struct tm *tempo_local = localtime(&tempo_atual); // Converte o tempo para o formato local
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local); // Formata a data e hora
    cout << "[UFCD_U15] - [POO] - [Andre Proenca] - [ " << data_hora << " ]" << endl;
}

// Função para exibir uma linha de separação de comprimento variável (padrão é 120)
void separador(int comprimento = 120)
{
    cout << string(comprimento, '*') << endl;
}

int main(int argc, char *argv[])
{
    // Verifica se o número de argumentos está correto
    if (argc != 4)
    {
        cerr << "Erro! O programa espera 3 argumentos." << endl; // Exibe erro se os argumentos são insuficientes
        separador();                                             // Linha de separação
        return 1;                                                // Retorna erro
    }

    // Converte argumentos para as variáveis corretas
    string nome = argv[1];               // Nome da pessoa (primeiro argumento)
    int idade = stoi(argv[2]);           // Idade da pessoa (segundo argumento, convertido para int)
    float classificacao = stof(argv[3]); // Classificação da pessoa (terceiro argumento, convertido para float)

    // Cria um objeto da classe Pessoa e define seus dados
    Pessoa pessoa;
    pessoa.set(nome, idade, classificacao);

    // Exibe as informações da pessoa
    cout << " Informacoes da pessoa: " << endl;
    pessoa.exibirInformacoes();  // Exibe nome, idade e classificação
    pessoa.verificarInscricao(); // Verifica se a pessoa pode se inscrever com base nas regras

    return 0; // Termina o programa com sucesso
}
