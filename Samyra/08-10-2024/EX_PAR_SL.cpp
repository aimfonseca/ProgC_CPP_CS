#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    
    if (argc > 1) {
        std::ofstream outputFile("EX_PAR_SL.txt"); 

        
        for (int i = 1; i < argc; ++i) {
            std::cout << "Parametro " << i << ": " << argv[i] << std::endl;
            outputFile << "Parametro " << i << ": " << argv[i] << std::endl;
        }

        outputFile.close(); 

    } else {
        std::cout << "Nenhum parametro foi passado." << std::endl;
    }

    return 0;
}


// UFCD_U14
// Samyra Lima
// 2024-10-08
