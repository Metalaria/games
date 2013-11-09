#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
struct node
{
	char stack;
	int data;
	struct node *next;
	struct node *prev;
};
 
 
void insert(struct node **start,int t)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=t;
	if((*start)->next==NULL)
	{
		temp->prev=*start;
		(*start)->next=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=(*start)->next;
		(*start)->next->prev=temp;
		(*start)->next=temp;
		temp->prev=*start;
    }
	
}
 
int delete(struct node **start)
{
	if((*start)==NULL)
	{
		printf("List is Empty\n");
		return 0;
	}
	struct node *temp=(*start)->next;
	int t=temp->data;
	if(temp->next==NULL)
	{
		(*start)->next=NULL;
		(*start)->prev=NULL;
		free(temp);
		return t;
	}
	(*start)->next=temp->next;
	temp->next->prev=*start;
	free(temp);
	return t;
}
 
void print(struct node **start)
{
	printf("STACK %c:\n",(*start)->stack);
	if((*start)->next==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	struct node *temp=(*start)->next;
	printf("%d\n",temp->data);
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%d\n",temp->data);		
	}
}
 
void tower_of_hanoi(int x, struct node **pole1, struct node **pole2, struct node **pole3)
{
		if(x==1)
		{
			int t=delete(pole1);
			insert(pole2,t);
			printf("Move disk from stack %c to stack %c\n",(*pole1)->stack,(*pole2)->stack);
		}
		else
		{
			tower_of_hanoi(x-1,pole1,pole3,pole2);
			tower_of_hanoi(1,pole1,pole2,pole3);
			tower_of_hanoi(x-1,pole3,pole2,pole1);
		}
}
 
main()
{
	printf("\t\t\tPROGRAM FOR TOWER OF HANOI\n\tShifting of disks from stack A to stack B using stack C\t\t\n\n");
	int t,i;
	printf("Enter the number of disks in a stack : ");
	scanf("%d",&t);
	printf("\n");
	struct node *pole1=malloc(sizeof(struct node));
	struct node *pole2=malloc(sizeof(struct node));
	struct node *pole3=malloc(sizeof(struct node));
	pole1->next=pole1->prev=NULL;
	pole2->next=pole2->prev=NULL;
	pole3->next=pole3->prev=NULL;
	pole1->stack='A';
	pole2->stack='B';
	pole3->stack='C';
	for(i=1;i<=t;i++)
	{
		insert(&pole1,t-i+1);
	}
	printf("Stacks before shifting are\n");
	print(&pole1);
	print(&pole2);
	print(&pole3);
	printf("\n");
	tower_of_hanoi(t,&pole1,&pole2,&pole3);
	printf("\n");
	printf("Stacks after shifting are\n");
	print(&pole1);
	print(&pole2);
	print(&pole3);
	return;
}
