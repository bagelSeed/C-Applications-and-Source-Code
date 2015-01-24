//
//  main.cpp
//  NumberSpiral
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<string> svec;
typedef vector<int> ivec;
typedef vector<ivec> imatrix;

svec spaces;

int maxStringSize(int n);
int getMaxRows(int num);
int getMaxCols(int num);
int getCentreX(int num);
int getCentreY(int num);

ostream & operator<<(ostream & stream, imatrix obj);

int main(int argc, const char * argv[])
{
    int num = 0;

    while (num <= 0)
    {
        cout << "Please enter the maximum number" << endl;
        cin >> num;
    }

    int maxSS = maxStringSize(num);

    string space;

    for (int i = 0; i <= maxSS; i++)
    {
        space += " ";
        spaces.push_back(space);
    }

    int maxRows = getMaxRows(num);
    int maxCols = getMaxCols(num);

    imatrix nums;

    for (int i = 0; i < maxRows; i++)
    {
        ivec row;
        for (int j = 0; j < maxCols; j++)
        {
            row.push_back(-1);
        }
        nums.push_back(row);
    }

    int x = getCentreX(num) - 1;
    int y = getCentreY(num);

    enum {right, up, left, down} dir;
    dir = right;
    int newMax = 2;
    for (int i = 1; i <= num; i++)
    {
        int sqrtNum = (int) sqrt(i);
        switch(dir)
        {
            case right:
                x++;
                if (i == newMax)
                {
                    dir = up;
                    newMax = sqrtNum * sqrtNum + sqrtNum + 1;
                }
                break;
            case up:
                y--;
                if (i == newMax)
                {
                    dir = left;
                    newMax = (sqrtNum + 1) * (sqrtNum + 1) + 1;
                }
                break;
            case left:
                x--;
                if (i == newMax)
                {
                    dir = down;
                    newMax = sqrtNum * sqrtNum + sqrtNum + 1;
                }
                break;
            case down:
                y++;
                if (i == newMax)
                {
                    dir = right;
                    newMax = (sqrtNum + 1) * (sqrtNum + 1) + 1;
                }
                break;
        }
        nums[y][x] = i;
    }

    for (int i = 0; i < maxRows; i++)
    {
        string line;
        for (int j = 0; j < maxCols; j++)
        {
            int value = nums[i][j];
            if (value > 0)
            {
                stringstream ss;
                ss << value;
                string valstr;
                ss >> valstr;
                line += spaces[maxSS - valstr.length()];
                line += valstr;
            }
            else
            {
                line += spaces[maxSS];
            }
        }
        cout << line << endl;
    }

    return 0;
}

int maxStringSize(int n)
{
    int retVal = 0;
    while (n > 0)
    {
        retVal++;
        n /= 10;
    }
    return retVal;
}

int getMaxRows(int num)
{
    int maxRows;
    int sqrtNum = (int) sqrt(num);
    if (num <= sqrtNum*(sqrtNum + 1))
    {
        maxRows = sqrtNum;
    }
    else
    {
        maxRows = sqrtNum + 1;
    }
    return maxRows;
}

int getMaxCols(int num)
{
    int maxCols;
    int sqrtNum = (int) sqrt(num);

    if (num == sqrtNum * sqrtNum)
    {
        maxCols = sqrtNum;
    }
    else
    {
        maxCols = sqrtNum + 1;
    }
    return maxCols;
}

int getCentreX(int num)
{
    int cen;
    int sqrtNum = (int) sqrt(num - 1);

    cen = sqrtNum / 2;

    return cen;
}

int getCentreY(int num)
{
    int cen = getMaxRows(num) / 2;

    return cen;
}

ostream & operator<<(ostream & stream, imatrix obj)
{
    ivec row = obj[0];
    int maxRows = (int) obj.size();
    int maxCols = (int) row.size();
    for (int i = 0; i < maxRows; i++)
    {
        ivec row = obj[i];
        for (int j = 0; j < maxCols; j++)
        {
            stream << row[j] << " ";
        }
        stream << endl;
    }
    return stream;
}
