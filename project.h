//
// Created by DERTY on 4/20/2023.
//

#ifndef EXAMPLE_PROJECT_H
#define EXAMPLE_PROJECT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

typedef struct face {
    Vector3 v1, v2, v3;
} face;

int parser_obj(char filename[],face indices[]);

#endif //EXAMPLE_PROJECT_H
