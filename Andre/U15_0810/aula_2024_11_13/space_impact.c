#include "raylib.h"
#include <stdlib.h>

#define MAX_PROJECTILES 10
#define ENEMY_GROUP_SIZE 5

typedef struct {
    Vector2 position;
    int speed;
    bool active;
} Enemy;

typedef struct {
    Vector2 position;
    int speed;
    bool active;
} Projectile;

typedef struct {
    Vector2 position;
    int speed;
    int health;
} Player;

Enemy enemies[ENEMY_GROUP_SIZE];
Projectile playerProjectiles[MAX_PROJECTILES];
Projectile enemyProjectiles[MAX_PROJECTILES];
Player player;

int screenWidth = 800;
int screenHeight = 600;
int score = 0;
bool gameOver = false;

void InitPlayer();
void InitEnemies();
void InitPlayerProjectiles();
void InitEnemyProjectiles();
void ShootPlayerProjectile();
void UpdateEnemies();
void UpdatePlayerProjectiles();
void UpdateEnemyProjectiles();
void CheckCollisions();
void ResetGame();

// Fun‡„o para inicializar o jogador
void InitPlayer() {
    player.position = (Vector2){ 50, screenHeight / 2 };
    player.speed = 5;
    player.health = 20;
}

// Fun‡„o para inicializar os inimigos
void InitEnemies() {
    for (int i = 0; i < ENEMY_GROUP_SIZE; i++) {
        enemies[i].position = (Vector2){ screenWidth + rand() % 100, rand() % (screenHeight - 40) };
        enemies[i].speed = 3;
        enemies[i].active = true;
    }
}

// Fun‡„o para inicializar os proj‚teis do jogador
void InitPlayerProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        playerProjectiles[i].active = false;
    }
}

// Fun‡„o para inicializar os proj‚teis inimigos
void InitEnemyProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        enemyProjectiles[i].active = false;
    }
}

// Fun‡„o para reiniciar o jogo
void ResetGame() {
    InitPlayer();
    InitEnemies();
    InitPlayerProjectiles();
    InitEnemyProjectiles();
    score = 0;
    gameOver = false;
}

// Fun‡„o para disparar um proj‚til do jogador
void ShootPlayerProjectile() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (!playerProjectiles[i].active) {
            playerProjectiles[i].position = (Vector2){ player.position.x + 20, player.position.y };
            playerProjectiles[i].speed = 7;
            playerProjectiles[i].active = true;
            break;
        }
    }
}

// Fun‡„o para disparar um proj‚til inimigo
void ShootEnemyProjectile(Enemy *enemy) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (!enemyProjectiles[i].active) {
            enemyProjectiles[i].position = (Vector2){ enemy->position.x - 10, enemy->position.y };
            enemyProjectiles[i].speed = 5;
            enemyProjectiles[i].active = true;
            break;
        }
    }
}

// Fun‡„o para atualizar os inimigos
void UpdateEnemies() {
    for (int i = 0; i < ENEMY_GROUP_SIZE; i++) {
        if (enemies[i].active) {
            enemies[i].position.x -= enemies[i].speed;

            // Se o inimigo sai da tela pela esquerda, reposiciona … direita
            if (enemies[i].position.x < -20) {
                enemies[i].position = (Vector2){ screenWidth + rand() % 100, rand() % (screenHeight - 40) };
                score++;
            }

            // Pequena chance de disparar proj‚til
            if (rand() % 100 < 2) {
                ShootEnemyProjectile(&enemies[i]);
            }
        } else {
            // Reposiciona inimigos inativos (ex. ap¢s colis„o)
            enemies[i].position = (Vector2){ screenWidth + rand() % 100, rand() % (screenHeight - 40) };
            enemies[i].active = true;
        }
    }
}

// Fun‡„o para atualizar os proj‚teis do jogador
void UpdatePlayerProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (playerProjectiles[i].active) {
            playerProjectiles[i].position.x += playerProjectiles[i].speed;

            if (playerProjectiles[i].position.x > screenWidth) {
                playerProjectiles[i].active = false;
            }
        }
    }
}

// Fun‡„o para atualizar os proj‚teis inimigos
void UpdateEnemyProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (enemyProjectiles[i].active) {
            enemyProjectiles[i].position.x -= enemyProjectiles[i].speed;

            if (enemyProjectiles[i].position.x < 0) {
                enemyProjectiles[i].active = false;
            }
        }
    }
}

