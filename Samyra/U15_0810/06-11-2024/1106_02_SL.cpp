#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

int main() {

    meuCarimbo();
	mudaLinha();

    ifstream inputFile("InteirosPositivos.txt");  // Arquivo de entrada
    ofstream outputFileA("1106_02A.txt");         // Arquivo para números menores que a média
    ofstream outputFileB("1106_02B.txt");         // Arquivo para números maiores ou iguais à média

    if (!inputFile.is_open() || !outputFileA.is_open() || !outputFileB.is_open()) {
        cerr << "Erro ao abrir os arquivos." << endl;
        return 1;
    }

    vector<int> numeros;
    int numero, soma = 0;
    
    // Lê cada número do arquivo e armazena no vetor
    while (inputFile >> numero) {
        numeros.push_back(numero);
        soma += numero;
    }

    // Calcula a média
    double media = static_cast<double>(soma) / numeros.size();

    // Salva os números nos arquivos adequados
    for (int num : numeros) {
        if (num < media) {
            outputFileA << num << endl;
        } else {
            outputFileB << num << endl;
        }
    }

    // Fecha os arquivos
    inputFile.close();
    outputFileA.close();
    outputFileB.close();

    cout << "Processamento concluído. Média calculada: " << media << endl;
    cout << "Números menores que a média foram gravados em '1106_02A.txt'." << endl;
    cout << "Números maiores ou iguais à média foram gravados em '1106_02B.txt'." << endl;

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
