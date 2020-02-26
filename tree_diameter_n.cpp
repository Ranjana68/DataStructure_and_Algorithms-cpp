//complexity is O(n)
#include<iostream>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};


node * create(int data)
{
    node * t=new node;
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    return t;
}


int diameter(node * root, int * height)
{
    int l_height=0,r_height=0,ldiameter=0,rdiameter=0;
    if(root==NULL)
    {return 0;
    *height=0;
    }
    else
    {


         ldiameter=diameter(root->left,&l_height);
         rdiameter=diameter(root->right,&r_height);

         *height=max(l_height,r_height)+1;
        return max(l_height+r_height+1,max(ldiameter,rdiameter));
    }
}

int main()
{
    node * root=create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left  = create(4);
    root->left->right = create(5);
    root->right->right= create(6);
    root->left->right->left = create(7);
    root->left->right->right = create(8);
    root->right->right->right= create(9);
    root->right->right->right->left= create(10);
    root->right->right->right->right= create(11);
    root->right->right->right->left->right= create(12);

int *h;

    cout<<diameter(root,h);
    return 0;
}
