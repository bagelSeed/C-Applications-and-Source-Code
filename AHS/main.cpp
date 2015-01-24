#include <iostream>

using namespace std;

int main()
{
    int numTerms = 0;
    float sumForward = 0, sumBackward = 0;
    while(numTerms<=0)
    {
        cout << "Enter the number of terms"<<endl;
        cin >> numTerms;
    }
    float negative;
    for(int index = 1; index <= numTerms; index++)
    {
        negative = (index%2)?1.0:-1.0;
        sumForward += negative*1.0/(float)index;//converting index to float
    }
    for(int index = numTerms; index >= 1; index--)
    {
        negative = (index%2)?1.0:-1.0;
        sumBackward += negative*1.0/(float)index;
    }

    cout <<numTerms<<" terms, the forward sum is "<<sumForward<< " and the backward sum is "<<sumBackward<<endl;

    return 0;
}
