
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
}NODE;


NODE* newNode(int item)
{
    NODE * tmp=(NODE *)malloc(sizeof(NODE));
    tmp->data=item;
    tmp->left=tmp->right=NULL;
    return tmp;
}

NODE* addBST(NODE* root, int key)
{
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left=addBST(root->left, key);
    else
        root->right=addBST(root->right, key);
    return root;
}


int leaf(NODE* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return leaf(root->left)+leaf(root->right);
}


int nonleaf(NODE* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;
    return 1+nonleaf(root->left)+nonleaf(root->right);
}


int two(NODE* root)
{
    if(root==NULL)
        return 0;
    if(root->left!=NULL && root->right!=NULL)
        return 1+two(root->left)+two(root->right);
    if(root->left==NULL)
        return two(root->right);
    if(root->right==NULL)
        return two(root->left);
    return 0;
}


int total(NODE* root)
{
    if(root==NULL)
        return 0;
    return 1+total(root->left)+total(root->right);
}


int main()
{
    int i,n,key;
    NODE *root=NULL;
    printf("\nEnter n: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter int %d: ", i+1);
        scanf("%d", &key);
        root=addBST(root, key);
    }

    printf("\nNo of leaf nodes: %d", leaf(root));
    printf("\nNo of non-leaf nodes: %d", nonleaf(root));
    printf("\nNo of nodes with degree two: %d", two(root));
    printf("\nTotal no of nodes: %d", total(root));
    return 0;
}