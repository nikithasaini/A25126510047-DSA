#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char page[30];
    struct Node *prev,*next;
};

struct Node *head=NULL,*current=NULL;

void insert(char s[])
{
    struct Node *p=malloc(sizeof(struct Node));
    strcpy(p->page,s);
    p->prev=p->next=NULL;

    if(head==NULL)
        head=current=p;
    else
    {
        p->prev=current;
        current->next=p;
        current=p;
    }
}

void forward()
{
    if(current==NULL || current->next==NULL)
        printf("Already at last page\n");
    else
    {
        current=current->next;
        printf("Current page: %s\n",current->page);
    }
}

void backward()
{
    if(current==NULL || current->prev==NULL)
        printf("Already at first page\n");
    else
    {
        current=current->prev;
        printf("Current page: %s\n",current->page);
    }
}

void deletePage(char s[])
{
    struct Node *p=head;

    while(p!=NULL && strcmp(p->page,s)!=0)
        p=p->next;

    if(p==NULL)
    {
        printf("Page not found\n");
        return;
    }

    if(p->prev!=NULL)
        p->prev->next=p->next;
    else
        head=p->next;

    if(p->next!=NULL)
        p->next->prev=p->prev;
    else
        current=p->prev;

    free(p);
    printf("Page deleted\n");
}

void displayForward()
{
    struct Node *p=head;
    while(p!=NULL)
    {
        printf("%s ",p->page);
        p=p->next;
    }
    printf("\n");
}

void displayBackward()
{
    struct Node *p=current;
    while(p!=NULL && p->next!=NULL)
        p=p->next;

    while(p!=NULL)
    {
        printf("%s ",p->page);
        p=p->prev;
    }
    printf("\n");
}

int main()
{
    insert("Google");
    insert("YouTube");
    insert("GitHub");

    printf("First to Last: ");
    displayForward();

    forward();
    backward();

    deletePage("YouTube");

    printf("First to Last: ");
    displayForward();

    printf("Last to First: ");
    displayBackward();

    return 0;
}