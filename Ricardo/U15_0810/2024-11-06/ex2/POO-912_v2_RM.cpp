#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class DVD {
protected:
    float preco;
    string titulo;
    string opiniao;
public:
    DVD(float p = 0.0, string t = "", string op = "") : preco(p), titulo(t), opiniao(op) {}
    virtual void adquirir() = 0;
    virtual void devolver() = 0;
    virtual void imprimir() const {
        cout << "Título: " << titulo << ", Preço: " << preco << ", Opinião: " << opiniao << endl;
    }
    string getTitulo() const { return titulo; }
    virtual string getInfoParaGuardar() const = 0;
};

class DVDdeVender : public DVD {
public:
    DVDdeVender(float preco, string titulo, string opiniao) : DVD(preco, titulo, opiniao) {}
    void adquirir() override {
        cout << "DVD comprado: " << titulo << endl;
    }
    void devolver() override {
        cout << "DVD de venda não pode ser devolvido." << endl;
    }
    void imprimir() const override {
        DVD::imprimir();
        cout << "Tipo: Venda" << endl;
    }
    string getInfoParaGuardar() const override {
        return "V," + titulo + "," + to_string(preco) + "," + opiniao + "\n";
    }
};

class DVDdeAlugar : public DVD {
private:
    string dataDevolucao;
public:
    DVDdeAlugar(float preco, string titulo, string dataDev, string opiniao) : DVD(preco, titulo, opiniao), dataDevolucao(dataDev) {}
    void adquirir() override {
        cout << "DVD alugado: " << titulo << endl;
    }
    void devolver() override {
        cout << "Devolução do DVD: " << titulo << " prevista para " << dataDevolucao << endl;
    }
    void imprimir() const override {
        DVD::imprimir();
        cout << "Tipo: Aluguer, Data de devolução: " << dataDevolucao << endl;
    }
    string getInfoParaGuardar() const override {
        return "A," + titulo + "," + to_string(preco) + "," + dataDevolucao + "," + opiniao + "\n";
    }
};

class ColecaoDeDVDs {
private:
    vector<DVD*> dvds;
public:
    ~ColecaoDeDVDs() {
        for (auto dvd : dvds) delete dvd;
    }

    void acrescentarDVD(DVD* d) {
        dvds.push_back(d);
    }

    void relatorio() const {
        cout << "Relatório de DVDs:\n";
        for (const auto& dvd : dvds) {
            dvd->imprimir();
        }
    }

    DVD* consultarDVD(string titulo) const {
        for (const auto& dvd : dvds) {
            if (dvd->getTitulo() == titulo) {
                return dvd;
            }
        }
        return nullptr;
    }

    void guardarEmFicheiro() const {
        ofstream ficheiro("colecaoDVDs.txt");
        for (const auto& dvd : dvds) {
            ficheiro << dvd->getInfoParaGuardar();
        }
        ficheiro.close();
    }

    void carregarDeFicheiro() {
        ifstream ficheiro("colecaoDVDs.txt");
        if (!ficheiro.is_open()) return;

        string tipo, titulo, opiniao, dataDev;
        float preco;

        while (getline(ficheiro, tipo, ',')) {
            getline(ficheiro, titulo, ',');
            ficheiro >> preco;
            ficheiro.ignore(); // Ignorar a vírgula
            getline(ficheiro, opiniao, ',');

            if (tipo == "A") {
                getline(ficheiro, dataDev);
                acrescentarDVD(new DVDdeAlugar(preco, titulo, dataDev, opiniao));
            } else if (tipo == "V") {
                acrescentarDVD(new DVDdeVender(preco, titulo, opiniao));
            }
        }
        ficheiro.close();
    }
};

// Funções para interatividade
void mostrarMenu() {
    cout << "\n--- Menu de Opções ---\n";
    cout << "1. Adicionar DVD\n";
    cout << "2. Consultar DVD\n";
    cout << "3. Listar todos os DVDs\n";
    cout << "4. Guardar e Sair\n";
    cout << "Escolha uma opção: ";
}

void adicionarDVD(ColecaoDeDVDs& colecao) {
    int tipo;
    string titulo, opiniao, dataDev;
    float preco;

    cout << "Tipo de DVD (1 para venda, 2 para aluguer): ";
    cin >> tipo;
    cout << "Título: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Preço: ";
    cin >> preco;
    cin.ignore();
    cout << "Opinião: ";
    getline(cin, opiniao);

    if (tipo == 1) {
        colecao.acrescentarDVD(new DVDdeVender(preco, titulo, opiniao));
    } else if (tipo == 2) {
        cout << "Data de devolução: ";
        getline(cin, dataDev);
        colecao.acrescentarDVD(new DVDdeAlugar(preco, titulo, dataDev, opiniao));
    }
}

void consultarDVD(const ColecaoDeDVDs& colecao) {
    string titulo;
    cout << "Título do DVD a consultar: ";
    cin.ignore();
    getline(cin, titulo);

    DVD* dvd = colecao.consultarDVD(titulo);
    if (dvd) {
        dvd->imprimir();
    } else {
        cout << "DVD não encontrado.\n";
    }
}

int main() {
    ColecaoDeDVDs colecao;
    colecao.carregarDeFicheiro();

    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;
        switch (opcao) {
            case 1:
                adicionarDVD(colecao);
                break;
            case 2:
                consultarDVD(colecao);
                break;
            case 3:
                colecao.relatorio();
                break;
            case 4:
                colecao.guardarEmFicheiro();
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opção inválida.\n";
                break;
        }
    } while (opcao != 4);

    return 0;
}
