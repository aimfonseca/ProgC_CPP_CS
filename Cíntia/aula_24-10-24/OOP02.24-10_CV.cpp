/* Cíntia Vasconcelos */
#include <iostream>
#include <string>

/* Função para imprimir uma assinatura personalizada */
void meuCarimbo() {
    std::cout << "--- Cintia Vasconcelos ---" << std::endl;
}

/* Definição da classe 'Pessoa' */
class Pessoa {
private:
    std::string nome;
    int idade;
    float classificacao;

public:
    /* Construtor da classe Pessoa */
    Pessoa(const std::string& nome, int idade, float classificacao) : nome(nome), idade(idade), classificacao(classificacao) {}

    /* Método para verificar se a pessoa pode frequentar o curso */
    void podeFrequentar() {
        if (classificacao > 12 && idade >= 20) {
            std::cout << nome << " pode inscrever-se." << std::endl;
        } else {
            std::cout << nome << " nao se pode inscrever." << std::endl;
        }
    }
};

int main() {
    /* Criação de uma nova instância da classe 'Pessoa' */
    std::string nome;
    int idade;
    float classificacao;

    /* Solicita os dados da pessoa */
    std::cout << "Digite o nome: ";
    std::getline(std::cin, nome);
    std::cout << "Digite a idade: ";
    std::cin >> idade;
    std::cout << "Digite a classificacao: ";
    std::cin >> classificacao;

    /* Criação do objeto 'pessoa' e chamada do método 'podeFrequentar' */
    Pessoa pessoa(nome, idade, classificacao);
    pessoa.podeFrequentar();

    /* Imprime assinatura personalizada */
    meuCarimbo();

    return 0;
}
