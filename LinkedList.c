#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
typedef struct Node{
int data;
struct Node *next;
}Node;

void printList(Node *head);

int isEmpty(Node *head);

Node * newCreateNode(int value);

void removeLast(Node **head);

void removeHead(Node **head);

void indexByRemove(Node **head,int index);

void addHead(Node **head,int value);

void addLast(Node**head,int value);

void insertAfter(Node **head,int value,int after);

void insertBefore(Node **head,int value,int after);

void removeList(Node **head);

int indeByValue(Node*head,int index);

Node *reverseList(Node **head);


int size(Node *head);

int main(){
    Node *root=(Node*)malloc(sizeof(Node));
    root->data=14;
    root->next=NULL;
    removeHead(&root);
    addHead(&root,20);
    addLast(&root,30);
    removeLast(&root);
    addLast(&root,78);
    addLast(&root,670);
    addLast(&root,89);
    insertAfter(&root,23,30);
    insertBefore(&root,55,670);
   printf("Value:%d\n",indeByValue(root,1));
   //removeList(&root);
   reverseList(&root);
   printf("length:%d\n",size(root));
    printList(root);


return 0;
}
void printList(Node*head){
Node *iter=head;
for(;iter!=NULL;iter =iter->next)
    printf("%d ",iter->data);
}
int isEmpty(Node *head){
return (head==NULL) ? 1 : 0;
}

Node * newCreateNode(int value){
Node *newNode=(Node*)malloc(sizeof(Node));
newNode->data=value;
newNode->next=NULL;
return newNode;
}


void removeLast(Node **head){
Node *iter=*head;
if(iter->next!=NULL){
    while(iter->next->next!=NULL){
        iter=iter->next;
    }
    free(iter->next);
    iter->next=NULL;
}
}
 void removeHead(Node**head){
 Node *iter=*head;
 (*head)=(*head)->next;
 free(iter);
 }
 void indexByRemove(Node **head,int index){
    Node *iter=*head;
    Node *temp=NULL;
     if(index==0){
           removeHead(*head);
           return;
     }
     for(int i=0;i<index-1;i++){
         if(iter->next==NULL)
         {
             removeLast(iter);
             return;
         }
        iter=iter->next;
     }
temp=iter->next;
iter->next=temp->next;
free(temp);
}
void addHead(Node **head,int value){
Node *newNode=newCreateNode(value);
if(isEmpty(*head)){
    *head=newNode;
    return;
}
newNode->next=*head;
*head=newNode;
}
void addLast(Node**head,int value){
Node *iter=*head;

Node *newNode=newCreateNode(value);

for(;iter->next!=NULL;iter=iter->next);

iter->next=newNode;
}

void insertAfter(Node **head,int value,int after){
Node *iter=*head;
Node *temp=NULL;
Node *newNode=newCreateNode(value);
if(isEmpty(iter)){
    printf("Failed to insert element. Out of memory");
    return;
}
while(iter->next->data==after)
{
 if(isEmpty(newNode)){
    printf("Failed to insert element. Out of memory");
    break;
 }
    iter=iter->next;
}
temp=iter->next;
iter->next=newNode;
newNode->next=temp;
}

void insertBefore(Node **head,int value,int before){
Node *temp=NULL;
Node *newNode=newCreateNode(value);
Node *iter=*head;
if(isEmpty(*head))
{
   addHead(&iter,value);
    return;
}
while(iter->next!=NULL){

   if(isEmpty(newNode)){
    printf("Failed to insert element. Out of memory");
    break;
   }
  else if(iter->next->data==before){
    temp=iter->next;
    iter->next=newNode;
    newNode->next=temp;
   }
    iter=iter->next;
}
}
void removeList(Node **head){
Node *iter=*head;
Node *temp=NULL;
for(;iter!=NULL;iter=temp)
 {
     temp=iter->next;
     free(iter);
 }
*head=NULL;
}
int indeByValue(Node *head,int index){
Node *iter=head;
if(isEmpty(head))
{
   printf("Failed to insert element. Out of memory");
   return;
}
for(int i=0;i <index-1;i++)iter=iter->next;

if(isEmpty(iter))return -1;

return iter->data;
}
Node *reverseList(Node **head){
Node *iter=*head;
Node *next=NULL;
Node *prev=NULL;

while(iter!=NULL){
    next=iter->next;
    iter->next=prev;
    prev=iter;
    iter=next;
}
*head=prev;
return *head;
}
int size(Node*head){
Node *iter=head;
int count=0;
if(isEmpty(iter))
    return 0;

for(;iter!=NULL;iter=iter->next) count++;

return count;
}
