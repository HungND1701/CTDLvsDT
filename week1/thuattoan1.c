#include<stdio.h>
#define MAX 1000
int Max_arr (int arr[],int n){

    int sum_max=-9999;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0 ;
             for(int x=i;x<=j;x++){
                 sum+=arr[x];
                 if(sum>sum_max) sum_max=sum;
             }
        }
    }
    return sum_max;
}
int main(){

    int arr[MAX],n;
    printf("Nhap so phan tu cua mang : ");
    scanf("%d",&n);
    printf("\nNhap mang : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Tri so max cua cac mang con la :%d ",Max_arr(arr,n));
    return 0;
} 