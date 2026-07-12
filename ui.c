//
// Created by DERTY on 4/20/2023.
//
#define RAYGUI_IMPLEMENTATION
#include "project.h"
#include "raygui.h"
#include <stdbool.h>
#include "terminal.h"
#define STARTX 650
#define STARTY 0
#define STEP 20
#define YPOS(x)(STARTY+STEP*(x-1))
#define XPOS(x)(STARTX+50)

void draw_gui(Vector3 *move, Vector3 *rotate, float *scale, Vector3 *opt, int* xMoveEditMode, char *xMoveText, int* yMoveEditMode, char *yMoveText, int* zMoveEditMode, char *zMoveText, int* xRotEditMode, char *xRotText, int* yRotEditMode, char *yRotText, int* zRotEditMode, char *zRotText) {
    GuiLoadStyleTerminal();
    DrawRectangle(STARTX-30,STARTY,350,160,DARKGRAY);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 21);

    float tmpXmoveS = move->x;
    GuiSliderBar((Rectangle){ XPOS(1), YPOS(1), 120, 20 }, "Move x", NULL, &tmpXmoveS, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(1) + 130, YPOS(1), 110, 20}, xMoveText, 29, *xMoveEditMode))
      *xMoveEditMode = !(*xMoveEditMode);
    float tmpXmoveT = validVal(xMoveText);
    if (tmpXmoveS != move->x){
       move->x = tmpXmoveS;
       sprintf(xMoveText, "%.2f", move->x);
    } else if (tmpXmoveT != move->x){
       move->x = tmpXmoveT;
    }

    float tmpYmoveS = move->y;
    GuiSliderBar((Rectangle){ XPOS(2), YPOS(2), 120, STEP }, "Move y", NULL, &tmpYmoveS, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(2) + 130, YPOS(2), 110, 20}, yMoveText, 29, *yMoveEditMode))
      *yMoveEditMode = !(*yMoveEditMode);
    float tmpYmoveT = validVal(yMoveText);
    if (tmpYmoveS != move->y){
       move->y = tmpYmoveS;
       sprintf(yMoveText, "%.2f", move->y);
    } else if (tmpYmoveT != move->y){
       move->y = tmpYmoveT;
    }

    float tmpZmoveS = move->z;
    GuiSliderBar((Rectangle){ XPOS(3), YPOS(3), 120, STEP }, "Move z", NULL, &tmpZmoveS, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(3) + 130, YPOS(3), 110, 20}, zMoveText, 29, *zMoveEditMode))
      *zMoveEditMode = !(*zMoveEditMode);
    float tmpZmoveT = validVal(zMoveText);
    if (tmpZmoveS != move->z){
       move->z = tmpZmoveS;
       sprintf(zMoveText, "%.2f", move->z);
    } else if (tmpZmoveT != move->z){
       move->z = tmpZmoveT;
    }

    float tmpXrotS = rotate->x;
    GuiSliderBar((Rectangle){ XPOS(4), YPOS(4), 120, STEP }, "Rotate x", NULL, &tmpXrotS, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(4) + 130, YPOS(4), 110, 20}, xRotText, 29, *xRotEditMode))
      *xRotEditMode = !(*xRotEditMode);
    float tmpXrotT = validVal(xRotText);
    if (tmpXrotS != rotate->x){
       rotate->x = tmpXrotS;
       sprintf(xRotText, "%.2f", rotate->x);
    } else if (tmpXrotT != rotate->x){
       rotate->x = tmpXrotT;
    }

    float tmpYrotS = rotate->y;
    GuiSliderBar((Rectangle){ XPOS(5), YPOS(5), 120, STEP }, "Rotate y", NULL, &tmpYrotS, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(5) + 130, YPOS(5), 110, 20}, yRotText, 29, *yRotEditMode))
      *yRotEditMode = !(*yRotEditMode);
    float tmpYrotT = validVal(yRotText);
    if (tmpYrotS != rotate->y){
       rotate->y = tmpYrotS;
       sprintf(yRotText, "%.2f", rotate->y);
    } else if (tmpYrotT != rotate->y){
       rotate->y = tmpYrotT;
    }

    float tmpZrotS = rotate->z;
    GuiSliderBar((Rectangle){ XPOS(6), YPOS(6), 120, STEP }, "Rotate z", NULL, &tmpZrotS, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(6) + 130, YPOS(6), 110, 20}, zRotText, 29, *zRotEditMode))
      *zRotEditMode = !(*zRotEditMode);
    float tmpZrotT = validVal(zRotText);
    if (tmpZrotS != rotate->z){
       rotate->z = tmpZrotS;
       sprintf(zRotText, "%.2f", rotate->z);
    } else if (tmpZrotT != rotate->z){
       rotate->z = tmpZrotT;
    }

    GuiSliderBar((Rectangle){ XPOS(7), YPOS(7), 120, STEP }, "Scale", NULL, scale, 0.1, 5);
    
    bool draw_full_lines = opt->x != 0.0f;
    GuiCheckBox((Rectangle){ XPOS(8), YPOS(8), 120, STEP }, "Is not line", &draw_full_lines);
    opt->x = draw_full_lines ? 1.0f : 0.0f;
    GuiSliderBar((Rectangle){ XPOS(9), YPOS(9), 120, STEP }, "Rotate z", NULL, &opt->y, 1, 10);
    bool extra_scale = opt->z != 0.0f;
    GuiCheckBox((Rectangle){ XPOS(10), YPOS(10), 120, STEP }, "Scale", &extra_scale);
    opt->z = extra_scale ? 1.0f : 0.0f;
}