#include <stdio.h>
#include <stdlib.h>
#define size 10

int adj[size][size];
int vis[size];

struct stack
{
    int a[size];
    int top;
}s1;

void push(int x)
{
   s1.top++;
   s1.a[s1.top]=x;
   return;
}

int pop()
{
    int t;
    t=s1.a[s1.top];
    s1.top--;
    return t;
}

void dfs(int s)
{
    int p;
    push(s);
    vis[s]=1;
    p=pop();

    if(p!=0)
    {
        printf("%d\t",p);
    }
    while(p!=0)
    {
        for(int i=1;i<=size;i++)
        {
            if(adj[p][i]==1&&vis[i]==0)
            {
                push(i);
                vis[i]=1;
            }
        }
        p=pop();
        if(p!=0)
        {
            printf("%d\t",p);
        }
    }
}
int main()
{
    int nodes,edges,sp,ep,sv,i,j;
    s1.top==-1;

    printf("Hello DFS Stack using Matrix!\n");

    for(i=1;i<=size;i++)
    {
        for(j=1;j<=size;j++)
        {
            adj[i][j]=0;
        }
    }

     for(i=1;i<size;i++)
     {
        vis[i]=0;
     }

     printf("Enter number of nodes:");
     scanf("%d",&nodes);
     printf("Enter number of edges:");
     scanf("%d",&edges);

     for(i=1;i<=edges;i++)
     {
        printf("\nEnter the start point:");
        scanf("%d",&sp);
        printf("Enter the end point:");
        scanf("%d",&ep);

        adj[ep][sp]=1;
        adj[sp][ep]=1;
     }

     printf("Adjacency Matrix:\n");

    for(i=1;i<=size;i++)
    {
        printf("\n");
        for(j=1;j<=size;j++)
        {
            printf("%d\t",adj[i][j]);
        }
    }

    printf("\nEnter the source vertex:\n");
    scanf("%d",&sv);

    dfs(sv);

    return 0;
}
