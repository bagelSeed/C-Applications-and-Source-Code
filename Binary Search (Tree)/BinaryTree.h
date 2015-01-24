#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(int data, node **tree);
void destroy(node *tree);
void printTree(node *tree);

#endif // BINARYTREE_H_INCLUDED
