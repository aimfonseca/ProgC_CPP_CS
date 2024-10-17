#include <iostream> // biblioteca de entrada e saída (cin, cout)
#include <fstream>  // biblioteca para manipulação de ficheiros (ofstream)

using namespace std; // simplifica o uso de funções da biblioteca padrão

// Função que valida a hora, os minutos e os segundos
// Retorna true se as entradas forem válidas ou false se forem inválidas

bool validacao(int horas, int minutos, int segundos)
{
    // faz verificacao se as horas estão dentro do parametro (1-23)
    if (horas < 1 || horas > 23)
    {
        // mostra  mensagem de erro se as horas forem inválidas
        cout << "Erro: As horas tem de estar entre 1 e 23." << endl;
        return false;
        // Retorna false para indicar erro na validação
    }
    // faz verificacao se os minutos estão dentro do parametro (0-60)
    if (minutos < 0 || minutos > 60)
    {
        // mostra uma mensagem de erro se os minutos forem inválidos
        cout << "Erro: Os minutos devem estar entre 0 e 60." << endl;
        return false;
    }
    // faz verificacao se os segundos estão dentro do parametro (0-60)
    if (segundos < 0 || segundos > 60)
    {
        // mostra uma mensagem de erro se os segundos forem inválidos
        cout << "Erro: Os segundos devem estar entre 0 e 60." << endl;
        return false;
    }
    return true; // Retorna true se todos os valores forem válidos
}

// Função principal do programa
int main()
{
    int horas, minutos, segundos;

    cout << "insere as horas entre 1 a 23: ";
    cin >> horas;
    cout << "insere os minutos entre 0 a 60: ";
    cin >> minutos;
    cout << "insere os segundos entre 0 a 60: ";
    cin >> segundos;

    // Valida os dados inseridos, mas se a validação falhar, o programa encerra com um código de erro 1
    if (!validacao(horas, minutos, segundos))
    {
        return 1;
    }

    // Cálculo do total de segundos desde o início do dia
    // Cada hora tem 3600 segundos
    // Cada minuto tem 60 segundos
    int tSegundos = (horas * 3600) + (minutos * 60) + segundos;

    // Exibe o total de segundos calculado
    cout << "segundos desde o início do dia: " << totalSegundos << endl;

    // Guardar o valor num ficheiro de texto
    ofstream ficheiro("segundos.txt");

    // Verifica se o ficheiro foi aberto com sucesso
    if (ficheiro.is_open())
    {

        ficheiro << "segundos desde o início do dia: " << tSegundos << endl;
        ficheiro.close(); // Fecha o ficheiro após a escrita
        cout << "A informacao foi guardada no ficheiro 'segundos.txt'." << endl;
    }
    else
    {
        // Se houver um erro ao abrir o ficheiro, exibe uma mensagem de erro
        cout << "Erro ao abrir o ficheiro." << endl;
    }

    return 0;

}
