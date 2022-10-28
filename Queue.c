#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 3
struct queue
{
    int front,rear;
    int a[size];
}Q;

void enqueue()
{
    int x;
    printf("Enter number to insert: ");
    scanf("%d",&x);

    if (Q.front-1 == Q.rear || (Q.front == 0 && Q.rear == size-1))
    {
        printf("Queue Overflow");
    }
    else
    if(Q.front == -1)
    {
        Q.rear ++;
        Q.front ++;
        Q.a[Q.front] = x;
    }
    else
    {
        Q.rear ++;
        Q.a[Q.rear] = x;
    }
}

void dequeue()
{
    if (Q.front == -1)
    {
        printf("Queue underflow");
        return;
    }
    if (Q.front == Q.rear)
    {
        Q.front == -1;
        Q.rear == -1;
        return;
    }
    Q.front ++ ;
}

void display()
{
   if (Q.front == -1)
    {
        printf("Queue underflow");
        return;
    }

    for(int i=Q.front; i<=Q.rear; i++)
    {
        printf("%d\t",Q.a[i]);
    }
}

int main()
{
    Q.front = -1;
    Q.rear = -1;
    int ch;
    do{
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
    break;
   case 3:
       display( );
    break;
    case 4:
    exit(0);
    }
    } while(ch!= 4);

    return 0;
}
