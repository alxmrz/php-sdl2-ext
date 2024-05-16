<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

class SDL_Rect {
    public int $x;
    public int $y;
    public int $width;
    public int $height;

    public function __construct(int $x, int $y, int $width, int $height) {}
}

class SDL_Window {}

class SDL_Renderer {}

function SDL_GetError(): string {}

function SDL_Init(int $flags): int {}

function SDL_CreateWindow(
    string $title,
    int $x,
    int $y,
    int $width,
    int $height,
    int $flags
): ?SDL_Window {}

function SDL_CreateRenderer(
    SDL_Window $window,
    int $index,
    int $flags
): ?SDL_Renderer {}

function SDL_UpdateWindowSurface(SDL_Window $window): int {}

function SDL_SetRenderDrawColor(
    SDL_Renderer $renderer,
    int $r,
    int $g,
    int $b,
    int $a
): int {}

function SDL_RenderFillRect(SDL_Renderer $renderer, SDL_Rect $rect): int {}

function SDL_RenderPresent(SDL_Renderer $renderer): void {}

function SDL_Delay(int $ms): void {}

function SDL_DestroyRenderer(SDL_Renderer $renderer): void {}

function SDL_Quit(): void {}

function SDL_DestroyWindow(SDL_Window $window): void {}