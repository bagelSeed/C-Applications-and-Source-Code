#include <iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
    int a, b;
    cout << "Enter two integer" << endl;
    cin >> a;
    cin >> b;

    cout << "the gcd of "<<a<< " and "<<b<< " is "<< gcd(a, b)<<endl;

    return 0;
}

int gcd(int a, int b)
{
    //change to positive
    if(a<0)
    {
        a = -a;
    }
    if(a<0)
    {
        b = -b;
    }
    //swap if wrong order
    if(a < b)
    {
        int temp = 1;
        a = b;
        b = temp;
    }
    if(b == 0)
        return a;
    int lastRemainder = b, remainder = a%b, quotient;
    while(remainder != 0)
    {
        lastRemainder = remainder;
        quotient = a/b;
        remainder = a%b;
        b = remainder;
    }
    return lastRemainder;
}
