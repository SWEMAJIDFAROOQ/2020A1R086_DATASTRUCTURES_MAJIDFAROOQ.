#include<stdio.h>
#include<stdlib.h>      // for dynamic memory allocation and exit()
#include<conio.h>       // for getch()
#include<limits.h>      
struct Queue{
    int front;              // front is the index of the front element(element present at the front of the queue)
    int rear;              // rear is the index of the rear element(element present at the rear/end of the queue)
    int maxSize;          // maximum size of the queue
    int *array;         // for storing elements
};
// calculating the number of elements in the queue
int totalElements(struct Queue *queue){
    if(queue->front == -1 && queue->rear == -1){
        // when queue is empty, the function returns 0
        return 0;
    }else if(queue->rear >= queue->front){
        return (queue->rear - queue->front)+1;
    }else{
        return  (((queue->maxSize - 1) - queue->front) + 1) + (queue->rear + 1);
    }
}
// check if the queue is full
int isFull(struct Queue *queue){
    // queue will be full when number of elements in queue will be equal to the maximum size of the queue
    if(totalElements(queue) == queue->maxSize){
        return 1;
    }else{
        return 0;
    }
}
// enQueue() function for inserting element in the queue
void enQueue(struct Queue *queue, int element){
    if(isFull(queue)){
        printf("Queue has reached its maximum capacity. \n");
    }else{
            if(totalElements(queue) == 0){
                     queue->front = 0;          // incrementing front
            }
        queue->rear = (queue->rear+1)%queue->maxSize;       // increment rear circularly
        queue->array[queue->rear] = element;                // insert the element in the queue
        printf(" %d enqueued to queue\n", element);
    }
}
// deQueue() function for deleting element from the queue
int deQueue(struct Queue *queue){
    int ret;
    if(totalElements(queue) != 0){
        ret = queue->array[queue->front];           
        if(queue->front == queue->rear){
            // queue will be empty after front exceeds rear
            queue->front = -1;
            queue->rear = -1;
        }else{
                 queue->front = (queue->front + 1)% queue->maxSize;     // increment front circularly
        }
        return ret;
    }else{
            return INT_MIN;
    }
}
// for displaying elements present in the queue
void displayElements(struct Queue *queue){
    int i;
    i = queue->front;
    if(totalElements(queue)== 0){
        printf("The queue is empty. \n");
    }else{
            printf("The elements present in the queue are... \n");
            do{
	        printf("%d ", queue->array[i]);
	        i = (i + 1) % (queue->maxSize);
	    } while (i != (queue->rear + 1) % queue->maxSize);
		printf("\n");
	}
}
int main(){
     printf("\t\t QUEUE IMPLEMENTATION \n");
    int maxSize, choice, element, del; 
    struct Queue queue;
    printf("Enter the maximum size of the queue : ");
    scanf("%d", &maxSize);
    queue.maxSize = maxSize;        // assigning maximum size to the queue
    queue.front = queue.rear = -1; // initializing front and rear to -1, queue is empty
    queue.array = (int *)malloc(queue.maxSize * sizeof(int)); // allocating memory
    do{
        printf("\t OPERATIONS \n");
        printf("1. enQueue \n");
        printf("2. deQueue \n");
        printf("3. Display Elements \n");
        printf("4. Exit \n ");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the element you want to insert in the queue : ");
                    scanf("%d", &element);
                    enQueue(&queue, element);       // function call
                    break;
            case 2: printf("Deleting from the Queue... \n");
                    del = deQueue(&queue);                          // function call
                    // condition after returning from the function
                    if(del == INT_MIN){
                        // Queue is empty
                        printf("No element deleted as the queue is empty. \n");
                    }else{
                        printf("%d deleted from the queue. \n", del);
                    }
                    break;
            case 3: displayElements(&queue);        // function call
                    break;
            case 4: exit(0);
            default: printf("WRONG CHOICE ENTERED !!!");
                     break;                         
        }
        printf("Press enter to continue... \n");
        getch();
    }while(1);
    return 0;
}