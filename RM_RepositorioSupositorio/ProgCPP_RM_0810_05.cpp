#include <iostream>
#include <fstream> // Para continuarmos a trabalhar com ficheiros

using namespace std;

int main(int argc, char* argv[]) {
    // Exibir o nome do programa (eng)
    cout << "Program name is: " << argv[0] << endl;

    // Exibir o número de argumentos (eng)
    cout << "Number Of Arguments Passed: " << argc << endl;
    
    // Exibir os argumentos passados (eng :-) com 4+4 hífens e tudo!)
    cout << "----Following Are The Command Line Arguments Passed----" << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }

    // Guardar os resultados num ficheiro de texto
    ofstream ficheiro("argumentos.txt"); // Abrir ou criar ficheiro
    if (ficheiro.is_open()) {
        ficheiro << "Program name is: " << argv[0] << endl;
        ficheiro << "Number Of Arguments Passed: " << argc << endl;
        ficheiro << "----Following Are The Command Line Arguments Passed----" << endl;
        for (int i = 0; i < argc; i++) {
            ficheiro << "argv[" << i << "]: " << argv[i] << endl;
        }
        ficheiro.close(); // Fechar o ficheiro
        cout << "Os argumentos foram guardados no ficheiro 'argumentos.txt'." << endl;
    } else {
        cout << "Erro ao abrir o ficheiro!" << endl;
    }

    return 0;
}
