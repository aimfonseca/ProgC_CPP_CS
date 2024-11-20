#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int horas, minutos, segundos;

    // Leitura das horas, minutos e segundos
    cout << "Introduza as horas (1-23): ";
    cin >> horas;
    if (horas < 1 || horas > 23) {
        cout << "Horas inválidas!" << endl;
        return 1;
    }

    cout << "Introduza os minutos (0-60): ";
    cin >> minutos;
    if (minutos < 0 || minutos > 60) {
        cout << "Minutos inválidos!" << endl;
        return 1;
    }

    cout << "Introduza os segundos (0-60): ";
    cin >> segundos;
    if (segundos < 0 || segundos > 60) {
        cout << "Segundos inválidos!" << endl;
        return 1;
    }

    // Cálculo do total de segundos
    int totalSegundos = horas * 3600 + minutos * 60 + segundos;

    // Gravação do resultado num ficheiro de texto
    ofstream outFile("total_segundos.txt");
    if (outFile.is_open()) {
        outFile << "Total de segundos desde o início do dia: " << totalSegundos << endl;
        outFile.close();
        cout << "Resultado guardado em 'total_segundos.txt'" << endl;
    } else {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return 1;
    }

    return 0;
}
