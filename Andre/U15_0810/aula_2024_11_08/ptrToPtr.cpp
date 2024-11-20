#include <iostream>

void modificarValor(int **ptr2) {
    **ptr2 = 20; 

// Modifica o valor apontado pelo ponteiro duplo
}

int main() {
    int valor = 5;
    int *ptr = &valor; 

// Ponteiro para valor
int **ptrParaPtr = &ptr; 

std::cout << ptr << std::endl;

// Ponteiro para ponteiro

   std::cout << "Antes: " << valor << std::endl; 
// Saída: 5

modificarValor(ptrParaPtr);
    std::cout << "Depois: " << valor << std::endl; 
// Saída: 10

std::cout << valor;
std::cout << ptr;

return 0;
}