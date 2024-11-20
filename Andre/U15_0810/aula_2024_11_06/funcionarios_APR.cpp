#include <iostream>
#include <string>
#include "template.h"

using namespace std;

class Funcionario {
protected:
    int numContribuinte;
    string nome;

public:
    Funcionario(int numContribuinte, const string& nome)
        : numContribuinte(numContribuinte), nome(nome) {}

    virtual void exibirInformacoes() const {
        cout << "Nome: " << nome << "\nNIF: " << numContribuinte << endl;
    }

    virtual double calcularSalario() const = 0; // Método virtual puro, para calcular salário

    void almoçar() const {
        cout << nome << " tem direito a almocar no refeitorio da empresa." << endl;
    }
};

// Classe para funcionários internos
class Interno : public Funcionario {
private:
    double salarioBase;
    double bonusAnual;
    string projeto; // Projeto específico, se houver

public:
    Interno(int numContribuinte, const string& nome, double salarioBase, double bonusAnual, const string& projeto = "")
        : Funcionario(numContribuinte, nome), salarioBase(salarioBase), bonusAnual(bonusAnual), projeto(projeto) {}

    void definirProjeto(const string& novoProjeto) {
        projeto = novoProjeto;
    }

    double calcularSalario() const override {
        return salarioBase + bonusAnual;
    }

    void exibirInformacoes() const override {
        Funcionario::exibirInformacoes();
        cout << "Cargo: Interno" << endl;
        cout << "Salario Base: " << salarioBase << "\nBonus Anual: " << bonusAnual << endl;
        if (!projeto.empty()) {
            cout << "Projeto: " << projeto << endl;
        }
    }
};

// Classe para freelancers
class Freelancer : public Funcionario {
private:
    int horasTrabalhadas;
    double valorPorHora;
    bool trabalhoPorTurnos;

public:
    Freelancer(int numContribuinte, const string& nome, int horasTrabalhadas, double valorPorHora, bool trabalhoPorTurnos)
        : Funcionario(numContribuinte, nome), horasTrabalhadas(horasTrabalhadas), valorPorHora(valorPorHora), trabalhoPorTurnos(trabalhoPorTurnos) {}

    double calcularSalario() const override {
        return horasTrabalhadas * valorPorHora;
    }

    void exibirInformacoes() const override {
        Funcionario::exibirInformacoes();
        cout << "Cargo: Freelancer" << endl;
        cout << "Horas Trabalhadas: " << horasTrabalhadas << "\nValor por Hora: " << valorPorHora << endl;
        cout << "Trabalho por Turnos: " << (trabalhoPorTurnos ? "Sim" : "Nao") << endl;
    }
};

int main() {
    header();
    mudaLinha();
    // Cria uma instância de Interno
    Interno funcionarioInterno(123456789, "Miculina", 2000.0, 666.0, "Projeto Lucifer");
    funcionarioInterno.exibirInformacoes();
    funcionarioInterno.almoçar();
    cout << "Salario Final: " << funcionarioInterno.calcularSalario() << endl;

    mudaLinha();
    separador();
    mudaLinha();
    mudaLinha();

    // Cria uma instância de Freelancer
    Freelancer funcionarioFreelancer(987654321, "Anacleto", 120, 15.0, true);
    funcionarioFreelancer.exibirInformacoes();
    funcionarioFreelancer.almoçar();
    cout << "Salario Final: " << funcionarioFreelancer.calcularSalario();

    mudaLinha();
    footer();

    return 0;
}
