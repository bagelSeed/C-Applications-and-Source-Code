#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> ivec;
typedef unsigned int uint32;

int linearSearch(ivec &nums, int key);//num = int of numbers, key = searching for
ostream &operator<<(ostream &stream, ivec &obj);

int main()
{
    ivec nums;
    while(true)
    {
        int input;
        cout <<"enter an integer"<<endl;
        cout <<"0 = quit"<<endl;
        cin >> input;
        if (input <= 0)
        {
            break;
        }
        nums.push_back(input);
    }
    if(nums.size())
    {
        int target;
        cout << "please enter target"<<endl;
        cin >> target;

        int position;
        position = linearSearch(nums, target);

        if(position >= 0)
        {
            cout << "the number target has position "<< position << " in the numbers "<<nums<<endl;
        }
        else
        {
            cout << "the number "<<target<< " is not in the numbers "<<nums<<endl;
        }
    }
    else
    {
        cout <<"nothing to search for"<<endl;
    }

    return 0;
}

int linearSearch(ivec &nums, int key)
{
    int position = -1;
    for(uint32 index = 0; index < nums.size(); index++)
    {
        if(nums[index]==key)
        {
            position = index;
            break;
        }
    }
    return position;
}

ostream &operator<<(ostream &stream, ivec &obj)
{
    for(uint32 index = 0; index < obj.size(); index++)
    {
        stream<<obj[index]<<" ";
    }
    return stream;
}
