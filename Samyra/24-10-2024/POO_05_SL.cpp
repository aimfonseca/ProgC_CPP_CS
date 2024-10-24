#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class Pessoa{
    
    public:
        string nome;
        int idade;
        float classificaacao;
    
    void podeFrequentar(){
        if(classificaacao >= 12 && idade >= 20){
            cout << nome << " pode increver-se." << endl;
        }
        else{
            cout << nome << " nao pode increver-se." << endl;
        }
    }
};

int main(){

    meuCarimbo();
	mudaLinha();

    Pessoa pessoa;

    cout << "Digite seu nome: ";
    getline(cin, pessoa.nome);

    cout << "Digite sua idade: ";
    cin >> pessoa.idade;

    cout << "Digite sua classificação: ";
    cin >> pessoa.classificaacao;

    pessoa.podeFrequentar();

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