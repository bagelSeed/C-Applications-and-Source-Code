#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> ivec;
typedef unsigned int uint32;

int binarySearch(ivec nums, int key);
ostream &operator<<(ostream &stream, ivec &obj);

int main()
{
    ivec nums;
    while(true)
    {
        int input;
        cout <<"enter a positive integer"<<endl;
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
        sort(nums.begin(), nums.end());
        int target;
        cout << "please enter target"<<endl;
        cin >> target;

        int position;
        position = binarySearch(nums, target);

        if(position >= 0)
        {
            cout << "the number "<< target << " is at position "<< position << " in "<< nums<<endl;
        }
        else
        {
            cout << "the number "<< target << " is not in the numbers "<<nums<<endl;
        }
    }
    else
    {
        cout <<"nothing to search for"<<endl;
    }
    return 0;
}

int binarySearch(ivec nums, int key)
{
    int first = 0;
    int last = nums.size() - 1;
    while (first <= last)
    {
        int mid = (first + last)/2;
        if(key > nums[mid])
            first = mid+1;
        else if (key < nums[mid])
            last = mid-1;
        else
            return mid;
    }
    return -1;
}

ostream &operator<<(ostream &stream, ivec &obj)
{
    for(uint32 index = 0; index < obj.size(); index++)
    {
        stream<<obj[index]<<" ";
    }
    return stream;
}
