#include <iostream>
#include <string>
using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

// Classe base para Funcionario
class Funcionario {
protected:
    string nome;
    string numeroContribuinte;

public:
    Funcionario(string nome, string numeroContribuinte)
        : nome(nome), numeroContribuinte(numeroContribuinte) {}

    virtual void exibirDetalhes() const = 0; // Método virtual puro para exibir detalhes
};

// Classe Freelancer, derivada de Funcionario
class Freelancer : public Funcionario {
private:
    int horasTrabalhadas;
    double valorPorHora;

public:
    Freelancer(string nome, string numeroContribuinte, int horasTrabalhadas, double valorPorHora)
        : Funcionario(nome, numeroContribuinte), horasTrabalhadas(horasTrabalhadas), valorPorHora(valorPorHora) {}

    double calcularPagamento() const {
        return horasTrabalhadas * valorPorHora;
    }

    void exibirDetalhes() const override {
        cout << "Freelancer: " << nome << endl;
        cout << "Numero de Contribuinte: " << numeroContribuinte << endl;
        cout << "Horas Trabalhadas: " << horasTrabalhadas << endl;
        cout << "Valor por Hora: " << valorPorHora << endl;
        cout << "Pagamento Total: " << calcularPagamento() << endl;
    }
};

// Classe Interno, derivada de Funcionario
class Interno : public Funcionario {
private:
    double salarioBase;
    double bonusAnual;

public:
    Interno(string nome, string numeroContribuinte, double salarioBase, double bonusAnual)
        : Funcionario(nome, numeroContribuinte), salarioBase(salarioBase), bonusAnual(bonusAnual) {}

    double calcularSalarioAnual() const {
        return salarioBase + bonusAnual;
    }

    void exibirDetalhes() const override {
        cout << "Interno: " << nome << endl;
        cout << "Numero de Contribuinte: " << numeroContribuinte << endl;
        cout << "Salario Base: " << salarioBase << endl;
        cout << "Bonus Anual: " << bonusAnual << endl;
        cout << "Salario Anual Total: " << calcularSalarioAnual() << endl;
    }
};

int main() {

    meuCarimbo();
	mudaLinha();

    // Instâncias de cada classe
    Freelancer freelancer("Joao Silva", "123456789", 160, 25.0);
    Interno interno("Maria Oliveira", "987654321", 3000.0, 1000.0);

    // Exibir detalhes dos funcionários
    cout << "Detalhes dos Funcionarios:" << endl;
    cout << "--------------------------" << endl;

    freelancer.exibirDetalhes();
    cout << endl;
    interno.exibirDetalhes();

    return 0;
}

// ------------------------------------------
// Fun��o que muda de linha quando necess�rio
	
	void mudaLinha(void)
	{
		printf("\n"); // muda de linha
	}	
	
// ------------------------------------------
// Fun��o que mostra (algumas) informa��es gerais
	
	void meuCarimbo(void)
	{
		time_t tempo_atual = time(NULL);
		struct tm *tempo_local = localtime(&tempo_atual);
		char data_hora[64];
		
		strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
		printf("\n[Samyra Lima] - [ %s ]", data_hora);
		mudaLinha();
	}