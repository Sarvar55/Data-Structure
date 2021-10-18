#include <stdio.h>
#include <stdlib.h>
typedef enum{false,true} boolean;
typedef struct Stack{
int top;/* sürekli eleman ekleme ve silme işlemi yapilacaği için en üstteki
* elemanın indisini tutan top adında bir değişken tanımladim */
unsigned size;
int *array;//array[]

}Mystack;

Mystack * createStack(unsigned size);

boolean isEmpty(Mystack *stack);

boolean isFull(Mystack *stack);

void push(Mystack *stack,int data);

void pop(Mystack *stack);

int peek(Mystack *stack);

void printStack(Mystack *stack);

int main()
{

   Mystack *stack=createStack(10);

   push(stack,13);
   push(stack,18);
   push(stack,24);
   push(stack,890);
   push(stack,1379);
   pop(stack);
   printStack(stack);
   printf("\npeek=>%d",peek(stack));

    return 0;
}
Mystack * createStack(unsigned size){

Mystack *stack =(Mystack*)malloc(sizeof(Mystack));
stack->size=size;
stack->top=-1;
stack->array=(int*)malloc(sizeof(int) * stack->size);
return stack;

}

boolean isEmpty(Mystack *stack){
return (stack->top==-1)? 1 : 0;  // stack boş mu diye kontrol ediliyor 
}

boolean isFull(Mystack *stack){
return (stack->top==stack->size-1)? 1 :0;// top son indisi tutuyorsa doludur  9==10-1 
}

void push(Mystack *stack,int data){
if(isFull(stack))return;

stack->array[++stack->top]=data;//++stack->top dememizin sebebi diziler 0. indsden basladigi icin 1 artirib sonra eleman ekilyoruz 
}

void pop(Mystack *stack){
if(isEmpty(stack))return -1;

stack->array[stack->top--];// burada ise ilk eleman siliniyor aslinda tam olarak silinmiyor yani yine de bellekde yer kapliyor ama silmek icin sadece -1 dememiz yetiyor
}

int peek(Mystack *stack){
if(isEmpty(stack))return -1;

return stack->array[stack->top];//burada ise top degeri kac ise o indisdeki degeri donduruyor yani ilk elemani
}

void printStack(Mystack *stack){
if(isEmpty(stack))return;

for(int i=stack->top;i >=0;i--)
    printf("%d ",stack->array[i]);
}
