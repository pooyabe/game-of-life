#include <stdio.h>

void draw(void *pworld, int w, int h)
{
    char(*board)[w] = pworld;

    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
            printf("%c", board[x][y]);
        printf("\n");
    }
}

int main()
{
    // Declear the variables
    int width = 30, height = width;
    char world[width][height];

    // Seed the world
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            world[x][y] = '+';

    // Draw the first world
    draw(world, width, height);


    // Some additional line breaks
    printf("\n\n\n");
    return 0;
}