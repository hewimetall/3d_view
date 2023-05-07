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

typedef struct facet {
    Vector3 v1, v2, v3;
} facet;
typedef struct options {
    
}options;
int parser_obj(char filename[],facet indices[]);
void draw_model(Color color, int count_index, facet indices[], float scale_p, Vector3 move, Vector3 rotate, Vector3 opt);
Vector3 oper(Vector3 vec, Vector3 rotate);
void draw_gui(Vector3 *move, Vector3 *rotate, float *scale, Vector4 *opt, int* xMoveEditMode, char *xMoveText, int* yMoveEditMode, char *yMoveText, int* zMoveEditMode, char *zMoveText, int* xRotEditMode, char *xRotText, int* yRotEditMode, char *yRotText, int* zRotEditMode, char *zRotText);


#endif //EXAMPLE_PROJECT_H
