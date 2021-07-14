#include <iostream>
#include <bits/stdc++.h>
//include<stdlib.h>
using namespace std;
class Node
{
public:
    Node *lchild, *rchild;
    int data;
};

class Queue
{
private:
    int front;
    int Rear;
    int size;

    Node **Q;

public:
    Queue()
    {
        front = Rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int SIZE)
    {
        front = Rear = -1;
        size = SIZE;
        Q = new Node *[size];
    }
    void enqueue(Node *x)
    {
        if (isfull())
        {
            cout << "Queue is full";
        }
        else
        {
            Rear++;
            Q[Rear] = x;
        }
    }
    bool isempty()
    {
        if (front == Rear)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if (Rear == size - 1)
            return true;
        else
            return false;
    }
    Node *dequeue()
    {
        Node *x = NULL;
        if (isempty())
            cout << "Queue empty";
        else
        {
            x = Q[front + 1];
            front++;
        }
        return x;
    }
};

class tree
{
public:
    Node *root;
    tree()
    {
        root = NULL;
    }
    void createtree()
    {
        Node *p, *t;
        int x;
        Queue q(100);
        cout << "enter root value ";
        cin >> x;
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);
        while (!q.isempty())
        {
            p = q.dequeue();
            cout << "enter left child of " << p->data << ": " << flush;
            cin >> x;
            if (x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "enter right child of " << p->data << ": " << flush;
            cin >> x;
            if (x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }
    void preorder(Node *p)
    {
        cout << p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
    void inorder(Node *p)
    {
        inorder(p->lchild);
        cout << p->data;
        inorder(p->rchild);
    }
    void postorder(Node *p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data;
    }
    void levelorder(Node *p)
    {
    }
    int Height(Node *root)
    {
        int x = 0, y = 0;
        Height(root->lchild);
        Height(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    Node *getroot()
    {
        return root;
    }
};

int main()
{
    tree t;
    t.createtree();
    t.preorder(t.root);
}