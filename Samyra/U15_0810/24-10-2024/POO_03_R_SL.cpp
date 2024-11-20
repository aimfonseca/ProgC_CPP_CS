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

    string nome;
    string palavraPasse;
    utilizador novo_obj;

    cout << "Valores iniciais:" << endl;
    novo_obj.get();
    cout << "Novo nome: ";
        cin >> nome;
    cout << "Nova palavra passe: ";
        cin >> palavraPasse;

    novo_obj.set(nome, palavraPasse);
    cout << "Valores atualizados:" << endl;
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