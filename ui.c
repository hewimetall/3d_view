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

int chrbrk(char simb, char *str) {
  char *p;
  int err = 1;
  for (p = str; *p != '\0' && err; ++p) {
    if (simb == *p) err = 0;
  }
  return err;
}

double validVal(char *input) {
  char numbs[] = {'1', '2', '3', '4', '5', '6', '7',
                  '8', '9', '0', '.', '-', '\0'};

  int start = 1;
  char *p = input;
  int dot = 0;
  double res = 0;
    int err = 0;
  while (*(p) && !err) {
    if (chrbrk(*p, numbs)) err++;
    if (*p == '.' && dot == 0)
      dot++;
    else if (*p == '.' && dot > 0)
      err++;
    else if (*p == '-' && !start) {
      err++;
    }
    start = 0;
    p++;
  }
  if (!err)
  sscanf(input, "%lf", &res);
  else res = 0;

  return res;
}

void draw_gui(Vector3 *move, Vector3 *rotate, float *scale, Vector4 *opt, int* xMoveEditMode, char *xMoveText) {
    DrawRectangle(STARTX-30,STARTY,350,160,WHITE);

    float tmpXmoveS = GuiSliderBar((Rectangle){ XPOS(1), YPOS(1), 120, 20 }, "Move x", NULL, move->x, -180, 180);
    if (GuiTextBox((Rectangle){XPOS(1) + 130, YPOS(1), 120, 20}, xMoveText, 29, *xMoveEditMode))
      *xMoveEditMode = !(*xMoveEditMode);
    float tmpXmoveT = validVal(xMoveText);
    if (tmpXmoveS != move->x){
       move->x = tmpXmoveS;
       sprintf(xMoveText, "%f", move->x);
    } else if (tmpXmoveT != move->x){
       move->x = tmpXmoveT;
    }

    move->y = GuiSliderBar((Rectangle){ XPOS(2), YPOS(2), 120, STEP }, "Move y", NULL, move->y, -180, 180);
    move->z = GuiSliderBar((Rectangle){ XPOS(3), YPOS(3), 120, STEP }, "Move z", NULL, move->z, -450, 180);

    rotate->x = GuiSliderBar((Rectangle){ XPOS(4), YPOS(4), 120, STEP }, "Rotate x", NULL, rotate->x, -180, 180);
    rotate->y = GuiSliderBar((Rectangle){ XPOS(5), YPOS(5), 120, STEP }, "Rotate y", NULL, rotate->y, -180, 180);
    rotate->z = GuiSliderBar((Rectangle){ XPOS(6), YPOS(6), 120, STEP }, "Rotate z", NULL, rotate->z, -180, 180);

    *scale = GuiSliderBar((Rectangle){ XPOS(7), YPOS(7), 120, STEP }, "Scale", NULL, *scale, 0.1, 5);
    
    opt->x = GuiCheckBox((Rectangle){ XPOS(8), YPOS(8), 120, STEP }, "Is not line", opt->x);
    opt->y = GuiSliderBar((Rectangle){ XPOS(9), YPOS(9), 120, STEP }, "Rotate z", NULL, opt->y, 1, 10);
    opt->z = GuiCheckBox((Rectangle){ XPOS(10), YPOS(10), 120, STEP }, "Scale", opt->z);
}