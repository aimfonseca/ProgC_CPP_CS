#include <iostream>   
#include <fstream>   

using namespace std;  

int main() {

    ofstream outputFile("EX_TAM_SL.txt");   // Criação do arquivo de texto 

    if (!outputFile) {
        cerr << "Erro ao criar o arquivo." << endl; // Mensagem de erro caso o arquivo não tenha sido criado com sucesso
        return 1; 
    }

    cout << "Olá Mundo!" << endl;
    outputFile << "Olá Mundo!" << endl;   // Grava a mensagem no arquivo

    // Grava no arquivo a seção de tamanhos dos tipos de dados
    outputFile << "Tamanhos em bytes dos tipos de dados:" << endl; 
    outputFile << "char: " << sizeof(char) << " bytes" << endl;     
    outputFile << "short: " << sizeof(short) << " bytes" << endl;   
    outputFile << "int: " << sizeof(int) << " bytes" << endl;      
    outputFile << "long: " << sizeof(long) << " bytes" << endl;    
    outputFile << "long long: " << sizeof(long long) << " bytes" << endl;      
    outputFile << "float: " << sizeof(float) << " bytes" << endl;      
    outputFile << "double: " << sizeof(double) << " bytes" << endl;    
    outputFile << "long double: " << sizeof(long double) << " bytes" << endl;  

    outputFile.close();   

    cout << "Os tamanhos foram gravados em 'EX_TAM_SL.txt'." << endl;   // Mensagem indica que os dados foram gravados 

    return 0; 
}

// UFCD_U14
// Samyra Lima
// 2024-10-08
