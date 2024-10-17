#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    // Verifica se o número de argumentos é igual a 2 (nome do programa + extensão)
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_extension>" << std::endl;
        return 1;
    }

    // Pega a extensão do argumento e verifica se começa com ponto
    std::string extension = argv[1];
    if (extension[0] != '.') {
        extension = "." + extension;
    }

    bool found = false;

    // Itera pelos arquivos do diretório atual
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == extension) {
            if (!found) {
                std::cout << "Files with the extension " << extension << " found in the current directory:" << std::endl;
                found = true;
            }
            // Obtém o tamanho do arquivo em bytes
            auto file_size = fs::file_size(entry);
            std::cout << "- " << entry.path().filename() << " (" << file_size << " bytes)" << std::endl;
        }
    }

    // Caso nenhum arquivo seja encontrado
    if (!found) {
        std::cout << "No files with the extension " << extension << " found in the current directory." << std::endl;
    }

    return 0;
}
