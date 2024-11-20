// Erro na componente de output
// Analisar com AI Cody
// Live Share

#include<iostream>
#include "template.h"

using namespace std;

class Livro {
protected:
    int paginas;

public:
    Livro(int p) {
        paginas = p;
    }
    virtual void descreve() {
        cout << "Este livro tem " << paginas << " paginas." << endl;
    }
};

class LivroPonto : public Livro {
private:
    int sumarios;

public:
    LivroPonto(int pag, int sum) : Livro(pag) {
        sumarios = sum; 
    }
    void descreve() override {
        cout << "Este livro de sumarios tem " << paginas << " paginas e " << sumarios << " sumarios." << endl;
    }
};

class Dicionario : public Livro {
private:
    int entradas;

public:
    Dicionario(int pag, int ent) : Livro(pag) {
        entradas = ent;
    }
    void descreve() override {
        cout << "Este dicionario tem " << paginas << " paginas e " << entradas << " entradas." << endl;
    }
};

int main() {
    header();
    Livro* tabela[5];
    tabela[0] = new Livro(100);
    tabela[1] = new Dicionario(900, 10000);
    tabela[2] = new LivroPonto(100, 9);
    tabela[3] = new Dicionario(700, 5000);
    tabela[4] = new Livro(250);

    for (int i = 0; i < 5; i++) {
        mudaLinha();
        tabela[i] -> descreve();
        mudaLinha();
        separador();
        mudaLinha();
    }

    footer();
    return 0;
}