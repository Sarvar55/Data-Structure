#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <stdio.h>

typedef struct Node
{
    int data;

    struct Node *next;
    
    struct Node *prev;

}node;

int isEmpty(node *head);

node *createNode(int data);

node *add(node *head,int data);

node *removelist(node *head,int index);

node*binaryConventor(node*head,int input);

node *last(node*head);

int length(node*head);

void reversePrint(node*head);

int main(){

node *head=NULL;

int number;

printf("Lutfen binary sayiya cevirmek istediginiz sayiyi giriniz:");
scanf("%d",&number);

reversePrint(binaryConventor(head,number));

printf("\n");
printf("length:%d",length(binaryConventor(head,number)));

    return 0;
}
int isEmpty(node *head){
    return (head==NULL) ? 1 : 0 ;
}

node *createNode(int data){
    node *temp=(node*)malloc(sizeof(node));

    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;

    return temp;
}


node *add(node *head,int data){
    if(isEmpty(head))
        head=createNode(data);
    else{
        node *temp=createNode(data);
        node *iter=head;
        while(iter->next)iter=iter->next;

           iter->next=temp;
           temp->next=NULL;
           temp->prev=iter;  
    }  
    return head;  
}

node *removelist(node *head,int index){
    
    node *iter=head;
    node *temp=NULL;
    int i=0;
    while(i++ < index)
      iter=iter->next;

    temp=iter->prev;
    temp=iter->next;
    free(iter);
 return head;
}

node* binaryConventor(node*head,int input){
    int bolunen;
    int kalan;
    
       while(bolunen!=0){

        bolunen = input / 2;

        kalan = input % 2;

        input = bolunen;
       head = add(head,kalan);
    }    
return head;
}


node *last(node*head){
    node *iter=head;
    while (iter->next!=NULL)iter=iter->next;
    
    return iter;
}

void reversePrint(node*head){
    node *iter=last(head);
    node *temp=head;
    while(iter!=temp){
        printf("%d ",iter->data);
        iter=iter->prev;
    }
    printf("%d",iter->data);
}

int length(node*head){
    int counter=0;
    node *iter=head;
    while(iter!=NULL){
        counter++;
        iter=iter->next;
    }
  return counter;
}