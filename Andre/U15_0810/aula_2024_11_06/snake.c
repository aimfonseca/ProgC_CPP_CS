#include "C:\raylib\raylib\src\raylib.h"
#include <stdlib.h>

// Definindo constantes para o jogo
#define SQUARE_SIZE 20      // Tamanho dos quadrados (corpo da cobra e comida)
#define SCREEN_WIDTH 800    // Largura da tela
#define SCREEN_HEIGHT 600   // Altura da tela
#define MAX_SNAKE_LENGTH 100 // Tamanho máximo da cobra

// Estrutura para a posi��o
typedef struct {
    int x;
    int y;
} Position;

// Estrutura para a cobra
typedef struct {
    Position body[MAX_SNAKE_LENGTH]; // Corpo da cobra
    int length;                      // Comprimento da cobra
    int speed;                       // Velocidade da cobra
    Position direction;              // Direção da cobra
} Snake;

// Função para reiniciar o jogo
void ResetGame(Snake *snake, Position *food) {
    snake->length = 1;
    snake->speed = 10;
    snake->direction = (Position){1, 0};
    snake->body[0] = (Position){SCREEN_WIDTH / (2 * SQUARE_SIZE), SCREEN_HEIGHT / (2 * SQUARE_SIZE)};
    *food = (Position){rand() % (SCREEN_WIDTH / SQUARE_SIZE), rand() % (SCREEN_HEIGHT / SQUARE_SIZE)};
}

int main(void) {
    // Inicializando a janela
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game em C com Raylib");
    SetTargetFPS(10); // Definindo FPS (10 é um bom valor para o jogo Snake)

    // Inicializando cobra e comida
    Snake snake;
    Position food;
    ResetGame(&snake, &food);

    bool gameOver = false;

    while (!WindowShouldClose()) {
        if (!gameOver) {
            // Controle da direção com teclas
            if (IsKeyPressed(KEY_RIGHT) && snake.direction.x == 0) snake.direction = (Position){1, 0};
            if (IsKeyPressed(KEY_LEFT) && snake.direction.x == 0) snake.direction = (Position){-1, 0};
            if (IsKeyPressed(KEY_UP) && snake.direction.y == 0) snake.direction = (Position){0, -1};
            if (IsKeyPressed(KEY_DOWN) && snake.direction.y == 0) snake.direction = (Position){0, 1};

            // Movendo a cobra
            for (int i = snake.length - 1; i > 0; i--) {
                snake.body[i] = snake.body[i - 1];
            }
            snake.body[0].x += snake.direction.x;
            snake.body[0].y += snake.direction.y;

            // Verificando se a cobra comeu a comida
            if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
                if (snake.length < MAX_SNAKE_LENGTH) snake.length++;
                food = (Position){rand() % (SCREEN_WIDTH / SQUARE_SIZE), rand() % (SCREEN_HEIGHT / SQUARE_SIZE)};
            }

            // Verificando colisões com a parede
            if (snake.body[0].x < 0 || snake.body[0].x >= SCREEN_WIDTH / SQUARE_SIZE ||
                snake.body[0].y < 0 || snake.body[0].y >= SCREEN_HEIGHT / SQUARE_SIZE) {
                gameOver = true;
            }

            // Verificando colisões com o próprio corpo
            for (int i = 1; i < snake.length; i++) {
                if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                    gameOver = true;
                    break;
                }
            }
        } else {
            if (IsKeyPressed(KEY_ENTER)) {
                ResetGame(&snake, &food);
                gameOver = false;
            }
        }

        // Renderização
        BeginDrawing();
        ClearBackground(BLACK);

        if (!gameOver) {
            // Desenhando a comida
            DrawRectangle(food.x * SQUARE_SIZE, food.y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, RED);

            // Desenhando a cobra
            for (int i = 0; i < snake.length; i++) {
                DrawRectangle(snake.body[i].x * SQUARE_SIZE, snake.body[i].y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, GREEN);
            }
        } else {
            DrawText("Game Over! Pressione ENTER para reiniciar", SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT / 2, 20, RAYWHITE);
        }

        EndDrawing();
    }

    // Fechando a janela e limpando a memória
    CloseWindow();
    return 0;
}
