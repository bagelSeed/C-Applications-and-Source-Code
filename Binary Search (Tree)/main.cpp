#include <iostream>
#include "BinaryTree.h"

using namespace std;

node *search(int key, node *tree);

int main()
{
    node *root = NULL;
    node *current = NULL;
    int value;
    do
    {
        cout<<"enter an integer, 0 to quit"<<endl;
        cin >>value;
        current = insert(value, &root);
    }while(value!=0);

    do
    {
        cout << "search for an integer, 0 to quit"<<endl;
        cin >>value;
        current = search(value, root);
        if(current == NULL)
        {
            cout << "the value is not in the tree"<<endl;
        }
        else
        {
            cout <<"the value is at node "<<current<<endl;
        }
    }while(value!=0);

    destroy(root);

    return 0;
}

node *search(int key, node *tree)
{
    if(tree==NULL||tree->data==key)
    {
        return tree;
    }
    if(key < tree->data)
        return search(key, tree->left);
    else
        return search(key, tree->right);
}
