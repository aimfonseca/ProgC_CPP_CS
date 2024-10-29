
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

class Utilizador {
    private:
        string nome = "Ricardo";
        string palavraPasse = "abc123def456";

    public:
        void set(string nome, string palavraPasse){ 
            this -> nome = nome;
            this -> palavraPasse = palavraPasse;
        }
        void get(){
            cout << nome << " " << palavraPasse << endl;
        }
};

int main() {
    string nome;
    string palavraPasse;
    Utilizador novo_obj;
    cout << "Valores iniciais: " << endl;
    novo_obj.get();
    cout << "Novo nome: ";
        cin >> nome;
    cout << "Nova password: ";
        cin >> palavraPasse;
    novo_obj.set(nome, palavraPasse);
    cout << "Novos valores: " << endl;
    novo_obj.get();

    mudarLinha();
	meuCarimbo();

    return 0;
}

