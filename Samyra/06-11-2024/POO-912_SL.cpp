// Falta algum código
// Falta implementar métodos
// Tem erros de sintaxe e de lógica

#include<iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);


// Classe base abstrata representando um DVD genérico
class DVD {
protected:
   float preco;
   string titulo;

public:
   // Construtor com valores padrão para preço e título
   DVD(float preco = 0.0, string titulo = "") : preco(preco), titulo(titulo) {}

   // Métodos virtuais puros (abstratos) que precisam ser implementados pelas subclasses
   virtual void adquirir() = 0; 
   virtual void devolver() = 0;
   virtual void recibo() const = 0;

   // Método para obter o título do DVD
   string getTitulo() const { return titulo; }
};

// Classe DVDdeVender, representando um DVD para venda
class DVDdeVender : public DVD {
public:
   // Construtor que inicializa preço e título do DVD de venda
   DVDdeVender(float preco, string titulo) : DVD(preco, titulo) {}

   // Implementação do método adquirir para venda
   void adquirir() override {
      cout << "DVD '" << titulo << "' adquirido para venda por " << preco << " euros.\n";
   }

   // Implementação do método devolver para venda (não permite devolução)
   void devolver() override {
      cout << "DVD '" << titulo << "' vendido não pode ser devolvido.\n";
   }

   // Método para imprimir detalhes do DVD de venda
   void recibo() const override {
      cout << "DVD de Venda: " << titulo << ", Preco: " << preco << endl;
   }
};

// Classe DVDdeAlugar, representando um DVD para aluguel
class DVDdeAlugar : public DVD {
private:
   string dataDevolucao;                    // Data de devolução do DVD

public:
   // Construtor que inicializa preço, título e data de devolução do DVD de aluguel
   DVDdeAlugar(float preco, string titulo, string dataDevolucao = "") : DVD(preco, titulo), dataDevolucao(dataDevolucao) {}

   // Implementação do método adquirir para aluguel
   void adquirir() override {
      cout << "DVD '" << titulo << "' alugado por " << preco << " euros.\n";
   }

   // Implementação do método devolver para aluguel, indicando a data de devolução
   void devolver() override {
      cout << "DVD '" << titulo << "' devolvido em " << dataDevolucao << ".\n";
   }

   // Método para imprimir detalhes do DVD de aluguel
   void recibo() const override {
      cout << "DVD de Aluguel: " << titulo << ", Preco: " << preco << ", Data de Devolução: " << dataDevolucao << endl;
   }
};

// Classe ColecaoDeDVDs para gerenciar uma coleção de DVDs
class ColecaoDeDVDs {
private:
   vector<DVD*> dvds;                        // Vetor para armazenar ponteiros para DVDs
   
public:
   // Método para adicionar um DVD à coleção
   void acrescentarDVD(DVD* d) {
      dvds.push_back(d);                     // Adiciona o DVD ao vetor
      cout << "DVD '" << d->getTitulo() << "' adicionado à coleção.\n";
   }

   // Método para exibir o relatório de todos os DVDs na coleção
   void relatorio() const {
      cout << "Relatório de DVDs:\n";
      for (const auto& dvd : dvds) {     // Itera sobre cada DVD no vetor
         dvd->recibo();                  // Chama o método recibo de cada DVD
      }
   }

   // Método para salvar o relatório em um arquivo de texto
   void salvarEmArquivo() const {
      ofstream arquivo("relatorio_dvds.txt");     // Abre um arquivo de saída
      if (arquivo.is_open()) {                    // Verifica se o arquivo foi aberto com sucesso
         for (const auto& dvd : dvds) {           // Itera sobre cada DVD
            arquivo << dvd->getTitulo() << "\n";  // Escreve o título do DVD no arquivo
         }
         arquivo.close();                         // Fecha o arquivo
         cout << "Relatório salvo em 'relatorio_dvds.txt'.\n";

      } else {
         cout << "Erro ao abrir o arquivo para salvar o relatório.\n";
      }
   }

   // Método para consultar um DVD pelo título
   DVD* consultar(string titulo) const {
      for (const auto& dvd : dvds) {           // Itera sobre cada DVD na coleção
         if (dvd->getTitulo() == titulo) {     // Verifica se o título corresponde
            return dvd;                        // Retorna o ponteiro para o DVD encontrado
         }
      }
      return nullptr;                          // Retorna nullptr se não encontrar
   }
};

// Função principal
int main() {

   meuCarimbo();
	mudaLinha();

   ColecaoDeDVDs c;  // Cria uma instância da coleção de DVDs
   
   // Adiciona DVDs de aluguel e venda na coleção
   c.acrescentarDVD(new DVDdeAlugar(2.99, "Filme A", "10/11/2024"));
   c.acrescentarDVD(new DVDdeVender(10.99, "Filme B"));
   
   c.relatorio();  // Exibe o relatório de todos os DVDs na coleção
   
   // Realiza uma busca pelo título de um DVD
   string tituloBusca;
   cout << "\nDigite o título do DVD para consultar: ";
   getline(cin, tituloBusca);  // Lê o título do DVD para busca

   // Consulta o DVD na coleção e exibe seus detalhes se encontrado
   DVD* dvdEncontrado = c.consultar(tituloBusca);
   if (dvdEncontrado) {
      dvdEncontrado->recibo();
   } else {
      cout << "DVD '" << tituloBusca << "' não encontrado na coleção.\n";
   }
   
   c.salvarEmArquivo();  // Salva o relatório de DVDs em um arquivo de texto
   
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
