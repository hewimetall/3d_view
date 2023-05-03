//
// Created by DERTY on 4/20/2023.
//

#include "project.h"
#define MAX_VERTEX 100000

int fgetsn(char buff[],int max,FILE *f) {
    char c = getc(f);
    for(int i=0; i<max && c !='\n' && c != '\0' && c != EOF;++i, c = getc(f))
        buff[i] = c;
    if(c == EOF) c = 0;
    return c;
}
int parser_obj(char filename[], facet indices[]) {
    Vector3 vertices[MAX_VERTEX];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not read file: %s\n", filename);
        return 1;
    }
    int vertex_count = 0, facet_count=0;
    char line[100];
    while (fgetsn(line, 100, file)) {
        if (strncmp(line, "v ", 2) == 0) {
            sscanf(line, "v %f %f %f", &vertices[vertex_count].x,
                   &vertices[vertex_count].y, &vertices[vertex_count].z);
            vertex_count++;
        } else if ((strncmp(line, "vt ", 3) == 0) || (strncmp(line, "vn ", 3) == 0) || (strncmp(line, "#", 1) == 0) ){
        } else if (strncmp(line, "f", 1) == 0 && vertex_count>0) {
            unsigned int v1, v2, v3, vt1, vt2, vt3, vn1, vn2, vn3;
            int matches = sscanf(line, "f %u/%u/%u %u/%u/%u %u/%u/%u\n", &v1, &vt1,
                                 &vn1, &v2, &vt2, &vn2, &v3, &vt3, &vn3);
            if (matches != 9) {
                matches = sscanf(line, "f %u//%u %u//%u %u//%u\n", &v1, &vn1, &v2, &vn2,
                                 &v3, &vn3);

                if (matches != 6) {
                    matches = sscanf(line, "f %u %u %u\n", &v1,&v2,&v3);
                    if (matches != 3) {
                        printf("Не удалось прочитать f строку. Вместо этого получено "
                               "значение %d.\n",
                               matches);
                               continue; 
                    }
                }
            }

            /* Индексы в OBJ начинаются с 1, в Си - с 0 */
            if(v1 < MAX_VERTEX && v2 < MAX_VERTEX && v3 < MAX_VERTEX) {
                indices[facet_count].v1 = vertices[v1 - 1];
                indices[facet_count].v2 = vertices[v2 - 1];
                indices[facet_count].v3 = vertices[v3 - 1];
                facet_count++;
            }
        } else {
            fprintf(stderr, "FAILE %s", line);
        }
    }
    fclose(file);
    return facet_count;
}