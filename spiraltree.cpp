#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node * newnode(int data)
{
    node * t=new node();
    t->data=data;
    t->left=t->right=NULL;
    return t;
}

void bfs(node * root)
{
    if (root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        cout<<temp->data<<",";
        q.pop();
        q.push(temp->left);
        q.push(temp->right);
    }
}

void spiral(node *root)
{
    if (root==NULL)
        return;

    stack<node*>s1;
    stack<node*>s2;

    s1.push(root);

    while(!s1.empty() || s2.empty())
    {
        while(!s1.empty())
        {
            node* temp=s1.top();
            s1.pop();

            cout<<temp->data<<",";

            if(temp->right)
            s2.push(temp->right);
            if(temp->left)
            s2.push(temp->left);

        }

        while(!s2.empty())
        {
            node* temp=s2.top();
            cout<<temp->data<<",";
            s2.pop();
            if(temp->left)
            s1.push(temp->left);
            if(temp->right)
            s1.push(temp->right);


        }
    }

}

int main()
{
node* root=newnode(1);
root->left=newnode(2);
root->right=newnode(3);
root->left->left=newnode(4);
root->left->right=newnode(5);
root->right->left=newnode(6);
root->right->right=newnode(7);

spiral(root);
return 0;
}
