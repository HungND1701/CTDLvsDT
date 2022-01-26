#include<stdio.h>
#define MAX 1000
int Max_arr (int arr[],int n){

    int sum_max,s[n];
    sum_max=arr[0];
    s[0]=arr[0];
    for(int i=1;i<n;i++){
        if(s[i-1]>0) s[i]=s[i-1]+arr[i];
        else s[i]=arr[i];
        if(sum_max<s[i]) sum_max=s[i];
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