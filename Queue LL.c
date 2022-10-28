//QUEUE LINKED LIST

#include<stdio.h>
#include<conio.h>

struct ll_node
{
    int data;
    struct ll_node *next;
};

struct ll_node *front;
struct ll_node *rear;

void enqueue()
{
    struct ll_node *pnew = (struct ll_node*) malloc(sizeof(struct ll_node));

    int value;
    printf("Enter number to insert: ");
    scanf("%d",&value);

    pnew->data = value;
    pnew->next = NULL;

    if(front==NULL)
    {
        front=pnew;
        rear=pnew;
        return;
    }
    rear->next=pnew;
    rear=pnew;
    return;
}

void dequeue()
{
    struct ll_node *help_ptr;

    if(front==NULL)
    {
        printf("Queue empty");
    }
    if(front==rear)
    {
        free(front);
        front=rear=NULL;
        return;
    }
    help_ptr=front;
    front=front->next;
    free(help_ptr);
    return;
}

void display()
{
    struct ll_node *help_ptr=front;
   if (front == NULL)
    {
        printf("Queue underflow");
        return;
    }
    while(help_ptr!=NULL)
    {
        printf("%d\t",help_ptr->data);
        help_ptr=help_ptr->next;
    }
    return;
}

int main()
{
    front=NULL;
    rear =NULL;
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
       display();
       break;
    case 4:
    exit(0);
    }
    } while(ch!= 4);

    return 0;
}

