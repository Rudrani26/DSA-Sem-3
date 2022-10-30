#include <stdio.h>
#define size 5

struct stack
{
  int top;
  int a[size];
}s1;

void push()
{
   int x;
   printf("Enter the number to insert: ");
   scanf("%d",&x);

   if(s1.top == size-1)
   {
       printf("Stack Overflow");
   }
   else
   {
       s1.top++;
       s1.a[s1.top] = x;
   }
}

void pop()
{
   if(s1.top == -1)
   {
       printf("Stack Underflow");
   }
   else
   {
       s1.top --;
   }
}

void display()
{
   if(s1.top == -1)
   {
       printf("Stack empty");
   }
   else
   {
       for(int i=s1.top;i>=0;i--)
       {
           printf("%d\n",s1.a[i]);
       }
   }
}

int main()
{
    int ch;
    int top = -1;

    while(ch!=4)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice: ");
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
    }

    return 0;
}





















