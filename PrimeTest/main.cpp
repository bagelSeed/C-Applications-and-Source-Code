#include <iostream>

using namespace std;
bool isPrime(int num);

int main()
{
    int num;
    do
    {
        cout << "enter a positive integer"<<endl;
        cin >> num;
    }while(num<2);

    for (int index = 2; index <= num; index++)
    {
        bool numberPrime = isPrime(index);
        if(numberPrime)
        {
            cout <<index<<" is prime"<<endl;
        }
        else
        {
            cout<< index<<" is not prime"<<endl;
        }
    }
    return 0;
}
 bool isPrime(int num)
 {
     int numIsPrime = true;
     for (int i = 2; i <num; i++)
     {
         if(num%i==0)//factor
         {
            numIsPrime = false;
            break;
         }
     }
     return numIsPrime;
 }
