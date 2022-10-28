//DOUBLY LINKED LIST

#include<stdio.h>
#include<conio.h>
struct ll_node
{
    int data;
    struct ll_node *next;
    struct ll_node *prev;
};

struct ll_node *list = NULL;

struct ll_node*insert(struct ll_node *list)
{

    int value;

    struct ll_node *help_ptr = list;
    struct ll_node pnew = (struct ll_node) malloc(sizeof(struct ll_node));

      printf("Enter number to insert: ");
      scanf("%d",&value);

        pnew->data = value;
        pnew->next = NULL;
        pnew->prev = NULL;

        if(list==NULL)
        {
            list = pnew;
            return list;
        }

        if (list->data >= value)
        {
            pnew->next = list;
            list->prev = pnew;
            list = pnew;
            return list;
        }

        while(help_ptr->next!=NULL && help_ptr->next->data < value )
        {
            help_ptr=help_ptr->next;
        }
        pnew->next=help_ptr->next;

        if(help_ptr->next!=NULL)
        {
            help_ptr->next->prev=pnew;
        }
            pnew->prev=help_ptr;
            help_ptr->next=pnew;
            return list;
}

struct ll_node *display()
{
    struct ll_node *help_ptr = list;

    if(help_ptr == NULL)
    {
        printf("Empty List");
        return;
    }

    while(help_ptr!=NULL)
    {
        printf("\t%d", help_ptr->data);
        help_ptr = help_ptr->next;
    }
}

struct ll_node*delete1(struct ll_node *list)
{

    int target;

    printf("Enter number to delete: ");
    scanf("%d",&target);

    struct ll_node *help_ptr = list;
    struct ll_node *node2delete;

    if(list == NULL)
    {
        printf("Empty List");
        return list;
    }
        if(help_ptr->data == target)
        {
            list = list->next;
            list->prev=NULL;
            free(help_ptr);
            return list;
        }

    while (help_ptr->next!=NULL && help_ptr->next->data != target)
    {
        help_ptr=help_ptr->next;
    }
    if(help_ptr->next == NULL)
    {
        printf("\nElement not found.");
        return list;
    }
        node2delete = help_ptr->next;
        help_ptr->next = node2delete->next;
    if(node2delete->next != NULL)
    {
        node2delete->next->prev = help_ptr;
    }
        free(node2delete);
        return list;
}

int main()
{

    int ch;
    list = NULL;
    do{
    printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        list=insert(list);
        break;
    case 2:
        list=delete1(list);
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
