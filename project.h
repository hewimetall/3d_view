//
// Created by DERTY on 4/20/2023.
//

#ifndef EXAMPLE_PROJECT_H
#define EXAMPLE_PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef UNIT_TEST
typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef int Color;
#define GREEN 0
#else
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#endif

typedef struct facet {
    Vector3 v1, v2, v3;
} facet;
typedef struct options {
    
}options;
int parser_obj(char filename[],facet indices[]);
void draw_model(Color color, int count_index, facet indices[], float scale_p, Vector3 move, Vector3 rotate, Vector3 opt);
Vector3 oper(Vector3 vec, Vector3 rotate);
Vector3 scaleV(Vector3 v, float scale);
Vector3 moveV(Vector3 v, Vector3 move);
Vector3 centerV(Vector3 v1, Vector3 v2);
int chrbrk(char simb, const char *str);
double validVal(const char *input);
void draw_gui(Vector3 *move, Vector3 *rotate, float *scale, Vector3 *opt, int* xMoveEditMode, char *xMoveText, int* yMoveEditMode, char *yMoveText, int* zMoveEditMode, char *zMoveText, int* xRotEditMode, char *xRotText, int* yRotEditMode, char *yRotText, int* zRotEditMode, char *zRotText);


#endif //EXAMPLE_PROJECT_H
