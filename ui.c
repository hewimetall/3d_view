//
// Created by DERTY on 4/20/2023.
//
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "terminal.h"
#define STARTX 650
#define STARTY 0
#define STEP 20
#define YPOS(x)(STARTY+STEP*(x-1))
#define XPOS(x)(STARTX+50)
#define POS(x) XPOS(x), YPOS(x)

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
typedef struct elem {
  char drawText[20];
  float* dest;
  float min;
  float max;
  char floatText[30];
  int editMode;
}elem;

elem* initGui(Vector3 *move, Vector3 *rotate, float* scale){
  GuiLoadStyleTerminal();
  GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
  GuiSetStyle(CHECKBOX, TEXT_ALIGNMENT, 0);

  elem *element = calloc(1, 7 * sizeof(elem));
  element[0] = (elem){"Move x", &move->x, -180, 180, "0", 0};
  element[1] = (elem){"Move y", &move->y, -180, 180, "0", 0};
  element[2] = (elem){"Move z", &move->z, -180, 180, "0", 0};
  element[3] = (elem){"Rotate x", &rotate->x, -10, 10, "0", 0};
  element[4] = (elem){"Rotate z", &rotate->z, -10, 10, "0", 0};
  element[5] = (elem){"Rotate y", &rotate->y, -10, 10, "0", 0};
  element[6] = (elem){"Scale", scale, 0.1, 5, "0", 0};
  
  return element;
};



void textSlide(int pos, elem* element) {
      float tmpSlide = GuiSliderBar((Rectangle){ XPOS(pos), YPOS(pos), 120, 20}, element->drawText, NULL, *(element->dest), element->min, element->max);
    if (GuiTextBox((Rectangle){XPOS(pos) + 130, YPOS(pos), 110, 20}, element->floatText, 29, element->editMode))
      element->editMode = !(element->editMode);
    float tmpText = validVal(element->floatText);
    if (tmpSlide != *(element->dest)){
       *(element->dest) = tmpSlide;
       sprintf(element->floatText, "%.2f", *(element->dest));
    } else if (tmpText != *(element->dest)){
       *(element->dest) = tmpText;
    }   
}

void draw_gui(Vector3 *move, Vector3 *rotate, float *scale, Vector4 *opt, elem* element) {
    DrawRectangle(STARTX-30,STARTY,350,200,DARKGRAY);

    for (int i = 0; i < 7; i++)
    { textSlide(i+1, &(element[i]));}
    
    // float tmpXmoveS = GuiSliderBar((Rectangle){ XPOS(1), YPOS(1), 120, 20 }, "Move x", NULL, move->x, -180, 180);
    // if (GuiTextBox((Rectangle){XPOS(1) + 130, YPOS(1), 110, 20}, xMoveText, 29, *xMoveEditMode))
    //   *xMoveEditMode = !(*xMoveEditMode);
    // float tmpXmoveT = validVal(xMoveText);
    // if (tmpXmoveS != move->x){
    //    move->x = tmpXmoveS;
    //    sprintf(xMoveText, "%.2f", move->x);
    // } else if (tmpXmoveT != move->x){
    //    move->x = tmpXmoveT;
    // }

    // float tmpYmoveS =  GuiSliderBar((Rectangle){ XPOS(2), YPOS(2), 120, STEP }, "Move y", NULL, move->y, -180, 180);
    // if (GuiTextBox((Rectangle){XPOS(2) + 130, YPOS(2), 110, 20}, yMoveText, 29, *yMoveEditMode))
    //   *yMoveEditMode = !(*yMoveEditMode);
    // float tmpYmoveT = validVal(yMoveText);
    // if (tmpYmoveS != move->y){
    //    move->y = tmpYmoveS;
    //    sprintf(yMoveText, "%.2f", move->y);
    // } else if (tmpYmoveT != move->y){
    //    move->y = tmpYmoveT;
    // }

    // float tmpZmoveS =  GuiSliderBar((Rectangle){ XPOS(3), YPOS(3), 120, STEP }, "Move z", NULL, move->z, -180, 180);
    // if (GuiTextBox((Rectangle){XPOS(3) + 130, YPOS(3), 110, 20}, zMoveText, 29, *zMoveEditMode))
    //   *zMoveEditMode = !(*zMoveEditMode);
    // float tmpZmoveT = validVal(zMoveText);
    // if (tmpZmoveS != move->z){
    //    move->z = tmpZmoveS;
    //    sprintf(zMoveText, "%.2f", move->z);
    // } else if (tmpZmoveT != move->z){
    //    move->z = tmpZmoveT;
    // }

    // float tmpXrotS =  GuiSliderBar((Rectangle){ XPOS(4), YPOS(4), 120, STEP }, "Rotate x", NULL, rotate->x, -10, 10);
    // if (GuiTextBox((Rectangle){XPOS(4) + 130, YPOS(4), 110, 20}, xRotText, 29, *xRotEditMode))
    //   *xRotEditMode = !(*xRotEditMode);
    // float tmpXrotT = validVal(xRotText);
    // if (tmpXrotS != rotate->x){
    //    rotate->x = tmpXrotS;
    //    sprintf(xRotText, "%.2f", rotate->x);
    // } else if (tmpXrotT != rotate->x){
    //    rotate->x = tmpXrotT;
    // }

    // float tmpYrotS =  GuiSliderBar((Rectangle){ XPOS(5), YPOS(5), 120, STEP }, "Rotate y", NULL, rotate->y, -10, 10);
    // if (GuiTextBox((Rectangle){XPOS(5) + 130, YPOS(5), 110, 20}, yRotText, 29, *yRotEditMode))
    //   *yRotEditMode = !(*yRotEditMode);
    // float tmpYrotT = validVal(yRotText);
    // if (tmpYrotS != rotate->y){
    //    rotate->y = tmpYrotS;
    //    sprintf(yRotText, "%.2f", rotate->y);
    // } else if (tmpYrotT != rotate->y){
    //    rotate->y = tmpYrotT;
    // }

    // float tmpZrotS =  GuiSliderBar((Rectangle){ XPOS(6), YPOS(6), 120, STEP }, "Rotate z", NULL, rotate->z, -10, 10);
    // if (GuiTextBox((Rectangle){XPOS(6) + 130, YPOS(6), 110, 20}, zRotText, 29, *zRotEditMode))
    //   *zRotEditMode = !(*zRotEditMode);
    // float tmpZrotT = validVal(zRotText);
    // if (tmpZrotS != rotate->z){
    //    rotate->z = tmpZrotS;
    //    sprintf(zRotText, "%.2f", rotate->z);
    // } else if (tmpZrotT != rotate->z){
    //    rotate->z = tmpZrotT;
    // }

    // float tmpScaleS = GuiSliderBar((Rectangle){ XPOS(7), YPOS(7), 120, STEP }, "Scale", NULL, *scale, 0.1, 5);
    // if (GuiTextBox((Rectangle){XPOS(7) + 130, YPOS(7), 110, 20}, scaleText, 29, *scaleEditMode))
    //   *scaleEditMode = !(*scaleEditMode);
    // float tmpScaleT = validVal(scaleText);
    // if (tmpScaleS != *scale){
    //    *scale = tmpScaleS;
    //    sprintf(scaleText, "%.2f", *scale);
    // } else if (tmpScaleT != *scale){
    //    *scale = tmpScaleT;
    // }

    
    opt->x = GuiCheckBox((Rectangle){ POS(8), 20, STEP }, "Dr line", opt->x);
    opt->y = GuiCheckBox((Rectangle){ XPOS(9), YPOS(9), 20, STEP }, "Type", opt->y);
}