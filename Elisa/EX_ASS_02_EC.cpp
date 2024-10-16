#include <iostream>
#include <fstream>
#include <string>

// Elisa Coutinho


int main() {
    std::string mensagem = "Olá Mundo!";
    std::ofstream arquivo("tamanhos_dados.txt");

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    arquivo << mensagem << std::endl;
    arquivo << "Tamanhos em bytes dos tipos de dados:" << std::endl;
    arquivo << "char: " << sizeof(char) << " bytes" << std::endl;
    arquivo << "short: " << sizeof(short) << " bytes" << std::endl;
    arquivo << "int: " << sizeof(int) << " bytes" << std::endl;
    arquivo << "long: " << sizeof(long) << " bytes" << std::endl;
    arquivo << "long long: " << sizeof(long long) << " bytes" << std::endl;
    arquivo << "float: " << sizeof(float) << " bytes" << std::endl;
    arquivo << "double: " << sizeof(double) << " bytes" << std::endl;
    arquivo << "long double: " << sizeof(long double) << " bytes" << std::endl;
    arquivo << "Tamanho da string: " << mensagem.size() << " bytes" << std::endl; // Usando .size() para a string

    arquivo.close();

    std::cout << "Os dados foram gravados em tamanhos_dados.txt" << std::endl; // Mensagem de confirmação

    return 0;
}
