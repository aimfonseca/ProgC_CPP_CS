#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class Carro{
public:
    string nomeCarro;
    
    // Construtor com um argumento
    Carro( string nomeCarro) {
        this -> nomeCarro = nomeCarro;
    }

    // Construtor de cópia
    Carro(Carro &outroCarro) {
       nomeCarro = outroCarro.nomeCarro;
    }

};

int main() {

    meuCarimbo();
	mudaLinha();

    Carro carroOriginal("Ruido tipo Mustang");
    cout << "Carro original: " << carroOriginal.nomeCarro << endl;
   
    Carro carroCopiado(carroOriginal);
    cout << "Primeiro carro copiado: " << carroCopiado.nomeCarro << endl;
    
    Carro outroCarroCopiado(carroOriginal);
    cout << "Segundo carro copiado: " << outroCarroCopiado.nomeCarro << endl;

    return 0;
}

// ------------------------------------------
// Fun��o que muda de linha quando necess�rio
	
	void mudaLinha(void)
	{
		printf("\n"); // muda de linha
	}	
	
// ------------------------------------------
// Fun��o que mostra (algumas) informa��es gerais
	
	void meuCarimbo(void)
	{
		time_t tempo_atual = time(NULL);
		struct tm *tempo_local = localtime(&tempo_atual);
		char data_hora[64];
		
		strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
		printf("\n[Samyra Lima] - [ %s ]", data_hora);
		mudaLinha();
	}
