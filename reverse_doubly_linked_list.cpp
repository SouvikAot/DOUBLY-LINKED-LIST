#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head, *tail;
//////----------------create doubly linked list---------------------------------------------------------------------------------////////////////////////////
void create()
{
	struct node *newnode;
	
	int choice;
	while(choice){
		newnode=(struct node*)malloc(sizeof(struct node));
	printf("which data you want to insert\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->prev=0;
	if(head==0)
	{
		head=tail=newnode;
		
	}
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
	printf("DO YOU WANT TO CONTINUE\n");
	scanf("%d",&choice);
	}

}
void reverse()
{
	struct node *current, *nextnode;
	current=head;
	while(current!=0)
	{
	nextnode=current->next;
	current->next=current->prev;
	current->prev=nextnode;
	current=nextnode;
	}
	current=head;
	head=tail;
	tail=current;
}
display()
{
	struct node *temp1;
	temp1=head;
	while(temp1!=0)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
	}
	printf("\n");
}

int main()
{
	create();
	reverse();
	display();	
}
