#include <iostream>
#include <string>
#include <ctime> //biblioteca ctime para manipulação de tempo
#include <cstdio> //biblioteca cstdio para printf

using namespace std;



class Pessoa
{
public:
    // Atributos
    string nome;
    int idade;
    float classificacao;

    // Método para verificar se a pessoa pode frequentar o curso
    void podeFrequentar()
    {
        if (classificacao > 12 && idade >= 20)
        {
            cout << nome << " pode inscrever-se." << endl;
        }
        else
        {
            cout << nome << " nao  pode inscrever-se." << endl;
        }
    }
};

// Funções auxiliares

void mudaLinha()
{
    printf("\n");
}

void meuCarimbo()
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [POO_082] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}


int main()
{
    meuCarimbo(); // Chama a função para imprimir o carimbo de data e hora

    // Criação de uma nova instância da classe 'Pessoa'
    Pessoa pessoa;

    // Solicita o nome, idade e classificação da pessoa
    cout << "Insere o nome da pessoa: ";
    getline(cin, pessoa.nome);
    cout << "Insere a idade de " << pessoa.nome << ": ";
    cin >> pessoa.idade;
    cout << "Insere a classificacao de " << pessoa.nome << " no exame de conhecimentos: ";
    cin >> pessoa.classificacao;

    // Chama o método 'podeFrequentar' para verificar se a pessoa pode ou não se inscrever no curso
    pessoa.podeFrequentar();

    return 0;
}
