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

void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void search(struct Node *root,int x)
{
    if(root==NULL)
    {
        printf("Value not found\n");
        return;
    }

    if(root->data==x)
        printf("Value found\n");
    else if(x<root->data)
        search(root->left,x);
    else
        search(root->right,x);
}

int main()
{
    struct Node *root=NULL;
    int n,x,i;

    printf("Enter number of values: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nEnter value to search: ");
    scanf("%d",&x);
    search(root,x);

    return 0;
}