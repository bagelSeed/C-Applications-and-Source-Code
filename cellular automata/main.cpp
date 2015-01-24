#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<bool> bvec;
typedef vector<bvec> bmatrix;

ostream &operator << (ostream &stream, bvec &vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        stream << vec[i];
    }
    return stream;
}

ostream &operator << (ostream &stream, bmatrix &matrix)
{
    for (int i = 0; i < (int) matrix.size(); i++)
    {
        stream << matrix[i] << endl;
    }
    return stream;
}

bmatrix grid, tempGrid;

void initGrid (int maxSize);
void runGame (int maxSize, int numStep);
bool getValue (int row, int col, int maxSize);

int main(int argc, const char *argv[])
{
    int maxSize, numStep;

    cout << "enter max size" << endl;
    cin >> maxSize;
    cout << "enter number of steps"<< endl;
    cin >> numStep;

    initGrid (maxSize);
    runGame (maxSize, numStep);

    return 0;
}
void initGrid (int maxSize)
{
    cout << "enter the data"<< endl;
    for (int row = 0; row < maxSize; row++)
    {
        string line;
        bvec bline;
        getline (cin, line);

        while (line.length() != maxSize)
        {
            cout << "re-enter line" << endl;
            getline (cin, line);
        }

        for (int col = 0; col < maxSize; col++)
        {
            if (line[col] == '0')
                bline.push_back(false);
            else
                bline.push_back(true);
        } // blien.push_back(line[col]=='0')

        grid.push_back(bline);
        tempGrid.push_back(bline);
    }
}
bool getValue (int row, int col, int maxSize)
{
    if (row < 0 || col < 0 || row >= maxSize || col >= maxSize)
        return false;

    return grid[row][col];
}
void runGame (int maxSize, int numStep)
{
    for (int i = 0; i < numStep; i++)
    {
        for (int row = 0; row < maxSize; row++)
        {
            for (int col = 0; col < maxSize; col ++)
            {
                int sum = 0;
                sum += getValue(row -1, col -1, maxSize);
                sum += getValue(row -1, col , maxSize);
                sum += getValue(row -1, col +1, maxSize);
                sum += getValue(row , col -1, maxSize);
                sum += getValue(row , col +1, maxSize);
                sum += getValue(row +1 , col -1, maxSize);
                sum += getValue(row +1 , col, maxSize);
                sum += getValue(row +1 , col +1, maxSize);

                if (grid[row][col] && sum < 2)
                    tempGrid[row][col] = false;
                else if (grid[row][col] && (sum == 2 || sum == 3))
                    tempGrid[row][col] = true;
                else if(grid[row][col] && sum > 3)
                    tempGrid[row][col] = false;
                else if (!grid[row][col] && sum == 3)
                    tempGrid[row][col] =  true;
                else
                    tempGrid[row][col] = false;
            }
        }

        for (int row = 0; row < maxSize ; row++)
        {
            for (int col = 0; col < maxSize; col++)
                grid[row][col] = tempGrid[row][col];
        }

        cout << "step " << i << " result is" << endl;
        cout << grid<< endl;
    }
}
