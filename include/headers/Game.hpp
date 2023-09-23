#ifndef GAME_HPP
#define GAME_HPP

#include <random>
#include <ctime>

#include "Algorithm.hpp"
#include "Input.hpp"

class Game
{
private:
    static Game *sInstance;
    static const int SIZE = 128;

    bool is_running;
    int arr[SIZE];
    int random_arr[SIZE];

    SDL_Event events;
    Graphics *graphics;
    Input *input;
    Algorithm *algorithm;

public:
    static Game *Instance();
    static void Release();

    void Run();

private:
    Game();
    ~Game();

    void LoadArray();
    void RandomizeArray();

    void Intro();
    void Update();
    void Render();
};

#endif