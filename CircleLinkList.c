#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

 typedef struct Node{
 int data;
 struct Node *next;
 }Node;

void printList(Node *head);

void addHead(Node*head,int val);

void addLast(Node *head,int val);

int isEmpty(Node *head);

Node *concatList(Node *list1,Node*list2);

Node *searchNode(Node *head,int val);

Node *hashSet(Node *head,int val);

int main()
{
Node *root=(Node *)malloc(sizeof(Node));
root->data=12;
root->next=root;
root->next->data=123;
root->next->next=root;
Node *root1=(Node *)malloc(sizeof(Node));
root1->data=13;
root1->next=root1;
addHead(root1,135);
addHead(root,134);
addLast(root,1256);
printList(root);
printf("\n");
printf("ConcatList=> ");
printList(concatList(root1,root));

printf("\n\n");

if(searchNode(root,1256))
    printf("Bulundu\n");
else
printf("Bulunamadi\n");

printf("\n\n");


printList(root);
printf("\n");
if(!hashSet(root,123))
    printf("Bu eleman listeden var");
else
    printf("Listeye yeni eleman eklendi");


    return 0;
}
int isEmpty(Node *head){
return head==NULL? 1 : 0;
}
void printList(Node*head){
Node *last=head;
do{
    printf("%d ",last->data);
    last=last->next;
}while(last!=head);
}

void addHead(Node*head,int val){
if(isEmpty(head))
{
    head->data=val;
    head->next=head;

}
else{
    Node *last=head;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    while(last->next!=head)last=last->next;
    temp->next=head;
    head=temp;
    last->next=temp;
}
}
void addLast(Node*head,int val){
if(isEmpty(head)){
    addHead(head,val);
}
else{
    Node *last=head;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    while(last->next!=head)last=last->next;
    last->next=temp;
    temp->next=head;
}
}
Node*concatList(Node*list1,Node*list2){
if(isEmpty(list1))
    list1=list2;
else{
    Node *last=list1;
    while(last->next!=list1)last=last->next;
    last->next=list2;

    last=list2;
    while(last->next!=list2)last=last->next;
    last->next=list1;
}
return list1;
}
Node *searchNode(Node *head,int val){
Node*last=head;
if(isEmpty(head))
{
    printf("Node is Empty");
}
if(head->data==val)
    return 1;

else{
    do{
        if(last->data==val)
            return 1;
        last=last->next;
    }while(last!=head);
}
return 0;
}

Node *hashSet(Node *head,int val){
Node *temp=(Node*)malloc(sizeof(Node));
 if(isEmpty(head)){
    head->data=val;
    head->next=head;
 }
 else{
    if(!searchNode(head,val)){// burada basit bir javada ki gibi hashSet yapmaya calistim
        temp->data=val;
        temp->next=head;
         return 1;// eger gonderilen eleman listede yoksa 0 varsa 1 dondurucek
    }
    else
     return 0;
  }
}
