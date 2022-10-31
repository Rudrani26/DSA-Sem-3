#include <stdio.h>
#include <stdlib.h>
#define size 10

//int adj[size][size];
int vis[size];
struct ll_node
{
    int vertex;
    struct ll_node* next;
};
struct ll_node* adj[size];
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
            if(adj[p]!=NULL&&vis[adj[p]->vertex]==0)
            {
                push(adj[p]->vertex);
                vis[adj[p]->vertex]=1;
                adj[p]=adj[p]->next;
            }
        }
        p=pop();
        if(p!=0)
        {
            printf("%d\t",p);
        }
    }
}

struct ll_node* creategraph(struct ll_node* temp, int x)
{
    struct ll_node* new1=(struct ll_node*)malloc(sizeof(struct ll_node));
    new1->vertex=x;
    new1->next=temp;
    temp=new1;
    return temp;
}
int main()
{
    int nodes,edges,sp,ep,sv,i,j;
    struct ll_node* hp;
    s1.top==-1;

    printf("Hello DFS Stack using List!\n");

    for(i=1;i<=size;i++)
    {
       adj[i]=NULL;
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

        adj[ep]=creategraph(adj[ep],sp);
        adj[sp]=creategraph(adj[sp],ep);
     }

     printf("Adjacency List:\n");

    for(i=1;i<=size;i++)
    {
        hp=adj[i];
        printf("\n");
        while(hp!=NULL)
        {
            printf("%d-->",hp->vertex);
            hp=hp->next;
        }
    }

    printf("\nEnter the source vertex:\n");
    scanf("%d",&sv);

    dfs(sv);

    return 0;
}
