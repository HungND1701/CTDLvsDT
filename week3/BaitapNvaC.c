/* Tim Day con tang, co so luong phan tu la lon nhat */
#include<stdio.h>
#include<stdlib.h>
#define MAX 999
int Arr[]={1,2,4,-6,-5,7,8,-10,9,-11};
int a[10],max,mark[10];
int kiemtra(int k){
    int j=-999;
    for(int x=0;x<9;x++){
        if(Arr[x]==-9999) continue;
        if(Arr[x]>j) j=Arr[x];
        else return 0;
    }
    return 1;
}
void process(int k){
    if(max<10-k) max=10-k;
}
void daycon(int k){
    for(int i=0;i<10;i++){
        if(mark[i]==0){
           a[i]=Arr[i];
           Arr[i]==-9999;
           mark[i]=1;
           if(kiemtra(k)==1){
             process(k);
           }else if(max<10-k) daycon(k+1);
           mark[i]=0;
           Arr[i]=a[i];
        }
    }
}

int main(){
    max=0;
    for(int i=0;i<10;i++) mark[i]=0;
    daycon(1);
    printf("%d\n",max);
    return 0;
}