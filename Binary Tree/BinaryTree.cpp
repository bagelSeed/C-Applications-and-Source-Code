#include "BinaryTree.h"
#include <iostream>

using namespace std;

void printNode(node *Node)
{
    if(Node != 0)
    {
        cout << "address ="<<Node<<" left ="<<Node->left;
        cout << " right ="<<Node->right<<" data ="<<Node->data<<endl;
        //cout << Node->data << " ";
    }
}

node *createNode(int data)
{
    node *newNode=NULL;
    newNode = new node;
    newNode->data = data;
    newNode->left=NULL;
    newNode->right=NULL;
    //cout <<"create node";
    //printNode(newNode);
    return newNode;
}

node *insert(int data, node **tree)
{
    node *newNode = NULL;
    if((*tree) == NULL)//there is no tree
    {
        newNode = createNode(data);
        *tree = newNode;
    }
    else if(data < (*tree)->data)//go to left of node
    {
        //check if left node exists
        if((*tree)->left==NULL)
        {
            newNode = createNode(data);
            (*tree)->left=newNode;
        }
        else
        {
            newNode=insert(data, &((*tree)->left));
        }
    }
    else//go to the right
    {
        if((*tree)->right==NULL)
        {
            newNode = createNode(data);
            (*tree)->right=newNode;
        }
        else
        {
            newNode=insert(data, &((*tree)->right));
        }
    }
    return newNode;
}

void destroy(node *tree)
{
    if(tree!=NULL)
    {
        if(tree->left!=NULL)
        {
            destroy(tree->left);
        }
        if(tree->left!=NULL)
        {
            destroy(tree->right);
        }
        delete tree;
    }
}

void printTree(node *tree)
{
    if(tree!=NULL)
    {
        printTree(tree->left);
        printNode(tree);
        printTree(tree->right);
    }
}
