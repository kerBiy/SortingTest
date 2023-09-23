#include "../include/headers/Input.hpp"

Input *Input::sInstance = NULL;

Input *Input::Instance()
{
    if (sInstance == NULL)
        sInstance = new Input();

    return sInstance;
}

void Input::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Input::Input()
{
    keyboard_state = SDL_GetKeyboardState(&key_length);
    prev_keyboard_state = new Uint8[key_length];
    Update();
}

Input::~Input()
{
    delete[] prev_keyboard_state;
    prev_keyboard_state = NULL;
}

bool Input::KeyDown(SDL_Scancode scan_code)
{
    return (keyboard_state[scan_code] != 0);
}

bool Input::KeyPressed(SDL_Scancode scan_code)
{
    return (prev_keyboard_state[scan_code]) == 0 && (keyboard_state[scan_code] != 0);
}

bool Input::KeyReleased(SDL_Scancode scan_code)
{
    return (prev_keyboard_state[scan_code] != 0) && (keyboard_state[scan_code] == 0);
}

void Input::Update()
{
    memcpy(prev_keyboard_state, keyboard_state, key_length);
}
