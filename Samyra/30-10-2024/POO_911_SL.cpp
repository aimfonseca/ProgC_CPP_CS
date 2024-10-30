#include <iostream>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);


class Retangulo {
    int altura;
    int largura;

public:
    // Construtor.
    Retangulo(int alt, int larg);

    // Função sobrecarregada.
    void desenha();
    void desenha(char c);
}; // Fim de class Retangulo.

// Implementação do construtor.
Retangulo::Retangulo(int alt, int larg) {
    altura = alt;
    largura = larg;
} 

// Função sobrecarregada.
void Retangulo::desenha() {
    
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            cout << '*';
        }
        cout << "\n";
    } 
}

//Função desenhar
void Retangulo::desenha(char c) {
    // Desenha o retângulo preenchendo-o com o caractere c recebido 
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            cout << c;
        }
        cout << "\n";
    } 
} // Fim de Retangulo::desenha(char c)

int main() {

    meuCarimbo();
	mudaLinha();

    // Cria um objeto da classe Retangulo.
    Retangulo ret(8, 12);

    // Desenha usando as duas versões de desenha()
    ret.desenha();
    cout << "\n\n";
    ret.desenha('A');

    return 0;
} // Fim de main()



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
