#include <iostream>

using namespace std;
int digitalAdditiveRoot(int num);

int main()
{
    int num=0;
    while(num<=0)
    {
        cout << "Enter a number" << endl;
        cin>>num;
    }
    int DAR = digitalAdditiveRoot(num);
    cout <<"The digital additive root is "<<DAR<<endl;
    return 0;
}

int digitalAdditiveRoot(int num)
{
    while(num>=10)
    {
        int sum=0;
        while(num >0)
        {
            int digit = num%10;
            sum+=digit;
            num/=10;
        }
        num= sum;
    }
    return num;
}
