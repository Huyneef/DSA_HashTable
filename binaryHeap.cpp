#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
typedef node *Tree;
Tree getNode(int x)
{
    Tree p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void InsertTree(Tree &T, int x)
{

    if (T)
    {
        if (x < T->data)
            InsertTree(T->left, x);
        else if (x > T->data)
            InsertTree(T->right, x);
    }
    else
        T = getNode(x);
}
void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertTree(T, x);
    }
}
void NLR(Tree T)
{
    if (T)
    {
        cout << T->data << " ";
        NLR(T->left);
        NLR(T->right);
    }
}
void LRN(Tree T)
{
    if (T)
    {

        LRN(T->left);
        LRN(T->right);
        cout << T->data << " ";
    }
}
void LNR(Tree T)
{
    if (T)
    {

        LNR(T->left);
        cout << T->data << " ";
        LNR(T->right);
    }
}
void listLeafs(Tree T)
{
    if (T != NULL)
    {
        if (T->left == NULL && T->right == NULL)
        {
            cout << T->data << " ";
        }
        listLeafs(T->left);
        listLeafs(T->right);
    }
}
void listInternalNodes(Tree T, int level)
{
    if (T != NULL)
    {
        if(level != 0) {
        if (T->left != NULL || T->right != NULL)
        {
            cout << T->data << " ";
           
        }
        
        }
         listInternalNodes(T->left, 1);
            
            listInternalNodes(T->right, 1);
    }
}
void listNodesWithOneChild(Tree T)
{
    if (T != NULL)
    {
        if ((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL))
        {
            cout << T->data << " ";
        }
        listNodesWithOneChild(T->left);
        listNodesWithOneChild(T->right);
    }
}
void listNodesWithTwoChildren(Tree T)
{
    if (T != NULL)
    {
        if (T->left != NULL && T->right != NULL)
        {
            cout << T->data << " ";
        }
        listNodesWithTwoChildren(T->left);
        listNodesWithTwoChildren(T->right);
    }
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: ";
    NLR(T);
    cout << "\nLRN: ";
    LRN(T);
    cout << "\nLNR: ";
    LNR(T);

    cout << "\nLeaf nodes: ";
    listLeafs(T);
    cout << "\nInternal nodes: ";
    listInternalNodes(T, 0);
    cout << "\nNodes with one child: ";
    listNodesWithOneChild(T);
    cout << "\nNodes with two children: ";
    listNodesWithTwoChildren(T);

    return 0;
}
