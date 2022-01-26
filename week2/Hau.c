#include<stdio.h>
#define MAX 100
int n,count;
int arr[MAX];

int kiemtra(int j , int i){       // j la cot , i la hang , arr[i] luu du gi tri cot j
    for(int x=1;x<i;x++)
        if(j==arr[x] || (j-arr[x])== (i-x) || (j-arr[x])==(x-i)){
            return 0;
        }
    return 1;
}
void result(){
    int i;
    count++;
    printf("Cach %d: ",count);
    for(i=1;i<=n;i++) printf("%d ",arr[i]);
    printf("\n");
}
int Hau(int i){
    for(int j=1;j<=n;j++){
         if(kiemtra(j,i)){
             arr[i]=j;
             if(i==n) result();
             else Hau(i+1);
          }
    }
}
int main(){
    
    printf("Nhap so quan Hau : ");
    scanf("%d",&n);
    // Liet ke so cach xep n quan Hau
    count=0 ; Hau(1);
    if(count==0) printf("Khong co cach xep Hau\n");
    else printf("Co %d Cach xep Hau \n",count);
    return 0;
}