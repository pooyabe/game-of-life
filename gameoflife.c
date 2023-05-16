#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Seed the random generator with time
    srand(time(NULL));

    // Seed the world
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            world[x][y] = rand() % 11 < 5 ? '+' : '.'; // Randomly seed the world homes

    // Draw the first world
    draw(world, width, height);

    // Some additional line breaks
    printf("\n\n\n");
    return 0;
}