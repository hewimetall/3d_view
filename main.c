#include "project.h"

int main() {
    facet (*indices)[] = calloc(1,sizeof(facet)*1000000);
    // Define the camera to look into our 3d world
    Camera camera = {0};
    camera.position = (Vector3){ 10.0f, 8.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    Vector2 center = {(GetScreenWidth() - 300)/2.0f, GetScreenHeight()/2.0f };

    Vector3 move = {1.,1.,1.};
    Vector3 rotate = {1.,1.,1.};
    float scale = 0;

    int count_index = 0;
    InitWindow(800, 450, "My Window");
    SetTargetFPS(60);
    char *filePaths[1024] = { 0 }; // We will register a maximum of filepaths
    Color color = GREEN;
    Vector3 opt = {1.};
    SetCameraMode(camera, CAMERA_FREE);
    while (!WindowShouldClose()) {
            ClearBackground(BLACK);
        if (IsFileDropped()) {
            FilePathList droppedFiles = LoadDroppedFiles();
            if (droppedFiles.count == 1){
                free(indices);
                indices = calloc(1,sizeof(facet)*1000000);
                TextCopy(filePaths, droppedFiles.paths[0]);
                printf("\n\n%d %d %s\n\n", droppedFiles.capacity, droppedFiles.count, droppedFiles.paths[0] );
                count_index = parser_obj(filePaths, indices);
            }
            UnloadDroppedFiles(droppedFiles);    // Unload filepaths from memory
        }
        else if ( count_index ) {
            BeginDrawing();
                draw_gui(&move,&rotate,&scale, &opt);
            BeginMode3D(camera);
            draw_model(color,count_index, indices, scale, move, rotate, opt);
            EndMode3D();
            EndDrawing();
        } else {
            BeginDrawing();
                DrawText("Drop file", 800/3,450/2-100,45,RED);
            EndDrawing();
        }
    }
    CloseWindow();
    free(indices);
    return 0;
}