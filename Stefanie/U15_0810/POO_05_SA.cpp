#include <iostream>
#include <string> // Inclui a biblioteca string para manipulação de strings
#include <ctime>  // Inclui a biblioteca ctime para manipulação de tempo

using namespace std;

// Declaração das funções
void meuCarimbo();
void mudaLinha();

class outraClasse
{
public:
    int xInt;
    string sString;
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
    meuCarimbo(); // Chamada correta da função meuCarimbo

    outraClasse outro_objeto;
    cout << "Tamanho de xInt: " << sizeof(outro_objeto.xInt) << " bytes" << endl;
    cout << "Tamanho de sString: " << sizeof(outro_objeto.sString) << " bytes" << endl;
    cout << "Tamanho do objeto outraClasse: " << sizeof(outro_objeto) << " bytes" << endl;

    return 0;
}
