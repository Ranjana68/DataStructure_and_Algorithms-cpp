#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
}*start,*t,*temp,*newptr;

node *create(int data)
{
    t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
    return t;
}


void i_beg(node *t)
{
    if(start==NULL)
       {
           start=t;
           t->next=start;
       }
    else
    {
      temp=start;
      while(temp->next!=start)
        temp=temp->next;
      t->next=start;
      temp->next=t;
      start=t;
    }
}

void d_beg()
{
    if(start==NULL)
        cout<<"empty"<<endl;
    else if(start->next==start)
       {
           start=NULL;
           free(start);
       }
    else
       {
        temp=start;
        while (temp->next != start)
        temp = temp->next;

        temp->next=start->next;
        free(start);
        start=temp->next;
       }

}

void i_end(node *t)
{

    if(start==NULL)
    {
        start=t;
        t->next=start;
    }
    else
    {
        temp=start;
        while (temp->next != start)
        temp = temp->next;
        temp->next=t;
        t->next=start;

    }
}

void d_end()
{
    struct node * pre;
    if(start==NULL)
        cout<<"empty"<<endl;
    else if(start->next==start)
       {
           start=NULL;
           free(start);
       }
    else
        {temp=start;
        while(temp->next!=start)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=temp->next;
        free(temp);
        }
}


void disp(node *t)
{
    if(start==NULL)
        cout<<"empty"<<endl;
    else{
    while(t->next!=start)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<t->data;
    cout<<endl;
    }
}

int main()
{
    int ch,x,pos;
    char ans;;
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
    cout<<"continue?"<<endl;
    cin>>ans;
    }while(ans=='y'||ans=='Y');
}
