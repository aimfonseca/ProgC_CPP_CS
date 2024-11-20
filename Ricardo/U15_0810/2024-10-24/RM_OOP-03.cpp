
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
        string nome = "Ricardo ";
        string palavraPasse = "abc123def456";

    public:
        void set(string nome, string palavraPasse){ 
            this -> nome = nome;
            this -> palavraPasse = palavraPasse;
        }
        void get(){
            cout << nome << "a palavra-passe é -> " << palavraPasse << endl;
        }
};

int main() {
    Utilizador novo_obj;
    novo_obj.get();
    novo_obj.set("Ricardo ", "def123abc456");
    novo_obj.get();

	mudarLinha();
	meuCarimbo();

    return 0;
}