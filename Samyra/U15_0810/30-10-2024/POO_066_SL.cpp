#include <iostream>
#include <string>

using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class Livro {
    protected:
        int paginas;

    public:
        Livro(int p){
            paginas = p;
        }
        virtual void descreve(){
            cout << "Este livro tem " << paginas << " paginas. " << endl;
        }
};

class LivroPonto : public Livro {
    private:
        int sumarios;

    public:
        LivroPonto(int pag, int sum) : Livro(pag) {
            sumarios = sum;
        }
        void descreve() {
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
        void descreve() {
            cout << "Este dicionario tem " << paginas << " paginas e " << entradas << " entradas." << endl;
        }
};

int main() {

    meuCarimbo();
	mudaLinha();

    Livro* tabela[5];
    tabela[0] = new Livro (100);
    tabela[1] = new Dicionario (900, 1000);
    tabela[2] = new LivroPonto (100, 9);
    tabela[3] = new Dicionario (700, 5000);
    tabela[4] = new Livro (250);

    for (int i = 0; i< 5; i++) {
        tabela[i]->descreve();
    }

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
