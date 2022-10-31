#include<stdio.h>

void insertion()
{
    int i,j,low,n;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
   {
        printf("Enter Element : ",i+1);
        scanf("%d",&a[i]);
   }
    for(i=1;i<n;i++)
    {
        low=a[i];
        j=i-1;

        display(a,n);

        while(j>=0 && low<a[j] )
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=low;
    }

}
void selection()
{
     int i,j,temp,n;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
   {
        printf("Enter Element : ",i+1);
        scanf("%d",&a[i]);
   }
    for(i=0;i<n-1;i++)
    {
         int min = i;

        for (j=i+1;j<n;j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
            if(min!=i)
            {
                temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }

             display(a,n);
    }
}
void display(int a[],int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
   {
        printf(" %d ",a[i]);
   }
    printf("\n");
}
int main()
{
    int ch;
   do{
   printf("\n1.Insertion sort\n2.Selection Sort\n3.Exit\n");
   printf("Enter your choice: ");
   scanf("%d",&ch);

   switch(ch)
   {
       case 1:
           //printf("Insertion sort");
           insertion();
        break;
       case 2:
           //printf("Selection sort");
           selection();
        break;
       case 3:
        exit(0);
   }
   }while(ch!=3);

   return 0;
}
