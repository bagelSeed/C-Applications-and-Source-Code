#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> ivec;
ostream &operator<<(ostream &stream, ivec &object);
void insertionSort(ivec &nums);

int main()
{
    ivec nums;
    while(true)
    {
        int input;
        cout <<"enter an int, 0 to quit"<<endl;
        cin >> input;
        if(input == 0)
            break;
        else
        {
            nums.push_back(input);
        }
    }
    if(nums.size())
    {
        insertionSort(nums);
        cout <<"the numbers are "<<nums<<endl;
    }
    else
        cout <<"nothing to sort"<<endl;
    return 0;
}

ostream &operator<<(ostream &stream, ivec &object)
{
    for(int i=0; i<(int)object.size(); i++)
        stream<<object[i]<<" ";
    return stream;
}

void insertionSort(ivec &nums)
{
    int len = (int)nums.size();
    for(int i = 1; i<len; i++)
    {
        int key = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>key)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}
