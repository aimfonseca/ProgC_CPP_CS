#include <iostream>
#include <fstream> // biblioteca para manipulação de arquivos

// data: 08/10/2024
// Stéfanie Abreu

int main(int argc, char *argv[])
{
    // verifica se foram fornecidos argumentos além do nome do programa
    if (argc > 1)
    {
        // Abre um arquivo para gravacão de texto
        std::ofstream file("parametros.txt");

        // Exibe e grava todos os argumentos numa linha
        std::cout << "Parâmetros: ";
        file << "Parâmetros: ";

        // Loop para percorrer e processar os argumentos
        for (int i = 1; i < argc; ++i)
        {
            std::cout << argv[i] << " ";
            file << argv[i] << " ";
        }

        std::cout << std::endl;
        file << std::endl;

        // Fecha o ficheiro após gravar os parâmetros
        file.close();
    }
    else
    {
        // Caso não haja argumentos além do nome do programa, exibe uma mensagem informativa
        std::cout << "Nenhum parâmetro fornecido." << std::endl;
    }

    return 0;
}
