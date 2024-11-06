#include <raylib.h>  // Biblioteca gráfica raylib
#include <iostream>  // Biblioteca de entrada e saída padrão do C++

using namespace std;

// Define o tabuleiro inicial com números representando cada célula
char tabuleiro[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char jogador = 'X';  // Define o jogador inicial como 'X'

// Função para desenhar o tabuleiro na tela
void desenharTabuleiro() {
    int cellSize = 100;  // Define o tamanho de cada célula do tabuleiro
    for (int i = 0; i < 3; i++) {        // Percorre as linhas do tabuleiro
        for (int j = 0; j < 3; j++) {    // Percorre as colunas do tabuleiro
            int x = j * cellSize;        // Calcula a posição x para a célula
            int y = i * cellSize;        // Calcula a posição y para a célula
            DrawRectangleLines(x, y, cellSize, cellSize, BLACK);  // Desenha a borda da célula

            // Exibe 'X' ou 'O' na célula se já estiver marcada
            if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O') {
                DrawText(TextFormat("%c", tabuleiro[i][j]), x + 40, y + 30, 40, BLACK);
            }
        }
    }
}

// Verifica se o movimento é válido e atualiza o tabuleiro
bool validarMovimento(int linha, int coluna) {
    // Verifica se a célula está livre para ser marcada
    if (tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
        tabuleiro[linha][coluna] = jogador;  // Marca a célula com o símbolo do jogador atual
        return true;  // Movimento válido
    }
    return false;  // Movimento inválido
}

// Verifica se o jogador atual venceu
bool verificarVitoria() {
    // Verifica as linhas e colunas para três símbolos iguais consecutivos
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) return true;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) return true;
    }
    // Verifica as diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) return true;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) return true;
    return false;  // Nenhuma vitória encontrada
}

// Verifica se o jogo terminou em empate (todas as células preenchidas)
bool verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O') return false;  // Célula livre, sem empate
        }
    }
    return true;  // Todas as células preenchidas, é um empate
}

// Troca o jogador atual entre 'X' e 'O'
void trocarJogador() {
    jogador = (jogador == 'X') ? 'O' : 'X';
}

int main() {
    InitWindow(300, 300, "Jogo da Velha com raylib");  // Inicializa a janela com tamanho 300x300 pixels
    SetTargetFPS(60);  // Define a taxa de atualização para 60 FPS

    bool jogoAtivo = true;  // Controle para saber se o jogo está ativo
    bool venceu = false;    // Indica se algum jogador venceu

    // Loop principal do jogo
    while (!WindowShouldClose()) {  // Continua até que a janela seja fechada
        BeginDrawing();
        ClearBackground(RAYWHITE);  // Limpa a tela com a cor branca

        desenharTabuleiro();  // Desenha o tabuleiro na tela

        if (jogoAtivo) {
            // Verifica se o botão esquerdo do mouse foi pressionado
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                int mouseX = GetMouseX() / 100;  // Converte a posição X do mouse para a coluna no tabuleiro
                int mouseY = GetMouseY() / 100;  // Converte a posição Y do mouse para a linha no tabuleiro

                // Verifica se a posição clicada está dentro do tabuleiro
                if (mouseX < 3 && mouseY < 3) {
                    if (validarMovimento(mouseY, mouseX)) {  // Marca a célula se o movimento for válido
                        if (verificarVitoria()) {  // Verifica se o jogador atual venceu
                            venceu = true;
                            jogoAtivo = false;  // Finaliza o jogo
                        } else if (verificarEmpate()) {  // Verifica se houve empate
                            jogoAtivo = false;  // Finaliza o jogo em caso de empate
                        } else {
                            trocarJogador();  // Troca o jogador caso não haja vitória ou empate
                        }
                    }
                }
            }
        } else {
            // Exibe mensagem de vitória ou empate
            if (venceu) {
                DrawText(TextFormat("Jogador %c venceu!", jogador), 50, 130, 20, GREEN);
            } else {
                DrawText("Empate!", 120, 130, 20, RED);
            }
            DrawText("Pressione R para reiniciar", 50, 160, 20, DARKGRAY);

            // Reinicia o jogo se a tecla 'R' for pressionada
            if (IsKeyPressed(KEY_R)) {
                // Restaura o tabuleiro ao estado inicial
                char novoTabuleiro[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
                memcpy(tabuleiro, novoTabuleiro, sizeof(tabuleiro));
                jogoAtivo = true;
                venceu = false;
                jogador = 'X';  // Define 'X' como o jogador inicial novamente
            }
        }

        EndDrawing();  // Finaliza o frame atual
    }

    CloseWindow();  // Fecha a janela e finaliza o raylib
    return 0;
}
