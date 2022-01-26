#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 1000
int a[MAX];
int n=0;
void insert(int x,int p){
    if(p>n) insert(x,n);
    for(int j=n-1;j>=p;j--){
        a[j+1]=a[j];
        a[p]=x;
        n=n+1;
    }
}
void delete(int *a,int p){
    for(int j=p+1;j<n;j++){
        a[j-1]=a[j];
    }
    n=n-1;
}
int location(int x){
    for(int j=0;j<n;j++){
        if(a[j]==x) return j;
    }
    return -1;
}
int main(){
    srand(time(0));
    int number=rand()%100;
    while(n!=number){
        insert(rand()%100,rand()%1000);
    }
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}