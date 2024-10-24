#include <iostream> 
/* Cíntia Vasconcelos */
using namespace std;

int main() {
    int horas, minutos, segundos; 
    int totalSegundos; 

    /* Peço para introduzir as horas, minutos e segundos */
    cout << "Digite as horas (entre 1 e 23): ";
    cin >> horas;

    /* Agora vamos validar se as horas estão entre 1 e 23 */
    if (horas < 1 || horas > 23) {
        /* Se as horas forem menores que 1 ou maiores que 23, o programa dá um erro e termina (return 1) */
        cout << "Erro: as horas devem ser entre 1 e 23." << endl;
        return 1; 
    }

    cout << "Digite os minutos (entre 0 e 59): ";
    cin >> minutos;

    /* Validando os minutos (entre 0 e 60) */
    if (minutos < 0 || minutos >= 60) {
        /* Se forem menores que 0 ou maiores ou iguais a 60, dá erro */
        cout << "Erro: os minutos devem ser entre 0 e 59." << endl;
        return 1; 
    }

    cout << "Digite os segundos (entre 0 e 59): ";
    cin >> segundos;

    /* Validando os segundos */
    if (segundos < 0 || segundos >= 60) {
        /* Entre 0 e 60 */
        cout << "Erro: os segundos devem ser entre 0 e 59." << endl;
        return 1; 
    }

    /* Depois das validações, vamos calcular o total de segundos:
       horas * 3600 (segundos por hora) + minutos * 60 (segundos por minuto) + os próprios segundos */
    totalSegundos = horas * 3600 + minutos * 60 + segundos;

    /* E mostramos o resultado final */
    cout << "Total de segundos desde 00:00h: " << totalSegundos << endl;

    return 0; /* Tudo certo xD */
}
