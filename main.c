#include "project.h"

int main() {
    face (*indices)[] = calloc(1,sizeof(face)*100000);
    // Define the camera to look into our 3d world
    Camera camera = {0};
    camera.position = (Vector3){ 10.0f, 8.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    Vector2 center = {(GetScreenWidth() - 300)/2.0f, GetScreenHeight()/2.0f };

    Vector3 angle = {0};
    Vector3 rotate = {0};
    float scale = 0;

    int count_index = parser_obj("C:/Users/DERTY/CLionProjects/opengl_test/test.obj", indices);
    InitWindow(800, 450, "My Window");
    SetTargetFPS(60);
    Color color = RED;
    SetCameraMode(camera, CAMERA_FREE);
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode3D(camera);
        draw_gui(&angle,&rotate,&scale);
        oper(&indices,angle,rotate,scale);
        draw_model(color,count_index,indices);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}