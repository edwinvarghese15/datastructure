#include <stdio.h>
#include <stdlib.h>


struct StackNode 
{
    int data;
    struct StackNode* next;
};


struct Stack 
{
    struct StackNode* top;
    int maxSize;
    int currentSize;
};


struct StackNode* createNode(int data)
 {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Stack* createStack(int maxSize) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->maxSize = maxSize;
    stack->currentSize = 0;
    return stack;
}


int isEmpty(struct Stack* stack) 
{
    return stack->top == NULL;
}


int isFull(struct Stack* stack) 
{
    return stack->currentSize >= stack->maxSize;
}

//  push 
void push(struct Stack* stack, int data) 
{
    if (isFull(stack)) 
    {
        printf("\nStack is full, cannot push %d!", data);
        return;
    }
    struct StackNode* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->currentSize++;
    printf("\nValue pushed: %d", data);
}

//  pop 
int pop(struct Stack* stack)
 {
    if (isEmpty(stack)) 
    {
        printf("\nStack is empty, cannot pop!");
        return -1; // Indicates an error
    }
    struct StackNode* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->currentSize--;
    printf("\nValue popped: %d", poppedValue);
    return poppedValue;
}

// display 
void display(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("\nStack is empty");
        return;
    }
    printf("\nStack elements are:");
    struct StackNode* current = stack->top;
    while (current != NULL) 
    {
        printf("\n%d", current->data);
        current = current->next;
    }
}

int main() 
{
    int maxSize;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);
    
    struct Stack* stack = createStack(maxSize);
    int choice, value;

    do {
        printf("\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
                break;
        }
    } while (choice != 4);

    // Free the allocated memory
    while (!isEmpty(stack))
     {
        pop(stack);
    }
    free(stack);

    return 0;
}

