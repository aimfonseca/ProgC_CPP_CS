#include <iostream> 

/* Cíntia Vasconcelos */

int main(int argc, char* argv[]) {
  /* nome do programa (primeiro argumento)*/
    std::cout << "Nome do programa: " << argv[0] << std::endl;
    
 /* Quantos argumentos foram passados */
    std::cout << "Quantidade de argumentos passados: " << argc - 1 << std::endl;
    
   /* essa parte mostrará os argumentos, um por um */
    std::cout << "---- Lista dos argumentos passados ----\n";
    
/* loop */
    for (int i = 0; i < argc; i++) {
    /* numero do argumento e o seu valor */
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    return 0;
}
