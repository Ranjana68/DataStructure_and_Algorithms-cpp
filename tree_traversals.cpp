#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node * Newnode(int x)
{
    node * t=new node();
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

void preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main()
{
node * root=Newnode(1);
root->left=Newnode(2);
root->right=Newnode(3);
root->left->left=Newnode(4);
root->left->right=Newnode(5);

preorder(root);
cout<<endl;

inorder(root);
cout<<endl;

postorder(root);
return 0;
}
