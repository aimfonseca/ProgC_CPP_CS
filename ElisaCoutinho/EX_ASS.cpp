#include <iostream>   // Biblioteca para entrada e saída de dados
#include <fstream>    // Biblioteca para manipulação de arquivos

using namespace std;

int main() {
    int horas, minutos, segundos;  // Variáveis para armazenar horas, minutos e segundos
    int totalSegundos;             // Variável para armazenar o total de segundos

    // Solicita ao usuário que introduza as horas
    cout << "Introduza as horas (1-23): ";
    cin >> horas;

    // Validação das horas: deve estar entre 1 e 23
    while (horas < 1 || horas > 23) {
        cout << "Horas invalidas. Introduza um valor entre 1 e 23: ";
        cin >> horas;
    }

    // Solicita ao usuário que introduza os minutos
    cout << "Introduza os minutos (0-59): ";
    cin >> minutos;

    // Validação dos minutos: deve estar entre 0 e 59
    while (minutos < 0 || minutos >= 60) {
        cout << "Minutos invalidos. Introduza um valor entre 0 e 59: ";
        cin >> minutos;
    }

    // Solicita ao usuário que introduza os segundos
    cout << "Introduza os segundos (0-59): ";
    cin >> segundos;

    // Validação dos segundos: deve estar entre 0 e 59
    while (segundos < 0 || segundos >= 60) {
        cout << "Segundos invalidos. Introduza um valor entre 0 e 59: ";
        cin >> segundos;
    }

    // Calcula o número total de segundos desde o início do dia
    // totalSegundos = (horas * 3600) + (minutos * 60) + segundos
    totalSegundos = (horas * 3600) + (minutos * 60) + segundos;

    // Exibe o total de segundos calculado
    cout << "O total de segundos desde o inicio do dia e: " << totalSegundos << " segundos." << endl;

    // Cria um arquivo de texto para armazenar o resultado
    ofstream arquivo("total_segundos.txt");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo.is_open()) {
        // Escreve o total de segundos no arquivo
        arquivo << "Total de segundos desde o inicio do dia: " << totalSegundos << " segundos." << endl;
        
        // Fecha o arquivo
        arquivo.close();

        // Exibe uma mensagem de sucesso
        cout << "O valor foi guardado no ficheiro total_segundos.txt" << endl;
    } else {
        // Exibe uma mensagem de erro se o arquivo não pôde ser aberto
        cout << "Erro ao abrir o ficheiro!" << endl;
    }

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
