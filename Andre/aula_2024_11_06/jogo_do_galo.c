#include "raylib.h"
#include <stdbool.h>

// Define o tamanho da grade e outros parâmetros
#define GRID_SIZE 3
#define CELL_SIZE 100
#define SCREEN_WIDTH (GRID_SIZE * CELL_SIZE)
#define SCREEN_HEIGHT (GRID_SIZE * CELL_SIZE)

typedef enum { EMPTY, PLAYER_X, PLAYER_O } Player;
typedef struct { Player grid[GRID_SIZE][GRID_SIZE]; Player currentPlayer; bool gameOver; } Game;

void DrawBoard(Game* game);
bool CheckWin(Game* game, Player player);
bool CheckDraw(Game* game);
void ResetGame(Game* game);

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT + 50, "Jogo do Galo com Raylib");
    SetTargetFPS(60);

    Game game = { .currentPlayer = PLAYER_X, .gameOver = false };
    ResetGame(&game);

    while (!WindowShouldClose())
    {
        // Detecta clique do jogador
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !game.gameOver) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int col = mousePosition.x / CELL_SIZE;

            if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE && game.grid[row][col] == EMPTY) {
                game.grid[row][col] = game.currentPlayer;

                // Verifica vitória ou empate
                if (CheckWin(&game, game.currentPlayer)) {
                    game.gameOver = true;
                } else if (CheckDraw(&game)) {
                    game.gameOver = true;
                    game.currentPlayer = EMPTY; // Empate
                } else {
                    // Alterna o jogador
                    game.currentPlayer = (game.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
                }
            }
        }

        // Reinicia o jogo
        if (IsKeyPressed(KEY_R)) {
            ResetGame(&game);
        }

        // Desenha a tela
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawBoard(&game);

            if (game.gameOver) {
                const char* message = (game.currentPlayer == EMPTY) ? "Empate!" : (game.currentPlayer == PLAYER_X ? "X Venceu!" : "O Venceu!");
                DrawText(message, 10, SCREEN_HEIGHT + 10, 16, DARKGRAY);
                DrawText("\n\nPressione 'R' para reiniciar.", 10, SCREEN_HEIGHT, 16, DARKGRAY);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Função para desenhar o tabuleiro e as células
void DrawBoard(Game* game) {
    for (int i = 1; i < GRID_SIZE; i++) {
        DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, SCREEN_HEIGHT, BLACK);
        DrawLine(0, i * CELL_SIZE, SCREEN_WIDTH, i * CELL_SIZE, BLACK);
    }

    // Desenha "X" e "O" nas células
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            Vector2 center = { col * CELL_SIZE + CELL_SIZE / 2.0f, row * CELL_SIZE + CELL_SIZE / 2.0f };

            if (game->grid[row][col] == PLAYER_X) {
                DrawText("X", center.x - 20, center.y - 20, 40, RED);
            } else if (game->grid[row][col] == PLAYER_O) {
                DrawText("O", center.x - 20, center.y - 20, 40, BLUE);
            }
        }
    }
}

// Função para verificar vitória
bool CheckWin(Game* game, Player player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if ((game->grid[i][0] == player && game->grid[i][1] == player && game->grid[i][2] == player) ||
            (game->grid[0][i] == player && game->grid[1][i] == player && game->grid[2][i] == player)) {
            return true;
        }
    }
    return (game->grid[0][0] == player && game->grid[1][1] == player && game->grid[2][2] == player) ||
           (game->grid[0][2] == player && game->grid[1][1] == player && game->grid[2][0] == player);
}

// Função para verificar empate
bool CheckDraw(Game* game) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (game->grid[row][col] == EMPTY) return false;
        }
    }
    return true;
}

// Função para reiniciar o jogo
void ResetGame(Game* game) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            game->grid[row][col] = EMPTY;
        }
    }
    game->currentPlayer = PLAYER_X;
    game->gameOver = false;
}
