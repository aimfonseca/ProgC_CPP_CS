#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class Pessoa{

    private:
    string nome;
    int idade;
    float classificacao;

    public:
    // Construtor para inicializar os atributos
    Pessoa(string n, int i, float c) : nome(n), idade(i), classificacao(c) {}
    
    // Função para verificar se a pessoa pode frequentar um evento
    void podeFrequentar(){
        if(classificacao >= 12 && idade >= 20){
            cout << nome << " pode increver-se." << endl;
        }
        else{
            cout << nome << " nao pode increver-se." << endl;
        }
    }
};

int main(int argc, char* argv[]){

    meuCarimbo();
	mudaLinha();

    if (argc != 4) { // Verificar se foram passados 3 argumentos: nome, idade e classificação
        cerr << "Uso correto: <nome> <idade> <classificacao>" << endl;
        return 1;
    }

    // Converter os argumentos fornecidos (string -> int/float)
    string nome = argv[1];
    int idade = atoi(argv[2]);  //  atoi converte string para integer
    float classificacao = atof(argv[3]); // atof converte string para float

    // Criar instância da classe Pessoa com os argumentos passados
    Pessoa pessoa(nome, idade, classificacao);
    pessoa.podeFrequentar();

    // Verificar se a pessoa pode ou não inscrever-se
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