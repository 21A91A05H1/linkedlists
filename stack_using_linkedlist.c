#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;  //self refferential structure
};
typedef struct node NODE; //user defined datatype alias name
NODE *head=NULL;

void insert(int val)
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

int delete()
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



void main()
{
	int val,ch;
	while(1)
	{
		printf("1.insert 2. delete 3.display 4.exit");
	    scanf("%d",&ch);
	    if(ch==1)
	    {
	    	//insert
	    	scanf("%d",&val);
	    	insert(val);
		}
		else if(ch==2)
		{
			//delete
			val= delete();
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
		else
		{
			break;
		}
	}
 }  
