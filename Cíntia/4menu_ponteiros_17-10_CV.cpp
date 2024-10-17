/* Cíntia Vasconcelos */
#include <iostream>
#include <fstream>
#include <string>

/* Função para imprimir uma linha em branco */
void mudaLinha() {
    std::cout << std::endl;
}

/* Função para imprimir uma assinatura personalizada */
void meuCarimbo() {
    std::cout << "--- Cintia Vasconcelos ---" << std::endl;
}

/* Função para exibir o texto da matéria a partir de um ficheiro */
void exibirTextoMateria(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);
    if (arquivo.is_open()) {
        std::string linha;
        while (getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
    }
}

int main() {
    int opcao;
    do {
        std::cout << "Menu de Opcoes:" << std::endl;
        std::cout << "1. Exemplo de ponteiro simples" << std::endl;
        std::cout << "2. Exemplo de ponteiro com array" << std::endl;
        std::cout << "3. Exemplo de ponteiro para ponteiro" << std::endl;
        std::cout << "4. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        mudaLinha();

        switch (opcao) {
            case 1: {
                exibirTextoMateria("materia_ponteiro_simples.txt");
                mudaLinha();
                /* Exemplo 01: Imprimindo valor e endereco de uma variavel inteira */
                int numero;
                numero = 10;
                std::cout << "Valor da variavel 'numero': " << numero << std::endl;
                std::cout << "Endereco de memoria da variavel 'numero': " << &numero << std::endl;
                mudaLinha();
                break;
            }

            case 2: {
                exibirTextoMateria("materia_ponteiro_array.txt");
                mudaLinha();
                /* Exemplo 04: Trabalhando com ponteiros e arrays */
                int numeros[5] = {10, 20, 30, 40, 50};
                int *ptr = numeros; // Ponteiro para o array 'numeros'
                std::cout << "Elementos do array 'numeros': ";
                for (int i = 0; i < 5; ++i) {
                    std::cout << *(ptr + i) << " ";
                }
                mudaLinha();
                break;
            }

            case 3: {
                exibirTextoMateria("materia_ponteiro_para_ponteiro.txt");
                mudaLinha();
                /* Exemplo de ponteiro para ponteiro */
                int var_ex03 = 20;
                int *ptr_ex03 = &var_ex03;
                int **ptr_ptr_ex03 = &ptr_ex03;
                std::cout << "Valor da variavel 'var_ex03': " << var_ex03 << std::endl;
                std::cout << "Endereco do ponteiro 'ptr_ex03': " << ptr_ex03 << std::endl;
                std::cout << "Valor apontado por 'ptr_ex03': " << *ptr_ex03 << std::endl;
                std::cout << "Endereco do ponteiro para ponteiro 'ptr_ptr_ex03': " << ptr_ptr_ex03 << std::endl;
                std::cout << "Valor apontado pelo ponteiro para ponteiro 'ptr_ptr_ex03': " << **ptr_ptr_ex03 << std::endl;
                mudaLinha();
                break;
            }

            case 4:
                std::cout << "Saindo..." << std::endl;
                break;

            default:
                std::cout << "Opcao invalida! Tente novamente." << std::endl;
                mudaLinha();
                break;
        }
    } while (opcao != 4);

    meuCarimbo();
    return 0;
}
