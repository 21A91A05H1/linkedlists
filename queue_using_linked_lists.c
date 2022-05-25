#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;  //self refferential structure
};
typedef struct node NODE; //user defined datatype alias name
NODE *head=NULL;

void insert_end(int val)
{
	NODE *nn,*temp;
	nn= (NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
}

void display()
{
	NODE *temp;
	if(head==NULL)
	{
		printf("no nodes \n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
		printf("\n");
		
	}
}

int delete_end()
{
	NODE *temp;
	int val;
	if(head==NULL)
	{
		return -1;
	}
	if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}

		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
    	}
    	val= temp->next->data;
    	temp->next=NULL;
    	return val;
    	
    
}
void insert_head(int val)
{
	NODE *nn;
	nn= (NODE *)malloc(sizeof(NODE));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
		head=nn;
	}
}

int delete_head()
{
	int val;
	NODE *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	temp=head;
	temp=temp->next;
	head->next=NULL;
	val=head->data;
	head=temp;
	return val;
	
}

void main()
{
	int val,ch;
	while(1)
	{
		printf("1.insert at end 2. delete at end 3.display 4.insert at head 5.delete at head 6.exit");
	    scanf("%d",&ch);
	    if(ch==1)
	    {
	    	//insert
	    	scanf("%d",&val);
	    	insert_end(val);
		}
		else if(ch==2)
		{
			//delete
			val= delete_end();
			if(val==-1)
			{
				printf("no nodes to delete\n");
			}
			else
			{
				printf("%d\n",val);
			}
			
		}
		else if(ch==3)
		{
			//display
			display();
		}
		else if(ch==4)
		{
			scanf("%d",&val);
			insert_head(val);
		}
		else if(ch==5)
		{
			val=delete_head();
			if(val==-1)
			{
				printf("no nodes");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else
		{
			break;
		}
	}
 }  
