#include <iostream>
using namespace std;    

void meuCarimbo(void);
void mudaLinha(void);

class Carro {
    public:
        string nomeCarro;

        //Construtor com um argumento
        Carro(string nomeCarro) {
            this->nomeCarro = nomeCarro;
        }

        //Construtor de cópia
        Carro(Carro &outroCarro) {
            nomeCarro = outroCarro.nomeCarro;
        }

        // Construtor sem argumentos
        Carro() {
            nomeCarro = "Carro normal";
        }

};

void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}


void mudaLinha(void)
{
    printf("\n");
}	

int main() {

    meuCarimbo();   
    mudaLinha();    
    
    Carro carroOriginal("Ruido tipo mustang");
    cout << carroOriginal.nomeCarro << endl;

    Carro carroCopiado(carroOriginal);
    cout << carroCopiado.nomeCarro << endl;

    Carro carroNormal;
    cout << "Carro normal: " << carroNormal.nomeCarro << endl;

    return 0;
}
    