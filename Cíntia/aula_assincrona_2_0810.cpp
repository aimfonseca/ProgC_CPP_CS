#include <iostream>
/* Cíntia Vasconcelos

Foi solicitado um programa que escreva "Olá Mundo!" e mostre o tamanho em bytes
 dos seguintes tipos de dados: char, short, int, long, long long, float, double e long double" */
 
int main() {
    std::cout << "Olá Mundo!" << std::endl;
    
    std::cout << "Tamanho de char: " << sizeof(char) << " byte(s)" << std::endl;
    std::cout << "Tamanho de short: " << sizeof(short) << " byte(s)" << std::endl;
    std::cout << "Tamanho de int: " << sizeof(int) << " byte(s)" << std::endl;
    std::cout << "Tamanho de long: " << sizeof(long) << " byte(s)" << std::endl;
    std::cout << "Tamanho de long long: " << sizeof(long long) << " byte(s)" << std::endl;
    std::cout << "Tamanho de float: " << sizeof(float) << " byte(s)" << std::endl;
    std::cout << "Tamanho de double: " << sizeof(double) << " byte(s)" << std::endl;
    std::cout << "Tamanho de long double: " << sizeof(long double) << " byte(s)" << std::endl;
    
    return 0;
}
