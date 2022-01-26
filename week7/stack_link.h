#include<stdio.h>
#include<stdlib.h>
typedef int Item;
typedef struct StackNode{
    Item Inf;
    struct StackNode * next;
}StackNode;
typedef struct Stack
{
    StackNode *top;
}Stack;
int StackEmpty(const Stack *s){
    return (s->top==NULL);
}
Stack *StackConstruct(){
    Stack * s;
    s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
    s->top=NULL;
    return s;   
}
int StackFull(){
    printf("\n No Memory, Stack is Full\n");
    getc(stdin);
    return 1;
}
void disp(Stack *s){
    StackNode * node;
    int ct=0;float m;
    printf("\n\n Danh Sach Cac phan tu cua Stack\n\n");
    if(StackEmpty(s)){
        printf("\n\n >>>>> EMPTY STACK <<<<<\n");
        getchar();
    }else{
        node = s->top;
        do{
            m=node->Inf;
            printf("%d ",m); ct++;
            if(ct%9==0) printf("\n");
            node=node->next;
        }while(!(node==NULL));
        printf("\n");
    }
}
int StackPush(Stack *s, Item X){
    StackNode * node;
    node=(StackNode*)malloc(sizeof(StackNode));
    if(node==NULL){
        StackFull();
        return 1;
    }
    node->Inf=X;
    node->next=s->top;
    s->top=node;
    return 0;
}
Item StackPop(Stack *s){
    Item X;
    StackNode * node;
    if(StackEmpty(s)){
        return -1;
    }
    node=s->top;
    X=node->Inf;
    s->top=node->next;
    free(node);
    return X;
}
void StackDestroy(Stack *s){
    while(!StackEmpty(s)){
        StackPop(s);
    }
    free(s);
}
