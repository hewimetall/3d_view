//
// Created by DERTY on 4/20/2023.
//
#include "project.h"

void draw_model(Color color, int count_index, face indices[], float scale_p, Vector3 move, Vector3 rotate) {
    rlPushMatrix();
    rlBegin(RL_LINES);
    rlColor4ub(color.r, color.g, color.b, color.a);
    for(int i = 0; i<count_index;i++) {
        Vector3  v1 = oper(indices[i].v1, rotate);
        Vector3  v2 = oper(indices[i].v2, rotate);
        Vector3  v3 = oper(indices[i].v3, rotate);
        
        rlVertex3f(move.x + v1.x * scale_p, move.y + v1.y * scale_p, move.z + v1.z * scale_p);
        rlVertex3f(move.x +v2.x * scale_p,move.y + v2.y * scale_p,move.z + v2.z * scale_p);
        
        rlVertex3f(move.x +v2.x * scale_p,move.y + v2.y * scale_p,move.z + v2.z * scale_p);
        rlVertex3f(move.x +v3.x * scale_p,move.y + v3.y* scale_p,move.z + v3.z*scale_p);
        
        rlVertex3f(move.x +v2.x * scale_p,move.y + v2.y * scale_p,move.z + v2.z * scale_p);
        rlVertex3f(move.x +v1.x * scale_p,move.y + v1.y * scale_p,move.z + v1.z * scale_p);
    }
    rlEnd();
    rlPopMatrix();
}
