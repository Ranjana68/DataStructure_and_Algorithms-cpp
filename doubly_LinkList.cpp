#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
}*t,*start,*rear,*newptr;

node *create(int data)
{    t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
    t->prev=NULL;
    return t;
}

void i_beg(node *t)
{
    if(start==NULL)
        start=t;
    else
    {
        t->prev=NULL;
        t->next=start;
        start->prev=t;
        start=t;
}
}

void i_end(node *t)
{
    if(start==NULL)
    {
        start=t;
    }


    else
    {
            rear=start;
        while (rear->next != NULL)
        rear = rear->next;

    /* 6. Change the next of last node */
    rear->next = t;
    t->prev=rear;
    }

}


void d_beg()
{
    if(start==NULL)
        cout<<"empty"<<endl;
    else if(start->next == NULL)
    {
        start = NULL;
        free(start);
    }
    else
        { t=start;
        start=start->next;
        start->prev=NULL;
        free(t);
        }
}

void d_end()
{
    if(start==NULL)
        cout<<"empty"<<endl;
     else if(start->next == NULL)
    {
        start = NULL;
        free(start);
    }
    else
        {t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->prev->next=NULL;
        }
}

void disp(node *t)
{
     if(start==NULL)
        cout<<"empty"<<endl;
    else{
    while(t!=NULL)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<endl;
    }
}

int main()
{
    int ch,x;
    char ans;
    do{
    cout<<"choose your option: 1.diplay  2.insert at beg 3.insert at end 4.delete head node 5.delete from end "<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        disp(start);
        break;
    case 2:
        cout<<"enter value: ";
        cin>>x;
        newptr=create(x);
        i_beg(newptr);
        break;
    case 3:
        cout<<"enter value: ";
        cin>>x;
        newptr=create(x);
        i_end(newptr);
        break;
    case 4:
        d_beg();
        break;
    case 5:
        d_end();
    }
    cout<<"continue (y/n)?"<<endl;
    cin>>ans;
    }while(ans=='y'||ans=='Y');
}

