// Assignment No. 3
// Name : Magdum Pirjade
// RollNo. : COSC28
// Batch : c3
// INPUT :
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
class pixel
{
    int X, Y, c; // to draw a pixel
public:
    void drawpixel(int x, int y, int color)
    {
        X = x;
        Y = y;
        c = color;
        putpixel(X, Y, c);
    }
};
class linealgo : public pixel // to draw a line
{
    int x1, x2, y1, y2;

public:
    linealgo(int X1, int Y1, int X2, int Y2)
    {
        x1 = X1;
        y1 = Y1;
        x2 = X2;
        y2 = Y2;
    }
    void drawline(int);
    int sign(float);
};
int linealgo::sign(float arg)
{
    if (arg < 0)
        return -1;
    else if (arg == 0)
        return 0;
    else
        return 1;
}
void linealgo::drawline(int color) // breshnam line drawing algo
{
    int s1, s2, exhg, y, x, i;
    float dx, dy, p, temp;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;
    s1 = sign(x2 - x1);
    s2 = sign(y2 - y1);
    if (dy > dx) // to make the symmetry of line
    {
        temp = dx;
        dx = dy;
        dy = temp;
        exhg = 1;
    }
    else
    {
        exhg = 0;
    }
    p = 2 * dy - dx;
    i = 1;
    while (i <= dx)
    {
        drawpixel(x, y, color);
        while (p >= 0)
        {
            if (exhg == 1)
                x = x + s1;
            else
                y = y + s2;
            p = p - 2 * dx;
        }
        if (exhg == 1)
            y = y + s2;
        else
            x = x + s1;
        p = p + 2 * dy;
        i++;
    }
}
class circlealgo : public pixel
{
    int x, y, r; // breshnam circle drawing algo
public:
    circlealgo(int X, int Y, int R)
    {
        x = X;
        y = Y;
        r = R;
    }
    void drawcircle();
};
void circlealgo::drawcircle()
{
    int d, x1, y1;
    x1 = 0;
    y1 = r;
    drawpixel(x, y, 2);
    d = 3 - (2 * r);
    while (x1 <= y1)
    {
        if (d <= 0)
        {
            d = d + (4 * x1) + 6;
            x1 = x1 + 1;
        }
        else
        {
            d = d + 4 * (x1 - y1) + 10;
            x1 = x1 + 1;
            y1 = y1 - 1;
        }
        drawpixel(x + x1, y - y1, 2);
        drawpixel(x - x1, y - y1, 2);
        drawpixel(x + x1, y + y1, 2);
        drawpixel(x - x1, y + y1, 2);
        drawpixel(x + y1, y - x1, 2);
        drawpixel(x - y1, y - x1, 2);
        drawpixel(x + y1, y + x1, 2);
        drawpixel(x - y1, y + x1, 2);
    }
}
int main()
{
    int l, xc, yc, a, b, c, u, v, r2, r1;
    cout << "\nEnter the length of equilateral triangle" << endl;
    cin >> l;
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    xc = 640; // coordinates of display screen
    yc = 480;
    xc = xc / 2;
    yc = yc / 2;
    // to calculate centre and co ordiantes of incircle centre==(xc,yc);
    r1 = (float)(sqrt(3) * l) / 6; // mathmatical formula to calculate radiuis of incircle
    // to calculate centre and co ordiantes of circumcircle centre==(xc,yc);
    a = xc - (float)(l / 2); // coordinates of lines
    b = yc + r1;
    c = xc + (float)(l / 2);
    r2 = (float)(sqrt((a - xc) * (a - xc) + (b - yc) * (b - yc))); // radius of circum circle
    // drawing triangle
    linealgo l1(a, b, c, b); // bottom edge
    l1.drawline(3);
    delay(200);
    u = xc; // top coordinate of triangle
    v = float(yc - r2);
    linealgo l2(a, b, u, v); // left edge
    l2.drawline(3);
    delay(200);
    linealgo l3(c, b, u, v); // right edge
    l3.drawline(3);
    delay(200);
    circlealgo c1(xc, yc, r1); // incircle
    c1.drawcircle();
    delay(2000);
    circlealgo c2(xc, yc, r2); // circumcircle
    c2.drawcircle();
    delay(200);
    getch();
    closegraph();
    return 0;
}
OUTPUT : Assignment No .1 Name : Satyam Shinde
                                     RollNo. : COSC28
                                                   Batch : B2
                                                               INPUT :
#include <iostream>
#include <graphics.h> //graphics.h library is used to include graphical operations in a program.
#include <math.h>
    using namespace std;
class scan
{
public:
    int x[20], y[20], k;
    float slope[20], x_int[20];
    void polygon(int n);
};
void scan::polygon(int n)
{
    int i;
    float dx, dy;
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 0; i < n; i++) // draw all lines (edges of polygon)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]); // line cordinates x1,y1,x2,y2
    }
    for (i = 0; i < n; i++) // finding slope of all lines
    {
        dy = y[i + 1] - y[i]; // dy=y2-y1
        dx = x[i + 1] - x[i]; // dx=x2-x1
        if (dy == 0)
            slope[i] = 1;
        else if (dx == 0)
            slope[i] = 0;
        else
            slope[i] = dx / dy;
    }
    // finding intersection points
    for (int p = 0; p < 480; p++) // consider 480 horizontal lines on screen
    {
        k = 0;
        for (i = 0; i < n; i++)
        {
            if (((y[i] <= p) && (y[i + 1] > p)) || ((y[i] > p) && (y[i + 1] <= p)))
            {
                x_int[k] = x[i] + slope[i] * (p - y[i]); // find out intersection points using formula
                k++;
            }
        }
        for (int j = 0; j < k - 1; j++) // perform sorting of intersection points on x direction
        {
            for (int i = 0; i < k - 1; i++)
            {
                if (x_int[i] > x_int[i + 1])
                {
                    int temp = x_int[i];
                    x_int[i] = x_int[i + 1];
                    x_int[i + 1] = temp;
                }
            }
        }
        for (int i = 0; i < k; i = i + 2) // fill points of line that are interior to polygon
        {
            setcolor(RED);
            line(x_int[i], p, x_int[i + 1], p); // x1,y1,x2,y2
            delay(10);
        }
    }
}
int main()
{
    int n, i;
    scan p;
    cout << "Enter edge : \t";
    cin >> n;
    cout << "\n\nEnter Coordinates : \t";
    for (i = 0; i < n; i++)
    {
        cin >> p.x[i] >> p.y[i];
    }
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    p.polygon(n);
    getch();
    closegraph();
    return 0;
}
