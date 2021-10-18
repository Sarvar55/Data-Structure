#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node*next;
struct Node*prev;
}node;


node *GetNewNode(int data);

void printList(node *head);

int isEmpty(node *head);

int length(node *head);

node* addHead(node*head,int data);

node* insertAdd(node*head,int data,int order);

node* addLast(node*head,int data);



int main()
{
    node *root=GetNewNode(12);

    root=addLast(root,45);
    root=addHead(root,19);
    root=addHead(root,14);
    root=addHead(root,345);
    root=insertAdd(root,790,3);
    root=insertAdd(root,367,5);

       printf("%d list length:\n",length(root));
       printList(root);

    return 0;
}
node *GetNewNode(int data){
node *temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->next=NULL;
temp->prev=NULL;

return temp;
}

void printList(node*head)
{
    node*iter=head;
    for(;iter!=NULL;iter=iter->next)
        printf("%d ",iter->data);

}

int length(node*head){
int count=0;node*iter=head;
    for(;iter!=NULL;iter=iter->next)
        count++;
    return count;
}


int isEmpty(node *head){
return (head==NULL);
}

node *addHead(node*head,int data){
node*temp=GetNewNode(data);
if(isEmpty(head)){
    head=temp;
    return;
}
else{
    head->prev=temp;
    temp->next=head;
    temp->prev=NULL;
    head=temp;
}
return head;
}

node* insertAdd(node*head,int data,int order){
node *newNode=GetNewNode(data);
int flag=0,count=0;
if(order==0){
    addHead(head,data);
    return;
}
if(isEmpty(head->next) && order > 0){
    printf("Ekleme yapilamaz:");
    return;
}
node *iter=head;
while(iter!=NULL){
    count++;
    if(order==count)
    {
        flag=1;
        break;
    }
    iter=iter->next;
}
if(!flag){
    printf("Eklenicek yer yok");
    return;
}
if(isEmpty(iter->next))
{
    addLast(head,data);
    return;
}
node *temp=iter->prev;
temp->next=newNode;
newNode->next=iter;
newNode->prev=temp;
iter->prev=temp;

return head;
}

node* addLast(node*head,int data){

node *temp=GetNewNode(data);
if(isEmpty(head))
    addHead(head,data);
else{

    node *iter=head;
    while(iter->next!=NULL)iter=iter->next;
    iter->next=temp;
    temp->prev=iter;
    temp->next=NULL;

}
return head;
}

