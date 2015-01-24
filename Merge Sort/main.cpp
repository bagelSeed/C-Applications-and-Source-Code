#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef vector <int> ivec;

void mergeSort(ivec &nums);
void mergeSortPartial(ivec &nums, int start, int end);
void merge(ivec &nums, int start1, int start2, int end);
ostream &operator<<(ostream &stream, ivec &obj)
{
    for(int i=0; i<(int)obj.size(); i++)
    {
        stream <<obj[i]<<" ";
    }
    return stream;
}

int main()
{
    ivec nums;
    int maxNum = 10000;
    srand((int)time(0));
    for(int i=0; i<maxNum; i++)
    {
        nums.push_back(rand()%maxNum);
    }
    mergeSort(nums);
    cout <<"the numbers are "<<nums<<endl;
    return 0;
}
void mergeSort(ivec &nums)
{
    mergeSortPartial(nums, 0, (int)nums.size()-1);
}

void mergeSortPartial(ivec &nums, int start, int end)
{
    if(start<end)
    {
        int middle = (start+end)/2;
        mergeSortPartial(nums, start, middle);
        mergeSortPartial(nums, middle+1, end);
        merge(nums, start, middle, end);
    }
}

void merge(ivec &nums, int start1, int start2, int end)
{
    int len1, len2;
    int sentinal= numeric_limits<int>::max();
    len1 = start2-start1+1;
    len2 = end - start2;
    ivec left, right;
    for(int i = 0; i<len1; i++)
    {
        int temp = nums[start1+i];
        left.push_back(temp);
    }
    left.push_back(sentinal);
    start2++;
    for(int j = 0; j<len2; j++)
    {
        int temp = nums[start2+j];
        right.push_back(temp);
    }
    right.push_back(sentinal);
    int leftIndex=0;
    int rightIndex=0;
    for(int i = start1; i<=end; i++)
    {
        if(left[leftIndex]<=right[rightIndex])
        {
            nums[i]=left[leftIndex];
            leftIndex++;
        }
        else
        {
            nums[i]=right[rightIndex];
            rightIndex++;
        }
    }
}
