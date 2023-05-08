//
// Created by DERTY on 4/20/2023.
//
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "terminal.h"
#include <string.h>
#define STARTX 650
#define STARTY 10
#define STEP 20
#define YPOS(x)(STARTY+(STEP+10)*(x-1))
#define XPOS(x)(STARTX+50)

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

char* findFilename(char* filePaths){
  char* p = filePaths;
  char* slash = NULL;
  while (*p != 0){
    if(*p == '/') slash = p;
    p++;
  }
  return ++slash;
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

void draw_gui(Vector3 *opt, elem* element, int* openExpl, char* filePaths, int count_index, int count_vertex) {
  char vertexText[30] = {0};
  char facetText[30] = {0};

    DrawRectangle(STARTX-30,STARTY-10,350,450, BLACK);
    DrawLine(STARTX-30, STARTY-10, STARTX-30, 450, DARKGRAY);

    for (int i = 0; i < 7; i++)
    { textSlide(i+1, &(element[i]));}
    
    opt->x = GuiCheckBox((Rectangle){ XPOS(8) + 130, YPOS(8), 20, STEP }, "Dropped line", opt->x);
    opt->y = GuiCheckBox((Rectangle){ XPOS(8), YPOS(8), 20, STEP }, "Type", opt->y);

    *openExpl = GuiButton((Rectangle){XPOS(15) - 20, YPOS(15) - 10, 260, 25}, "Open new file");

    DrawText(findFilename(filePaths), XPOS(15) - 20, YPOS(12) - 10, 20, GREEN);

    sprintf(vertexText, "Count of vertex: %d", count_vertex);
    sprintf(facetText, "Count of facet: %d", count_index);
    DrawText(vertexText, XPOS(15) - 20, YPOS(13) - 10, 20, GREEN);
    DrawText(facetText, XPOS(15) - 20, YPOS(14) - 10, 20, GREEN);
}