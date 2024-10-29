#include<stdio.h>
int s[100],element,size,top=-1,choice,i;
void push();
void pop();
void display();
int main()
{
	int choice=1;
	printf("Stack with array");
	printf("\n enter the size of the stack(max 100):");
	scanf("%d",&size);
	printf("\npress 1 to push");
	printf("\npress 2 to pop");
	printf("\npress 3 to display");
	while(choice<4&&choice!=0)
	{
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			}
		}
	}



// Insertion


void push()
{
	if(top==size-1)
	{
		printf("\nstackoverflow");
		}
	else
	{
		printf("\nenter the element to push :");
		scanf("%d",&element);
		top++;
		s[top]=element;
		printf("\nelement added:%d",element);
		}
	}


// Deletion


void pop()
{
	if(top==-1)
	{
		printf("\nstack underflow");
	}
	else
	{
		printf("\ndeleted :%d",s[top]);
		top--;
		}
	}
	

// Display


void display()
{
	if (top>=0)
	{
		printf("\n stack elements are given below:");
		for(i=top;i>=0;i--)
		{
			printf("\n %d",s[i]);
			}
		}
	else
	{
		printf("\n stack is empty");
		}
	
	
	
	
	
	
	
	
	}
