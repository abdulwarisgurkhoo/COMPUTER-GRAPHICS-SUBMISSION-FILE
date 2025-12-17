#include <graphics.h>
#include <stdio.h>

void drawEllipse(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, a, b;
    int x = 0, y;
    long a2, b2;
    long p1, p2;

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    a2 = a * a;
    b2 = b * b;
    y = b;

    // Region 1
    p1 = b2 - (a2 * b) + (a2 / 4);

    while ((2 * b2 * x) <= (2 * a2 * y))
    {
        drawEllipse(xc, yc, x, y);

        if (p1 < 0)
        {
            x++;
            p1 += (2 * b2 * x) + b2;
        }
        else
        {
            x++;
            y--;
            p1 += (2 * b2 * x) - (2 * a2 * y) + b2;
        }
    }

    // Region 2
    p2 = b2 * (x + 0.5) * (x + 0.5)
         + a2 * (y - 1) * (y - 1)
         - a2 * b2;

    while (y >= 0)
    {
        drawEllipse(xc, yc, x, y);

        if (p2 > 0)
        {
            y--;
            p2 -= (2 * a2 * y) + a2;
        }
        else
        {
            x++;
            y--;
            p2 += (2 * b2 * x) - (2 * a2 * y) + a2;
        }
    }

    getch();
    closegraph();
    return 0;
}

