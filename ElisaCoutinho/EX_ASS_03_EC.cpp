#include <iostream>
#include <fstream> 

using namespace std;

// Elisa Coutinho

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        cout << "Não foi passado nenhum argumento." << endl;
        return 1;
    }

    // Abre ficheiro para gravar os argumentos
    ofstream ficheiro("argumentos.txt");
    if (!ficheiro.is_open()) {
        cerr << "Erro ao abrir o ficheiro." << endl;
        return 1;
    }

    // Exibe os argumentos no ecrã e grava no ficheiro
    cout << "Argumentos passados:" << endl;
    ficheiro << "Argumentos passados:" << endl;
    for (int i = 1; i < argc; ++i) {  
        cout << argv[i] << endl;
        ficheiro << argv[i] << endl;
    }

    // Fecha o arquivo
    ficheiro.close();
    cout << "Argumentos gravados no ficheiro 'argumentos.txt'." << endl;

    return 0;
}
