
#include "types.h"
#include <stdlib.h>
#include <string.h>
#include "ply_handling.h"

void readData(const char* file_name, Point points[]){
    FILE* file = fopen(file_name, "r");

    
    int vertex_count = 2903;
    int face_count = 5804;

    char s[1000];
    int line = 1;
    while(line++){
        fscanf(file, "%s", s);

        if (strcmp(s, "end_header") == 0) break;
    }


    for (int i = 0; i < face_count; i++){
        double x, y, z;
        fscanf("%lf %lf %lf", &x, &y, &z);
        points[i].x = x;
        points[i].y = y;
        points[i].z = z;
    }
    
}