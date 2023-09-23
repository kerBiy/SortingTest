#ifndef INPUT_HPP
#define INPUT_HPP

#include "../SDL2/SDL.h"
#include <cstring>

class Input
{
private:
    static Input *sInstance;

    const Uint8 *keyboard_state;
    Uint8 *prev_keyboard_state;
    int key_length;

public:
    static Input *Instance();
    static void Release();

    bool KeyDown(SDL_Scancode scan_code);
    bool KeyPressed(SDL_Scancode scan_code);
    bool KeyReleased(SDL_Scancode scan_code);

    void Update();

private:
    Input();
    ~Input();
};
#endif