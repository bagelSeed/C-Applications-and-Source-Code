#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef vector <int> ivec;
typedef vector <ivec> imatrix;

struct cellInfo
{
    int maxRows;
    int maxCols;
    int maxValues;
};

struct location
{
    int row;
    int col;
};

ostream &operator<<(ostream &stream, imatrix &obj)
{
    for(int i =0; i<(int)obj.size(); i++)
    {
        for(int j=0; j<(int)obj[i].size(); j++)
        {
            stream <<obj[i][j]<<" ";
        }
        stream<<endl;
    }
    return stream;
}

cellInfo getCellInfo();
void initMatrix(imatrix &cells, imatrix &zeros, cellInfo info);
void changeConnected(imatrix &cells, imatrix &result, int r, int c, int value);
location getLocation();

int main()
{
    srand((int)time(0));
    imatrix cells;
    imatrix result;
    cellInfo cInfo;
    location cLoc;
    cInfo = getCellInfo();
    initMatrix (cells, result, cInfo);
    cLoc = getLocation();
    int value = cells[cLoc.row][cLoc.col];
    changeConnected(cells, result, cLoc.row, cLoc.col, value);
    cout <<"the connected cells of "<< endl;
    cout << cells<<endl<<" are "<<endl;
    cout << result<<endl;

    return 0;
}

cellInfo getCellInfo()
{
    cellInfo retVal;
    int maxRows, maxCols, maxVal;
    cout <<"enter max row"<<endl;
    cin >> maxRows;
    cout <<"enter max col"<<endl;
    cin >> maxCols;
    cout <<"enter max val"<<endl;
    cin >> maxVal;
    retVal.maxRows= maxRows;
    retVal.maxCols= maxCols;
    retVal.maxValues= maxVal;
    return retVal;
}

void initMatrix(imatrix &cells, imatrix &zeros, cellInfo info)
{
    for (int i = 0; i < info.maxRows; i++)
    {
        ivec cRow, zeroRow;
        for(int j=0; j<info.maxCols; j++)
        {
            int cVal=rand()%info.maxValues+1;
            cRow.push_back(cVal);
            zeroRow.push_back(0);
        }
        cells.push_back(cRow);
        zeros.push_back(zeroRow);
    }
}

location getLocation()
{
    int row;
    int col;
    location retVal;
    cout <<"enter the row"<<endl;
    cin >> row;
    cout <<"enter the column"<<endl;
    cin >> col;
    retVal.row = row;
    retVal.col = col;
    return retVal;
}

void changeConnected(imatrix &cells, imatrix &result, int r, int c, int value)
{
    int maxRow = (int)cells.size();
    int maxCol = (int)cells[0].size();
    if(r<0 || c<0 || r>= maxRow || c>=maxCol)
        return;
    if((cells[r][c]==value) && (result[r][c]!=1))
    {
        result[r][c]=1;
        changeConnected(cells, result, r-1, c, value);
        changeConnected(cells, result, r+1, c, value);
        changeConnected(cells, result, r, c-1, value);
        changeConnected(cells, result, r, c+1, value);
    }
}
