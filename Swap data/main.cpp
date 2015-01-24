#include <iostream>

using namespace std;

void swapNum(int *first, int *second);
int main()
{
    int a,b;
    cout << "get integer #1" << endl;
    cin>>a;
    cout <<"get integer #2"<<endl;
    cin>>b;
    cout <<"a ="<<a<< " b ="<<b<<endl;
    swapNum(&a,&b);
    cout <<"a ="<<a<< " b ="<<b<<endl;
    return 0;
}

void swapNum(int *first, int *second)
{
    int temp;
    temp = *second;
    *second = *first;
    *first = temp;

}
