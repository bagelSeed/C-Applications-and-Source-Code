//
//  main.cpp
//  simpleGraphC
//
//

#include <iostream>

using namespace std;

struct point
{
    double x;
    double y;
};

bool display[25][60];

double xLeft = -3.0;
double xRight = 3.0;
double yBottom = -1.0;
double yTop = 1.0;

int xNumTicks = 60;
int yNumTicks = 25;

double xScale;
double yScale;

void initDisplay();
void showDisplay();
void insertPoint(point pt);
double getPoly(double x);

int main (int argc, const char * argv[])
{
    //cout << "started " << endl;
    initDisplay();
    //cout << "finished initializing" << endl;
    for (double x = xLeft; x <= xRight; x+=0.05)
    {
        double y = getPoly(x);
        point pt;
        pt.x=x;
        pt.y=y;
        insertPoint(pt);
    }
    showDisplay();
    //cout << "ended " << endl;
    
    return 0;
}

void initDisplay()
{
    for (int row = 0; row < yNumTicks; row++)
    {
        for (int col = 0; col < xNumTicks; col++)
        {
            display[row][col] = false;
        }
    }
    
    xScale = (xRight - xLeft)/xNumTicks;
    yScale = (yTop - yBottom)/yNumTicks;
    
    //cout << "scale = " << xScale << ", " << yScale << endl;
    
    // draw the grid
    for (double x = xLeft; x <= xRight; x+= (xScale / 2))
    {
        //cout << "x = " << x << endl;
        point pt;
        pt.x=x;
        pt.y=0;
        insertPoint(pt);
    }
    
    for (double y = yBottom; y <= yTop; y+= (yScale / 2))
    {
        //cout << "y = " << y << endl;
        point pt;
        pt.x=0;
        pt.y=y;
        insertPoint(pt);
    }
}

void insertPoint(point pt)
{
    if (pt.x <= xLeft || pt.x >= xRight || pt.y <= yBottom || pt.y >= yTop)
    {
        return;
    }
    int col = (int)( (pt.x - xLeft) / xScale );
    int row = yNumTicks - (int)( (pt.y - yBottom) / yScale );
    display[row][col] = true;
    cout << "(" << pt.x << ", " << pt.y << ") at (row, col) = (" << row << ", " << col << ")" << endl;
}

void showDisplay()
{
    for (int row = 0; row < yNumTicks; row++)
    {
        for (int col = 0; col < xNumTicks; col++)
        {
            if (display[row][col])
            {
                cout << "*";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}

double getPoly(double x)
{
    return x * (x - 1) * (x + 1);
}
