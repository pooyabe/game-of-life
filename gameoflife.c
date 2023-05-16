#include <stdio.h>

int main()
{
    // Declear the variables
    int width = 30, height = width;
    char world[width][height];

    // Seed the world
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            world[x][y] = 1;
    

    return 0;
}