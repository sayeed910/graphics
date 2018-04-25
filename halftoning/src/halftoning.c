#define WIDTH 900
#define HEIGHT 600
#include <stdio.h>

typedef struct
{
    double r;
    double g;
    double b;
} Pixel;
int width, height;
double grey_image[HEIGHT][WIDTH] = {0};
Pixel color_image[HEIGHT][WIDTH];
double halftone_image[HEIGHT][WIDTH] = {0};

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
    }};

int get_average(int row, int column)
{
    int sum = grey_image[row][column] + grey_image[row][column + 1] + grey_image[row][column + 2] + grey_image[row + 1][column] + grey_image[row + 1][column + 1] + grey_image[row + 1][column + 2] + grey_image[row + 2][column] + grey_image[row + 2][column + 1] + grey_image[row + 2][column + 2];

    return sum / 9;
}

void fill_with_half_toned_color(int scale, int row, int column)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            halftone_image[row + i][column + j] = half_tone_sets[scale][i][j];
        }
    }
}

int get_scale(int average)
{
    int index;
    if (average <= 25)
        index = 0;
    else if (average <= 50)
        index = 1;
    else if (average <= 75)
        index = 2;

    else if (average <= 100)
        index = 3;
    else if (average <= 125)
        index = 4;
    else if (average <= 150)
        index = 5;
    else if (average <= 175)
        index = 6;
    else if (average <= 200)
        index = 7;
    else if (average <= 225)
        index = 8;
    else
        index = 9;

    return index;
}

// int get_scale2(int average)
// {
//     int index = 0;

//     for (int i = 25; i <= 225; i += 25)
//     {
//         if (average <= i)
//             return index++;
//     }

//     return index;
// }

void read_image(char *fname)
{
    FILE *image_file = fopen(fname, "r");
    char line[100];

    fgets(line, 100, image_file); //color
    fgets(line, 100, image_file); //comment
    int width, height, max_color_val;
    fscanf(image_file, "%d %d %d", &width, &height, &max_color_val);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
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

void make_grey()
{

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            // printf()
            grey_image[i][j] = (color_image[i][j].b + color_image[i][j].r + color_image[i][j].g) / 3;

        }
    }
}

void readBMP(char *filename)
{

    int i;
    FILE *f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
    // extract image height and width from header
    width = *(int *)&info[18];
    height = *(int *)&info[22];

    int size = 3 * width * height;
    unsigned char data[size];                   // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

    for (i = 0; i < size; i += 3)
    {
        unsigned char tmp = data[i];
        data[i] = data[i + 2];
        data[i + 2] = tmp;
    }

    int data_idx = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            Pixel p;
            p.r = (int)data[data_idx] ;
            p.g = (int)data[data_idx + 1];
            p.b = (int)data[data_idx + 2] ;
            data_idx += 3;
            color_image[i][j] = p;


        }
    }

    puts("Done");
}

void halftone(char *fname)
{
    readBMP(fname);
    make_grey();

    for (int row = 0; row < height; row += 3)
    {
        for (int column = 0; column < width; column += 3)
        {
            int average_color_value = get_average(row, column);
            int scale = get_scale(average_color_value);
            fill_with_half_toned_color(scale, row, column);
        }
    }
}

