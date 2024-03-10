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
///////////////////-----------------------insert at begin-----------------------------------------------------------------------------//////////////////////////
void insert_at_begin()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("ENTER DATA \n");
	scanf("%d",&newnode->data);
	if(head==0)
	{
		head=newnode;
	}
	else
	{
	head->prev=newnode;
	newnode->next=head;
	head=newnode;

	}
}
/////////////------------------------------insert at end------------------------------------------------------////////////////////////////////////////////////
void insert_at_end()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("ENTER DATA \n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=newnode;
	}
	else
	{
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;

	}
}
///////////////////////-------------------------------display---------------------------------/////////////////////////////////////////////
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
//////////length of doubly ll------------///////////////////////////////////////////////////////////////
int length()
{
	int count=0;
	struct node *len;
	len=head;
	while(len!=0)
	{
		count++;
		len=len->next;
	}
	return count;
}

/////////////////-------------------------insert at any pos----------------------------------------//////////////////////////////////////////////////////
void insert_at_pos()
{
	struct node *temp, *newnode;
	int pos, i;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER DATA TO INSERT AT DESIRED POSITION\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->prev=0;
	printf("ENTER POS\n");
	scanf("%d",&pos);
	int x=length();
	temp=head;
	if(pos<1 || pos>x)
	{
		printf("INVAlID POSITION YOU HAVE CHOOSEN\n");
	}
	else
	{
		while(pos>2)
		{
			temp=temp->next;
			pos--;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
//////////////-----------------------------------------delete from the begining -------------------------------/////////////////////////////////////////////
void delete_at_begin()
{
	struct node *ptr;
	ptr=head;
	ptr=ptr->next;
	head=ptr;
	ptr->prev=0;
	
}
///////////////-------------------------delete at end---------------------------------------------------------------////////////////////////////////////////
void delete_at_end()
{
	struct node *ptr;
	ptr=tail;
	ptr=ptr->prev;
	tail=ptr;
	tail->next=0;
	tail->prev=ptr->prev;
	
}
////////////////----------------------------delete at postion---------------------------------------------------///////////////////////////////////////
void delete_at_pos()
{
	int pos;
	struct node *temp,*ptr;
	temp=head;
	int i=1;
	printf("ENTER A DESIRED POS\n");
	scanf("%d",&pos);
	int x=length();
	if(pos<1 || pos>x)
	{
		printf("INVALID POSITION\n");
	}
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
}
 int main()
 {
 	int ch;
 	printf("CREATE ONE LINKED LIST TO PERFORM ALL TYPE DELETION OPERATION\n");
 	create();
 	while(1){
 		printf("ENTER 1 TO DELETE FROM END PRESS 2 DELETE FROM BEGIN PRTESS 3 TO DELETE FROM DESIRED position, press 4 to display, press 5 insert at begin , press 6 insert at end , press 7 insert at desired positions\n");
 	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			 delete_at_end();
			 	break;
		case 2:
			delete_at_begin();
			break;
		case 3:
			delete_at_pos();
			break;
		case 4: 
			display();
			break;
		case 5: 
			insert_at_begin();
			break;
		case 6: 
			insert_at_end();
			break;
		case 7:
			insert_at_pos();
	}}
 }
