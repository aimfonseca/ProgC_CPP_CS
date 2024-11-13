#include <iostream>
#include "template.h"

using namespace std;

// AINDA POR EXPLORAR


/*
 * Macros são diretivas de pré-processamento que permitem definir constantes,
 * funções e blocos de código que são substituídos durante a compilação.
 * 
 * Tipos comuns de macros:
 * 1. Macros de constantes (#define PI 3.14159)
 * 2. Macros de função (#define QUADRADO(x) ((x) * (x)))
 * 3. Macros condicionais (#ifdef, #ifndef, #endif)
 * 
 * Vantagens das macros:
 * - Código mais legível
 * - Manutenção simplificada
 * - Processamento em tempo de compilação
 */

// Macros de constantes
#define PI 3.14159
#define VERSAO "1.0"
#define MAX_VALORES 5

// Macros de função
#define QUADRADO(x) ((x) * (x))
#define CUBO(x) ((x) * (x) * (x))
#define MAIOR(a,b) ((a) > (b) ? (a) : (b))
#define MENOR(a,b) ((a) < (b) ? (a) : (b))

// Macro para debug
#define DEBUG(x) cout << "Debug: " << x << endl

class DemoMacros {
private:
    int valores[MAX_VALORES];
    int contador;

public:
    DemoMacros() {
        contador = 0;
    }

    void adicionarValor(int valor) {
        if (contador < MAX_VALORES) {
            valores[contador++] = valor;
            DEBUG("Valor adicionado: " << valor);
        }
    }

    void mostrarCalculos() {
        cout << "\nCálculos usando macros:" << endl;
        for (int i = 0; i < contador; i++) {
            cout << "Número: " << valores[i] << endl;
            cout << "Quadrado: " << QUADRADO(valores[i]) << endl;
            cout << "Cubo: " << CUBO(valores[i]) << endl;
            cout << "-------------------" << endl;
        }
    }

    void compararValores() {
        if (contador >= 2) {
            cout << "\nComparações:" << endl;
            cout << "Maior entre " << valores[0] << " e " << valores[1] 
                 << ": " << MAIOR(valores[0], valores[1]) << endl;
            cout << "Menor entre " << valores[0] << " e " << valores[1]
                 << ": " << MENOR(valores[0], valores[1]) << endl;
        }
    }
};

int main() {
    header();

    cout << "Demonstração de Macros - Versão " << VERSAO << endl;
    cout << "Valor de PI definido por macro: " << PI << endl;
    mudaLinha();
    separador();

    DemoMacros demo;
    int valor;

    for (int i = 0; i < MAX_VALORES; i++) {
        cout << "\nIntroduza o valor " << (i + 1) << ": ";
        cin >> valor;
        demo.adicionarValor(valor);
    }

    separador();
    demo.mostrarCalculos();
    separador();
    demo.compararValores();
    mudaLinha();

    footer();
    return 0;
}
