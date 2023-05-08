//
// Created by DERTY on 4/20/2023.
//

#ifndef EXAMPLE_PROJECT_H
#define EXAMPLE_PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

typedef struct elem {
  char drawText[20];
  float* dest;
  float min;
  float max;
  char floatText[30];
  int editMode;
}elem;

typedef struct facet {
    Vector3 v1, v2, v3;
} facet;
typedef struct options {
    
}options;
int parser_obj(char filename[],facet indices[], int* vertex_count);
void draw_model(Color color, int count_index, facet indices[], float scale_p, Vector3 move, Vector3 rotate, Vector3 opt);
Vector3 oper(Vector3 vec, Vector3 rotate);
void draw_gui(Vector3 *opt,  elem* element, int* openExpl, char* filePaths, int count_index, int count_vertex);
elem* initGui(Vector3 *move, Vector3 *rotate, float* scale);

#endif //EXAMPLE_PROJECT_H
