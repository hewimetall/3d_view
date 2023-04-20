#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "project.h"
void print_cube(Color color, int count_index, face indices[]) {
        rlPushMatrix();
        rlTranslatef(0, 0, 0);
        rlBegin(RL_TRIANGLES);

        rlColor4ub(color.r, color.g, color.b, color.a);
        for(int i = 0; i<count_index;i++) {
            Vector3  v1 =  indices[i].v1;
            Vector3  v2 = indices[i].v2;
            Vector3  v3 = indices[i].v3;
            float scale_p = 10.0;
            rlVertex3f(v1.x * scale_p, v1.y * scale_p, v1.z * scale_p);
            rlVertex3f(v2.x * scale_p, v2.y * scale_p, v2.z * scale_p);
            rlVertex3f(v3.x * scale_p, v3.y* scale_p, v3.z*scale_p);
        }
        rlEnd();
        rlPopMatrix();
}

int main() {
    face (*indices)[] = calloc(1,sizeof(face)*100000);
    // Define the camera to look into our 3d world
    Camera camera = {0};
    camera.position = (Vector3){ 10.0f, 8.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

//    int count_index = parser_obj("C:/Users/DERTY/CLionProjects/opengl_test/room.obj", indices);
    Model md = LoadModel("C:/Users/DERTY/CLionProjects/opengl_test/room.obj");
    InitWindow(800, 450, "My Window");
    SetTargetFPS(60);
    Color color = RED;
    SetCameraMode(camera, CAMERA_FREE);
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode3D(camera);
//        rlCheckRenderBatchLimit(36);
//        print_cube(color,count_index,indices);
        DrawModel(md,(Vector3) {0.,0,0},1.f,RED);
//        DrawCube((Vector3) {0,0,0}, 10,10,10,RED );
        EndMode3D();

        EndDrawing();
    }
//    UnloadModel(md);
    CloseWindow();
    return 0;
}