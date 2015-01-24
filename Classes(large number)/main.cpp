#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef vector<int> ivec;
typedef unsigned int uint32;

class largeNum
{
    public:
        largeNum();//~largeNum(); = destructor
        largeNum(string str);
        void fromString(string str);
        ivec getVec();
        void addFromLargeNum(largeNum Num);
        friend ostream &operator<<(ostream &stream, largeNum &obj);
    private:
        ivec mNumber;
};

//helper functions
ivec ivecCopy(ivec num);
ivec prePadZeros(ivec num, int numZeros);
largeNum :: largeNum()
{
}

int main()
{
    string inNum;
    cout<<"enter a number"<<endl;
    getline(cin, inNum);
    largeNum num1(inNum);
    cout <<"enter another number"<<endl;
    getline(cin, inNum);
    largeNum num2(inNum);
    cout <<"adding "<<num1<<"+"<<num2;
    num1.addFromLargeNum(num2);
    cout <<" = "<<num1<<endl;
    return 0;
}

largeNum::largeNum(string str)
{
    fromString(str);
}

void largeNum::fromString(string str)
{
    mNumber.empty();
    for(uint32 i=0; i<str.length(); i++)
    {
        stringstream ss;
        char letter=str[i];
        int digit;
        ss<<letter;
        ss>>digit;
        mNumber.push_back(digit);
    }
}

ivec largeNum::getVec()
{
    return mNumber;
}

ostream &operator<<(ostream &stream, largeNum &obj)
{
    for(uint32 i=0; i<obj.mNumber.size(); i++)
    {
        stream<<obj.mNumber[i];
    }
    return stream;
}

void largeNum::addFromLargeNum(largeNum Num)
{
    ivec result;
    ivec numSmall, numLarge;

    numLarge=ivecCopy(mNumber);
    numSmall=Num.getVec();
    int sizeDiff=(int)numLarge.size()-(int)numSmall.size();
    if(numLarge.size()>numSmall.size())
    {
        numSmall=prePadZeros(numSmall, sizeDiff);
    }
    else
    {
        numLarge=prePadZeros(numLarge, -sizeDiff);
    }
    int carry=0;
    for(int i=(int)numLarge.size()-1; i>=0; i--)
    {
        int sum = numLarge[i]+numSmall[i]+carry;
        carry = sum/10;
        result.insert(result.begin(), sum%10);
    }
    if(carry)
        result.insert(result.begin(),carry);
    mNumber=ivecCopy(result);
}

ivec ivecCopy(ivec num)
{
    return num;
}

ivec prePadZeros(ivec num, int numZeros)
{
    for(int i = 0; i<numZeros; i++)
    {
        num.insert(num.begin(), 0);
    }
    return num;
}
