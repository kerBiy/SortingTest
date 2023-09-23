#include "../include/headers/Graphics.hpp"

Graphics *Graphics::sInstance = NULL;

bool Graphics::sInitialized = false;

Graphics *Graphics::Instance()
{
    if (sInstance == NULL)
        sInstance = new Graphics();

    return sInstance;
}

void Graphics::Release()
{
    delete sInstance;
    sInstance = NULL;

    sInitialized = false;
}

bool Graphics::Initialized()
{
    return sInitialized;
}

Graphics::Graphics()
{
    sInitialized = Init();
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_Quit();
}

bool Graphics::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Initialization error : " << SDL_GetError() << '\n';
        return false;
    }

    window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Window error : " << SDL_GetError() << '\n';
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        std::cout << "Renderer error : " << SDL_GetError() << '\n';
        return false;
    }

    SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, SDL_ALPHA_OPAQUE);

    return true;
}

void Graphics::DrawRect(const SDL_Rect rect, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &rect);
}

void Graphics::Draw(const int *arr, int x, int y, int z)
{
    ClearBackBuffer();
    for (int i = 0, j = 0; i <= Graphics::SCREEN_WIDTH - RECT_SIZE; i += RECT_SIZE, ++j)
    {
        SDL_PumpEvents();
        SDL_Rect rect = {i, Graphics::SCREEN_HEIGHT - arr[j], RECT_SIZE, arr[j]};

        if (complete)
            DrawRect(rect, GREEN);

        else if (j == x || j == z)
            DrawRect(rect, GREEN);

        else if (j == y)
            DrawRect(rect, MAGENTA);

        else
            DrawRect(rect, GREY);
    }
    Render();
}

bool Graphics::Complete()
{
    return complete;
}

void Graphics::Complete(bool complete)
{
    this->complete = complete;
}

void Graphics::ClearBackBuffer() const
{
    SDL_RenderClear(renderer);
}

void Graphics::Render() const
{
    SDL_RenderPresent(renderer);
}
