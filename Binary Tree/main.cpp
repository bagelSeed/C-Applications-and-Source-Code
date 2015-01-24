#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    node *root=NULL;
    node *current=NULL;
    int value;
    while (true)
    {
        cout <<"enter an integer, 0 to quit"<<endl;
        cin >> value;
        if (value == 0)
            break;
        current = insert(value, &root);
    }
    cout <<"the values are"<<endl;
    printTree(root);
    destroy(root);
    return 0;
}
