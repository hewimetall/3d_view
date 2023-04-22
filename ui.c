//
// Created by DERTY on 4/20/2023.
//
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#define STARTX 650
#define STARTY 0
#define STEP 20
#define YPOS(x)(STARTY+STEP*(x-1))
#define XPOS(x)(STARTX+20)

void draw_gui(Vector3 *angle, Vector3 *rotate, float *scale) {
    DrawRectangle(STARTX-30,STARTY,200,160,WHITE);
    angle->x = GuiSliderBar((Rectangle){ XPOS(1), YPOS(1), 120, 20 }, "Move x", NULL, angle->x, -180, 180);
    angle->y = GuiSliderBar((Rectangle){ XPOS(2), YPOS(2), 120, STEP }, "Move y", NULL, angle->y, -180, 180);
    angle->z = GuiSliderBar((Rectangle){ XPOS(3), YPOS(3), 120, STEP }, "Move z", NULL, angle->z, -450, 180);

    rotate->x = GuiSliderBar((Rectangle){ XPOS(4), YPOS(4), 120, STEP }, "Rotate x", NULL, rotate->x, -180, 180);
    rotate->y = GuiSliderBar((Rectangle){ XPOS(5), YPOS(5), 120, STEP }, "Rotate y", NULL, rotate->y, -180, 180);
    rotate->z = GuiSliderBar((Rectangle){ XPOS(6), YPOS(6), 120, STEP }, "Rotate z", NULL, rotate->z, -180, 180);

    *scale = GuiSliderBar((Rectangle){ XPOS(7), YPOS(7), 120, STEP }, "Scale", NULL, *scale, 0.1, 5);
}