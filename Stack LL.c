#include<stdio.h>
#include<conio.h>

struct ll_node
{
    int data;
    struct ll_node *next;
};

struct ll_node *top = NULL;

void push()
{
    struct ll_node *pnew = (struct ll_node*) malloc(sizeof(struct ll_node));

    int value;
    printf("Enter number to insert: ");
    scanf("%d",&value);

    pnew->data = value;


    if(top==NULL)
    {
       pnew->next = NULL;
    }
    pnew->next = top;
    top = pnew;
    return;
}

void pop() {
    struct ll_node *temp = top;
    if(top==NULL) {
            printf("Stack Underflow");
    }
        temp->data = top->data;
        top=top->next;
        free(temp);
return;
    }


void display()
{
    while(top!=NULL) {
        printf("%d\n",top->data);
        top=top->next;
    }
}

int main()
{
    int ch;
    top = NULL;
    do{
    printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
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



