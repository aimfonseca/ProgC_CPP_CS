#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class umaClasse {
public:
    int valor;
    
    // Construtor por omissão [by default] (sem parâmetros)
    umaClasse() {
        cout << "Evoca o construtor sem parâmetros." << endl;
        valor = 29;
    }

    // Construtor com parâmetros
    umaClasse(int umValor) {
        cout << "Evoca o construtor com um parâmetro (ou argumento)." << endl;
        valor = umValor;
    }

    // Método
    void mostraValor() {
        cout << "valor: " << valor << endl;
    }

};

int main() {

    meuCarimbo();
	mudaLinha();

    umaClasse objeto_um;        
       objeto_um.mostraValor();

    umaClasse objeto_dois(10);     
       objeto_dois.mostraValor();

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
