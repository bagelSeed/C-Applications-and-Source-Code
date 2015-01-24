#include <iostream>

using namespace std;
int gcd(int quotient, int remainder);

int main()
{
    int a,b;
    cout << "enter 2 integer" << endl;
    cin>>a;
    cin>>b;
    int largePos;
    int smallPos;
    largePos=(a<0)?-a:a;
    smallPos=(b<0)?-b:b;
    if(largePos<smallPos)
    {
        int temp = largePos;
        largePos = smallPos;
        smallPos = temp;
    }
    cout<<"the gcd of "<< a <<" and "<<b<<" is "<<gcd(largePos, smallPos)<<endl;
    return 0;
}

int gcd(int quotient, int remainder)
{
    if(remainder == 0)
        return quotient;
    return gcd(remainder, quotient%remainder);
}
