#include <stdio.h>
#include<stdlib.h>
#define tablesize 11

int h[tablesize]={NULL};

void insert()
{

 int value,index,i,flag=0,v,steps;
 printf("\nEnter a value to insert: \n");
 scanf("%d",&value);

 v = value % tablesize;

 for(i=0;i<tablesize;i++)
    {

     index = v % tablesize;

     if(h[index] == NULL)
     {
        h[index]=value;
         break;
     }
     else
     {
        steps = 1 + ((value/tablesize)%(tablesize-1));
        index = index + steps;
        h[index] = value;
     }

    }

    if(i == tablesize)

     printf("\nValue cannot be inserted\n");
}

void search()
{

 int value,index,i,flag=0,v;
 printf("\nEnter the  element to search: \n");
 scanf("%d",&value);
 v=value%tablesize;
 for(i=0;i<tablesize; i++)
 {
    index=(v+i)%tablesize;
    if(h[index]==value)
    {
      printf("Value is at index %d",index);
      break;
    }
  }
  if(i == tablesize)
    printf("\n Value not found\n");
}

void display()
{

  int i;

  printf("\nHASH TABLE: \n");

  for(i=0;i< tablesize; i++)

  printf("\nIndex %d \t Value =  %d\n",i,h[i]);

}

int main()
{
    int opt,i;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
    return 0;
}