// Fun‡„o para verificar colis”es
void CheckCollisions() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (playerProjectiles[i].active) {
            for (int j = 0; j < ENEMY_GROUP_SIZE; j++) {
                if (enemies[j].active &&
                    CheckCollisionCircles(playerProjectiles[i].position, 5, enemies[j].position, 20)) {
                    playerProjectiles[i].active = false;
                    enemies[j].active = false;
                    score++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (enemyProjectiles[i].active) {
            if (CheckCollisionCircles(enemyProjectiles[i].position, 5, player.position, 20)) {
                enemyProjectiles[i].active = false;
                player.health -= 2;
                if (player.health <= 0) {
                    player.health = 0;
                    gameOver = true;
                }
            }
        }
    }
}

// Fun‡„o para aumentar a dificuldade do jogo
void IncreaseDifficulty() {
    // Aumenta a velocidade dos inimigos e proj‚teis a cada 20 pontos
    int difficultyLevel = score / 20;  // Cada 20 pontos, aumenta o n¡vel de dificuldade

    // Aumenta a velocidade dos inimigos
    for (int i = 0; i < ENEMY_GROUP_SIZE; i++) {
        enemies[i].speed = 3 + difficultyLevel;  // Aumenta a velocidade dos inimigos
    }

    // Aumenta a velocidade dos proj‚teis inimigos
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        enemyProjectiles[i].speed = 5 + difficultyLevel;  // Aumenta a velocidade dos proj‚teis
    }

    // Aumenta a velocidade dos proj‚teis do jogador
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        playerProjectiles[i].speed = 7 + difficultyLevel;  // Aumenta a velocidade dos proj‚teis do jogador
    }
}

int main(void) {
    InitWindow(screenWidth, screenHeight, "Space Impact");
    ResetGame();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (!gameOver) {
            if (IsKeyDown(KEY_UP) && player.position.y > 0) player.position.y -= player.speed;
            if (IsKeyDown(KEY_DOWN) && player.position.y < screenHeight) player.position.y += player.speed;
            if (IsKeyDown(KEY_RIGHT) && player.position.x < screenWidth - 20) player.position.x += player.speed;
            if (IsKeyDown(KEY_LEFT) && player.position.x > 0) player.position.x -= player.speed;

            if (IsKeyPressed(KEY_SPACE)) ShootPlayerProjectile();

            UpdateEnemies();
            UpdatePlayerProjectiles();
            UpdateEnemyProjectiles();
            CheckCollisions();
            IncreaseDifficulty();

            if (score >= 100) {
                gameOver = true;
            }
        } else {
            if (IsKeyPressed(KEY_ENTER)) {
                ResetGame();
            }
            if (IsKeyPressed(KEY_ESCAPE)) {
                break;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        
        int textWidth;
        
        if (gameOver) {
            if (score >= 100){
                
                textWidth = MeasureText("GANHASTE!", 40);
                DrawText("GANHASTE!", (screenWidth - textWidth) / 2, screenHeight / 2, 40, GREEN);
                
            } else {
                
                textWidth = MeasureText("GAME OVER", 40);
                DrawText("GAME OVER", (screenWidth - textWidth) / 2, screenHeight / 2, 40, RED);
            }
                  
            textWidth = MeasureText("Pressione ENTER para jogar de novo", 20);
            DrawText("Pressione ENTER para jogar de novo", (screenWidth - textWidth) / 2, screenHeight / 2 + 60, 20, WHITE);

            textWidth = MeasureText("Pressione ESC para sair do jogo", 20);
            DrawText("Pressione ESC para sair do jogo", (screenWidth - textWidth) / 2, screenHeight / 2 + 100, 20, WHITE);
       
        } else {
            DrawCircleV(player.position, 20, BLUE);

            for (int i = 0; i < ENEMY_GROUP_SIZE; i++) {
                if (enemies[i].active) {
                    DrawCircleV(enemies[i].position, 20, RED);
                }
            }

            for (int i = 0; i < MAX_PROJECTILES; i++) {
                if (playerProjectiles[i].active) {
                    DrawCircleV(playerProjectiles[i].position, 5, WHITE);
                }
            }

            for (int i = 0; i < MAX_PROJECTILES; i++) {
                if (enemyProjectiles[i].active) {
                    DrawCircleV(enemyProjectiles[i].position, 5, YELLOW);
                }
            }

            DrawText(TextFormat("Pontos: %d", score), 10, 10, 20, WHITE);
            DrawText(TextFormat("Vida: %d", player.health), 10, 40, 20, RED);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
