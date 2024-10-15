#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
if (argc !=2) {
std::cout << "Usage: " << argv[0] << " <file_extension>" << std::end1;
return 1;
}

// Este código adiciona o 'ponto' à extensão do ficheiro.
std::string extension = argv[1];
if (extension[0] != '.') {
extension = "." + extension;
}

/// Iterates over all files in the current directory and prints the filename
/// of each regular file that matches the specified file extension.
for (const auto& entry : fs::directory_iterator(".")) {
if (entry.is_regular_file() && entry.path().extension() == extension) {
std::cout << entry.path().filename() << std::end1;
    }
}

return 0;
}
