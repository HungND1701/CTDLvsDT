#include<stdio.h>
#define MAX 999
int arr[MAX],n,count=0;
int kiemtra(int v,int i){
    if(i+1==v) return 0;
    for(int j=0;j<i;j++){
        if(arr[j]==v) return 0;
    }
    return 1;
}
void result(){
   count++;
   printf("%d: ",count);
   for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
   }
   printf("\n");
}
void Hoanvi(int i,int n){
   for(int x=1;x<=n;x++){
       if(kiemtra(x,i)){
           arr[i]=x;
           if(i==(n-1)) result();
           else Hoanvi(i+1,n);
       }
   }
}

int main(){
    printf("Nhap so n : ");
    scanf("%d",&n);
    Hoanvi(0,n);
    return 0;
}