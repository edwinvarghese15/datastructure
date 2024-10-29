#include <stdio.h>

void insert();
void delete();
void display();

int front = -1, rear = -1;
int maxsize, queue[100];

int main() 
{
    int choice = 1;
    printf("Queue with array");
    printf("\nEnter the size of the queue (max 100): ");
    scanf("%d", &maxsize);
    
    while (choice < 4 && choice != 0) 
    {
        printf("\nPress 1 to insert");
        printf("\nPress 2 to delete");
        printf("\nPress 3 to display");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
                break;
        }
    }
    return 0;
}

void insert() 
{
    int item;
    printf("\nEnter the element to push: ");
    scanf("%d", &item);
    
    if (rear == (maxsize - 1)) 
    {
        printf("\nQueue is full");
    } else {
        if (front == -1 && rear == -1) 
        {
            front = 0;
            rear = 0;
        } else {
            rear = rear + 1;
        }
        queue[rear] = item;
        printf("\nValue inserted");
    }
}

void delete() 
{
    if (front == -1 || front > rear) 
    {
        printf("\nQueue is empty");
    } else 
    {
        int item = queue[front];
        front = front + 1;
        printf("\nValue deleted: %d", item);
    }
}

void display() {
    if (front == -1 || front > rear) 
    {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue elements are given below:");
        for (int i = front; i <= rear; i++) 
        {
            printf("\n%d", queue[i]);
        }
    }
}

