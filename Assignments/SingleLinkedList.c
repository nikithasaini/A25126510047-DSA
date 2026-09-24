#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head=NULL;

void display()
{
    struct Node *p=head;
    printf("List: ");
    while(p!=NULL)
    {
        printf("%d ",p->roll);
        p=p->next;
    }
    printf("\n");
}

void insertBeg(int x)
{
    struct Node *p=malloc(sizeof(struct Node));
    p->roll=x;
    p->next=head;
    head=p;
}

void insertEnd(int x)
{
    struct Node *p=malloc(sizeof(struct Node)),*q;
    p->roll=x;
    p->next=NULL;

    if(head==NULL)
        head=p;
    else
    {
        q=head;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}

void search(int x)
{
    struct Node *p=head;
    while(p!=NULL)
    {
        if(p->roll==x)
        {
            printf("Roll number found\n");
            return;
        }
        p=p->next;
    }
    printf("Roll number not found\n");
}

void delete(int x)
{
    struct Node *p=head,*q=NULL;

    while(p!=NULL && p->roll!=x)
    {
        q=p;
        p=p->next;
    }

    if(p==NULL)
    {
        printf("Roll number not found\n");
        return;
    }

    if(q==NULL)
        head=p->next;
    else
        q->next=p->next;

    free(p);
    printf("Deleted successfully\n");
}

int main()
{
    insertBeg(20);
    display();

    insertBeg(10);
    display();

    insertEnd(30);
    display();

    search(20);
    delete(20);
    display();

    search(50);

    return 0;
}