#pragma once

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game
{
public:
    // Игровое состояние
    GameState State;
    bool Keys[1024];
    unsigned int Width, Height;

    // Конструктор
    Game(unsigned int width, unsigned int height);

    // Деструктор
    ~Game();

    // Инициализация начального состояния игры (загрузка всех шейдеров, текстур, уровней)
    void Init();

    // Игровой цикл
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void StartGameLoop();
};