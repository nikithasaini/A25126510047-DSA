#include<stdio.h>
int main()
{
    int n,i,key,low,high,mid,comparisons;
    printf("enter no. of employee IDs:\n");
    scanf("%d",&n);
    int id[n];
    printf("enter employee IDs in ascending order:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&id[i]);
    }
    printf("enter ID to search:");
    scanf("%d",&key);
    low=0;
    high=n-1;
    comparisons=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        comparisons++;

        if(id[mid]==key)
        {
            printf("employee ID %d found at position %d\n",key,mid+1);
            printf("Number of comparisions:%d\n",comparisons);
            return 0;
        }
        else if(key<id[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
            
    }

    printf("Employee ID %d is absent\n",key);
    printf("Number of comparisions:%d",comparisons);
    return 0;
    
}