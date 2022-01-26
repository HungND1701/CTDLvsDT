//Lap trinh de quy co nho _ to hop nCk
#include<stdio.h>
#define MAX 100 
int F[MAX][MAX];
int C(int k,int n){
    if(k==0||k==n) F[k][n]=1;
    else{
        if(F[k][n]<0) F[k][n]= C(k-1,n-1)+C(k,n-1);
    }
    return F[k][n];
}
int main(){
    int n,k;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++) F[i][j]=-1;
    }
    printf("Nhap to hop can tinh nCk: ");
    scanf("%dC%d",&n,&k);
    printf(" nCk = %d", C(k,n));

    return 0;
}