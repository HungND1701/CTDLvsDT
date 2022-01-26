#include<stdio.h>
#define MAX 1000
#define oo -999999
int max(int a,int b,int c){
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    return max;
}
int maxleft(int arr[],int i,int j){
    int sum=0,max = oo;
    for(int x=j;x>=i;x--){
        sum+=arr[x];
        if(max<sum) max=sum;
    }
    return max;
}
int maxright(int arr[],int i,int j){
    int sum=0,max = oo;
    for(int x=i;x<=i;x++){
        sum+=arr[x];
        if(max<sum) max=sum;
    }
    return max;
}
int maxsub(int arr[],int i ,int j){ 
    if(i==j) return arr[i];
    else {
        int m=(i+j)/2;
        int wL=maxsub(arr,i,m);
        int wR=maxsub(arr,m+1,j);
        int wM=maxleft(arr,i,m)+ maxright(arr,m+1,j);
        return max(wL,wR,wM);
    }
}
int main(){

    int arr[MAX],n;
    printf("Nhap so phan tu cua mang : ");
    scanf("%d",&n);
    printf("\nNhap mang : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Tri so max cua cac mang con la :%d ",maxsub(arr,0,n-1));
    return 0;
} 