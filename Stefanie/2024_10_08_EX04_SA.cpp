// 08/10/2024
// Stefanie Abreu

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // mostra a mensagem com acentos
    cout << "Olá Mundo!" << endl;

    // Declaração das variáveis para armazenar os tamanhos
    // size_t é um tipo de dado de C e C++ que nunca é negativo,
    // como o sizeof e é usado em arrays e contagem de elementos.
    size_t sizeChar = sizeof(char);
    size_t sizeShort = sizeof(short);
    size_t sizeInt = sizeof(int);
    size_t sizeLong = sizeof(long);
    size_t sizeLongLong = sizeof(long long);
    size_t sizeFloat = sizeof(float);
    size_t sizeDouble = sizeof(double);
    size_t sizeLongDouble = sizeof(long double);

    // Exibe os tamanhos no console
    cout << "O tamanho de char: " << sizeChar << " bytes" << endl;
    cout << "O tamanho de short: " << sizeShort << " bytes" << endl;
    cout << "O tamanho de int: " << sizeInt << " bytes" << endl;
    cout << "O tamanho de long: " << sizeLong << " bytes" << endl;
    cout << "O tamanho de long long: " << sizeLongLong << " bytes" << endl;
    cout << "O tamanho de float: " << sizeFloat << " bytes" << endl;
    cout << "O tamanho de double: " << sizeDouble << " bytes" << endl;
    cout << "O tamanho de long double: " << sizeLongDouble << " bytes" << endl;

    // Guarda os resultados num ficheiro de texto
    ofstream ficheiro("tamanhosDedados.txt");
    if (ficheiro.is_open())
    {
        ficheiro << "O tamanho de char: " << sizeChar << " bytes" << endl;
        ficheiro << "O tamanho de short: " << sizeShort << " bytes" << endl;
        ficheiro << "O tamanho de int: " << sizeInt << " bytes" << endl;
        ficheiro << "O tamanho de long: " << sizeLong << " bytes" << endl;
        ficheiro << "O tamanho de long long: " << sizeLongLong << " bytes" << endl;
        ficheiro << "O tamanho de float: " << sizeFloat << " bytes" << endl;
        ficheiro << "O tamanho de double: " << sizeDouble << " bytes" << endl;
        ficheiro << "O tamanho de long double: " << sizeLongDouble << " bytes" << endl;
        ficheiro.close();
        cout << "resultados foram guardados no ficheiro 'tamanhosDedados.txt'." << endl;
    }
    else
    {
        cout << "Erro ao abrir o ficheiro." << endl;
    }

    return 0;
}
