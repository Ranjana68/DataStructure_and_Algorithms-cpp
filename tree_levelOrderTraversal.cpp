#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct node
{
    char data;
    node * left;
    node * right;
};

node* Newnode(char x)
{
    node * t=new node();
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

void levelOrder(node * root)
{
    if(root==NULL)
            return;

    queue<node *>q;
    q.push(root);

    while(q.empty()==false)
    {
        node * n=q.front();
        cout<<n->data<<" ";
        q.pop();

        if(n->left!=NULL)
            q.push(n->left);

        if(n->right!=NULL)
            q.push(n->right);

    }
}
int main()
{
    node * root=Newnode('a');
    root->left=Newnode('b');
    root->right=Newnode('c');
    root->left->right=Newnode('d');
    root->right->left=Newnode('e');
    root->right->right=Newnode('f');
    root->left->right->left=Newnode('g');

    levelOrder(root);

return 0;
}
