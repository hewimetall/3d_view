//
// Created by DERTY on 4/20/2023.
//
#include "project.h"

void draw_model(Color color, int count_index, face indices[]) {
    rlPushMatrix();
    rlBegin(RL_LINES);
    rlColor4ub(color.r, color.g, color.b, color.a);
    for(int i = 0; i<count_index;i++) {
        Vector3  v1 =  indices[i].v1;
        Vector3  v2 = indices[i].v2;
        Vector3  v3 = indices[i].v3;
        float scale_p = 1.0f;
        rlVertex3f(v1.x * scale_p, v1.y * scale_p, v1.z * scale_p);
        rlVertex3f(v2.x * scale_p, v2.y * scale_p, v2.z * scale_p);
        
        rlVertex3f(v2.x * scale_p, v2.y * scale_p, v2.z * scale_p);
        rlVertex3f(v3.x * scale_p, v3.y* scale_p, v3.z*scale_p);
        
        rlVertex3f(v2.x * scale_p, v2.y * scale_p, v2.z * scale_p);
        rlVertex3f(v1.x * scale_p, v1.y * scale_p, v1.z * scale_p);
    }
    rlEnd();
    rlPopMatrix();
}
