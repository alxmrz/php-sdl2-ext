<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

function SDL_GetError(): string {}

function SDL_Init(int $flags): int {}

function SDL_CreateWindow(
    string $title,
    int $x,
    int $y,
    int $width,
    int $height,
    int $flags
): bool {}

function SDL_CreateRenderer(
    int $index,
    int $flags
): bool {}

function SDL_UpdateWindowSurface(): int {}

function SDL_SetRenderDrawColor(
    int $r,
    int $g,
    int $b,
    int $a
): int {}

function SDL_RenderFillRect(int $x, int $y, int $width, int $height): int {}

function SDL_RenderPresent(): void {}

function SDL_Delay(int $ms): void {}

function SDL_DestroyRenderer(): void {}

function SDL_Quit(): void {}

function SDL_DestroyWindow(): void {}