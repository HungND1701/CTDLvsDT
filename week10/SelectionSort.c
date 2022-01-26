#include<stdio.h>

void selectionSort(int A[],int N){
    for(int k=0;k<N;k++){
        int min =k;
        for(int j=k+1;j<N;j++){
            if(A[min]>A[j]) min=j;
        }
        int tmp= A[min];
        A[min]=A[k];
        A[k]=tmp;
    }
}

int main(){
    int A[]={5,7,3,8,1,2,9,4,6};
    int n = sizeof(A)/sizeof(int);
    selectionSort(A,n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}