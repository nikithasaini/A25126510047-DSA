#include<stdio.h>
#define INF 999

int main()
{
    int n,i,j,src,u,min;
    int a[10][10],dist[10],visited[10]={0};

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter weighted adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter source vertex: ");
    scanf("%d",&src);
    src--;

    for(i=0;i<n;i++)
        dist[i]=a[src][i];

    dist[src]=0;
    visited[src]=1;

    for(i=1;i<n;i++)
    {
        min=INF;
        u=-1;

        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(j=0;j<n;j++)
        {
            if(!visited[j] && a[u][j]!=0 &&
               dist[u]+a[u][j]<dist[j])
                dist[j]=dist[u]+a[u][j];
        }
    }

    printf("\nShortest distances from vertex %d:\n",src+1);
    for(i=0;i<n;i++)
        printf("To %d = %d\n",i+1,dist[i]);

    return 0;
}