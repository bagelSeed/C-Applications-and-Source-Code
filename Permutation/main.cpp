#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int fact(int num);
string enumPerm(int currentEnum, int ofFactorial, string input, vector<int> facts);

int main()
{
    int num;
    do
    {
        cout << "Enter a positive integer" << endl;
        cin >> num;
    }while(num<=0);

    string text;
    for(int i=1; i<=num;i++)
    {
        stringstream ss;
        char ch;
        ss <<i;
        ss >>ch;
        text+=ch;
    }
    vector<int> facts;
    int maxVal = fact(num);
    for(int i = num-1; i >=2; i--)
    {
        facts.push_back(fact(i));
    }
    for(int i = 0; i < maxVal; i++)
    {
        string currEnum = enumPerm(i, num, text, facts);
        cout<< "Enum "<< i+1 <<" is "<<currEnum<<endl;
    }
    return 0;
}
int fact(int num)
{
    int retVal = 1;
    if(num <0)
    {
        return -1;
    }
    for(int index = 1; index <=num; index++)
    {
        retVal *= index;
    }
    return retVal;
}

string enumPerm(int currentEnum, int ofFactorial, string input, vector<int> facts)
{
    string text;
    for(int i = 0; i < ofFactorial -2; i ++)
    {
        int arrIndex = currentEnum/facts[i];
        currentEnum -= facts[i]*arrIndex;
        char ch = input[arrIndex];
        text += ch;
        input.erase(arrIndex, 1);
    }
    if(currentEnum%2)
    {
        text += input[input.length()-1];
        text += input[input.length()-2];
    }
    else
    {
        text += input;
    }
    return text;
}
