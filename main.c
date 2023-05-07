#include "project.h"

int main() {
    facet (*indices)[] = calloc(1,sizeof(facet)*1000000);
    // Define the camera to look into our 3d world
    Camera camera = {0};
    camera.position = (Vector3){ 5.0f, 10.0f, 15.0f }; // Camera position
    camera.target = (Vector3){ 5.0f, 3.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    Vector2 center = {(GetScreenWidth() - 300)/2.0f, GetScreenHeight()/2.0f };

    int xMoveEditMode = 0;
    int yMoveEditMode = 0;
    int zMoveEditMode = 0;
    int xRotEditMode = 0;
    int yRotEditMode = 0;
    int zRotEditMode = 0;
    int scaleEditMode = 0;

    char xMoveText[30] = {0};
    xMoveText[0] = '0';
    char yMoveText[30] = {0};
    yMoveText[0] = '0';
    char zMoveText[30] = {0};
    zMoveText[0] = '0';
    char xRotText[30] = {0};
    xRotText[0] = '0';
    char yRotText[30] = {0};
    yRotText[0] = '0';
    char zRotText[30] = {0};
    zRotText[0] = '0';
    char scaleText[30] = {0};
    scaleText[0] = '0';

    Vector3 move = {1.,1.,1.};
    Vector3 rotate = {0.,0.,0.};
    float scale = 0;

    int count_index = 0;
    InitWindow(950, 450, "My Window");
    SetTargetFPS(60);
    char *filePaths[1024] = { 0 }; // We will register a maximum of filepaths
    Color color = GREEN;
    Vector3 opt = {1.};
    SetCameraMode(camera, CAMERA_FREE);
    elem *element = initGui(&move, &rotate, &scale);
    float a = element[1].max;
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
            BeginMode3D(camera);
            draw_model(color,count_index, indices, scale, move, rotate, opt);
            EndMode3D();
            draw_gui(&move,&rotate,&scale, &opt, &element);
            EndDrawing();
        } else {
            BeginDrawing();
                DrawText("Drop file", 380,450/2-50,45,RED);
            EndDrawing();
        }
    }
    CloseWindow();
    free(indices);
    return 0;
}