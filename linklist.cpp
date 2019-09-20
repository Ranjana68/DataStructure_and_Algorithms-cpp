#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
}*newptr,*newptr2,*save,*t,*ptr,*ptr1,*ptr2,*start,*rear;

node *create(int data)
{
    //ptr=new node;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}


void i_beg(node *t)
{
    if(start==NULL)
        start=t;
    else
    {
        //save=start;
        //start=t;
        t->next=start;
        start=t;
    }
}

void d_beg()
{
    if(start==NULL)
        cout<<"empty"<<endl;
    else
        start=start->next;
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

    }
}

void d_end()
{
    if(start==NULL)
        cout<<"empty"<<endl;
    else
        {ptr=start;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
        }
}


void i_position(int pos,node *newNode)
{


  int tempPos = 0;   // Traverses through the list

  ptr2 = start;      // Initialize current to head;
   while(ptr2->next != NULL && tempPos != pos)
    {
        ptr1 = ptr2;
        ptr2 = ptr2->next;
        tempPos++;
    }
    if(pos==0)
    {
       i_beg(newNode);
    }
    else if(ptr2->next == NULL && pos == tempPos+1)
    {
      i_end(newNode);
    }
    else if(pos > tempPos+1)
      cout << " Position is out of bounds " << endl;

    else
    {
        ptr1->next = newNode;
        newNode->next = ptr2;
    }
}


void d_position(int pos)
{
    int tp=0;
     ptr2 = start;      // Initialize current to head;
   while(ptr2->next != NULL && tp != pos)
    {
        ptr1 = ptr2;
        ptr2 = ptr2->next;
        tp++;
    }
    if(pos==0)
        d_beg();
    else if(ptr2->next == NULL && pos == tp+1)
    {
      d_end();
    }
    else if(pos > tp+1)
      cout << " Position is out of bounds " << endl;

    else
    {
        ptr1->next = ptr2->next;

    }

}
void disp(node *t)
{
    while(t!=NULL)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<endl;
}

void del(int x)
{
    int c=0;
t=start;
while(t!=NULL)
{

   if(t->data > x)
   {
       c++;
   }
   t=t->next;
}
cout<<endl<<c<<"dfds"<<endl;
for(int i=0;i<c;i++)
{
    ptr2=start;
    cout<<endl<<"ptr2->data :"<<ptr2->data;
    while(ptr2->next!=NULL && ptr2->data<=x)
    {
        ptr1=ptr2;
        cout<<endl<<"ptr1->data :"<<ptr1->data;
        ptr2=ptr2->next;
        cout<<endl<<"ptr2->data :"<<ptr2->data;

    }
    ptr1->next=ptr2->next;

}
}
int main()
{
    int ch,x,pos;
    char ans;;
    do{
    cout<<"choose your option: 1.diplay  2.insert at beg 3.insert at end 4.delete head node 5.delete from end 6.insert at given position 7. del pos"<<endl;
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
        newptr2=create(x);
        i_end(newptr2);
        break;
    case 4:
        d_beg();
        break;
    case 5:
        d_end();
        break;
    case 6:
        cout<<"enter position and value: ";
        cin>>pos>>x;
        newptr=create(x);
        i_position(pos,newptr);
        break;
    case 7:
        cout<<"enter position: ";
        cin>>pos;
        d_position(pos);
        break;
    case 8:
        cout<<"enter x: ";
        cin>>x;
        del(x);
    }
    cout<<"continue?"<<endl;
    cin>>ans;
    }while(ans=='y'||ans=='Y');
}
