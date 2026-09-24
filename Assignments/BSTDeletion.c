#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
};

struct Node *create(int x)
{
    struct Node *p=malloc(sizeof(struct Node));
    p->data=x;
    p->left=p->right=NULL;
    return p;
}

struct Node *insert(struct Node *root,int x)
{
    if(root==NULL)
        return create(x);

    if(x<root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);

    return root;
}

void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct Node *minNode(struct Node *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

struct Node *delete(struct Node *root,int x)
{
    struct Node *p;

    if(root==NULL)
        return root;

    if(x<root->data)
        root->left=delete(root->left,x);
    else if(x>root->data)
        root->right=delete(root->right,x);
    else
    {
        if(root->left==NULL)
        {
            p=root->right;
            free(root);
            return p;
        }
        else if(root->right==NULL)
        {
            p=root->left;
            free(root);
            return p;
        }

        p=minNode(root->right);
        root->data=p->data;
        root->right=delete(root->right,p->data);
    }

    return root;
}

int main()
{
    struct Node *root=NULL;
    int a[]={50,30,70,20,40,60,80};
    int i,x;

    for(i=0;i<7;i++)
        root=insert(root,a[i]);

    printf("Before deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    scanf("%d",&x);
    root=delete(root,x);
    printf("After deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    scanf("%d",&x);
    root=delete(root,x);
    printf("After deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    scanf("%d",&x);
    root=delete(root,x);
    printf("After deletion: ");
    inorder(root);

    
    return 0;
}