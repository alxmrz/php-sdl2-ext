<?php

if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Cant intitialize SDL: %s\n", SDL_GetError());
    return;
}

$window = SDL_CreateWindow(
    "PHP works with SDL2!",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    800,
    600,
    SDL_WINDOW_SHOWN);

if (!$window) {
    printf("Can't create window: %s\n", SDL_GetError());
    return;
}

$renderer = SDL_CreateRenderer($window, -1, SDL_RENDERER_ACCELERATED);
if (!$renderer) {
    printf("Can't create renderer: %s\n", SDL_GetError());

    return;
}

SDL_UpdateWindowSurface($window);
SDL_SetRenderDrawColor($renderer, 160, 160, 160, 0);

$rect = new SDL_Rect(0, 0, 800, 600);
if (SDL_RenderFillRect($renderer, $rect) < 0) {
    printf("Cant fill rect: (%s)", SDL_GetError());
    SDL_Quit();
    return;
}

SDL_RenderPresent($renderer);
SDL_Delay(1000);

SDL_DestroyRenderer($renderer);
SDL_DestroyWindow($window);
SDL_Quit();
