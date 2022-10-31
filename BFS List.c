#include<stdio.h>
#include<malloc.h>
#define size 10

int adj_mat[size][size];
int vis[size];

struct ll_node
{
    int vertex;
    struct ll_node *next;
};

struct ll_node *adj[size];

struct queue1
{
    int a[size];
    int front,rear;
}q1;

int enqueue(int x)
{
  if(q1.front==-1)
  {
      //q1.a[++q1.front]=x;
      q1.front++;
      q1.rear++;
      q1.a[q1.front]=x;
      return;
  }
  q1.rear++;
  q1.a[q1.rear]=x;
  return;
}

int dequeue()
{
    int t;
    t=q1.a[q1.front];
    q1.front++;
    return t;
}

void bfs(int s)
{
    int p;
    enqueue(s);
    vis[s]=1;
    p=dequeue();

    if(p!=0)
    {
        printf("\t%d",p);
    }

    while(p!=0)
    {
        while(adj[p]!=NULL && vis[adj[p]->vertex]==0)
        {
            enqueue(adj[p]->vertex);
            vis[adj[p]->vertex]=1;
            adj[p]=adj[p]->next;
        }

        p=dequeue();
        if(p!=0)
       {
        printf("\t%d",p);
       }

    }
}

struct ll_node *creategraph(struct ll_node *temp,int x)
{
    struct ll_node *new1;
    new1 = (struct ll_node*)malloc(sizeof(struct ll_node));
    new1->vertex=x;
    new1->next=temp;
    temp=new1;
    return temp;
}

int main()
{
    int  node,edges,sp,ep,sv;
    struct ll_node *hp;
    q1.front=-1;
    q1.rear=-1;
    printf("Hello BFS-LIST");

    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            adj_mat[i][j]=0;;
        }
    }
    for(int i=1;i<=size;i++)
    {
        vis[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        adj[i]=NULL;
    }

    printf("\nHow many nodes? : ");
    scanf("%d",&node);

    printf("\nHow many edges? : ");
    scanf("%d",&edges);

    for(int i=1;i<=edges;i++)
    {
        printf("\nEnter the start point: ");
        scanf("%d",&sp);

        printf("\nEnter the end point: ");
        scanf("%d",&ep);

        //adj_mat[sp][ep] = 1;
        //adj_mat[ep][sp] = 1;
        adj[sp]=creategraph(adj[sp],ep);
        adj[ep]=creategraph(adj[ep],sp);
    }

    printf("\nAdjacency List");
    for(int i=1;i<=size;i++)
    {
        hp =adj[i];
        printf("\n");
        while(hp!=NULL)
        {
            printf("%d->",hp->vertex);
            hp=hp->next;
        }
    }

    printf("\nEnter the source vertex:");
    scanf("%d",&sv);

    bfs(sv);

    return 0;
}

