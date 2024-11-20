#include <iostream>
#include "template.h"

using namespace std;

// ainda por explorar

// Macros de constantes básicas
#define PI 3.14159
#define VERSAO "2.0"
#define MAX_VALORES 5
#define AUTOR "André"
#define TRUE 1
#define FALSE 0

// Macros de mensagens
#define MENSAGEM_INICIO "Início do Programa de Demonstração de Macros"
#define MENSAGEM_FIM "Fim do Programa"

// Macros de função matemática
#define QUADRADO(x) ((x) * (x))
#define CUBO(x) ((x) * (x) * (x))
#define MAIOR(a,b) ((a) > (b) ? (a) : (b))
#define MENOR(a,b) ((a) < (b) ? (a) : (b))
#define SOMA(a,b) ((a) + (b))
#define MEDIA(a,b) (((a) + (b)) / 2.0)

// Macros de controle
#define INICIO_SECAO(x) cout << "\n=== " << x << " ===" << endl
#define FIM_SECAO cout << "===================" << endl

// Macros de debug
#define DEBUG_INFO(x) cout << "[INFO] " << x << endl
#define DEBUG_ERRO(x) cout << "[ERRO] " << x << endl
#define DEBUG_VALOR(x) cout << "[VALOR] " << #x << " = " << x << endl

// Macros condicionais
#define MODO_DEBUG

#ifdef MODO_DEBUG
    #define LOG(x) cout << "[DEBUG] " << x << endl
#else
    #define LOG(x)
#endif

// Macros de concatenação
#define CONCAT(a, b) a##b
#define STR(x) #x

class DemoMacros {
private:
    int valores[MAX_VALORES];
    int contador;

public:
    DemoMacros() : contador(0) {
        LOG("Objeto DemoMacros criado");
    }

    void adicionarValor(int valor) {
        if (contador < MAX_VALORES) {
            valores[contador++] = valor;
            DEBUG_INFO("Valor " << valor << " adicionado com sucesso");
        } else {
            DEBUG_ERRO("Limite de valores atingido");
        }
    }

    void mostrarCalculos() {
        INICIO_SECAO("Cálculos com Macros");
        
        for (int i = 0; i < contador; i++) {
            DEBUG_VALOR(valores[i]);
            cout << "Quadrado: " << QUADRADO(valores[i]) << endl;
            cout << "Cubo: " << CUBO(valores[i]) << endl;
            
            if (i > 0) {
                cout << "Média com anterior: " << MEDIA(valores[i], valores[i-1]) << endl;
            }
        }
        
        FIM_SECAO;
    }

    void demonstrarMacros() {
        INICIO_SECAO("Demonstração de Macros Especiais");
        
        // Demonstração de concatenação
        int CONCAT(valor, 123) = 456;
        cout << "Macro concatenada: " << STR(valor123) << " = " << valor123 << endl;
        
        // Demonstração de constantes
        cout << "Autor: " << AUTOR << endl;
        cout << "PI: " << PI << endl;
        
        FIM_SECAO;
    }
};

int main() {
    header();
    
    cout << MENSAGEM_INICIO << " - Versão " << VERSAO << endl;
    
    DemoMacros demo;
    int valor;

    for (int i = 0; i < MAX_VALORES; i++) {
        cout << "\nIntroduza o valor " << (i + 1) << ": ";
        cin >> valor;
        demo.adicionarValor(valor);
    }

    demo.mostrarCalculos();
    demo.demonstrarMacros();

    cout << MENSAGEM_FIM << endl;
    
    footer();
    return 0;
}
