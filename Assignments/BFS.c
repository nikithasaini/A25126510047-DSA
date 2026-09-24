#include<stdio.h>
int main()
{
    int n,i,j,start,v;
    int a[10][10],visited[10]={0};
    int q[10],front=0,rear=-1;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    start=start-1;
    visited[start]=1;
    q[++rear]=start;

    printf("BFS Traversal: ");
    while(front<=rear)
    {
        v=q[front++];
        printf("%d ",v+1);

        for(i=0;i<n;i++)
        {
            if(a[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                q[++rear]=i;
            }
        }
    }
    return 0;
}