#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};
ostream &operator<<(ostream &stream, node *list);
node *appendList(node *current, int newData);
void destroyList(node *begin);

int main()
{
    node *current;
    node *begin;
    int count;
    const int maxloop = 10;
    //allecate first node
    current = new node;
    current -> data=1;
    current -> next=NULL;
    begin = current;
    //create data
    for(count =1; count<maxloop; count++)
    {
        current = appendList(current, count*count);
    }
    cout <<"the list is "<<begin<<endl;
    destroyList(begin);
    return 0;
}

ostream &operator <<(ostream &stream, node *list)
{
    while(list!=NULL)
    {
        stream <<list->data<<" ";
        list = list->next;
    }
    return stream;
}

node *appendList(node *current, int newData)
{
    node *newNode;
    newNode=new node;
    newNode->data=newData;
    newNode->next= NULL;//newnode ->next = current-> next
    current->next=newNode;//for insertion
    return newNode;
}

void destroyList(node*begin)
{
    node *current;
    node *temp;
    if(begin==NULL)
    {
        return;
    }
    current = begin-> next;
    while(current!=NULL)
    {
        begin->next=current->next;
        temp = current->next;
        delete current;
        current = temp;
    }
    delete begin;
}
