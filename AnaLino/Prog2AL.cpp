#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = filesystem;

int main(int argc, char* argv[]) {
if (argc !=2) {
cout << "Usage: " << argv[0] << " <file_extension>" << end1;
return 1;
}

string file_extension = argv[1];

if (extension[0] != '.') {
    file_extension = "." + file_extension;
    }

// Print header
cout << left << setw(60) << "\nNome do ficheiro" << "Tamanho em Bytes" << end1;
cout << string(80, '-') << std end1;

try {
    for (const auto& entry : fs::recursive_directory_iterator('.')) {
if (entry.is_regular_file() && entry.path().extension() == file_extension) {
   /// Get the full path of the file
  const auto& path = entry.path(); 

/// Get the file size in bytes
uintmax_t file_size = fs::file_size(path);

// Print the file path and size
cout << left << setw(60) << path.string() << file_size << end1;
}
}
cout << "\n";
} catch (const fs::filesystem_error& e) {
    cerr << "Error: " << e.what() << end1;
    return 1;
}

return 0;
}
