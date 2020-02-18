#include<iostream>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

node *Newnode(int x)
{
    node * t=new node();
    t->data=x;
    t->left=t->right=NULL;

    return t;
}

int maxDepth(node *root)
{
    if (root==NULL)
        return 0;
    else
    {
        int left_d=maxDepth(root->left);
        int right_d=maxDepth(root->right);

        if(left_d>right_d)
            return (left_d+1);
        else return (right_d+1);
    }
}
int main()
{
    node * root=Newnode(1);
    root->left=Newnode(2);
    root->right=Newnode(3);
    root->left->left=Newnode(4);
    root->left->right=Newnode(5);
    root->left->left->right=Newnode(6);


    cout<<maxDepth(root);
return 0;

}
