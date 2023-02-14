// Including Libraries and Files
#include <raylib.h>
#include "res/items.h"

// Screen Resolution
#define ScreenWidth 1600
#define ScreenHeight 900

// Initiating Functions
void drawElements();
void Controls();
void healthSystem();

// Globals
Monster mnst[50];
int lvl = 1;

// Update Function
void Update()
{
    // Draw Elements on Screen
    drawElements();

    // Control Management
    Controls();

    // Monster Health Management
    healthSystem();
}

int main()
{
    // Initiating the Window
    InitWindow(ScreenWidth, ScreenHeight, "Monster Hunter");
    SetTargetFPS(60);
    ToggleFullscreen();

    // Initializing Monsters
    for (int i = 1; i <= 50; i++)
    {
        mnst[i].createMonster(i, i * 100);
    }

    // Main Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            Update();

        EndDrawing();
    }

    // Cleaning
    for (int i = 1; i <= 50; i++)
    {
        UnloadTexture(mnst[i].monsterTexture());
    }
    
    // Closing the Window
    CloseWindow();
}


/* FUNCTIONS PERFORMING TASKS */

void drawElements()
{
    if (lvl == mnst[lvl].monsterNumber())
    {
        mnst[lvl].drawRes(ScreenWidth, ScreenHeight);
    }
}

void Controls()
{
    if (IsKeyPressed(KEY_A))
    {
        mnst[lvl].monsterHealthchanger(0);
    }
}

void healthSystem()
{
    if (mnst[lvl].monsterHealth() == 0)
    {
        lvl++;
    }
}