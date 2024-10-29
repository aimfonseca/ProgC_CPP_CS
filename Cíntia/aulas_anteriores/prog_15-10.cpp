#include <iostream>
#include <filesystem>
#include <string>


int main(int argc, char* argv[]) {
    // Verifica se o número de argumentos passados está correto
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_extension>" << std::endl;
        return 1;
    }

    // Este código adiciona o 'ponto' à extensão do ficheiro.
    std::string extension = argv[1];
    if (extension[0] != '.') {
        extension = "." + extension;
    }

    // Itera sobre todos os arquivos no diretório atual
    // e imprime o nome de cada arquivo regular que tem a extensão especificada.
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == extension) {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    return 0;
}
