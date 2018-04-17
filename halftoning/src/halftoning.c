#define WIDTH 900
#define HEIGHT 600
#include<stdio.h>

int grey_image[HEIGHT][WIDTH] = {0};
int half_tone_sets[10][3][3] = {
    {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    },
    {
        {0, 0, 0},
        {0, 255, 0},
        {0, 0, 0},
    },
    {
        {0, 0, 0},
        {255, 255, 0},
        {0, 0, 0},
    },
    {
        {0, 0, 0},
        {255, 255, 0},
        {0, 255, 0},
    },
    {
        {0, 0, 0},
        {255, 255, 255},
        {0, 255, 0},
    },
    {
        {0, 0, 255},
        {255, 255, 255},
        {0, 255, 0},
    },
    
    {
        {0, 0, 255},
        {255, 255, 255},
        {255, 255, 0},
    },
    {
        {255, 0, 255},
        {255, 255, 255},
        {255, 255, 0},
    },
    {
        {255, 0, 255},
        {255, 255, 255},
        {255, 255, 255},
    },
    {
        {255, 255, 255},
        {255, 255, 255},
        {255, 255, 255},
    }
};

int get_average(int row, int column){
    int sum = grey_image[row][column] + grey_image[row][column + 1] + grey_image[row][column + 2]
            + grey_image[row + 1][column] + grey_image[row + 1][column + 1] + grey_image[row + 1][column + 2]
            + grey_image[row + 2][column] + grey_image[row + 2][column + 1] + grey_image[row + 2][column + 2];

    return sum / 9;    
} 

void fill_with_half_toned_color(int scale, int row, int column){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            grey_image[row + i][column + j] = half_tone_sets[scale][i][j];
        }
    }    

}

int get_scale(int average){
    int index;
    if (average <= 25)
        index = 0;
    else if (average <= 50)
        index = 1;
    else if (average <= 75)
        index = 2;
    
    // else if (average <= 100)
    //     index = 3;
    // else if (average <= 125)
    //     index = 4;
    // else if (average <= 150)
    //     index = 5;
    // else if (average <= 175)
    //     index = 6;
    // else if (average <= 200)
    //     index = 7;
    // else if (average <= 225)
    //     index = 8;
    // else 
    //     index = 9;

    return index;
}

int get_scale2(int average){
    int index;
    if (average <= 25)
        index = 0;
    else if (average <= 50)
        index = 1;
    else if (average <= 75)
        index = 2;

    for (int i = 75; i <= 225; i += 25)
    {
        if (average<= i)
            return index++;
    }

    return index;
}

void read_image(char* fname){
    FILE* image_file = fopen(fname, "r");
    char line[100];

    fgets(line, 100, image_file); //color
    fgets(line, 100, image_file); //comment
    int width, height, max_color_val;
    fscanf(image_file, "%d %d %d", &width, &height, &max_color_val);
    
    

    for (int i = 0; i < height; i++)
    {   
        for (int j= 0; j < width; j++ ){
            fscanf(image_file, "%d", &grey_image[i][j]);
        }
    }   

    // printf("%d %d\n", width, height);
  
    // for (int i = 0; i < height; i++){
    //     for (int j =0; j < width; j++)
    //         printf("%d ", image[i][j]);

    //     puts("");
    // }   
    

}

void halftone(char* fname){
    read_image(fname);

    for (int row = 0; row < HEIGHT; row += 3){
        for (int column = 0; column < WIDTH; column += 3){
            int average_color_value = get_average(row, column);
            int scale = get_scale(average_color_value);         
            fill_with_half_toned_color(scale, row, column);
        }
    }
}