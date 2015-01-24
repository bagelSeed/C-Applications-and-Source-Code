#include <iostream>

using namespace std;

int fibnum(int term);

int main()
{
    int numTerms;
    do
    {
        cout << "enter the number terms" << endl;
        cin>>numTerms;
    }while (numTerms<=0);

    for(int i=1; i<=numTerms; i++)
    {
        int value;
        value = fibnum(i);
        cout<<"term "<<i<<" is "<<value<<endl;
    }
    return 0;
}

int fibnum(int term)
{
    if(term==1 || term==2)
        return 1;
    return fibnum(term-1)+fibnum(term-2);
}
