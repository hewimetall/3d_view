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

typedef struct face {
    Vector3 v1, v2, v3;
} face;

int parser_obj(char filename[],face indices[]);
void draw_model(Color color, int count_index, face indices[], float scale_p, Vector3 move, Vector3 rotate);
void draw_gui(Vector3 *move, Vector3 *rotate, float *scale);
Vector3 oper(Vector3 vec, Vector3 rotate);

#endif //EXAMPLE_PROJECT_H
