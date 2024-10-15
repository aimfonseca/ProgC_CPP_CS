#include <iostream>  
#include <fstream>  

using namespace std; // Permite usar elementos da biblioteca padrão sem o prefixo 'std::'

// Validar as horas, minutos e segundos
bool validarTempo(int horas, int minutos, int segundos) {
    return (horas >= 0 && horas <= 23) && (minutos >= 0 && minutos < 60) && (segundos >= 0 && segundos < 60);
}

// Calcular o total de segundos desde o início do dia
// Converte horas e minutos em segundos, e soma tudo
int calcularSegundos(int horas, int minutos, int segundos) {
    return horas * 3600 + minutos * 60 + segundos;  // 1 hora = 3600 segundos
}

// Salvar o total de segundos num arquivo de texto
void salvarArquivo(int segundos) {
    ofstream arquivo("EX_SEG_SL.txt");  // Abre/cria o arquivo 
    if (arquivo.is_open()) {            
        arquivo << segundos;            // Grava o total de segundos no arquivo
        arquivo.close();                // Fecha o arquivo após a gravação
    }
}

int main() {
    int horas, minutos, segundos; 

    // Solicita e lê as horas, minutos e segundos inseridos pelo usuário
    cout << "Insira as horas (0-23): ";
    cin >> horas;  
    cout << "Insira os minutos (0-59): ";
    cin >> minutos;  
    cout << "Insira os segundos (0-59): ";
    cin >> segundos; 

    // Verifica se os valores de horas, minutos e segundos são válidos
    if (validarTempo(horas, minutos, segundos)) { 

        int segundosTotais = calcularSegundos(horas, minutos, segundos);     // Calcula o total de segundos
        cout << "Segundos totais desde 00:00: " << segundosTotais << endl;   // Exibe o total de segundos calculados

        salvarArquivo(segundosTotais);                                       // Salva o total de segundos no arquivo 'EX_SEG_SL.txt'
        cout << "Total de segundos salvo no arquivo 'EX_SEG_SL.txt'.\n";     // Informa que o valor foi salvo com sucesso

    } else {
        
        cout << "Valores de tempo inválidos. Por favor, verifique os valores inseridos.\n"; // Mensagem de erro se os valores não forem válidos
    }

    return 0;  
}

// UFCD_U14
// Samyra Lima
// 2024-10-08
