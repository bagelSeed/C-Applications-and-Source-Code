#include <iostream>

using namespace std;

struct point
{
    double x, y;
};
bool display[25][60];
double xleft=-3.0;
double xright=3.0;
double ybottom=-1.0;
double ytop=1.0;
int xNumTicks=60;
int yNumTicks=25;
double xScale;
double yScale;
void initDisplay();
void showDisplay();
void insertPoint(point pt);
double getPoly(double x);
int main()
{
    initDisplay();
    for(double x =xleft; x<=xright; x+=0.5)
    {
        double y=getPoly(x);
        point pt;
        pt.x=x;
        pt.y=y;
        insertPoint(pt);
    }
    showDisplay();
    return 0;
}
void initDisplay()
{
    for(int row =0; row<=yNumTicks; row++)
    {
        for(int col=0; col<xNumTicks;col++)
        {
            display[row][col]=false;
        }
    }
    xScale=(xright-xleft)/xNumTicks;
    yScale=(ytop-ybottom)/yNumTicks;
    for(double x=xleft; x<=xright; x+=(xScale/2))
    {
        point pt;
        pt.x = x;
        pt.y = 0;
        insertPoint(pt);
    }
    for(double y=ybottom; y<=ytop; y+=(yScale/2))
    {
        point pt;
        pt.x=0;
        pt.y=y;
        insertPoint(pt);
    }
}

void insertPoint(point pt)
{
    if(pt.x<=xleft || pt.x>=xright || pt.y<=ybottom || pt.y>=ytop)
    {
        return;
    }
    int col=(int)((pt.x-xleft)/xScale);
    int row=yNumTicks-(int)((pt.y-ybottom)/yScale);
    display[row][col]=true;
}

void showDisplay()
{
    for(int row=0; row<yNumTicks; row++)
    {
        for(int col=0; col<xNumTicks; col++)
        {
            if(display[row][col])
                cout<<"*";
            else
                cout<<".";
        }
        cout<<endl;
    }
}

double getPoly(double x)
{
    return x*(x-1)*(x+1);
}
