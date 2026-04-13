#include "raylib.h"

#include "config.h"
#include "colours.h"
#include "utils.h"
#include "ball.h"
#include "camera.h"
#include "render.h"

int main(void)
{
    Ball b = {
        .pos = (Vec2) {.x = 0, .y = 0 },
        .vel = (Vec2) {.x = 0, .y = 0 },
        .type = BALL_BLUE,
        .bool_draw = 1,
    };

    ball_println(&b);

    Table table = table_init();
    SimCamera camera = { .offset = vec2_zeroed(), .scale = SCREEN_SCALE };

    InitWindow(1280, 720, "snooker");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(SKYBLUE);
            table_draw(&camera, &table);
            ball_draw(&camera, &b);
            //DrawCircle(100, SCREEN_H / 2, 40, COLOR_WHITE);
            //DrawCircle(200, SCREEN_H / 2, 40, COLOR_RED);
            //DrawCircle(300, SCREEN_H / 2, 40, COLOR_BLACK);
            //DrawCircle(400, SCREEN_H / 2, 40, COLOR_PINK);
            //DrawCircle(500, SCREEN_H / 2, 40, COLOR_BLUE);
            //DrawCircle(600, SCREEN_H / 2, 40, COLOR_BROWN);
            //DrawCircle(700, SCREEN_H / 2, 40, COLOR_GREEN);
            //DrawCircle(800, SCREEN_H / 2, 40, COLOR_YELLOW);
            //DrawRectangle(900, SCREEN_H / 2, 40, 40, COLOR_WOOD);
            //DrawRectangle(920, SCREEN_H / 2, 40, 40, COLOR_POCKET);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
