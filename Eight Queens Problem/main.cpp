#include <iostream>
#include <vector>
#include <cstdlib>//for absolute value

using namespace std;

typedef vector<int> ivec;
typedef vector<ivec> imatrix;
imatrix solutions;

ostream &operator<<(ostream &stream, ivec &vec)
{
    for (int i = 0; i<(int)vec.size(); i++)
    {
        stream<<vec[i]<<" ";
    }
    return stream;
}

ostream &operator<<(ostream &stream, imatrix &matrix)
{
    for(int i=0; i<(int)matrix.size(); i++)
    {
        stream<<matrix[i]<<endl;
    }
    return stream;
}

void queens(int maxSize);
void backTrack(ivec &queens, int currRow, int maxSize);
bool constructCandidates(ivec &queens, int row, int maxSize, ivec &candidates);
bool isSafeSquare(ivec &queens, int row, int col, int maxSize);
bool isSolution(ivec &queens, int maxSize);

int main()
{
    int maxSize = 8;
    queens(maxSize);
    cout<<"there are "<<solutions.size()<<" solutions"<<endl;
    cout<<solutions<<endl;
    return 0;
}

void queens(int maxSize)
{
    ivec queens;
    backTrack(queens, 0, maxSize);
}

void backTrack(ivec &queens, int currRow, int maxSize)
{
    if (isSolution(queens, maxSize))
    {
        solutions.push_back(queens);
    }
    else
    {
        ivec candidates;
        if (constructCandidates(queens, currRow, maxSize, candidates))
        {
            for(int i = 0; i<(int)candidates.size(); i++)
            {
                //partial solution
                queens.push_back(candidates[i]);
                backTrack(queens, currRow+1, maxSize);
                //candidates is longer any good
                queens.pop_back();
            }
        }
    }
}

bool constructCandidates(ivec &queens, int row, int maxSize, ivec &candidates)
{
    for(int i=0; i<maxSize; i++)
    {
        if(isSafeSquare(queens, row, i, maxSize))
        {
            candidates.push_back(i);
        }
    }
    return candidates.size()>0;
}

bool isSafeSquare(ivec &queens, int row, int col, int maxSize)
{
    for(int i =0; i<(int)queens.size(); i++)
    {
        if(i==row||queens[i]==col)
        {
            return false;
        }
        if(abs(i-row)==abs(queens[i]-col))
        {
            return false;
        }
    }
    return true;
}

bool isSolution(ivec &queens, int maxSize)
{
    return (int)queens.size()==maxSize;
}
