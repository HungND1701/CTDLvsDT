#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct d_List{
	int num;
	struct d_List *next;
	struct d_List *prev;
}dList; 
dList *First,*Last;
dList * MakeNode(int x){
    dList * temp;
    temp=(dList*)malloc(sizeof(dList));
    temp->num=x;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
int IsEmpty(){
    if(First==NULL&&Last==NULL) return 1;
    return 0;
}
void push_back(int X){
    dList * temp;
    temp=MakeNode(X);
    if(IsEmpty()){
        First=temp;
        Last=temp;
        return ;
    }
    temp->prev=Last;
    Last->next=temp;
    Last=temp;
    return ;
}
void push_front(int X){
    dList * temp;
    temp=MakeNode(X);
    if(IsEmpty()){
        First=temp;
        Last=temp;
        return ;
    }
    temp->next=First;
    First->prev=temp;
    First=temp;
    return ;
}
void erase(dList *p){
    if(p == NULL) return;
    if(IsEmpty()){
        First = NULL; 
        Last = NULL; 
        free(p);
    } 
    if(p == First){
        First = p->next; 
        First->prev = NULL;
        free(p); 
        return;
    }
    if(p == Last){
        Last = p->prev; 
        Last->next = NULL;
        free(p);
        return;
    } 
    p->prev->next = p->next;  p->next->prev = p->prev;  free(p); 
}
void pop_front(){
    if(IsEmpty()) return;
    dList*TempNode,*p;
    p=First;
    TempNode = First->next;
    First=TempNode;
    First->prev=NULL;
    free(p);
}
void pop_back(){
    if(IsEmpty()) return;
    dList*TempNode,*p;
    p=Last;
    TempNode = Last->prev;
    Last=TempNode;
    Last->next=NULL;
    free(p);
}
void clear(){  //Xoa List
    while(!IsEmpty()){
        pop_front();
    }    
}
int size(){
    int i=1;
    dList * pred;
    pred=First;
    while(pred!=Last){
        pred=pred->next;
        i++;
    }
    return i;
}
void Print(){
    if(IsEmpty()){
        printf("List is empty\n");
        return;
    }
    dList * pred=First;
    do{
        printf("%d ",pred->num);
        pred=pred->next;
    }while(pred!=NULL);
    printf("\n");
}
int main(){
    for(int i=1;i<=5;i++){
        push_front(i);
    }
    Print();
    for(int i=1;i<=5;i++) push_back(i);
    Print();
    printf("size : %d \n",size());
    pop_front();
    pop_back();
    Print();
    printf("size : %d \n",size());
    int i=0;
    dList*pred=First;
    while(i!=2){
        pred=pred->next;
        i++;
    }
    erase(pred);
    Print();
    printf("size : %d \n",size());
}