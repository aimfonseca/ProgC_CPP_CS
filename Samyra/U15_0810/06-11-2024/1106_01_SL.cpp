#include <iostream>
#include <fstream>

using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

int main() {

    meuCarimbo();
	mudaLinha();

    ifstream inputFile("Inteiros.txt");   // Abrir o arquivo de entrada
    ofstream outputFile("1106_01.txt");   // Criar o arquivo de saída

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Erro ao abrir os arquivos." << endl;
        return 1;
    }

    int numero;
    int somaPositivos = 0;
    int somaNegativos = 0;

    // Ler cada número no arquivo e atualizar as somas de positivos e negativos
    while (inputFile >> numero) {
        if (numero > 0) {
            somaPositivos += numero;
        } else {
            somaNegativos += numero;
        }
    }

    // Gravar os resultados no arquivo de saída
    outputFile << "Soma dos números positivos: " << somaPositivos << endl;
    outputFile << "Soma dos números negativos: " << somaNegativos << endl;

    // Fechar os arquivos
    inputFile.close();
    outputFile.close();

    cout << "Processamento concluído. Resultados gravados em '1106_01.txt'." << endl;

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

