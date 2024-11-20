#include <iostream>
#include <string>

using namespace std;

void mudarLinha() {
    cout << endl; // Função para adicionar uma linha em branco
}

void meuCarimbo() {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    cout << "Ricardo Moreira - " << asctime(&datetime); // Imprime assinatura com o carimbo 
}

// Classe base Funcionario
class Funcionario {
protected:
    string nome;
    int numeroContribuinte;

public:
    Funcionario(const string &nome, int numeroContribuinte)
        : nome(nome), numeroContribuinte(numeroContribuinte) {}

    virtual void mostrarInfo() const {
        cout << "Nome: " << nome << endl;
        cout << "Número de Contribuinte: " << numeroContribuinte << endl;
    }

    virtual void direitoAlmoco() const {
        cout << nome << " tem direito a almoçar no refeitório.";
        mudarLinha();
    }
    
    virtual ~Funcionario() {} // Destrutor virtual
};

// Classe derivada Freelancer
class Freelancer : public Funcionario {
private:
    int horasTrabalhadas;
    double valorPorHora;

public:
    Freelancer(const string &nome, int numeroContribuinte, int horasTrabalhadas, double valorPorHora)
        : Funcionario(nome, numeroContribuinte), horasTrabalhadas(horasTrabalhadas), valorPorHora(valorPorHora) {}

    double calcularPagamento() const {
        return horasTrabalhadas * valorPorHora;
    }

    void mostrarInfo() const override {
        Funcionario::mostrarInfo();
        cout << "Horas Trabalhadas: " << horasTrabalhadas << endl;
        cout << "Valor por Hora: " << valorPorHora << endl;
        cout << "Pagamento Total: " << calcularPagamento() << endl;
    }

    void trabalhoPorTurnos() const {
        cout << nome << " está a realizar trabalho por turnos.";
        mudarLinha();
    }
};

// Classe derivada Interno
class Interno : public Funcionario {
private:
    double salarioBase;
    double bonusAnual;

public:
    Interno(const string &nome, int numeroContribuinte, double salarioBase, double bonusAnual)
        : Funcionario(nome, numeroContribuinte), salarioBase(salarioBase), bonusAnual(bonusAnual) {}

    double calcularSalarioAnual() const {
        return salarioBase + bonusAnual;
    }

    void mostrarInfo() const override {
        Funcionario::mostrarInfo();
        cout << "Salário Base: " << salarioBase << endl;
        cout << "Bónus Anual: " << bonusAnual << endl;
        cout << "Salário Anual Total: " << calcularSalarioAnual() << endl;
    }

    void designarProjeto(const string &projeto) const {
        cout << "Projeto designado: " << projeto << endl;
    }
};

// Função principal
int main() {
    // Instância de um Freelancer
    Freelancer freelancer("Nelson Mandela", 123456789, 160, 20.5);
    cout << "Informações do Freelancer: ";
    mudarLinha();
    freelancer.mostrarInfo();
    freelancer.trabalhoPorTurnos();
    freelancer.direitoAlmoco();

    mudarLinha();

    // Instância de um Interno
    Interno interno("Miguel Bombarda", 987654321, 1500.0, 300.0);
    cout << "Informações do Interno: ";
    mudarLinha();
    interno.mostrarInfo();
    interno.designarProjeto("Projeto X");
    interno.direitoAlmoco();

    mudarLinha();
    meuCarimbo();

    return 0;
}
