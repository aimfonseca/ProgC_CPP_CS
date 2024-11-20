#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class Retangulo {
    int altura;   
    int largura;  

public:
    // Construtor da classe Retangulo, que recebe altura e largura como parâmetros
    Retangulo(int alt, int larg);

    // Funções para desenhar o retângulo: sobrecarregadas para aceitar ou não um caractere
    void desenha();         // Versão que usa '*' como caractere 
    void desenha(char c);    // Versão que usa uma letra
}; // Fim de class Retangulo.


// Implementação do construtor.
Retangulo::Retangulo(int alt, int larg) {
    altura = alt;    //define a altura
    largura = larg;  //define a largura
} 

// Função desenhar padrão
void Retangulo::desenha() {
     // Desenha o retângulo preenchendo-o com o caractere * 
    for (int i = 0; i < altura; i++) {       // Loop para cada linha do retângulo
        for (int j = 0; j < largura; j++) {   // Loop para cada coluna
            cout << '*';                      
        }
        cout << "\n";                       
    }
}

// Função desenhar com o caractere customizado
void Retangulo::desenha(char c) {
    // Desenha o retângulo preenchendo-o com o caractere c recebido 
    for (int i = 0; i < altura; i++) {        // Loop para cada linha do retângulo
        for (int j = 0; j < largura; j++) {   // Loop para cada coluna
            cout << c;                       
        }
        cout << "\n";                         
    }
} 

int main() {

    meuCarimbo();
	mudaLinha();

    // Cria um objeto da classe Retangulo, com altura 8 e largura 12
    Retangulo ret(8, 12);

    // Desenha usando as duas versões de desenha()
    ret.desenha();       //versão com *

    cout << "\n\n";

    ret.desenha('A');    //versão com A

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
