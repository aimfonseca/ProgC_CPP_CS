#include <iostream>   // Biblioteca para manipulação de entrada e saída padrão
#include <ctime>      // Biblioteca para manipulação de data e hora

using namespace std;

// Declaração das funções 'meuCarimbo' e 'mudaLinha'
void meuCarimbo(void); // Exibe carimbo com data e hora
void mudaLinha(void);  // Função para pular uma linha

// Declaração da classe 'Retangulo'
class Retangulo {
    int altura;   // Atributo para armazenar a altura do retângulo
    int largura;  // Atributo para armazenar a largura do retângulo

public:
    // Construtor da classe, que inicializa a altura e largura do retângulo
    Retangulo(int alt, int larg);

    // Funções sobrecarregadas para desenhar o retângulo
    void desenha();         // Desenha o retângulo com '*' (asteriscos)
    void desenha(char c);   // Desenha o retângulo com um caractere específico
};

// Implementação do construtor
Retangulo::Retangulo(int alt, int larg) : altura(alt), largura(larg) {}
// Inicializa os atributos 'altura' e 'largura' com os valores passados

// Implementação da função 'desenha' que desenha com '*'
void Retangulo::desenha() {
    // Loop para cada linha do retângulo
    for (int i = 0; i < altura; i++) {
        // Loop para cada coluna da linha atual
        for (int j = 0; j < largura; j++)
            cout << '*';  // Imprime '*' para preencher a linha
        cout << "\n";     // Pula para a próxima linha ao final da linha atual
    }
}

// Implementação da função 'desenha' sobrecarregada, usando um caractere específico
void Retangulo::desenha(char c) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++)
            cout << c;  // Imprime o caractere 'c' para preencher a linha
        cout << "\n";   // Pula para a próxima linha ao final da linha atual
    }
}

// Função para exibir o carimbo de identificação com data e hora
void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);                 // Obtenção do tempo atual
    struct tm *tempo_local = localtime(&tempo_atual); // Converte para o tempo local
    char data_hora[64];

    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    // Formata data e hora como dia-mês-ano hora:minuto:segundo e armazena em 'data_hora'
    printf("\n[UFCD_U15] - [Stefanie Abreu] - [ %s ]\n", data_hora);
    // Exibe o carimbo com informações formatadas
}

// Função para pular uma linha
void mudaLinha(void) {
    cout << "\n";
}

// Função principal do programa
int main() {
    // Chama 'meuCarimbo' no início para exibir o carimbo com data e hora
    meuCarimbo();

    // Cria um objeto 'ret' da classe Retangulo com altura 8 e largura 12
    Retangulo ret(8, 12);

    // Desenha o retângulo usando a primeira versão de 'desenha()', com '*'
    ret.desenha();
    mudaLinha(); // Chama 'mudaLinha' para pular uma linha entre as exibições

    // Desenha o retângulo usando a segunda versão de 'desenha()', com o caractere 'A'
    ret.desenha('A');

    return 0; // Encerra o programa
}
