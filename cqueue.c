#include<stdio.h>
void enqueue();
void dequeue();
void display();
int front=-1,rear=-1;
int max,cqueue[100];
int main()
{
	int choice=1;
	printf(" Cirlular Queue with array");
	printf("\n Enter the size of the queue(max 100):");
	scanf("%d",&max);
	printf("\n1.enqueue");
	printf("\n2.dequeue");
	printf("\n3.dislay");
	while(choice<4&&choice!=0)
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			}
		}
	}

//Insertion

void enqueue()
{
	int item;
	printf("\nEnter the element to push :");
	scanf("%d",&item);
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		cqueue[rear]=item;
		}	
	else if((rear+1)%max==front)
	{
		printf("FULL");
		}
	else
	{
		rear=(rear+1)%max;
		cqueue[rear]=item;
		printf("\n Value Inserted");
		}
	}
	
//Deletion	
	
	
void dequeue()
{
	int item;
	if(front==-1&&rear==-1)
	{
		printf("\nEmpty");
		}
	else if(front==rear)
	{
		rear=-1;
		front=-1;
		printf("\n Value Deleted");
		}
	else
	{
		item=cqueue[front];
		front=(front+1)%max;
		printf("\n Value Deleted");
		}
	}


//Display

void display()
{
	int i=front;
	if (front==-1&&rear==-1)
	{
		printf("\n Empty");
		}
	else
	{
		printf("\n Elements are :");
		for(i=front;i<=rear;i++)
		{
			printf("\n %d",cqueue[i]);
			}
		}
	}
