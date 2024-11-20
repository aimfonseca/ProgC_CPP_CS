
#include <iostream>

using namespace std;

void mudarLinha() {
    std::cout << std::endl; // Função para adicionar uma linha em branco
}

void meuCarimbo() {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    cout << "Ricardo Moreira - " << asctime(&datetime); // Imprime assinatura com o carimbo 
}

// #01: Definição da classe
class nomeClasse {
    // #02: Declaração de membros privados (dados e funções) da classe
private:
    int valorPrivado;

// #03: Declaração de membros públicos (dados e funções) da classe
public:
    int valorPublico;
    
    void funcaoPublica() {

    cout << "Esta é a minha primeira função" << endl;
    }
}; // Fim da classe 'nomeClasse', com o terminador ';'

int main() {
    // #04: Criação de um objeto do tipp da classe
    nomeClasse objectoNovo;

    // #05: Podemos aceder e modificar os dados de um objecto público
    objectoNovo.valorPublico = 10;

    // #6: E também podemos usar as funções definidas dentro da classe
    objectoNovo.funcaoPublica();

    mudarLinha();
	meuCarimbo();

return 0;
}