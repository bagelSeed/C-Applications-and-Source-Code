#include <iostream>

using namespace std;

class display
{
    public:
        void initDisplay();
        void showDisplay();
        void insertPoint(double x, double y);
        //helper functions
        double getLeft();
        double getRight();
    private:
        bool display[25][60];
        double xLeft, xRight, yBottom, yTop;
        int xNumTicks, yNumTicks;
        double xScale, yScale;
};

double getPoly(double x)
{
    return x*(x-1)*(x+1);
}

int main()
{
    display disp;
    disp.initDisplay();
    for (double x = disp.getLeft(); x <= disp.getRight(); x+=0.05)
    {
        double y = getPoly(x);
        disp.insertPoint(x,y);
    }
    disp.showDisplay();
    return 0;
}

void display::initDisplay()
{
    xLeft=-3.0;
    xRight=3.0;
    yBottom=-1.0;
    yTop=1.0;
    xNumTicks= 60;
    yNumTicks= 25;
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
        insertPoint(x, 0);
    }

    for (double y = yBottom; y <= yTop; y+= (yScale / 2))
    {
        //cout << "y = " << y << endl;
        insertPoint(0, y);
    }
}

void display::insertPoint(double x, double y)
{
    if (x <= xLeft || x >= xRight || y <= yBottom || y >= yTop)
    {
        return;
    }
    int col = (int)( (x - xLeft) / xScale );
    int row = yNumTicks - (int)( (y - yBottom) / yScale );
    display[row][col] = true;
    //cout << "(" << pt.x << ", " << pt.y << ") at (row, col) = (" << row << ", " << col << ")" << endl;
}

void display::showDisplay()
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

double display::getLeft()
{
    return xLeft;
}
double display::getRight()
{
    return xRight;
}
