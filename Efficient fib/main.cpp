#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> ivec;
ivec fibvec;
int fibon(int term);

int main()
{
    int numTerms;
    do
    {
        cout << "Enter num term" << endl;
        cin >> numTerms;
    }while(numTerms<=0);

    for(int i = 1; i<=numTerms; i++)
    {
        int value;
        value = fibon(i);
        cout <<value<<" is term "<< i<< endl;
    }
    return 0;
}

int fibon(int term)
{
    int retVal;
    if(fibvec.size()==0)
    {
        fibvec.push_back(1);
        fibvec.push_back(1);
    }

    if(term>fibvec.size())
    {
        retVal = fibon(term-1)+fibon(term-2);
        fibvec.push_back(retVal);
    }
    else
    {
        retVal = fibvec[term-1];
    }
    return retVal;
}
