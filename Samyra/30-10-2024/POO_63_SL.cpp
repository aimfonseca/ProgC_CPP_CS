#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class classeBase {
    public:
    int comissao = 10;
    void print(){
        cout << "Funcao principal. " << endl;
    }
};

class classeDerivada : public classeBase {
    public:
    void print(){
        cout << "Funcao derivada " << endl;
    }
};


int main() {

    meuCarimbo();
	mudaLinha();

    classeDerivada exemploUm;

    exemploUm.print();

    cout << exemploUm.comissao << endl;

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
