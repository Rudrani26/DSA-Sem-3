//Binary Search Tree 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	 int data;
	struct node *left;
	struct node *right;
};
struct node *ins(struct node *root,int v)
{
	struct node *q=root;
	struct node *follow=NULL;
	struct node *p=(struct node *)malloc(sizeof(struct node));
	 p->data=v;
	 p->left=NULL;
	 p->right=NULL;

	 if(root==NULL)
	 {
		  root=p;
		return root;
	}

	 while(q!=NULL)
	 {
		  follow=q;
		if(q->data<p->data)
		{
			 q=q->right;
		}
		else
		 {
			  q=q->left;
		}
	}
	if(follow->data>p->data)
	{
		  follow->left=p;
	}
	else
	{
		 follow->right=p;
	}
	return root;
}


 struct node *del(struct node *root,int x)
 {
	struct node *p=root;
	struct node *follow=NULL;
	  struct node *q=p;
	 struct node *fp=NULL;
	 int y;

	  while(p->data!=x&&p!=NULL)
	  {
		 follow=p;
		if(p->data>x)
		{
			p=p->left;
		 }
		else
		{
			 p=p->right;
		}
	}
	if(p==NULL)
	{
		 printf("Element not found");
		return root;
	}
	if(p->left==NULL&&p->right==NULL)
	{
		if (follow!=NULL)
		{
		 	if(follow->right==p)
			{
			follow->right=NULL;
			}
			else
			{
			follow->left=NULL;
			 }
			free(p);
			return root;
		}
		else
		 return NULL;
	}

	  if(p->left==NULL||p->right==NULL)
	 {
		  if(follow->right==p)
		{
			if(p->right!=NULL)
			{
		               if(follow!=NULL)
		               follow->right=p->right;
				else
			 root=p->right;
			}
			else
			{
		if (follow!=NULL)
		follow->right=p->left;
		else
		root=p->left;
			}
		}
		if(follow->left==p)
		{
			if(p->left!=NULL)
			{
			 if (follow!=NULL)
			follow->left=p->left;
				else
				root=p->left;
			}
			else
			{
		   if (follow!=NULL)
		   follow->left=p->right;
				else
			root=p->right;
			}
		}
		 free(p);
		return root;
	}
	q=p->left;

	 while(q->right!=NULL)
	{
		 fp=q;
		q=q->right;
	  }
            y=p->data;
	p->data=q->data;
	q->data=y;
	 if(q->left==NULL&&q->right==NULL)
	{
		if (fp!=NULL)
		  fp->right=NULL;
		else
		  p->left=NULL;
	}
	if(q->left==NULL||q->right==NULL)
	{
		if (fp!=NULL)
	        fp->right=q->left;
		else
	        p->left=q->left;
	}
	free(q);
	return root;
}

void display(struct node*root)
{
 if(root!=NULL)
 {

  display(root->left);
    printf("%d\t",root->data);
  display(root->right);
 }
}
void preorder(struct node*root)
{
 if(root!=NULL)
 {

   printf("%d\t",root->data);
   display(root->left);
   display(root->right);
 }
}
void postoder(struct node*root)
{
 if(root!=NULL)
 {
  display(root->left);
  display(root->right);
    printf("%d\t",root->data);
 }
}

int main()
{
   struct node *root=NULL;
  int c,v;
   while(c!=4)
 {
  printf("\nEnter\n 1.for insert\n 2.for delete\n 3.for display\n 4.for exit\n");
  scanf("%d",&c);
  switch(c)
  {
  case 1:printf("\nEnter the value");
	 scanf("%d",&v);
	 root=ins(root,v);
	 if(root!=NULL)
	 display(root);
	 else
	 printf("Tree is empty");
	 break;
  case 2:printf("Enter the value");
	 scanf("%d",&v);
	 root=del(root,v);
	 if(root!=NULL)
	 display(root);
	 else
	 printf("Tree is empty");
	 break;
  case 3:if(root!=NULL)
	 display(root);
	 else
	 printf("Tree is empty");
	 break;
  }
  }
  return 0;
 }
