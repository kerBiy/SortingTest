#include "../include/headers/Game.hpp"

Game *Game::sInstance = NULL;

Game *Game::Instance()
{
    if (sInstance == NULL)
        sInstance = new Game();

    return sInstance;
}

void Game::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Game::Game()
{
    srand(time(NULL));

    is_running = true;

    graphics = Graphics::Instance();

    if (!Graphics::Initialized())
        is_running = false;

    input = Input::Instance();

    algorithm = Algorithm::Instance();

    RandomizeArray();
    LoadArray();
}

Game::~Game()
{
    Graphics::Release();
    graphics = NULL;

    Input::Release();
    input = NULL;

    Algorithm::Release();
    algorithm = NULL;
}

void Game::Intro()
{
    std::cout << "Available Controls inside Sorting Visualizer:\n"
              << "    Use r to Generate a different randomized list.\n"
              << "    Use 1 to start Selection Sort Algorithm.\n"
              << "    Use 2 to start Insertion Sort Algorithm.\n"
              << "    Use 3 to start Bubble Sort Algorithm.\n"
              << "    Use 4 to start Quick Sort Algorithm.\n"
              << "    Use 5 to start Merge Sort Algorithm.\n"
              << "    Use 6 to start Heap Sort Algorithm.\n"
              << "    Use ESC to exit out of Sorting Visualizer\n\n";
}

void Game::LoadArray()
{
    memcpy(arr, random_arr, sizeof(int) * SIZE);
}

void Game::RandomizeArray()
{
    for (int i = 0; i < SIZE; ++i)
        random_arr[i] = rand() % Graphics::SCREEN_HEIGHT;
}

void Game::Update()
{
    if (input->KeyPressed(SDL_SCANCODE_ESCAPE))
    {
        is_running = false;
        std::cout << "\nEXITING SORTING VISUALIZER.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_R))
    {
        RandomizeArray();
        graphics->Complete(false);
        LoadArray();
        std::cout << "\nNEW RANDOM LIST GENERATED.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_1))
    {
        LoadArray();
        std::cout << "\nSELECTION SORT STARTED.\n";
        graphics->Complete(false);
        algorithm->SelectionSort(arr, SIZE);
        graphics->Complete(true);
        std::cout << "\nSELECTION SORT COMPLETE.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_2))
    {
        LoadArray();
        std::cout << "\nINSERTION SORT STARTED.\n";
        graphics->Complete(false);
        algorithm->InsertionSort(arr, SIZE);
        graphics->Complete(true);
        std::cout << "\nINSERTION SORT COMPLETE.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_3))
    {
        LoadArray();
        std::cout << "\nBUBBLE SORT STARTED.\n";
        graphics->Complete(false);
        algorithm->BubbleSort(arr, SIZE);
        graphics->Complete(true);
        std::cout << "\nBUBBLE SORT COMPLETE.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_4))
    {
        LoadArray();
        std::cout << "\nQUICK SORT STARTED.\n";
        graphics->Complete(false);
        algorithm->QuickSort(arr, 0, SIZE - 1);
        graphics->Complete(true);
        std::cout << "\nQUICK SORT COMPLETE.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_5))
    {
        LoadArray();
        std::cout << "\nMERGE SORT STARTED.\n";
        graphics->Complete(false);
        algorithm->MergeSort(arr, 0, SIZE - 1);
        graphics->Complete(true);
        std::cout << "\nMERGE SORT COMPLETE.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_6))
    {
        LoadArray();
        std::cout << "\nHEAP SORT STARTED.\n";
        graphics->Complete(false);
        algorithm->HeapSort(arr, SIZE);
        graphics->Complete(true);
        std::cout << "\nHEAP SORT COMPLETE.\n";
    }
    else if (input->KeyPressed(SDL_SCANCODE_7))
    {
        LoadArray();
        std::cout << "\nSTARTED.\n";
        graphics->Complete(false);
        algorithm->CountingSort(arr, SIZE);
        graphics->Complete(true);
        std::cout << "\nCOMPLETE.\n";
    }

    input->Update();
}

void Game::Render()
{
    graphics->Draw(arr);
}

void Game::Run()
{
    Intro();

    while (is_running)
    {
        while (SDL_PollEvent(&events) != 0)
            if (events.type == SDL_QUIT)
                is_running = false;

        Update();
        Render();
    }
}