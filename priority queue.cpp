#include <iostream>
using namespace std;
struct node
{
    int priority;
    int data;
    struct node *link;
}*frnt=NULL;

int ins()
{
    struct node *temp,*q;
    int item,item_priority;
    temp=new node;
    cout<<"\nEnter : ";
    cin>>item;
    cout<<"\nEnter its priority :";
    cin>>item_priority;
    temp->data=item;
    temp->priority=item_priority;
    if(frnt==NULL || item_priority<frnt->priority)
    {
        temp->link=frnt;
        frnt=temp;
    }
    else
    {
        q=frnt;
        while(q->link!=NULL && q->link->priority<=item_priority)
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
    }
}
void del()
{
    struct node *temp;
    if(frnt==NULL)
    {
        cout<<"\nEmpty";
    }
    else
    {
        temp=frnt;
        cout<<"\nDeleted data is :";
        cout<<temp->data;
        frnt=frnt->link;
        delete(temp);
    }
}
void display()
{
    struct node *ptr;
    ptr=frnt;
    if(frnt==NULL)
    {
        cout<<"\nEmpty";
    }
    else
    {
        cout<<"------Queue------";
        cout<<"\nPriority\tData\n\n";
        while(ptr!= NULL)
        {
            cout<<ptr->priority<<"\t"<<ptr->data<<"\n";
            ptr=ptr->link;
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        cout<<"\n1. Insert.\n2.Delete\n3.display";
        cin>>choice;
        switch(choice)
        {
        case 1:
            ins();
            break;

        case 2:
            del();
            break;

        case 3:
            display();
            break;

        default:
            cout<<"\nWrong Choice\n";
        }
    }
}
