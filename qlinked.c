    #include<stdio.h>   
    #include<stdlib.h>  
    struct node   
    {  
        int data;   
        struct node *next;  
    };  
    struct node *front;  
    struct node *rear;   
    void enqueue();  
    void dequeue();  
    void display();  
    void main ()  
    {  
        int choice; 
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");   
        while(choice != 4)   
        {       
            printf("\nEnter your choice :");  
            scanf("%d",& choice);  
            switch(choice)  
            {  
                case 1:  
                enqueue();  
                break;  
                case 2:  
                dequeue();  
                break;  
                case 3:  
                display();  
                break;  
                case 4:  
                exit(0);  
                break;  
                default:   
                printf("\nEnter valid choice!!\n");  
            }  
        }  
    }  
    void enqueue()  
    {  
        struct node *ptr;  
        int item;   
          
        ptr = (struct node *) malloc (sizeof(struct node));  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW\n");  
            return;  
        }  
        else  
        {   
            printf("\nEnter value :\n");  
            scanf("%d",&item);  
            ptr -> data = item;  
            if(front == NULL)  
            {  
                front = ptr;  
                rear = ptr;   
                front -> next = NULL;  
                rear -> next = NULL;  
            }  
            else   
            {  
                rear -> next = ptr;  
                rear = ptr;  
                rear->next = NULL;  
            }  
        }  
    }     
    void dequeue()  
    {  
        struct node *ptr;  
        if(front == NULL)  
        {  
            printf("\nUNDERFLOW\n");  
            return;  
        }  
        else   
        {  
            ptr = front;  
            front = front -> next;  
            free(ptr);  
        }  
    }  
    void display()  
    {  
        struct node *ptr;  
        ptr = front;      
        if(front == NULL)  
        {  
            printf("\nEmpty queue\n");  
        }  
        else  
        {   printf("\nELEMENTS ARE :\n");  
            while(ptr != NULL)   
            {  
                printf("\n%d\n",ptr -> data);  
                ptr = ptr -> next;  
            }  
        }  
    }  
