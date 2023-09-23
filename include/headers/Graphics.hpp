#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include "Colors.hpp"

class Graphics
{
public:
    static const int SCREEN_WIDTH = 1024;
    static const int SCREEN_HEIGHT = 720;
    const char *WINDOW_NAME = "Sorting Visualizer";

private:
    static Graphics *sInstance;
    static bool sInitialized;

    SDL_Renderer *renderer;
    SDL_Window *window;

    const int RECT_SIZE = 8;
    bool complete = false;

public:
    static Graphics *Instance();
    static void Release();
    static bool Initialized();

    void DrawRect(const SDL_Rect rect, SDL_Color color);
    void Draw(const int *arr, int x = -1, int y = -1, int z = -1);

    bool Complete();
    void Complete(bool complete);

    void ClearBackBuffer() const;
    void Render() const;

private:
    Graphics();
    ~Graphics();
    bool Init();
};

#endif