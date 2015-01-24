#include <iostream>
#include <string>

using namespace std;
string LSystem(string curr);

int main()
{
    int num;
    cout << "enter max num of iterations" << endl;
    cin >>num;

    int count=0;
    string cur="A";
    cout <<count<<":"<<cur<<endl;
    while(count<num)
    {
        count++;
        cur=LSystem(cur);
        cout<<count<<":"<<cur<<endl;
    }
    return 0;
}

string LSystem(string curr)
{
    string next;
    for(int i =0; i<(int)curr.length(); i++)
    {
        char ch=curr[i];
        switch(ch)
        {
            case'A':
                next+="AB";
                break;
            case'B':
                next+="A";
                break;
            default:
                break;
        }
    }
    return next;
}
