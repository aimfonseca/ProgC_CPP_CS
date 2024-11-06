#include <iostream>
#include <string>

using namespace std;

void meuCarimbo(void);
void mudaLinha(void);

class Animal {
    protected:
        string nome;

    public:
        Animal(string _nome) : nome(_nome) {}

        void come() {
            cout << nome << " está a comer." << endl;
        }
        
};

class mamifero : public Animal {
    protected:
        int numPatas;

    public:
        mamifero(string _nome, int _numPatas) : Animal(_nome) 
        {
            numPatas = _numPatas;
        }

        void anda() {
            cout << nome << " está a caminhar em " << numPatas << " patas." << endl;
        }
};

class gato : public mamifero {
    public:
        gato(string _nome, int _numPatas) : mamifero(_nome, _numPatas) {}

        void mia() {
            cout << nome << " está a miar." << endl;
        }
};

void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Stefanie Abreu] - [ %s ]", data_hora);

}
   
   void mudaLinha(void)
{
    printf("\n");
}	



int main() {

    meuCarimbo();
    mudaLinha();

    gato meuGato("Loki", 4);

    meuGato.come();
    meuGato.anda();
    meuGato.mia();

    return 0;
}
