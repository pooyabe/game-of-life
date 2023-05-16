#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void draw(void *pworld, int w, int h)
{
    // Clear the screen if works!
    system("clear");
    // if the above code does not work, use below instead
    // printf("\033[H");

    char(*world)[w] = pworld;

    // Print the board, like any other arrays.
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
            printf("%c", world[x][y] ? '+' : '.');
        printf("\n");
    }
}

void give_life(void *pworld, int w, int h)
{
    char(*world)[w] = pworld,
    new_world[w][h]; // New world for storing the analizes on the current world;

    // int lives; // for counting the number of living neighbors

    // Browse all items and one item arround
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
        {
            int lives = 0;
            // xa means the x around this element. and ya so on
            for (int xa = x - 1; xa <= x + 1; xa++)
                for (int ya = y - 1; ya <= y + 1; ya++)
                    if (world[(ya + h) % h][(xa + w) % w])
                        lives++;
            
            if (world[y][x])
                lives--;

            // Create the new world at this element
            new_world[y][x] = (lives == 3 || (lives == 2 && world[y][x]));
        }

    // Seed the main world based on the new world
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
            world[x][y] = new_world[x][y];
}

int main()
{
    // Declear the variables
    int width = 30, height = width;
    char world[width][height];

    // Get the time for sleep
    int sleep_time;
    printf("Enter a sleep time between 1 to 10 (1 is fastest. 100 slowest) :");
    scanf("%d", &sleep_time);

    sleep_time *= 100000;

    // Seed the random generator with time
    srand(time(NULL));

    // Seed the world
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            world[x][y] = rand() % 11 < 2 ? 1 : 0; // Randomly seed the world homes

    while (1)
    {
        // Draw the world
        draw(world, width, height);
        // The beginning of creation and moving on
        give_life(world, width, height);

        // get some rest in 6th day. or maybe 7 i dont now much about it!
        usleep(sleep_time);
    }

    // Some additional line breaks
    printf("\n\n\n");
    return 0;
}