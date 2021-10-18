#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true}boolean;

typedef struct Queue{
int front,rear,size;
int *array;
unsigned capacity;

}queue;

queue *getCreateQueue(unsigned capacity);

boolean isEmpty(queue*root);

boolean isFull(queue*root);

void enqueue(queue *root,int val);

int dequeue(queue*root);

int front(queue*root);

int rear(queue*root);

void printList(queue*root);

int main()
{

queue*root=getCreateQueue(10);

for(int i=0;i<10;i++)
    enqueue(root,(i*2)+(10+i));

printList(root);
printf("\nFront:%d\n",front(root));
printf("Rear:%d\n",rear(root));
printf("%d dequeued from queue\n",dequeue(root));





    return 0;
}

queue *getCreateQueue(unsigned capacity){
queue *root=(queue*)malloc(sizeof(queue));
root->capacity=capacity;
root->front=root->size=0;
root->rear=root->capacity-1;
root->array=(int*)malloc(sizeof(int) * root->capacity);
return root;
}
boolean isEmpty(queue*root){
return (root->size==0);
}

boolean isFull(queue*root){
return (root->size==root->capacity);
}

void enqueue(queue *root,int val){
if(isFull(root))
    return;
                // (9+1) %10 =0, (0 +1)% 10 =1 ;
   root->rear=(root->rear + 1) % root->capacity;// 0 1 2 3 ...
   root->array[root->rear]=val;
   root->size++;
}
int dequeue(queue*root){
if(isEmpty(root))return ;

int deleteVal=root->array[root->front];
//            (0+1)%10=1
root->front=(root->front+1) % root->capacity;
root->size--;
return deleteVal;
}

int front(queue*root){
return root->array[root->front];
}

int rear(queue*root){
return root->array[root->rear];
}

void printList(queue*root){
if(isEmpty(root))
    return;

for(int i=root->front;i<root->size;i++){
    printf("%d ",root->array[i]);
}
}
