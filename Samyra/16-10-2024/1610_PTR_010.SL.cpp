#include <iostream>

void mudaLinha(void); 
void meuCarimbo(void);

int main() {

    meuCarimbo();
	mudaLinha();

    int numeros[5] = {10, 20, 30, 40, 50}; // Declaração e inicialização de um array de inteiros com 5 elementos

    int *ptr = numeros; // Declaração de um ponteiro para inteiro e inicialização com o endereço do primeiro elemento do array

    // Explicação para o usuário
    std::cout << "O programa vai imprimir o valor do primeiro elemento do array usando duas abordagens diferentes.\n";
    std::cout << "Pressione Enter para continuar...\n";
    std::cin.get(); // Espera o usuário pressionar Enter

    // Imprime o primeiro elemento do array usando notação de colchetes
    std::cout << "Primeiro elemento do array usando notacao de colchetes: " << numeros[0] << std::endl;

    // Imprime o valor apontado por ptr (primeiro elemento do array)
    std::cout << "Primeiro elemento do array usando ponteiro: " << *ptr << std::endl;

    std::cout << "\nAgora, o ponteiro vai ser incrementado para apontar para o proximo elemento do array.\n";
    std::cout << "Pressione Enter para continuar...\n";
    std::cin.get();

    // Incrementa o ponteiro para apontar para o próximo elemento
    ptr++;
    std::cout << "Segundo elemento do array usando ponteiro: " << *ptr << std::endl; // Imprime o valor do segundo elemento do array

    std::cout << "\nO ponteiro será decrementado para voltar ao primeiro elemento do array.\n";
    std::cout << "Pressione Enter para continuar...\n";
    std::cin.get();

    // Decrementa o ponteiro para voltar ao primeiro elemento
    ptr--;
    std::cout << "Primeiro elemento do array novamente: " << *ptr << std::endl; // Imprime o valor do primeiro elemento novamente

    std::cout << "\nAgora, vamos usar aritmética de ponteiros para acessar o terceiro elemento do array.\n";
    std::cout << "Pressione Enter para continuar...\n";
    std::cin.get();

    // Imprime o valor do terceiro elemento do array usando aritmética de ponteiros
    std::cout << "Terceiro elemento do array usando aritmética de ponteiros: " << *(ptr + 2) << std::endl;

    return 0;
}

// ------------------------------------------
// Fun��o que muda de linha quando necess�rio
	
	void mudaLinha(void)
	{
		printf("\n"); // muda de linha
	}	
	
// ------------------------------------------
// Fun��o que mostra (algumas) informa��es gerais
	
	void meuCarimbo(void)
	{
		time_t tempo_atual = time(NULL);
		struct tm *tempo_local = localtime(&tempo_atual);
		char data_hora[64];
		
		strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
		printf("\n[Samyra Lima] - [ %s ]", data_hora);
		mudaLinha();
	}
   

