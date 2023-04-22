//
// Created by DERTY on 4/20/2023.
//
#include "project.h"
#include "raymath.h"

typedef struct Matrix3 {
    float m0, m3, m6;  // Matrix first row (4 components)
    float m1, m4, m7;  // Matrix second row (4 components)
    float m2, m5, m8; // Matrix third row (4 components)
} Matrix3;

typedef struct MatrixVec3 {
    Vector3 v[3];
} MatrixVec3;

#define MATRIXVEC3_TO_MATRIX3(mvec3, m3) \
    do { \
        (m3).m0 = (mvec3).v[0].x; (m3).m1 = (mvec3).v[0].y; (m3).m2 = (mvec3).v[0].z; \
        (m3).m3 = (mvec3).v[1].x; (m3).m4 = (mvec3).v[1].y; (m3).m5 = (mvec3).v[1].z; \
        (m3).m6 = (mvec3).v[2].x; (m3).m7 = (mvec3).v[2].y; (m3).m8 = (mvec3).v[2].z; \
    } while(0)

#define MATRIX3_TO_MATRIXVEC3(m3, mvec3) \
    do { \
        (mvec3).v[0].x = (m3).m0; (mvec3).v[0].y = (m3).m1; (mvec3).v[0].z = (m3).m2; \
        (mvec3).v[1].x = (m3).m3; (mvec3).v[1].y = (m3).m4; (mvec3).v[1].z = (m3).m5; \
        (mvec3).v[2].x = (m3).m6; (mvec3).v[2].y = (m3).m7; (mvec3).v[2].z = (m3).m8; \
    } while(0)

#define MATRIX3_MULTIPLY_VECTOR3(m, v) ((Vector3) { \
    m.m0 * v.x + m.m3 * v.y + m.m6 * v.z, \
    m.m1 * v.x + m.m4 * v.y + m.m7 * v.z, \
    m.m2 * v.x + m.m5 * v.y + m.m8 * v.z \
})

Matrix3 Matrix3Identity(Vector3 angle) {
    Matrix3 result = { 1.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f,
                      0.0f, 0.0f, 1.0f }; // MatrixIdentity()


    return result;
}

Matrix3 Matrix3Multiply(Matrix3 a, Matrix3 b) {
    Matrix3 result = { 0 };
    result.m0 = a.m0 * b.m0 + a.m3 * b.m1 + a.m6 * b.m2;
    result.m1 = a.m1 * b.m0 + a.m4 * b.m1 + a.m7 * b.m2;
    result.m2 = a.m2 * b.m0 + a.m5 * b.m1 + a.m8 * b.m2;
    result.m3 = a.m0 * b.m3 + a.m3 * b.m4 + a.m6 * b.m5;
    result.m4 = a.m1 * b.m3 + a.m4 * b.m4 + a.m7 * b.m5;
    result.m5 = a.m2 * b.m3 + a.m5 * b.m4 + a.m8 * b.m5;
    result.m6 = a.m0 * b.m6 + a.m3 * b.m7 + a.m6 * b.m8;
    result.m7 = a.m1 * b.m6 + a.m4 * b.m7 + a.m7 * b.m8;
    result.m8 = a.m2 * b.m6 + a.m5 * b.m7 + a.m8 * b.m8;
    return result;
}

Matrix3 Matrix3Rotate(float radians)
{
    float cosAngle = cosf(radians);
    float sinAngle = sinf(radians);

    Matrix3 result = { cosAngle, 0.0f, 0.0f,
                      0.0f, sinAngle, 0.0f,
                      0.0f, 0.0f, cosAngle }; // MatrixIdentity()


    return result;
}

Matrix3 Matrix3RotateX(float angle){
    Matrix3 result = { 1.0f, 0.0f, 0.0f,
                       0.0f, cosf(angle), -sinf(angle),
                       0.0f, sinf(angle), cosf(angle) };
    return result;
}

Matrix3 Matrix3RotateY(float angle){
    Matrix3 result = { cosf(angle), 0.0f, sinf(angle),
                       0.0f, 1, 0.0f,
                       -sinf(angle), 0, cosf(angle) };
    return result;
}

Matrix3 Matrix3RotateZ(float angle){
    Matrix3 result = { cosf(angle), -sinf(angle), 0.0f,
                       sinf(angle), cosf(angle), 0.0f,
                       0.0f, 0.0f, 1.0f};
    return result;
}

//void rotate(float angle, float x, float y, float z) {
//    Matrix3 rx =
//};

void oper(face *index, Vector3 angle, Vector3 rotate, float scale) {
}