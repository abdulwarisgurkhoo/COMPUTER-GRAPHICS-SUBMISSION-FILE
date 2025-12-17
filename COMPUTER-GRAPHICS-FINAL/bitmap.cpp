#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

 int arr[7][4]={{0,1,1,0},
                {1,0,0,1},
                {1,0,0,1},
                {1,0,0,1},
                {1,0,0,1},
                {1,0,0,1},
                {0,1,1,0}};
 int x0 = 200, y0 = 200;   // starting position
    int scale = 10;          // pixel size

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 1)
            {
                // draw scaled pixels
                for (int x = 0; x < scale; x++)
                    for (int y = 0; y < scale; y++)
                        putpixel(x0 + j*scale + x,
                                 y0 + i*scale + y,
                                 WHITE);
            }
        }
    }
    getch();
    closegraph();

}
