#include <stdio.h>
#include <stdlib.h>
typedef enum {false,true}boolean;

typedef struct Stack{
int top;
struct Stack  *next;
}Stack;

boolean isEmpty(Stack*root);

Stack *getCreateStack(int data);

void push(Stack**root,int data);

int pop(Stack**root);

int peek(Stack*root);

void printStack(Stack*root);


int main()
{
    Stack *root=getCreateStack(12);
    push(&root,15);
    push(&root,45);
    push(&root,95);
    printf("pop=>%d\n",pop(&root));
    printf("peek=>%d\n",peek(root));

    printStack(root);


    return 0;

}
boolean isEmpty(Stack*root){
return !root;
}
Stack *getCreateStack(int data){
 Stack *newStack=(Stack*)malloc(sizeof(Stack));

 newStack->top=data;

 newStack->next=NULL;

 return newStack;
}

void push(Stack**root,int data){
    Stack *temp=getCreateStack(data);
    if(isEmpty(root)) root=temp;
    else{
       temp->next=*root;
       *root=temp;
    }
}
int pop(Stack**root){
if(isEmpty(*root)) return-1;

Stack *temp=(*root);

int deleteVal=(*root)->top;
(*root)=(*root)->next;
free(temp);

return deleteVal;
}
int peek(Stack*root){
if(isEmpty(root))return-1;
return root->top;
}
void printStack(Stack*root){
Stack*iter=root;
while(iter!=NULL){
    printf("%d ",iter->top);
    iter=iter->next;
}
}



