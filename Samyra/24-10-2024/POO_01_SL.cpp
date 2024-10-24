#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

// 01: Definição da classe 
class nomeClasse{
    // 02: Declaração de membros privados 
    private:
        int valorPrivado;
    // 03: Declaração de membros publicos 
    public:
        int valorPublico;

        void funcaoPublica(){
            cout << "Esta e minha primeira funcao" << endl;
        }
}; // Fim da classe

int main(){
    
    meuCarimbo();
	mudaLinha();

    // 04 Criação de um objeto do tipo classe
    nomeClasse objectoNovo;

    // 05: Podemos aceder e modificar os dados de um objeto público
    objectoNovo.valorPublico = 10;

    // 06: E também podemos usar as funçoes definidas dentro da classe
    objectoNovo.funcaoPublica();

    return 0;
};

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