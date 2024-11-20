
#include<iostream>
#include<string>

using namespace std;

void mudarLinha() {
    std::cout << std::endl; // Função para adicionar uma linha em branco
}

void meuCarimbo() {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    cout << "Ricardo Moreira - " << asctime(&datetime); // Imprime assinatura com o carimbo 
}

class Estudante {
public:
    string nome;
    int idade;

    void mostrar() {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

int main() {
    Estudante novoEstudante;

    cout << "Insira o nome do estudante: "; // Mensagem para o utilizador inserir o nome
    // cin >> novoEstudante.nome; Método para a inserção de um nome
    // cin.ignore(); // Limpa o buffer antes de usar o getline (serve para não dar problemas)
    getline(cin, novoEstudante.nome); // Método para a inserção de um nome completo com espaços

    cout << "Insira a idade do estudante: "; // Mensagem para o utilizador inserir a idade
    cin >> novoEstudante.idade;
    novoEstudante.mostrar();

	mudarLinha();
	meuCarimbo();

    return 0;
}