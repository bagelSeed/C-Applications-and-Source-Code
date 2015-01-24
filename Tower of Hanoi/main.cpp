#include <iostream>

using namespace std;
void tower(int num, int source, int destination, int storage);
int main()
{
    int numDiscs;
    do
    {
        cout <<"enter the number of discs"<<endl;
        cin >> numDiscs;
    }while(numDiscs<=0);
    tower (numDiscs,1,2,3);
    return 0;
}
void tower(int num, int source, int destination, int storage)
{
    if(num>0)
    {
        tower(num-1, source, storage, destination);
        cout<<"moved top disc from "<<source<<" to "<<destination<<endl;
        tower(num-1, storage, destination, source);
    }
}
