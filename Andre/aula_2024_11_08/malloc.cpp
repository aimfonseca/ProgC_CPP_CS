#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main() {
    int* array;
    int size = 5;
   
    // Alocação inicial do array
    array = (int*)malloc(size * sizeof(int));
   
    // Preenchendo o array inicial
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
   
    // Mostrando o array inicial
    cout << "Array inicial: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
   
    // Redimensionando o array
    int new_size = 8;
    array = (int*)realloc(array, new_size * sizeof(int));
   
    // Preenchendo os novos elementos
    for (int i = size; i < new_size; i++) {
        array[i] = i + 1;
    }
   
    // Mostrando o array redimensionado
    cout << "Array redimensionado: ";
    for (int i = 0; i < new_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
   
    // Liberando a memória
    free(array);
   
    return 0;
}
 