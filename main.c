#include "project.h"

int main() {
    facet* indices = calloc(1,sizeof(facet)*1000000);
    // Define the camera to look into our 3d world
    Camera camera = {0};
    camera.position = (Vector3){ 5.0f, 10.0f, 15.0f }; // Camera position
    camera.target = (Vector3){ 5.0f, 3.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    Vector3 move = {1.,1.,1.};
    Vector3 rotate = {0.,0.,0.};
    float scale = 0;
    int openExpl = 0;

    int count_index = 0;
    int count_vertex = 0;
    InitWindow(950, 450, "My Window");
    SetTargetFPS(60);
    char filePaths[1024] = { 0 }; // We will register a maximum of filepaths
    Color color = GREEN;
    Vector3 opt = {0., 1., 0};
    SetCameraMode(camera, CAMERA_FREE);
    elem *element = initGui(&move, &rotate, &scale);
    while (!WindowShouldClose()) {
            ClearBackground(BLACK);
        if (IsFileDropped()) {
            FilePathList droppedFiles = LoadDroppedFiles();
            if (droppedFiles.count == 1){
                free(indices);
                indices = calloc(1,sizeof(facet)*1000000);
                TextCopy(filePaths, droppedFiles.paths[0]);
                printf("\n\n%d %d %s\n\n", droppedFiles.capacity, droppedFiles.count, droppedFiles.paths[0] );
                count_index = parser_obj(filePaths, indices, &count_vertex);
            }
            UnloadDroppedFiles(droppedFiles);    // Unload filepaths from memory
        }
        else if ( count_index ) {
            BeginDrawing();  
            BeginMode3D(camera);
            draw_model(color,count_index, indices, scale, move, rotate, opt);
            EndMode3D();
        
            draw_gui(&opt, element, &openExpl, filePaths, count_index, count_vertex);
            EndDrawing();
        } else {
            BeginDrawing();
                DrawText("Drop file", 380,450/2-50,45,RED);
                openExpl = GuiButton((Rectangle){400,450/2+30, 150, 30}, "Open file");
            EndDrawing();
        }
    }
    CloseWindow();
    free(indices);
    free(element);
    return 0;
}