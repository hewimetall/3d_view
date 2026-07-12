//
// Created by DERTY on 4/20/2023.
//

#include "project.h"
#include <ctype.h>
#include <errno.h>
#define MAX_VERTEX 100000

static int parse_face_vertex(const char *token, unsigned int *index) {
    char *end = NULL;
    errno = 0;
    unsigned long parsed = strtoul(token, &end, 10);
    if (errno || end == token || parsed == 0 || parsed > MAX_VERTEX) {
        return 0;
    }
    if (*end != '\0' && *end != '/' && !isspace((unsigned char)*end)) {
        return 0;
    }
    *index = (unsigned int)parsed;
    return 1;
}

int parser_obj(char filename[], facet indices[]) {
    Vector3 vertices[MAX_VERTEX];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not read file: %s\n", filename);
        return 0;
    }
    int vertex_count = 0, facet_count=0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "v ", 2) == 0) {
            int match = 0;
            if (vertex_count < MAX_VERTEX) {
                match = sscanf(line, "v %f %f %f", &vertices[vertex_count].x,
                   &vertices[vertex_count].y, &vertices[vertex_count].z);
            }
            if (match == 3) {
                vertex_count++;
            }
        } else if ((strncmp(line, "vt ", 3) == 0) || (strncmp(line, "vn ", 3) == 0) ||
                   (strncmp(line, "#", 1) == 0) || line[0] == '\n' || line[0] == '\r') {
        } else if (line[0] == 'f' && isspace((unsigned char)line[1]) && vertex_count > 0) {
            char t1[64] = {0};
            char t2[64] = {0};
            char t3[64] = {0};
            unsigned int v1 = 0, v2 = 0, v3 = 0;
            int matches = sscanf(line, "f %63s %63s %63s", t1, t2, t3);
            if (matches != 3 || !parse_face_vertex(t1, &v1) ||
                !parse_face_vertex(t2, &v2) || !parse_face_vertex(t3, &v3)) {
                fprintf(stderr, "Could not parse face line: %s", line);
                continue;
            }

            /* OBJ indices start at 1; C arrays start at 0. */
            if (v1 <= (unsigned int)vertex_count && v2 <= (unsigned int)vertex_count &&
                v3 <= (unsigned int)vertex_count) {
                indices[facet_count].v1 = vertices[v1 - 1];
                indices[facet_count].v2 = vertices[v2 - 1];
                indices[facet_count].v3 = vertices[v3 - 1];
                facet_count++;
            } else {
                fprintf(stderr, "Face references missing vertex: %s", line);
            }
        } else {
            fprintf(stderr, "Skipped unsupported OBJ line: %s", line);
        }
    }
    fclose(file);
    return facet_count;
}