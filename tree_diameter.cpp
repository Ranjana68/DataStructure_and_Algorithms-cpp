//complexity O(n^2)
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

int height(node * root)
{
    if (root==NULL) return 0;

    else
    {
        int l=height(root->left);
        int r=height(root->right);

        if(l>r)
            return (l+1);
        else
            return (r+1);
    }
}
int diameter(node * root)
{
    if(root==NULL) return 0;
    else
    {
        int l_height=height(root->left);
        int r_height=height(root->right);

        int ldiameter=diameter(root->left);
        int rdiameter=diameter(root->right);

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



    cout<<diameter(root);
    return 0;
}
