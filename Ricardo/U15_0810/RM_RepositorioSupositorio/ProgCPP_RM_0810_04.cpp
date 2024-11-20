#include <iostream>
#include <fstream> // Para trabalhar com ficheiros

using namespace std;

int main() {
    // Exibir "Olá Mundo!" com acentos
    cout << "Olá Mundo!" << endl;

    // Obter os tamanhos dos tipos de dados
    ofstream ficheiro("tamanhos_tipos_dados.txt"); // Criar ficheiro de saída

    if (ficheiro.is_open()) {
        ficheiro << "Tamanho dos tipos de dados em bytes:\n";
        ficheiro << "char: " << sizeof(char) << " byte(s)\n";
        ficheiro << "short: " << sizeof(short) << " byte(s)\n";
        ficheiro << "int: " << sizeof(int) << " byte(s)\n";
        ficheiro << "long: " << sizeof(long) << " byte(s)\n";
        ficheiro << "long long: " << sizeof(long long) << " byte(s)\n";
        ficheiro << "float: " << sizeof(float) << " byte(s)\n";
        ficheiro << "double: " << sizeof(double) << " byte(s)\n";
        ficheiro << "long double: " << sizeof(long double) << " byte(s)\n";

        ficheiro.close(); // Fechar o ficheiro
        cout << "Os resultados foram guardados no ficheiro 'tamanhos_tipos_dados.txt'." << endl;
    } else {
        cout << "Erro ao abrir o ficheiro!" << endl;
    }

    return 0;
}
