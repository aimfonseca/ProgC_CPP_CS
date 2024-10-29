#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class utilizador{
    private:
        string nome = "Samyra";
        string palavraPasse = "abc123def456";
    
    public:
        void set(string nome, string palavraPasse){
            this -> nome = nome;
            this -> palavraPasse = palavraPasse;
        }
        void get(){
            cout << nome << " " << palavraPasse << endl;
        }
};

int main(){

    meuCarimbo();
	mudaLinha();

    utilizador novo_obj;
    novo_obj.get();
    novo_obj.set("Samyra", "def123abc567po");
    novo_obj.get();

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