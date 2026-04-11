#include "raylib.h"

#include "config.h"

#define COLOR_FELT   GetColor(0x1e7d1cff)
#define COLOR_WHITE  GetColor(0xfff9c3ff)
#define COLOR_RED    GetColor(0xbf1a17ff)
#define COLOR_BLACK  GetColor(0x151112ff)
#define COLOR_PINK   GetColor(0xfd778fff)
#define COLOR_BLUE   GetColor(0x015db1ff)
#define COLOR_BROWN  GetColor(0x6d3526ff)
#define COLOR_GREEN  GetColor(0x076c34ff)
#define COLOR_YELLOW GetColor(0xfed208ff)
#define COLOR_WOOD   GetColor(0x410918ff)
#define COLOR_POCKET GetColor(0xe0c891ff)

int main(void)
{
    InitWindow(1280, 720, "snooker");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(COLOR_FELT);

            DrawCircle(100, SCREEN_H / 2, 40, COLOR_WHITE);
            DrawCircle(200, SCREEN_H / 2, 40, COLOR_RED);
            DrawCircle(300, SCREEN_H / 2, 40, COLOR_BLACK);
            DrawCircle(400, SCREEN_H / 2, 40, COLOR_PINK);
            DrawCircle(500, SCREEN_H / 2, 40, COLOR_BLUE);
            DrawCircle(600, SCREEN_H / 2, 40, COLOR_BROWN);
            DrawCircle(700, SCREEN_H / 2, 40, COLOR_GREEN);
            DrawCircle(800, SCREEN_H / 2, 40, COLOR_YELLOW);
            DrawRectangle(900, SCREEN_H / 2, 40, 40, COLOR_WOOD);
            DrawRectangle(920, SCREEN_H / 2, 40, 40, COLOR_POCKET);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
