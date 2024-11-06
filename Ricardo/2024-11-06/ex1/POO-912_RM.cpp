#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DVD {
protected:
   float preco;
   string titulo;
public:
   DVD(float p = 0.0, string t = "") : preco(p), titulo(t) {}
   virtual void adquirir() = 0;   // Método virtual para tornar a classe abstrata
   virtual void devolver() = 0;
   virtual void imprimir() const {
      cout << "Título: " << titulo << ", Preço: " << preco << endl;
   }
   string getTitulo() const { return titulo; }
};

class DVDdeVender : public DVD {
public:
   DVDdeVender(float preco, string titulo) : DVD(preco, titulo) {}
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
};

class DVDdeAlugar : public DVD {
private:
   string dataDevolucao;
public:
   DVDdeAlugar(float preco, string titulo, string dataDev) : DVD(preco, titulo), dataDevolucao(dataDev) {}
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
};

class ColecaoDeDVDs {
private:
   DVD* dvds[100];
   int numeroDVDs = 0;
public:
   void acrescentarDVD(DVD* d) {
      dvds[numeroDVDs] = d;
      numeroDVDs++;
   }

   void relatorio() {
      cout << "Relatório de DVDs:\n";
      for (int i = 0; i < numeroDVDs; i++) {
         dvds[i]->imprimir();
      }
   }

   void guardarRelatorioEmFicheiro() {
      ofstream ficheiro("relatorioDVDs.txt");
      for (int i = 0; i < numeroDVDs; i++) {
         ficheiro << "Título: " << dvds[i]->getTitulo() << "\n";
         // Guardar mais detalhes conforme necessário
      }
      ficheiro.close();
      cout << "Relatório guardado em relatorioDVDs.txt" << endl;
   }

   DVD* consultarDVD(string titulo) {
      for (int i = 0; i < numeroDVDs; i++) {
         if (dvds[i]->getTitulo() == titulo) {
            return dvds[i];
         }
      }
      return nullptr;
   }
};

int main() {
   ColecaoDeDVDs colecao;

   colecao.acrescentarDVD(new DVDdeAlugar(4.99, "Inception", "2024-11-15"));
   colecao.acrescentarDVD(new DVDdeVender(9.99, "Avatar"));

   colecao.relatorio();

   DVD* dvdConsultado = colecao.consultarDVD("Inception");
   if (dvdConsultado) {
      dvdConsultado->imprimir();
   } else {
      cout << "DVD não encontrado." << endl;
   }

   colecao.guardarRelatorioEmFicheiro();

   return 0;
}
