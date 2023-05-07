//
// Created by DERTY on 4/20/2023.
//
#include "project.h"

Vector3 scaleV(Vector3 v, float scale) {
    v.x = v.x * scale;
    v.y = v.y * scale;
    v.z = v.z * scale;
    return v;
}

Vector3 moveV(Vector3 v, Vector3 move) {
    v.x = v.x + move.x;
    v.y = v.y + move.y;
    v.z = v.z + move.z;
    return v;
}
Vector3 centerV(Vector3 v1, Vector3 v2) {
    Vector3 v = {
        (v1.x+v2.x)/2,
        (v1.y+v2.y)/2,
        (v1.z+v2.z)/2,
    };
    return v;
}

void draw_model(Color color, int count_index, facet indices[], float scale_p, Vector3 move, Vector3 rotate, Vector3 opt) {
    for(int i = 0; i<count_index ;i++) {
        
        Vector3  v1 = moveV(scaleV(oper(indices[i].v1, rotate), scale_p), move);
        Vector3  v2 = moveV(scaleV(oper(indices[i].v2, rotate), scale_p), move);
        Vector3  v3 = moveV(scaleV(oper(indices[i].v3, rotate), scale_p), move);


        Vector3  vc12 = centerV(v1,v2);
        Vector3  vcvc122 = centerV(vc12,v2);
        Vector3  vcvc221 = centerV(vc12,v1);
        Vector3  vc23 = centerV(v2,v3);
        Vector3  vcvc232 = centerV(vc23,v2);
        Vector3  vcvc233 = centerV(vc23,v3);
        if(!opt.x){
            DrawLine3D(v1,v2,GREEN);
            DrawLine3D(v2,v3,GREEN);
        } else {
            DrawLine3D(v1,vcvc122,GREEN);
            DrawLine3D(vcvc221,v2,GREEN);
            DrawLine3D(v2,vcvc232,GREEN);
            DrawLine3D(vcvc233,v3,GREEN);
        }
        }
}
