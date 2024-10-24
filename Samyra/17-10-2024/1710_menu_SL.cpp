#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void mudaLinha(void); 
void meuCarimbo(void);

void carregar_conteudo(const std::string& filename, std::vector<std::string>& conteudos) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string linha, conteudo;
    while (std::getline(file, linha)) {
        if (linha.empty()) {
            conteudos.push_back(conteudo); // Adiciona o conteúdo ao vetor
            conteudo.clear();
        } else {
            conteudo += linha + "\n";
        }
    }
    if (!conteudo.empty()) {
        conteudos.push_back(conteudo); // Adiciona o último bloco de conteúdo
    }
    file.close();
}

void mostrar_menu(const std::vector<std::string>& conteudos) {
    while (true) {
        std::cout << "\nMenu de Opcoes:\n";
        for (size_t i = 0; i < conteudos.size(); ++i) {
            // Exibe apenas o título de cada exemplo (primeira linha de cada conteúdo)
            std::cout << i + 1 << ". " << conteudos[i].substr(0, conteudos[i].find('\n')) << std::endl;
        }
        std::cout << conteudos.size() + 1 << ". Sair" << std::endl;

        int escolha;
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;

        if (escolha >= 1 && escolha <= conteudos.size()) {
            std::cout << "\n" << conteudos[escolha - 1] << std::endl;  // Exibe o conteúdo completo
        } else if (escolha == conteudos.size() + 1) {
            std::cout << "Saindo..." << std::endl;
            break;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

int main() {

    meuCarimbo();

    std::vector<std::string> conteudos;
    std::string ficheiro = "materia.txt"; 

    carregar_conteudo(ficheiro, conteudos);
    if (!conteudos.empty()) {
        mostrar_menu(conteudos);
    } else {
        std::cerr << "Nenhum conteúdo foi carregado." << std::endl;
    }

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
